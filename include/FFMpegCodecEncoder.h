#ifndef _H_FFMPEG_CODEC_ENCODER
#define _H_FFMPEG_CODEC_ENCODER

extern "C"
{
	#include <libavcodec/avcodec.h>
}
#include <FFMpegConverter.h>

int ffmpeg_jpeg_encode(unsigned char *srcBuf,unsigned char* dstBuf,int dstBufSize,PixelFormat srcPixFmt,int srcWidth,int srcHeight,int qvalue);

typedef struct
{
	unsigned short inputWidth;
	unsigned short inputHeight;
	unsigned short encodeWidth;
	unsigned short encodeHeight;
	unsigned char qmin;
	unsigned char qmax;
	unsigned short max_bframes;
	char inputPixelType[32];

}FFMpegCodecEncoderParam;

class FFMpegCodecEncoder
{
public:
	FFMpegCodecEncoder();
	~FFMpegCodecEncoder();


	int InitCodec(const char* codecStr, FFMpegCodecEncoderParam *param);
	int Encode(void* inputBuf);
	char* GetEncodeBuf();


protected:
	AVCodec *codec;
    AVCodecContext *c;
	int encBufSize;
	char *encBuf;

	FFMpegConverter *picConv;
	AVPicture *picSrc;
	AVFrame *frameSrc;
};

#endif
