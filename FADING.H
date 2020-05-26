/* 
adapted  and written BY RADsoft some of this was taken from SDL examples 


*/

#include <stdio.h>
#include "sdl.h"

/* fades the surface in or out in the time you want */
void fade (SDL_Surface* p_surf_screen, SDL_Surface* p_surf_img, Uint32 ui_seconds, int i_fade_out) ;

/* fades the screen over the first one  EG cross-fading */
void crossFade (SDL_Surface* p_surf_screen, SDL_Surface* p_surf_img1, SDL_Surface* p_surf_img2, Uint32 ui_seconds) ;
