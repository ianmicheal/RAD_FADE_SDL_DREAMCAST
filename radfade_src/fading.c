
  
//////////////////////////////////////////////////////////////////////////////////////////////

Thanks ("no one can survive in a vacuum NOt EVEN ME")
------

* SDL by Sam Latinga and the SDL opensource team.
* Black aura  ' kos raw image loading routine
* Warmtoe     ' maim source and support
* Blue crab   ' SDL help and support
* Bero        ' Porter of SDL to dreamcast
* Dan potter  ' kos free tools an /os for dreamcast


///////////////////////////////////////////////////////////////////////////////////////////////


AND ereckA There shes is hun!


/*
///////////////////////////////////////////////////////////////////////////////////////////////
Legal LIC
-----

Free tools (gcc and KOS) were used for development (i.e. absolutely no devkits/libraries from Sega or Microsoft).
1) You may freely distribute this emulator as long as it is not on the same
   medium as the necessary ROM files.
2) You must never charge money for this Midiplayer.
3) You must not obtain or use copyright music for music you do not own.  If you decide
   to anyway, it is entirely at your own risk.
4) You must not distribute altered versions of this Midiplayer or it's
   documentation and call it your own.
5) This Midiplayer is distributed with NO WARRANTY as to it's functionality
   or fitness for any purpose.  Although the software is believed to be
   free of major problems, the authors cannot be held liable for any damage
   or problems related to the use of this emulator.
6) We will not give you copyright music, and you may not ask for them on our message
   boards.  Violators will be banned.
/////////////////////////////////////////////////////////////////////////////////////////////
THIS PROGRAM IS NOT ENDORSED BY, LICENSED BY, WARRANTED BY, OR IN ANY OTHER
WAY CONNECTED WITH SEGA ENTERPRISES.

Sega and Dreamcast are registered trademarks of Sega Enterprises, Ltd.

All other trademarks are the property of their respective owners.
Libs and dev kit  used 

SDL,SDL_TTF,FREETYPE,SDL_IMAGE,KOS all source is provide this was written by me with help tip.
*/


#include "drawfade.h"

void fade (SDL_Surface* Draw_sf, SDL_Surface* fade_sf, Uint32 ui_seconds, int b_fade_out) {
  SDL_Surface* fad_black = NULL ;
  SDL_Surface* Draw_sf_copy = NULL ;
  Uint32 ui_old_time, ui_curr_time, ui_time_ms ;
  float f_alpha ;
  Uint32 ui_flags = SDL_SRCALPHA ;
  if ((Draw_sf->flags & SDL_HWSURFACE)) {
    ui_flags |= SDL_HWSURFACE ;
  }
  else {
    ui_flags |= SDL_SWSURFACE ;
  }
  if ((fad_black = SDL_CreateRGBSurface (ui_flags,
    Draw_sf->w, Draw_sf->h, 
    Draw_sf->format->BitsPerPixel, 
    Draw_sf->format->Rmask, Draw_sf->format->Gmask, Draw_sf->format->Bmask,
    Draw_sf->format->Amask)) == NULL) {
      return ;
  }

  SDL_FillRect (fad_black, NULL, SDL_MapRGB (Draw_sf->format, 0, 0, 0)) ;
  if (Draw_sf == fade_sf) {
    if ((Draw_sf_copy = SDL_CreateRGBSurface (ui_flags,
    Draw_sf->w, Draw_sf->h, 
    Draw_sf->format->BitsPerPixel, 
    Draw_sf->format->Rmask, Draw_sf->format->Gmask, Draw_sf->format->Bmask,
    Draw_sf->format->Amask)) == NULL) {
      SDL_FreeSurface (fad_black) ;
      return ;
    }
    SDL_BlitSurface (Draw_sf, NULL, Draw_sf_copy, NULL) ;
    fade_sf = Draw_sf_copy ;
  }
  
  ui_old_time = SDL_GetTicks () ;
  ui_curr_time = ui_old_time ;
  ui_time_ms = ui_seconds * 450 ;
  if (b_fade_out) {
    f_alpha = 0.0 ;
    while (f_alpha < 255.0) {
      SDL_BlitSurface (fade_sf, NULL, Draw_sf, NULL) ;
      SDL_SetAlpha (fad_black, SDL_SRCALPHA, (Uint8) f_alpha) ;
      SDL_BlitSurface (fad_black, NULL, Draw_sf, NULL) ;
      ui_old_time = ui_curr_time ;
      ui_curr_time = SDL_GetTicks () ;
      SDL_Flip (Draw_sf) ;
      f_alpha += 255 * ((float) (ui_curr_time - ui_old_time) / ui_time_ms) ;
    }
  }
  else {
    f_alpha = 255.0 ;
    while (f_alpha > 0.0) {
      SDL_BlitSurface (fade_sf, NULL, Draw_sf, NULL) ;
      SDL_SetAlpha (fad_black, SDL_SRCALPHA, (Uint8) f_alpha) ;
      SDL_BlitSurface (fad_black, NULL, Draw_sf, NULL) ;
      ui_old_time = ui_curr_time ;
      ui_curr_time = SDL_GetTicks () ;
      SDL_Flip (Draw_sf) ;
      f_alpha -= 255 * ((float) (ui_curr_time - ui_old_time) / ui_time_ms) ;
    }
  }
  SDL_FreeSurface (fad_black) ;
  if (Draw_sf_copy != NULL) {
    SDL_FreeSurface (Draw_sf_copy) ;
  }
}
void crossFade (SDL_Surface* Draw_sf, SDL_Surface* fade_sf1, SDL_Surface* fade_sf2, Uint32 ui_seconds) {
  Uint32 ui_old_time, ui_curr_time, ui_time_ms ;
  float f_alpha ;  
  ui_old_time = SDL_GetTicks () ;
  ui_curr_time = ui_old_time ;
  ui_time_ms = ui_seconds * 450 ;
  f_alpha = 0.0 ;
  while (f_alpha < 255.0) {
    SDL_BlitSurface (fade_sf1, NULL, Draw_sf, NULL) ;
    SDL_SetAlpha (fade_sf2, SDL_SRCALPHA, (Uint8) f_alpha) ;
    SDL_BlitSurface (fade_sf2, NULL, Draw_sf, NULL) ;
    ui_old_time = ui_curr_time ;
    ui_curr_time = SDL_GetTicks () ;
    SDL_Flip (Draw_sf) ;
    f_alpha += 255 * ((float) (ui_curr_time - ui_old_time) / ui_time_ms) ;
  }
}
