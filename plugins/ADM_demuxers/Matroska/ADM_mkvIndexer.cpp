/***************************************************************************
    copyright            : (C) 2006 by mean
    email                : fixounet@free.fr
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <math.h>

#include "ADM_default.h"
#include "ADM_Video.h"
//#include "fourcc.h"

#include "ADM_mkv.h"

#include "mkv_tags.h"
#include "DIA_working.h"
#define VIDEO _tracks[0]
/**
    \fn videoIndexer
    \brief index the video Track
*/
uint8_t mkvHeader::videoIndexer(ADM_ebml_file *parser)
{
  uint64_t fileSize,len,bsize;
  uint32_t alen,vlen;
  uint64_t id;
  ADM_MKV_TYPE type;
  const char *ss;

   parser->seek(0);
   DIA_working *work=new DIA_working("Matroska Images");
   // Start with a small index, it will grow automatically afterward
   for(int i=0;i<_nbAudioTrack+1;i++)
   {
    _tracks[i]._indexMax=1000;
    _tracks[i]._index=new mkvIndex[_tracks[i]._indexMax];
   }
    //************
   work->update(0);
   for(int clusters=0;clusters<_nbClusters;clusters++)
   {
   parser->seek(_clusters[clusters].pos);
   ADM_ebml_file cluster(parser,_clusters[clusters].size);
   int thiscluster=0;
   while(!cluster.finished())
   {
      work->update(clusters,_nbClusters);
      cluster.readElemId(&id,&len);
      if(!ADM_searchMkvTag( (MKV_ELEM_ID)id,&ss,&type))
      {
        printf("[MKV] Tag 0x%"LLX" not found (len %"LLU")\n",id,len);
        cluster.skip(len);
        continue;
      }
      //printf("\t\tFound %s\n",ss);
      switch(id)
      {
                default:
                case MKV_TIMECODE:
                  //printf("Skipping %s\n",ss);
                  cluster.skip(len);
                  break;
                case MKV_SIMPLE_BLOCK:
                    {
                      indexBlock(parser,len,_clusters[clusters].Dts);
                    }
                    break;
                case MKV_BLOCK_GROUP:
                {
                        //printf("Block Group\n");
                        ADM_ebml_file blockGroup(parser,len);
                        while(!blockGroup.finished())
                        {
                                blockGroup.readElemId(&id,&len);
                                if(!ADM_searchMkvTag( (MKV_ELEM_ID)id,&ss,&type))
                                {
                                  printf("[MKV] Tag 0x%"LLX" not found (len %"LLU")\n",id,len);
                                  blockGroup.skip(len);
                                  continue;
                                }
                                //printf("\t\t\t\tFound %s\n",ss);
                                //printf(">%s\n",ss);
                                switch(id)
                                {
                                  default: blockGroup.skip(len);
                                  case MKV_BLOCK :
                                  case MKV_SIMPLE_BLOCK:
                                  {
                                    indexBlock(&blockGroup,len,_clusters[clusters].Dts);
                                  }
                                  break;
                                }
                          }
                          thiscluster++;
            }

            break; // Block Group
       }
     }
   // printf("[MKV] ending cluster at 0x%llx\n",segment.tell());
  }
     printf("Found %"LU" images in this cluster\n",VIDEO._nbIndex);
     delete work;
     return 1;
}
/**
      \fn indexBlock
      \brief index a block, identify it and update index
*/
uint8_t mkvHeader::indexBlock(ADM_ebml_file *parser,uint32_t len,uint32_t clusterTimeCodeMs)
{
  int lacing,nbLaces,entryFlags=0;
  //
  uint64_t tail=parser->tell()+len;
  // Read Track id
  uint32_t tid=parser->readEBMCode();
  int track=searchTrackFromTid(tid);

      //printf("Wanted %u got %u\n",_tracks[0].streamIndex,tid);
      if(track==-1) //dont care track
      {
        parser->seek(tail);
        return 1; // we do only video here...
      }
      // Skip timecode
      uint64_t blockBegin=parser->tell();
      int16_t timecode=parser->readSignedInt(2);
      //if(!track) printf("TC: %d\n",timecode);
      uint8_t flags=parser->readu8();

      lacing=((flags>>1)&3);

      addIndexEntry(track,blockBegin,tail-blockBegin,entryFlags,clusterTimeCodeMs+timecode);
      parser->seek(tail);
      return 1;
}

/**
    \fn addVideoEntry
    \brief add an entry to the video index
    @param timecodeMS PTS of the frame in ms!
*/
uint8_t mkvHeader::addIndexEntry(uint32_t track,uint64_t where, uint32_t size,uint32_t flags,uint32_t timecodeMS)
{
  //
  mkvTrak *Track=&(_tracks[track]);
  // Need to grow index ?
  if(Track->_nbIndex==Track->_indexMax-1)
  {
    // Realloc
    mkvIndex *dx=new mkvIndex[Track->_indexMax*2];
    memcpy(dx, Track->_index,sizeof(mkvIndex)*Track->_nbIndex);
    Track->_indexMax*=2;
    delete [] Track->_index;
    Track->_index=dx;
  }

  mkvIndex *index=Track->_index;
  int x=Track->_nbIndex;
  index[x].pos=where;
  index[x].size=size;
  index[x].flags=AVI_KEY_FRAME;
  index[x].Dts=timecodeMS*1000;
  index[x].Pts=timecodeMS*1000;
  Track->_nbIndex++;
  return 1;
}

/**
  \fn searchTrackFromTid
  \brief Returns our track number for the stream track number. -1 if the stream is not handled.

*/
int mkvHeader::searchTrackFromTid(uint32_t tid)
{
  for(int i=0;i<1+_nbAudioTrack;i++)
  {
    if(tid==_tracks[i].streamIndex) return i;
  }
  return -1;
}

/**
  \fn readCue
  \brief Update index with cue content

*/
uint8_t                 mkvHeader::readCue(ADM_ebml_file *parser)
{
  uint64_t fileSize,len,bsize;
  uint64_t alen,vlen;
  uint64_t id;
  ADM_MKV_TYPE type;
  const char *ss;
  uint64_t time;
  uint64_t segmentPos;

   parser->seek(0);

   if(!parser->simplefind(MKV_SEGMENT,&vlen,1))
   {
     printf("[MKV] Cannot find CLUSTER atom\n");
     return 0;
   }
   ADM_ebml_file segment(parser,vlen);
   segmentPos=segment.tell();

   while(segment.simplefind(MKV_CUES,&alen,0))
  {
   ADM_ebml_file cues(&segment,alen);
   while(!cues.finished())
   {
      cues.readElemId(&id,&len);
      if(!ADM_searchMkvTag( (MKV_ELEM_ID)id,&ss,&type))
      {
        printf("[MKV] Tag 0x%"LLX" not found (len %"LLU")\n",id,len);
        cues.skip(len);
        continue;
      }
      if(id!=MKV_CUE_POINT)
      {
        printf("Found %s in CUES, ignored \n",ss);
        cues.skip(len);
        continue;
      }
      ADM_ebml_file cue(&cues,len);
      // Cue TIME normally
       cue.readElemId(&id,&len);
       if(id!=MKV_CUE_TIME)
       {
          ADM_searchMkvTag( (MKV_ELEM_ID)id,&ss,&type);
          printf("Found %s(0x%"LLX"), expected CUE_TIME  (0x%x)\n", ss,id,MKV_CUE_TIME);
          cue.skip(cue.remaining());
          continue;
       }
       time=cue.readUnsignedInt(len);


       cue.readElemId(&id,&len);
       if(id!=MKV_CUE_TRACK_POSITION)
       {
          ADM_searchMkvTag( (MKV_ELEM_ID)id,&ss,&type);
          printf("Found %s (0x%"LLX"), expected MKV_CUE_TRACK_POSITION (0x%x)\n", ss,id,MKV_CUE_TRACK_POSITION);
          cue.skip(cues.remaining());
          continue;
       }
       ADM_ebml_file trackPos(&cue,len);
       uint64_t tid=0;
       uint64_t cluster_position=0;
       while(!trackPos.finished())
       {
         trackPos.readElemId(&id,&len);
         switch(id)
         {
           case MKV_CUE_TRACK: tid=trackPos.readUnsignedInt(len);break;
           case MKV_CUE_CLUSTER_POSITION: cluster_position=trackPos.readUnsignedInt(len);break;
           default:
                 ADM_searchMkvTag( (MKV_ELEM_ID)id,&ss,&type);
                 printf("[MKV] in cluster position found tag %s (0x%"LLX")\n",ss,id);
                 trackPos.skip(len);
                 continue;
         }
       }
       printf("Track %"LLX" Position 0x%"LLX" time %"LLU" final pos:%"LLX" \n",tid,cluster_position,time,
             cluster_position+segmentPos );
     }
   }
   printf("[MKV] Cues updated\n");
   return 1;
}
/**
        \fn indexClusters
        \brief make a list of all clusters with there position & size
*/
uint8_t   mkvHeader::indexClusters(ADM_ebml_file *parser)
{
  uint64_t fileSize,len,bsize;
  uint64_t alen,vlen;
  uint64_t id;
  ADM_MKV_TYPE type;
  const char *ss;
  uint64_t time;
  uint64_t pos;

#define NB_DEFAULT_CLUSTERS 10
  // Allocate some clusters
  _clusters=new mkvIndex[NB_DEFAULT_CLUSTERS];
  _clustersCeil=NB_DEFAULT_CLUSTERS;
  _nbClusters=0;

  // Search segment
   fileSize=parser->getFileSize();
   if(!parser->simplefind(MKV_SEGMENT,&vlen,1))
   {
     printf("[MKV] cluster indexer, cannot find CLUSTER atom\n");
     return 0;
   }
   ADM_ebml_file segment(parser,vlen);
   DIA_working *work=new DIA_working("Matroska clusters");
   while(segment.simplefind(MKV_CLUSTER,&alen,0))
   {

     // UI update
     work->update(segment.tell()>>10,fileSize>>10);
     // Grow clusters index if needed
     if(_nbClusters==_clustersCeil-1)
     {
         mkvIndex *dx=new mkvIndex[_clustersCeil*2];
         memcpy(dx,_clusters,sizeof(mkvIndex)*_nbClusters);
         delete [] _clusters;
         _clusters=dx;
         _clustersCeil*=2;
     }
     _clusters[_nbClusters].pos=segment.tell();
     _clusters[_nbClusters].size=alen;

     // Normally the timecode is the 1st one following
       segment.readElemId(&id,&len);
       int seekme=_nbClusters;
       if(id!=MKV_TIMECODE)
       {
          ADM_searchMkvTag( (MKV_ELEM_ID)id,&ss,&type);
          printf("[MKV] Cluster : no time code Found %s(0x%"LLX"), expected MKV_TIMECODE  (0x%x)\n",
                  ss,id,MKV_TIMECODE);
       }
       else
       {
           uint64_t timecode=segment.readUnsignedInt(len);
           _clusters[_nbClusters].Dts=timecode;
           _nbClusters++;
       }
       segment.seek( _clusters[seekme].pos+ _clusters[seekme].size);
       //printf("Position :%u %u MB\n", _clusters[seekme].pos+ _clusters[seekme].size,( _clusters[seekme].pos+ _clusters[seekme].size)>>20);
   }
   delete work;
   printf("[MKV] Found %u clusters\n",_nbClusters);
   return 1;
}
//EOF
