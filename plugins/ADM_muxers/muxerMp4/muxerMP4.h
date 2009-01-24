/***************************************************************************
                          oplug_vcdff.h  -  description
                             -------------------
    begin                : Sun Nov 10 2002
    copyright            : (C) 2002 by mean
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
#ifndef ADM_MUXER_MP4
#define ADM_MUXER_MP4

#include "ADM_muxer.h"

typedef enum
{
    MP4_MUXER_MP4,
    MP4_MUXER_PSP
}MP4_MUXER_TYPE;

typedef struct
{
    MP4_MUXER_TYPE muxerType;
    uint32_t       useAlternateMP3Tag;
}M4MUXERCONFIG;

extern M4MUXERCONFIG muxerConfig;

class muxerMP4 : public ADM_muxer
{
protected:

public:
                muxerMP4();
        virtual ~muxerMP4();
        virtual bool open(const char *file, ADM_videoStream *s,uint32_t nbAudioTrack,ADM_audioStream **a);
        virtual bool save(void) ;
        virtual bool close(void) ;

};

#endif