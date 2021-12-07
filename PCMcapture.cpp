   
    #include "alsa/asoundlib.h"
    #include <iostream>
    #include <fstream>
    #include <string.h>
    #include <signal.h>
    #include <unistd.h>
    /* Capture stream */
    snd_pcm_stream_t stream_capture = SND_PCM_STREAM_CAPTURE;
    
    /* Read num_frames frames from the PCM device  */
    /* pointed to by pcm_handle to buffer capdata. */
    /* Returns the number of frames actually read. */
    snd_pcm_readi(pcm_capture_handle, capdata, num_frames);
    
    /* Read num_frames frames from the PCM device  */         
    /* pointed to by pcm_handle to buffer capdata. */      
    /* Returns the number of frames actually read. */   
    snd_pcm_readn(pcm_capture_handle, capdata, num_frames);
    
    int pcmreturn;

    while ((pcmreturn = snd_pcm_readi(pcm_capture_handle, capdata, periodsize>>2)) < 0) {
      snd_pcm_prepare(pcm_capture_handle);
      fprintf(stderr, "<<<<<<<<<<<<<<< Buffer Overrun >>>>>>>>>>>>>>>\n");
    }