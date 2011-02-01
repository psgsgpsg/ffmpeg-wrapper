#ifndef _H_FFMPEG_CONVERTER
#define _H_FFMPEG_CONVERTER

#ifdef DLL_EXPORT
#define FFMPEGWRAPPER_API __declspec(dllexport)
#else
#define FFMPEGWRAPPER_API __declspec(dllimport)
#endif

extern "C"
{
	//#include <libavutil/avconfig.h>
	#include <libavcodec/avcodec.h>
	#include <libavformat/avformat.h>
	#include <libswscale/swscale.h>
}



class FFMPEGWRAPPER_API FFMpegConverter
{
public:
	FFMpegConverter(int w1,int h1,PixelFormat f1,
					int w2,int h2,PixelFormat f2,unsigned char* dstBuf=NULL,int dstBufSize=0);
	~FFMpegConverter(void);

	int initContext(int w1,int h1,PixelFormat f1,
					int w2,int h2,PixelFormat f2);
	AVPicture* convertVideo(AVPicture *picSrc);


	SwsContext		*img_convert_ctx;
	int				scaleBufSize;
	unsigned char	*scaleBuf;
	AVPicture		*pPicScaled;

	bool m_bAllocBuf;
	int w1,w2,h1,h2;
	PixelFormat f1,f2;

};

#endif
