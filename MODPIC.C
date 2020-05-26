
/*exmaple from RADsoft music wav's png's cross-fading alpha blending ect*/





 #include <kos.h>
#include <string.h>
#include <stdio.h> 
#include <stdlib.h> 
#include "SDL_mixer.h" 
#include "SDL_image.h" 
#include "SDL_timer.h" 
#include "SDL.h"  
 



  #include <string.h>
#include <stdio.h> 
#include <stdlib.h> 


#include "SDL.h"  
 
#include <SDL/SDL_mixer.h> 
#include "SDL_mixer.h"

#include "fading.h"

/* define BPP settings little hack */

#define BPP                    16






 extern uint8 romdisk[];

 KOS_INIT_FLAGS(INIT_DEFAULT);
 KOS_INIT_ROMDISK(romdisk);


/* Now, our sample main-function: */
int main(int argc, char *argv[]) {



 // initialize the mouse
    SDL_ShowCursor(0);


/* Now we set up the audio  */
  int audio_rate = 22050;
  Uint16 audio_format = AUDIO_S8; 
 int audio_channels = 1;
  int audio_buffers = 1024;

  // declare sound
   Mix_Chunk *sound;




 /* Now we load the songs */
    Mix_Music * song1; 
  //Mix_Music * song2;
  
 /* Surfaces  EG loading our pictures */
  SDL_Surface* p_surf_screen = NULL ;
  SDL_Surface* p_surf_img1 = NULL ;
  SDL_Surface* p_surf_img2 = NULL ;
  SDL_Surface* p_surf_img3 = NULL ;
  SDL_Surface* p_surf_img4 = NULL ;
  SDL_Surface* p_surf_img5 = NULL ;
  SDL_Surface* p_surf_img6 = NULL ;
  SDL_Surface* p_surf_img7 = NULL ;
  SDL_Surface* p_surf_img8 = NULL ;
  SDL_Surface* p_surf_img9 = NULL ;
  SDL_Surface* p_surf_img10 = NULL ;
  SDL_Surface* p_surf_img11 = NULL ;
  SDL_Surface* p_surf_img12 = NULL ;
  // SDL_Surface* p_surf_img13 = NULL ;
  // SDL_Surface* p_surf_img14 = NULL ;
 // add more going up in numbers and follow that going down ok
 


  /* Init SDL: */ 
  SDL_Init(SDL_INIT_AUDIO);
 
 
 
  
  /* Open mixer: */ 
  
   (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers));

  /* Load a song: */ 
  
  song1 = Mix_LoadMUS("/cd/intro/dark.xm"); 
   
 /* Begin playing the song: */ 

  Mix_PlayMusic(song1, 0); 


  SDL_Delay(1000); //7000
  
  
   SDL_Init(SDL_INIT_VIDEO);
   /* Set our video mode to 640x480 16bpp */ 
     /* Setup uup the display */
  if (SDL_VideoModeOK (640, 480, 16, SDL_SWSURFACE|SDL_FULLSCREEN) == BPP) {
   
 /* Hardware */
    if ((p_surf_screen = SDL_SetVideoMode (640, 480, 16, SDL_SWSURFACE|SDL_FULLSCREEN)) == NULL) {
      SDL_Quit () ;

}
  
 
  }
   
  /* Load the images */ // intro and start screens 
  p_surf_img1 = SDL_DisplayFormat (IMG_Load ("/cd/intro/neo.png")) ;
  p_surf_img2 = SDL_DisplayFormat (IMG_Load ("/cd/intro/neorad.png")) ;
  p_surf_img3= SDL_DisplayFormat (IMG_Load ("/cd/intro/rad.png")) ;
  p_surf_img4= SDL_DisplayFormat (IMG_Load ("/cd/intro/rad2.png")) ;
  p_surf_img5= SDL_DisplayFormat (IMG_Load ("/cd/intro/5.png")) ;
  p_surf_img6= SDL_DisplayFormat (IMG_Load ("/cd/intro/4.png")) ;
  p_surf_img7= SDL_DisplayFormat (IMG_Load ("/cd/intro/3.png")) ;
  p_surf_img8= SDL_DisplayFormat (IMG_Load ("/cd/intro/2.png")) ;
  p_surf_img9= SDL_DisplayFormat (IMG_Load ("/cd/intro/1.png")) ;
  p_surf_img10= SDL_DisplayFormat (IMG_Load  ("/cd/intro/P.png")) ;
  p_surf_img11= SDL_DisplayFormat (IMG_Load  ("/cd/intro/P2.png")) ;
  p_surf_img12= SDL_DisplayFormat (IMG_Load  ("/cd/intro/old1.png")) ;
 // p_surf_img13= SDL_DisplayFormat (IMG_Load  ("/cd/intro/old2.png")) ;
//  p_surf_img14= SDL_DisplayFormat (IMG_Load  ("/cd/intro/blank.png")) ;
  if (p_surf_img1 == NULL || p_surf_img2 == NULL) {
    SDL_Quit () ;
    fprintf (stderr, "Error: could not load the image.\n") ;
    return 0 ;
  }
 
    /* load */  // rad image
  SDL_Delay (2000) ;
  fade (p_surf_screen,p_surf_img3, 2, 0) ;
  
     /* load */  //rad2 image
  SDL_Delay (3000) ;
  fade (p_surf_screen,p_surf_img4, 2, 0) ;
   /* Cross-fade img2 over img1 */
  crossFade (p_surf_screen, p_surf_img4, p_surf_img4, 2) ;
   
     
         
  SDL_FreeSurface (p_surf_img3) ;
  SDL_FreeSurface (p_surf_img4) ;
    
    
  
  fade (p_surf_screen,p_surf_img5, 2, 0) ;
    
   /* Cross-fade img over img */
  crossFade (p_surf_screen, p_surf_img5, p_surf_img5, 2) ;  
    
   
  
  fade (p_surf_screen,p_surf_img6, 2, 0) ;
    
   /* Cross-fade img over img */
  crossFade (p_surf_screen, p_surf_img6, p_surf_img6, 2) ;  
    
    
  
  fade (p_surf_screen,p_surf_img7, 2, 0) ;
    
   /* Cross-fade img2 over img1 */
  crossFade (p_surf_screen, p_surf_img7, p_surf_img7, 2) ;  
  
  
  fade (p_surf_screen,p_surf_img8, 2, 0) ;
    
   /* Cross-fade img over img */
  crossFade (p_surf_screen, p_surf_img8, p_surf_img8, 2) ;  
  
  fade (p_surf_screen,p_surf_img9, 2, 0) ;
    
   /* Cross-fade img2 over img1 */
  crossFade (p_surf_screen, p_surf_img9, p_surf_img9, 2) ;  
   
     
  fade (p_surf_screen,p_surf_img10, 2, 0) ;
    
   /* Cross-fade img over img */
  crossFade (p_surf_screen, p_surf_img10, p_surf_img10, 2) ;  
    
    
    
   /* Cross-fade img over img */
  crossFade (p_surf_screen, p_surf_img11, p_surf_img10, 2) ;  
    
      




   /* Pause */
  SDL_Delay (2000) ;
  /* Fade img 1 out */
  fade (p_surf_screen, p_surf_img1, 2, 0) ;
  
  
  
      /* Quit: */   //this closes the first song  
    Mix_CloseAudio();
     
           /* Open mixer: */  //THIS is here to reopen the mixer when it was closed 
(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers));
  
    /* Pause */
  SDL_Delay (2000) ; 
  
    
    

    
    // load wave
    sound=Mix_LoadWAV("/cd/intro/radsound.wav");

    // set volume (1..255) (optional, default is 255)
    Mix_VolumeChunk(sound,200);

 /* play song */  //starts playing the 
//  Mix_PlayMusic(song2, 0); 
   

  
  Mix_PlayChannel(-1,sound,0);
  

   
 

  
  /* Cross-fade img over img */
  crossFade (p_surf_screen, p_surf_img1, p_surf_img2, 2) ;
 
 
   /* Fade img  out */
  fade (p_surf_screen, p_surf_img2, 2, 0) ;
  
  
   
  
  /* End-delay of a second */
  SDL_Delay (5000) ;
  pvr_mem_reset();
  SDL_FreeSurface (p_surf_img1) ;
  pvr_mem_reset();
  SDL_FreeSurface (p_surf_img2) ;
  pvr_mem_reset();

  pvr_mem_reset();
  SDL_FreeSurface (p_surf_img5) ;
  pvr_mem_reset();

  pvr_mem_reset();
  SDL_FreeSurface (p_surf_img7) ;
  pvr_mem_reset();
  SDL_FreeSurface (p_surf_img8) ;
  pvr_mem_reset();
  SDL_FreeSurface (p_surf_img9) ;
  pvr_mem_reset();
  SDL_FreeSurface (p_surf_img10) ;
  pvr_mem_reset();
  SDL_FreeSurface (p_surf_img11) ;
  pvr_mem_reset();
  SDL_FreeSurface (p_surf_screen) ;
  pvr_mem_reset();
  

   /* Quit: */   //this closes the first song  
    //   Mix_CloseAudio();
  
 

 
    // void SDL_FreeWAV(); 
    
    /*c64 vebose flash bar loader */
    
    vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
 
     vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0);
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192); 
  vid_clear(0, 0, 255); 
 vid_clear(255, 0, 255); 
 vid_clear(192, 192, 192);  
 vid_clear(0, 0, 255);  
 vid_clear(0, 192, 0);

 vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
   
  
    

/* cut and paste this to add new scene's*/
      /* load */  //demo image count down 
 
   //adds delay 
 // SDL_Delay (3000) ;
  
  fade (p_surf_screen,p_surf_img12, 2, 0) ;
    
   /* Cross-fade img over img */
  crossFade (p_surf_screen, p_surf_img6, p_surf_img12, 2) ;  
    
      /*end of cut and paste add scene code*/


     SDL_Delay (3000) ;
  
  
    SDL_FreeSurface (p_surf_img6) ;
  
  vid_clear(0, 0, 255); 
 vid_clear(192, 0, 0); 
 vid_clear(0, 192, 0); 
    

   
     SDL_Delay (3000) ;

  {
	
	
	return 0;
}

SDL_Delay (3000) ;
    
    // distory SDL //
   // SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
   
    
    }

