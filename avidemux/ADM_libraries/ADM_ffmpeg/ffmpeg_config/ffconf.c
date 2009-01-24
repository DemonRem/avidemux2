/*
 * Glue to lavcodec configure
 * MEANX
 * */
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	printf("#include \"ADM_coreConfig.h\"\n");

#define DECLARE_DECODER(a,b); printf("#define ENABLE_"#a"_DECODER 1\n"); printf("#define CONFIG_"#a"_DECODER 1\n");
  
    DECLARE_DECODER(NELLYMOSER,nellymoser);
    DECLARE_DECODER(ADPCM_IMA_AMV, amv);
    DECLARE_DECODER(CINEPAK, cinepak);
    DECLARE_DECODER(DNXHD, dnxhd);
    DECLARE_DECODER(FOURXM, fourxm);
    DECLARE_DECODER(FRAPS, fraps);
	DECLARE_DECODER(H263, h263);
    DECLARE_DECODER(H264, h264);
    DECLARE_DECODER(INDEO2, indeo2);
    DECLARE_DECODER(INDEO3, indeo3);
    DECLARE_DECODER(INTERPLAY_VIDEO, interplay_video);
    DECLARE_DECODER(MPEGVIDEO, mpegvideo);
    DECLARE_DECODER(MSVIDEO1, msvideo1);
    DECLARE_DECODER(VC1, vc1);
    DECLARE_DECODER(VCR1, vcr1);
    DECLARE_DECODER(VP5, vp5);
    DECLARE_DECODER(VP6, vp6);
    DECLARE_DECODER(VP6A, vp6);
    DECLARE_DECODER(VP6F, vp6f);
    DECLARE_DECODER(WMV3, wmv3);
    DECLARE_DECODER (WMV1, wmv1);
    DECLARE_DECODER (WMV2, wmv2);
    DECLARE_DECODER(VP3, vp3);
    DECLARE_DECODER (MPEG4, mpeg4);
    DECLARE_DECODER (MSMPEG4V1, msmpeg4v1);
    DECLARE_DECODER (MSMPEG4V2, msmpeg4v2);
    DECLARE_DECODER (MSMPEG4V3, msmpeg4v3);
    DECLARE_DECODER(MJPEGB, mjpegb);
    DECLARE_DECODER (MJPEG, mjpeg);
    DECLARE_DECODER(WMAV2, wmav2);
    DECLARE_DECODER (DVVIDEO, dvvideo);
    DECLARE_DECODER (HUFFYUV, huffyuv);
    DECLARE_DECODER (FFVHUFF, ffvhuff);
    DECLARE_DECODER(SVQ3, svq3);
    DECLARE_DECODER(TSCC, tscc);
    DECLARE_DECODER(QDM2, qdm2);
    DECLARE_DECODER (FFV1, ffv1);
    DECLARE_DECODER (MPEG1VIDEO, mpeg1video);
    DECLARE_DECODER (MPEG2VIDEO, mpeg2video);
    DECLARE_DECODER (RV10, rv10);
    DECLARE_DECODER (RV20, rv20);
    DECLARE_DECODER (DVBSUB, dvbsub);
    DECLARE_DECODER (FLV, flv);
    DECLARE_DECODER (SNOW, snow);
    DECLARE_DECODER (AMV, amv);
#undef DECLARE_DECODER
#define DECLARE_DECODER(a,b); printf("#define ENABLE_"#a"_DECODER 0\n"); 

    DECLARE_DECODER(H264_VDPAU, h264_vdpau);
    DECLARE_DECODER(EATGQ, eatgq);
    DECLARE_DECODER(PCX, aasc);
    DECLARE_DECODER(SUNRAST, aasc);
    DECLARE_DECODER(VB, aasc);
    DECLARE_DECODER(XSUB, aasc);
    DECLARE_DECODER(AC3, aasc);
    DECLARE_DECODER(APE, aasc);
    DECLARE_DECODER(MPC8, aasc);
    DECLARE_DECODER(PCM_S16LE_PLANAR, aasc);
    DECLARE_DECODER(PCM_ZORK, aasc);
    DECLARE_DECODER(ADPCM_EA_R1, aasc);
    DECLARE_DECODER(ADPCM_EA_R2, aasc);
    DECLARE_DECODER(ADPCM_EA_R3, aasc);
    DECLARE_DECODER(ADPCM_EA_XAS, aasc);
    DECLARE_DECODER(ADPCM_IMA_EA_EACS, aasc);
    DECLARE_DECODER(ADPCM_IMA_EA_SEAD, aasc);

//
    DECLARE_DECODER(AASC, aasc);
    DECLARE_DECODER(AVS, avs);
    DECLARE_DECODER(BETHSOFTVID, bethsoftvid);
    DECLARE_DECODER(C93, c93);
    DECLARE_DECODER(CAVS, cavs);
    DECLARE_DECODER(CLJR, cljr);
    DECLARE_DECODER(CSCD, cscd);
    DECLARE_DECODER(CYUV, cyuv);
    DECLARE_DECODER(DSICINVIDEO, dsicinvideo);
    DECLARE_DECODER(DXA, dxa);
    DECLARE_DECODER(EIGHTBPS, eightbps);
    DECLARE_DECODER(FLIC, flic);
    DECLARE_DECODER(IDCIN, idcin);
    DECLARE_DECODER(KMVC, kmvc);
    DECLARE_DECODER(LOCO, loco);
    DECLARE_DECODER(MDEC, mdec);
    DECLARE_DECODER(MMVIDEO, mmvideo);
    DECLARE_DECODER(MPEG_XVMC, mpeg_xvmc);
    DECLARE_DECODER(MSRLE, msrle);
    DECLARE_DECODER(MSZH, mszh);
    DECLARE_DECODER(NUV, nuv);
    DECLARE_DECODER(PTX, ptx);
    DECLARE_DECODER(QDRAW, qdraw);
    DECLARE_DECODER(QPEG, qpeg);
    DECLARE_DECODER(RPZA, rpza);
    DECLARE_DECODER(SMACKER, smacker);
    DECLARE_DECODER(SMC, smc);
    DECLARE_DECODER(SP5X, sp5x);
    DECLARE_DECODER(THEORA, theora);
    DECLARE_DECODER(THP, thp);
    DECLARE_DECODER(TIERTEXSEQVIDEO, tiertexseqvideo);
    DECLARE_DECODER(TRUEMOTION1, truemotion1);
    DECLARE_DECODER(TRUEMOTION2, truemotion2);
    DECLARE_DECODER(TXD, txd);
    DECLARE_DECODER(ULTI, ulti);
    DECLARE_DECODER(VMDVIDEO, vmdvideo);
    DECLARE_DECODER(VMNC, vmnc);
    DECLARE_DECODER(VQA, vqa);
    DECLARE_DECODER(WNV1, wnv1);
    DECLARE_DECODER(XAN_WC3, xan_wc3);
    DECLARE_DECODER(XL, xl);
    DECLARE_DECODER(MPEG4AAC, mpeg4aac);
    DECLARE_DECODER(ALAC, alac);
    DECLARE_DECODER(ATRAC3, atrac3);
    DECLARE_DECODER(COOK, cook);
    DECLARE_DECODER(DCA, dca);
    DECLARE_DECODER(DSICINAUDIO, dsicinaudio);
    DECLARE_DECODER(IMC, imc);
    DECLARE_DECODER(LIBA52, liba52);
    DECLARE_DECODER(LIBFAAD, libfaad);
    DECLARE_DECODER(MACE3, mace3);
    DECLARE_DECODER(MACE6, mace6);
    DECLARE_DECODER(MP3, mp3);
    DECLARE_DECODER(MP3ADU, mp3adu);
    DECLARE_DECODER(MP3ON4, mp3on4);
    DECLARE_DECODER(MPC7, mpc7);
    DECLARE_DECODER(RA_144, ra_144);
    DECLARE_DECODER(RA_288, ra_288);
    DECLARE_DECODER(SHORTEN, shorten);
    DECLARE_DECODER(SMACKAUD, smackaud);
    DECLARE_DECODER(TRUESPEECH, truespeech);
    DECLARE_DECODER(TTA, tta);
    DECLARE_DECODER(VMDAUDIO, vmdaudio);
    DECLARE_DECODER(WAVPACK, wavpack);
    DECLARE_DECODER(WS_SND1, ws_snd1);
    DECLARE_DECODER(INTERPLAY_DPCM, interplay_dpcm);
    DECLARE_DECODER(SOL_DPCM, sol_dpcm);
    DECLARE_DECODER(XAN_DPCM, xan_dpcm);
    DECLARE_DECODER(ADPCM_THP, adpcm_thp);
    /* DUPE */
    DECLARE_DECODER (ASV1, asv1);
    DECLARE_DECODER (ASV2, asv2);
    DECLARE_DECODER (BMP, bmp);
    DECLARE_DECODER (FLASHSV, flashsv);
    DECLARE_DECODER (GIF, gif);
    DECLARE_DECODER (H261, h261);
	DECLARE_DECODER (H263I, h263i);
    DECLARE_DECODER (JPEGLS, jpegls);
    DECLARE_DECODER (PNG, png);
    DECLARE_DECODER (QTRLE, qtrle);
    DECLARE_DECODER (RAWVIDEO, rawvideo);
    DECLARE_DECODER (ROQ, roq);
    DECLARE_DECODER (SGI, sgi);
    DECLARE_DECODER (SVQ1, svq1);
    DECLARE_DECODER (TARGA, targa);
    DECLARE_DECODER (TIFF, tiff);
    DECLARE_DECODER (ZLIB, zlib);
    DECLARE_DECODER (ZMBV, zmbv);
    DECLARE_DECODER (FLAC, flac);
    DECLARE_DECODER (LIBAMR_NB, libamr_nb);
    DECLARE_DECODER (LIBAMR_WB, libamr_wb);
    DECLARE_DECODER (LIBGSM, libgsm);
    DECLARE_DECODER (LIBGSM_MS, libgsm_ms);
    DECLARE_DECODER (MP2, mp2);
    DECLARE_DECODER (SONIC, sonic);
    DECLARE_DECODER (VORBIS, vorbis);
    DECLARE_DECODER(WMAV1, wmav1);
    DECLARE_DECODER (PCM_ALAW, pcm_alaw);
    DECLARE_DECODER (PCM_MULAW, pcm_mulaw);
    DECLARE_DECODER (PCM_S8, pcm_s8);
    DECLARE_DECODER (PCM_S16BE, pcm_s16be);
    DECLARE_DECODER (PCM_S16LE, pcm_s16le);
    DECLARE_DECODER (PCM_S24BE, pcm_s24be);
    DECLARE_DECODER (PCM_S24DAUD, pcm_s24daud);
    DECLARE_DECODER (PCM_S24LE, pcm_s24le);
    DECLARE_DECODER (PCM_S32BE, pcm_s32be);
    DECLARE_DECODER (PCM_S32LE, pcm_s32le);
    DECLARE_DECODER (PCM_U8, pcm_u8);
    DECLARE_DECODER (PCM_U16BE, pcm_u16be);
    DECLARE_DECODER (PCM_U16LE, pcm_u16le);
    DECLARE_DECODER (PCM_U24BE, pcm_u24be);
    DECLARE_DECODER (PCM_U24LE, pcm_u24le);
    DECLARE_DECODER (PCM_U32BE, pcm_u32be);
    DECLARE_DECODER (PCM_U32LE, pcm_u32le);
    DECLARE_DECODER (ROQ_DPCM, roq_dpcm);
    DECLARE_DECODER (ADPCM_4XM, adpcm_4xm);
    DECLARE_DECODER (ADPCM_ADX, adpcm_adx);
    DECLARE_DECODER (ADPCM_CT, adpcm_ct);
    DECLARE_DECODER (ADPCM_EA, adpcm_ea);
    DECLARE_DECODER (ADPCM_G726, adpcm_g726);
    DECLARE_DECODER (ADPCM_IMA_DK3, adpcm_ima_dk3);
    DECLARE_DECODER (ADPCM_IMA_DK4, adpcm_ima_dk4);
    DECLARE_DECODER (ADPCM_IMA_QT, adpcm_ima_qt);
    DECLARE_DECODER (ADPCM_IMA_SMJPEG, adpcm_ima_smjpeg);
    DECLARE_DECODER (ADPCM_IMA_WAV, adpcm_ima_wav);
    DECLARE_DECODER (ADPCM_IMA_WS, adpcm_ima_ws);
    DECLARE_DECODER (ADPCM_MS, adpcm_ms);
    DECLARE_DECODER (ADPCM_SBPRO_2, adpcm_sbpro_2);
    DECLARE_DECODER (ADPCM_SBPRO_3, adpcm_sbpro_3);
    DECLARE_DECODER (ADPCM_SBPRO_4, adpcm_sbpro_4);
    DECLARE_DECODER (ADPCM_SWF, adpcm_swf);
    DECLARE_DECODER (ADPCM_XA, adpcm_xa);
    DECLARE_DECODER (ADPCM_YAMAHA, adpcm_yamaha);
    DECLARE_DECODER (DVDSUB, dvdsub);
	DECLARE_DECODER (LIBVORBIS, libvorbis);

#define DECLARE_PARSER(a,b); printf("#define ENABLE_"#a"_PARSER 1\n"); 
    DECLARE_PARSER (H263, h263);
    DECLARE_PARSER (H264, h264);
    DECLARE_PARSER (MPEG4VIDEO, mpeg4video);

#undef DECLARE_PARSER
#define DECLARE_PARSER(a,b); printf("#define ENABLE_"#a"_PARSER 0\n"); 
    DECLARE_PARSER (AAC, aac);
    DECLARE_PARSER (AC3, ac3);
    DECLARE_PARSER (CAVSVIDEO, cavsvideo);
    DECLARE_PARSER (DCA, dca);
    DECLARE_PARSER (DVBSUB, dvbsub);
    DECLARE_PARSER (DVDSUB, dvdsub);
    DECLARE_PARSER (H261, h261);
    DECLARE_PARSER (MJPEG, mjpeg);
    DECLARE_PARSER (MPEGAUDIO, mpegaudio);
    DECLARE_PARSER (MPEGVIDEO, mpegvideo);
    DECLARE_PARSER (PNM, pnm);
    DECLARE_PARSER (VC1, vc1);

#define DECLARE_ENCODER(a,b); printf("#define ENABLE_"#a"_ENCODER 1\n"); printf("#define CONFIG_"#a"_ENCODER 1\n");

    DECLARE_ENCODER (MJPEG, mjpeg);
    DECLARE_ENCODER (MSMPEG4V3, msmpeg4v3);
    DECLARE_ENCODER(H263P, h263p);
    DECLARE_ENCODER(AC3, ac3);
    DECLARE_ENCODER (FFV1, ffv1);
    DECLARE_ENCODER (FLV1, flv1);
    DECLARE_ENCODER (FFVHUFF, ffvhuff);
    DECLARE_ENCODER (H263, h263);
    DECLARE_ENCODER (MPEG1VIDEO, mpeg1video);
    DECLARE_ENCODER (MPEG2VIDEO, mpeg2video);
    DECLARE_ENCODER (MPEG4, mpeg4);
    DECLARE_ENCODER (FLV, flv);
    DECLARE_ENCODER (MP2, mp2);
    DECLARE_ENCODER (DVVIDEO, dvvideo);
    DECLARE_ENCODER (HUFFYUV, huffyuv);
    DECLARE_ENCODER (DVBSUB, dvbsub);
    DECLARE_ENCODER (SNOW, snow);

#undef DECLARE_ENCODER
#define DECLARE_ENCODER(a,b); printf("#define ENABLE_"#a"_ENCODER 0\n"); 
    DECLARE_ENCODER(DNXHD, amv);
    DECLARE_ENCODER(PCM_ZORK, amv);
    DECLARE_ENCODER(ADPCM_IMA_AMV, amv);
    DECLARE_ENCODER(LIBX264, libx264);
    DECLARE_ENCODER(LIBXVID, libxvid);
    DECLARE_ENCODER(LJPEG, ljpeg);
    DECLARE_ENCODER(PAM, pam);
    DECLARE_ENCODER(PBM, pbm);
    DECLARE_ENCODER(PGM, pgm);
    DECLARE_ENCODER(PGMYUV, pgmyuv);
    DECLARE_ENCODER(PPM, ppm);
    DECLARE_ENCODER(LIBFAAC, libfaac);
    DECLARE_ENCODER(LIBMP3LAME, libmp3lame);
    DECLARE_ENCODER(LIBTHEORA, libtheora);
    DECLARE_ENCODER(SONIC_LS, sonic_ls);
/* Dupe */
	DECLARE_ENCODER (ASV1, asv1);
    DECLARE_ENCODER (ASV2, asv2);
    DECLARE_ENCODER (BMP, bmp);
    DECLARE_ENCODER (FLASHSV, flashsv);
    DECLARE_ENCODER (GIF, gif);
    DECLARE_ENCODER (H261, h261);
    DECLARE_ENCODER (JPEGLS, jpegls);
    DECLARE_ENCODER (MSMPEG4V1, msmpeg4v1);
    DECLARE_ENCODER (MSMPEG4V2, msmpeg4v2);
    DECLARE_ENCODER (PNG, png);
    DECLARE_ENCODER (QTRLE, qtrle);
    DECLARE_ENCODER (RAWVIDEO, rawvideo);
    DECLARE_ENCODER (ROQ, roq);
    DECLARE_ENCODER (RV10, rv10);
    DECLARE_ENCODER (RV20, rv20);
    DECLARE_ENCODER (SGI, sgi);
    DECLARE_ENCODER (SVQ1, svq1);
    DECLARE_ENCODER (TARGA, targa);
    DECLARE_ENCODER (TIFF, tiff);
    DECLARE_ENCODER (WMV1, wmv1);
    DECLARE_ENCODER (WMV2, wmv2);
    DECLARE_ENCODER (ZLIB, zlib);
    DECLARE_ENCODER (ZMBV, zmbv);
    DECLARE_ENCODER (FLAC, flac);
    DECLARE_ENCODER (LIBAMR_NB, libamr_nb);
    DECLARE_ENCODER (LIBAMR_WB, libamr_wb);
    DECLARE_ENCODER (LIBGSM, libgsm);
    DECLARE_ENCODER (LIBGSM_MS, libgsm_ms);
    DECLARE_ENCODER (SONIC, sonic);
    DECLARE_ENCODER (VORBIS, vorbis);
    DECLARE_ENCODER(WMAV1, wmav1);
    DECLARE_ENCODER(WMAV2, wmav2);
    DECLARE_ENCODER (PCM_ALAW, pcm_alaw);
    DECLARE_ENCODER (PCM_MULAW, pcm_mulaw);
    DECLARE_ENCODER (PCM_S8, pcm_s8);
    DECLARE_ENCODER (PCM_S16BE, pcm_s16be);
    DECLARE_ENCODER (PCM_S16LE, pcm_s16le);
    DECLARE_ENCODER (PCM_S24BE, pcm_s24be);
    DECLARE_ENCODER (PCM_S24DAUD, pcm_s24daud);
    DECLARE_ENCODER (PCM_S24LE, pcm_s24le);
    DECLARE_ENCODER (PCM_S32BE, pcm_s32be);
    DECLARE_ENCODER (PCM_S32LE, pcm_s32le);
    DECLARE_ENCODER (PCM_U8, pcm_u8);
    DECLARE_ENCODER (PCM_U16BE, pcm_u16be);
    DECLARE_ENCODER (PCM_U16LE, pcm_u16le);
    DECLARE_ENCODER (PCM_U24BE, pcm_u24be);
    DECLARE_ENCODER (PCM_U24LE, pcm_u24le);
    DECLARE_ENCODER (PCM_U32BE, pcm_u32be);
    DECLARE_ENCODER (PCM_U32LE, pcm_u32le);
    DECLARE_ENCODER (ROQ_DPCM, roq_dpcm);
    DECLARE_ENCODER (ADPCM_4XM, adpcm_4xm);
    DECLARE_ENCODER (ADPCM_ADX, adpcm_adx);
    DECLARE_ENCODER (ADPCM_CT, adpcm_ct);
    DECLARE_ENCODER (ADPCM_EA, adpcm_ea);
    DECLARE_ENCODER (ADPCM_G726, adpcm_g726);
    DECLARE_ENCODER (ADPCM_IMA_DK3, adpcm_ima_dk3);
    DECLARE_ENCODER (ADPCM_IMA_DK4, adpcm_ima_dk4);
    DECLARE_ENCODER (ADPCM_IMA_QT, adpcm_ima_qt);
    DECLARE_ENCODER (ADPCM_IMA_SMJPEG, adpcm_ima_smjpeg);
    DECLARE_ENCODER (ADPCM_IMA_WAV, adpcm_ima_wav);
    DECLARE_ENCODER (ADPCM_IMA_WS, adpcm_ima_ws);
    DECLARE_ENCODER (ADPCM_MS, adpcm_ms);
    DECLARE_ENCODER (ADPCM_SBPRO_2, adpcm_sbpro_2);
    DECLARE_ENCODER (ADPCM_SBPRO_3, adpcm_sbpro_3);
    DECLARE_ENCODER (ADPCM_SBPRO_4, adpcm_sbpro_4);
    DECLARE_ENCODER (ADPCM_SWF, adpcm_swf);
    DECLARE_ENCODER (ADPCM_XA, adpcm_xa);
    DECLARE_ENCODER (ADPCM_YAMAHA, adpcm_yamaha);
    DECLARE_ENCODER (DVDSUB, dvdsub);
	DECLARE_ENCODER (LIBVORBIS, libvorbis);

#define DECLARE_BSF(a,b); printf("#define ENABLE_"#a"_BSF 0\n");

	DECLARE_BSF(MP3_HEADER_COMPRESS, mp3_header_compress);
	DECLARE_BSF(IMX_DUMP_HEADER, imx_dump_header);
	DECLARE_BSF(DUMP_EXTRADATA, dump_extradata);
	DECLARE_BSF(REMOVE_EXTRADATA, remove_extradata);
	DECLARE_BSF(NOISE, noise);
	DECLARE_BSF(MP3_HEADER_DECOMPRESS, mp3_header_decompress);
	DECLARE_BSF(MJPEGA_DUMP_HEADER, mjpega_dump_header);
	DECLARE_BSF(H264_MP4TOANNEXB, imx_dump_header);
	DECLARE_BSF(MOV2TEXTSUB, imx_dump_header);
	DECLARE_BSF(TEXT2MOVSUB, imx_dump_header);

#define DECLARE_MUXER(a,b); printf("#define CONFIG_"#a"_MUXER 1\n");

	printf("#define CONFIG_MUXERS 1\n");
	DECLARE_MUXER(MOV, mov)
	DECLARE_MUXER(MP4, mp4)
	DECLARE_MUXER(PSP, psp)
	DECLARE_MUXER(TG2, tg2)
	DECLARE_MUXER(TGP, tgp)

	printf("#define CONFIG_ENCODERS 1\n");
	printf("#define CONFIG_DVVIDEO_ENCODER 1\n");
	printf("#define CONFIG_SNOW_ENCODER 1\n");

#define DECLARE_CONFIG_DECODER(a,b); printf("#define CONFIG_"#a"_DECODER 1\n");

	printf("#define CONFIG_DECODERS 1\n");
	DECLARE_CONFIG_DECODER(DVVIDEO, dvvideo);
	DECLARE_CONFIG_DECODER(H263, h263);
	DECLARE_CONFIG_DECODER(MPEG4, mpeg4);
	DECLARE_CONFIG_DECODER(SNOW, snow);
	DECLARE_CONFIG_DECODER(VC1, vc1);
	DECLARE_CONFIG_DECODER(WMV2, wmv2);
	DECLARE_CONFIG_DECODER(WMV3, wmv3);

	printf("#define CONFIG_MPEGAUDIO_HP 1\n");
	printf("#define CONFIG_ZLIB 1\n");
	printf("#define CONFIG_GPL 1\n");

#define ENABLE(a,b); printf("#define ENABLE_"#a" 0\n");

	ENABLE(ARMV4L, armv4l);
	ENABLE(MLIB, mlib);
	ENABLE(SPARC, sparc);
	ENABLE(ALPHA, alpha);
	ENABLE(MMI, mmi);
	ENABLE(SH4, sh4);
	ENABLE(BFIN, bfin);
	ENABLE(SMALL, small);
#define DECLARE_ENABLE_PARSER(a,b); printf("#define ENABLE_"#a"_PARSER 0\n");
	DECLARE_ENABLE_PARSER(MLP, wmv3);
        printf("//****************** SYSTEM *******************\n");
	printf("#ifdef __APPLE__\n");
	printf("#	define CONFIG_DARWIN 1\n");
	printf("#endif\n");

	printf("#if defined(ADM_CPU_X86_32)\n");
	printf("#	define ARCH_X86 1\n");
	printf("#	define ARCH_X86_32 1\n");
	printf("#elif defined(ADM_CPU_X86_64)\n");
	printf("#	define ARCH_X86 1\n");
	printf("#	define ARCH_X86_64 1\n");
	printf("#elif defined(ADM_CPU_PPC)\n");
	printf("#	define ARCH_POWERPC 1\n");
	printf("#ifdef ADM_CPU_ALTIVEC\n");
	printf("#	define HAVE_ALTIVEC 1\n");
	printf("#ifndef __APPLE__\n");
	printf("#	define HAVE_ALTIVEC_H 1\n");
	printf("#endif	// __APPLE__\n");
	printf("#endif	// ADM_CPU_ALTIVEC\n");
	printf("#ifdef ADM_CPU_DCBZL\n");
	printf("#	define HAVE_DCBZL 1\n");
	printf("#endif	// ADM_CPU_DCBZL\n");
	printf("#endif	// ADM_CPU_X86_32\n");
printf("#ifndef ADM_MINIMAL_INCLUDE\n");

	printf("#if defined(ADM_CPU_X86_32) && defined(ADM_CPU_MMX2)\n");
	printf("#	define HAVE_MMX2 1\n");
	printf("#endif\n");

	printf("#ifdef ADM_CPU_SSSE3\n");
	printf("#	define HAVE_SSSE3 1\n");
	printf("#endif\n");
printf("#endif //ADM_MINIMAL_INCLUDE\n");

	printf("#ifdef ARCH_POWERPC\n");
	printf("#	define ENABLE_POWERPC 1\n");
	printf("#else\n");
	printf("#	define ENABLE_POWERPC 0\n");
	printf("#endif\n");

	printf("#ifdef ARCH_X86\n");
	printf("#	define ENABLE_BSWAP 1\n");
printf("#ifndef ADM_MINIMAL_INCLUDE\n");
	printf("#	define HAVE_MMX 1\n");
	printf("#	define ENABLE_MMX 1\n");
printf("#endif //ADM_MINIMAL_INCLUDE\n");
	printf("#	define HAVE_FAST_UNALIGNED 1\n");
	printf("#	define HAVE_EBP_AVAILABLE 1\n");
	printf("#	define HAVE_EBX_AVAILABLE 1\n");
	printf("#else\n");
	printf("#	define ENABLE_MMX 0\n");
	printf("#endif\n");

	printf("#ifdef ARCH_X86_64\n");
	printf("#	define HAVE_FAST_64BIT 1\n");
	printf("#endif\n");

	printf("#ifdef ADM_BIG_ENDIAN\n");
	printf("#	define WORDS_BIGENDIAN 1\n");
	printf("#endif\n");

        printf("#define ENABLE_YASM      0\n");
        printf("#define ENABLE_ARM      0\n");
        printf("#define ENABLE_PPC      0\n");
	printf("#define ENABLE_THREADS 1\n");
	printf("#define ENABLE_ENCODERS 1\n");
	printf("#define CONFIG_MUXERS 1\n");
	printf("#define CONFIG_DEMUXERS 1\n");
	printf("#define ENABLE_VIS 0\n");
	printf("#define ENABLE_GRAY 0\n");
	printf("#define HAVE_LRINTF 1\n");
	printf("#define HAVE_LLRINT 1\n");
	printf("#define HAVE_LRINT 1\n");
	printf("#define HAVE_ROUND 1\n");
	printf("#define HAVE_ROUNDF 1\n");
	printf("#define HAVE_THREADS 1\n");
	printf("#define RUNTIME_CPUDETECT 1\n");
	printf("#define EXTERN_PREFIX\n");
	printf("#define restrict __restrict__\n");
}
