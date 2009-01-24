
/**
    \file edCache
    \brief Handle internal cache for decoded image

    Eviction is done using LRU method
    Counter is "now" and farther frame are seleced for replacement

*/
#include "ADM_default.h"
#include "ADM_image.h"
#include "ADM_editor/ADM_edCache.h"


#include "ADM_osSupport/ADM_debugID.h"
#define MODULE_NAME MODULE_EDITOR
#include "ADM_osSupport/ADM_debug.h"
#undef aprintf
#define aprintf(...) {}
/**
    \fn EditorCache
    \brief Constructor
*/

EditorCache::EditorCache(uint32_t size,uint32_t w, uint32_t h)
{
	_elem=new cacheElem[size];
	for(uint32_t i=0;i<size;i++)
	{
		_elem[i].image=new ADMImage(w,h);
		_elem[i].frameNum=ADM_INVALID_CACHE;
		_elem[i].lastUse=ADM_INVALID_CACHE;
	}
	_counter=0;
	_nbImage=size;
}
/**
    \fn EditorCache
    \brief Destructor
*/
EditorCache::~EditorCache(void)
{
	for(uint32_t i=0;i<_nbImage;i++)
	{
		delete _elem[i].image;
	}
	delete[] _elem;

}
/**
    \fn getImage
    \brief find image by framenumber, returns null if not found (obsolete)
*/
ADMImage 	*EditorCache::getImage(uint32_t no)
{
	for(uint32_t i=0;i<_nbImage;i++)
	{
		if(_elem[i].frameNum==no)
		{
			aprintf("EdCache: %lu  in cache %lu\n",no,i);
			_elem[i].lastUse=_counter;
			_counter++;
			 return _elem[i].image;
		}
	}
// 	aprintf("EdCache: %lu not in cache\n",no);
	return NULL;
}
/**
    \fn getFreeImage
    \brief  Get the LRUed iimage in the cache
                the cache is big enough to be immune
                to reuse in the same go
*/
ADMImage	*EditorCache::getFreeImage(void)
{
	uint32_t min=0;
	uint64_t  delta=0;
    int found=-1;

    // First search for a really free image
    for(int i=0;i<_nbImage;i++)
    {
        if(_elem[i].frameNum==ADM_INVALID_CACHE);
        found=i;
    }
    // Then the older one/LRU
    if(found==-1)
        for(int i=0;i<_nbImage;i++)
        {
            delta=abs((int)(_counter-_elem[i].lastUse));
            if(delta>min)
            {
                min=delta;
                found=i;

            }
        }
    if(found==-1) ADM_assert("Could not get a free image\n");
	_elem[found].lastUse=_counter+1;;
	_elem[found].frameNum=ADM_IN_USE_CACHE;

	return _elem[found].image;

}
/**
    \fn flush
    \brief Empty cache, mark all slots as not used

*/
 void        EditorCache::flush(void)
{
 for(int i=0;i<_nbImage;i++)
    {
        _elem[i].frameNum==ADM_INVALID_CACHE;
    }
}
/**
    \fn invalidate
    \brief invalidate one line of cache
*/
void        EditorCache::invalidate(ADMImage *image)
{
   // First search for a really free image
    for(int i=0;i<_nbImage;i++)
    {
        if(_elem[i].image==image);
            {
                   _elem[i].lastUse=ADM_INVALID_CACHE;;
                   _elem[i].frameNum=ADM_INVALID_CACHE;
                  return;
            }
    }
    ADM_assert("Image not in cache\n");
}
/**
        \fn updateFrameNum
        \brief update the frameNo associated to a cache line (obsolete)
               Only used to mark it as valid
*/
uint8_t		EditorCache::updateFrameNum(ADMImage *image,uint32_t frameno)
{
	for(uint32_t i=0;i<_nbImage;i++)
	{
		if(_elem[i].image==image)
		{
			ADM_assert(_elem[i].frameNum==ADM_IN_USE_CACHE);
			_elem[i].frameNum=frameno;
			_elem[i].lastUse=_counter;
			_counter++;
			return 1;

		}

	}
	ADM_assert(0);

}
void EditorCache::dump( void)
{
	for(int i=0;i<_nbImage;i++)
	{
		aprintf("Edcache content:%d %lu\n",i,_elem[i].frameNum);
	}
}
/**
    \fn findJustAfter
    \brief Find the image with the closest PTS just above pts.

*/
ADMImage    *EditorCache::findJustAfter(uint64_t pts)
{
int smallest=-1;
uint64_t value=0x100000000LL;

    for(uint32_t i=0;i<_nbImage;i++)
	{
		if(_elem[i].frameNum==ADM_INVALID_CACHE) continue;
		if(_elem[i].image->Pts>pts)
        {
            //printf("[Editor::findJustAfer] Looking for %lu, got %lu\n",pts,_elem[i].image->Pts);
            if(_elem[i].image->Pts < value)
            {
                value=_elem[i].image->Pts;
                smallest=i;
            }
        }
    }
	if(smallest==-1) return NULL;
    return _elem[smallest].image;
}
/**
    \fn getByPts
    \brief returns the image that has exactly that PTS
*/
ADMImage *EditorCache::getByPts(uint64_t Pts)
{
    for(int i=0;i<_nbImage;i++)
	{
		if(_elem[i].frameNum==ADM_INVALID_CACHE) continue;
		if(_elem[i].image->Pts==Pts)
        {
            _elem[i].lastUse=_counter;
			_counter++;
            return _elem[i].image;
        }
    }
    return NULL;
}
