
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
http://www.imrtech.mirrorz.com/ main site and can be translated use the translater tool
on the menu.  also were all downloads are note refresh a lot due to your isp not updating
your dns cache the site will show as not there just keep hiting refresh 5 or 6 times

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

#include <stdio.h>
#include <SDL/SDL.h>

/* Fades the given surface in or out to the given screen within the given time */
void fade (SDL_Surface* Draw_sf, SDL_Surface* fade_sf, Uint32 ui_seconds, int i_fade_out) ;

/* Cross-Fades the given surfaces onto the given screen within the given time */
void crossFade (SDL_Surface* Draw_sf, SDL_Surface* fade_sf1, SDL_Surface* fade_sf2, Uint32 ui_seconds) ;
