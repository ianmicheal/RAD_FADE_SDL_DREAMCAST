
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
#include <string.h>
#include <stdlib.h> 
#include <SDL/SDL.h>   
#include <SDL/SDL_image.h>   
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h>



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <kos.h>

#include "drawfade.h"
extern uint8 romdisk[];
KOS_INIT_ROMDISK(romdisk);
int main(int argc, char *argv[])
{

/* Surfaces */
SDL_Surface* Draw_sf = NULL ;
SDL_Surface* dis1 = NULL ;
SDL_Surface* dis2 = NULL ;
SDL_Surface* fade_sf1 = NULL ;
SDL_Surface* fade_sf2 = NULL ;
SDL_Surface* fade_sf3 = NULL ;
/* Initialize SDL */
if (SDL_Init (SDL_INIT_VIDEO) < 0) {
}
Draw_sf = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE|SDL_FULLSCREEN);
SDL_ShowCursor(SDL_DISABLE);
/* Load the images */
dis1 = SDL_DisplayFormat (IMG_Load ("/rd/dis1.jpg")) ;
dis2 = SDL_DisplayFormat (IMG_Load ("/rd/dis2.jpg")) ;
fade_sf1 = SDL_DisplayFormat (IMG_Load ("/rd/logo1.jpg")) ;
fade_sf2 = SDL_DisplayFormat (IMG_Load ("/rd/logo2.jpg")) ;
fade_sf3 = SDL_DisplayFormat (IMG_Load ("/rd/logo3.jpg")) ;
if (fade_sf1 == NULL) {
return 0 ;
}

/* Fade img 1 in */
fade (Draw_sf, dis1, 2, 0) ;
/* Pause */
SDL_Delay (3000);
/* Fade img 2 out */
fade (Draw_sf, dis2, 2, 1);
/* Pause */
/* Fade img 3 out */
fade (Draw_sf, fade_sf3, 2, 1);
/* Pause */
SDL_Delay (1000);
/* Fade img 5 in */
fade (Draw_sf, fade_sf1, 2, 0) ;
/* Pause */
SDL_Delay (1000);
/* Fade img 6 out */
fade (Draw_sf, fade_sf2, 2, 1);
/* Pause */
/* Fade img 7 out */
fade (Draw_sf, fade_sf3, 2, 1);
/* Pause */
SDL_Delay (500);
SDL_FreeSurface (dis1) ;
SDL_FreeSurface (dis2) ;
SDL_FreeSurface (fade_sf1) ;
SDL_FreeSurface (fade_sf2) ;
SDL_FreeSurface (fade_sf3) ;
SDL_FreeSurface (Draw_sf) ;
/* end fade routine */	
static SDL_Joystick * cont1;
TTF_Font * font;
SDL_Surface * screen;
SDL_Surface * bk;
SDL_Surface * up;
SDL_Surface * down;
SDL_Surface * play;
SDL_Surface * stop;
static int SDLinitted = 0;
extern uint8 ui_frameskip;
static time_t timesince;
/*intro */
SDL_Surface * string;
SDL_Surface * start;
SDL_Event event;
SDL_Color color = {0xFF, 0xFF, 0xFF};
SDL_Rect rect;
int ddone = 0;
int ch = 0; 
if(SDLinitted == 0)	{	 
if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_JOYSTICK) < 0)	{
return -1;
}
SDL_ShowCursor(SDL_DISABLE);
screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE|SDL_FULLSCREEN);
SDL_JoystickEventState(SDL_ENABLE);
cont1 = SDL_JoystickOpen(0);
if(TTF_Init())	{
return -1;
}
font = TTF_OpenFont("/rd/font.ttf", 16);    
bk = IMG_Load("/rd/bk.jpg");   
up = IMG_Load("/rd/up.jpg");
down = IMG_Load("/rd/down.jpg");
play = IMG_Load("/rd/play.jpg");
stop = IMG_Load("/rd/stop.jpg");
SDL_BlitSurface( bk, NULL, screen, NULL); 
SDL_Flip(screen);		
/* IMRsound system  sound set up    */
int audio_rate = 22050;
Uint16 audio_format = AUDIO_S16; 
int audio_channels = 2;
int audio_buffers = 4094;
int looping = 0;
int interactive = 0;
int i;
static int next_track = 0;
static int audio_open = 0; 
/* Now we load the songs */
Mix_Music * song1= NULL;  
/* Open mixer: */ 
(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers));
/* This is taken from libSGE -- http://freshmeat.net/projects/sge/ */
// void sge_FilledRectAlpha(SDL_Surface *surface, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color, Uint8 alpha)
void RectAlpha(SDL_Surface * surface, SDL_Rect * rect, Uint32 color, Uint8 alpha)
{
Sint16 x1 = rect->x;
Sint16 y1 = rect->y;
Sint16 x2 = rect->x + rect->w;
Sint16 y2 = rect->y + rect->h;	
/* Fix coords */
Sint16 tmp;
if(x1>x2){
tmp=x1; x1=x2; x2=tmp;
}
if(y1>y2){
tmp=y1; y1=y2; y2=tmp;
}
Uint32 Rmask = surface->format->Rmask, Gmask = surface->format->Gmask, Bmask = surface->format->Bmask, Amask = surface->format->Amask;
Uint32 R,G,B,A=0;
Sint16 x,y;	
if (SDL_MUSTLOCK(surface))
if (SDL_LockSurface(surface) < 0)
return;	
switch (surface->format->BytesPerPixel) {
case 1: { /* Assuming 8-bpp */
Uint8 *row, *pixel;
Uint8 dR, dG, dB;			
Uint8 sR = surface->format->palette->colors[color].r;
Uint8 sG = surface->format->palette->colors[color].g;
Uint8 sB = surface->format->palette->colors[color].b;			
for(y = y1; y<=y2; y++){
row = (Uint8 *)surface->pixels + y*surface->pitch;
for(x = x1; x <= x2; x++){
pixel = row + x;					
dR = surface->format->palette->colors[*pixel].r;
dG = surface->format->palette->colors[*pixel].g;
dB = surface->format->palette->colors[*pixel].b;					
dR = dR + ((sR-dR)*alpha >> 8);
dG = dG + ((sG-dG)*alpha >> 8);
dB = dB + ((sB-dB)*alpha >> 8);			
*pixel = SDL_MapRGB(surface->format, dR, dG, dB);
}
}
}
break;
case 2: { /* Probably 15-bpp or 16-bpp */
Uint16 *row, *pixel;
Uint32 dR=(color & Rmask),dG=(color & Gmask),dB=(color & Bmask),dA=(color & Amask);			
for(y = y1; y<=y2; y++){
row = (Uint16 *)surface->pixels + y*surface->pitch/2;
for(x = x1; x <= x2; x++){
pixel = row + x;
R = ((*pixel & Rmask) + (( dR - (*pixel & Rmask) ) * alpha >> 8)) & Rmask;
G = ((*pixel & Gmask) + (( dG - (*pixel & Gmask) ) * alpha >> 8)) & Gmask;
B = ((*pixel & Bmask) + (( dB - (*pixel & Bmask) ) * alpha >> 8)) & Bmask;
if( Amask )
A = ((*pixel & Amask) + (( dA - (*pixel & Amask) ) * alpha >> 8)) & Amask;
*pixel= R | G | B | A;
}
}
}
break;
case 3: { /* Slow 24-bpp mode, usually not used */
Uint8 *row,*pix;
Uint8 dR, dG, dB, dA;
Uint8 rshift8=surface->format->Rshift/8; 
Uint8 gshift8=surface->format->Gshift/8; 
Uint8 bshift8=surface->format->Bshift/8;
Uint8 ashift8=surface->format->Ashift/8;			
Uint8 sR = (color>>surface->format->Rshift)&0xff;
Uint8 sG = (color>>surface->format->Gshift)&0xff;
Uint8 sB = (color>>surface->format->Bshift)&0xff;
Uint8 sA = (color>>surface->format->Ashift)&0xff;				
for(y = y1; y<=y2; y++){
row = (Uint8 *)surface->pixels + y * surface->pitch;
for(x = x1; x <= x2; x++){
pix = row + x*3;
dR = *((pix)+rshift8); 
dG = *((pix)+gshift8);
dB = *((pix)+bshift8);
dA = *((pix)+ashift8);				
dR = dR + ((sR-dR)*alpha >> 8);
dG = dG + ((sG-dG)*alpha >> 8);
dB = dB + ((sB-dB)*alpha >> 8);
dA = dA + ((sA-dA)*alpha >> 8);
*((pix)+rshift8) = dR; 
*((pix)+gshift8) = dG;
*((pix)+bshift8) = dB;
*((pix)+ashift8) = dA;
}
}					
}
break;
case 4: { /* Probably 32-bpp */
Uint32 *row, *pixel;
Uint32 dR=(color & Rmask),dG=(color & Gmask),dB=(color & Bmask),dA=(color & Amask);
for(y = y1; y<=y2; y++){
row = (Uint32 *)surface->pixels + y*surface->pitch/4;
for(x = x1; x <= x2; x++){
pixel = row + x;
R = ((*pixel & Rmask) + (( dR - (*pixel & Rmask) ) * alpha >> 8)) & Rmask;
G = ((*pixel & Gmask) + (( dG - (*pixel & Gmask) ) * alpha >> 8)) & Gmask;
B = ((*pixel & Bmask) + (( dB - (*pixel & Bmask) ) * alpha >> 8)) & Bmask;
if( Amask )
A = ((*pixel & Amask) + (( dA - (*pixel & Amask) ) * alpha >> 8)) & Amask;
*pixel= R | G | B | A;
}
}
}
break;
}	
if (SDL_MUSTLOCK(surface)) {
SDL_UnlockSurface(surface);
}
}
char midi_file[256]; 
char fn[1025][257]; 
char realfn[300]; 
int count = 0; 
int romcount = 0; 
dirent_t *ent; 
uint32 hnd; 
int sel = 0, scsel = 0, prevsel = 0, offset = 0, done = 0, redraw = 1; 
SDL_Surface * temp; 
SDL_Rect rect; 
SDL_Color color = {0xFF, 0xFF, 0xFF}; 
SDL_Event event; 
hnd = fs_open("/cd/music", O_RDONLY | O_DIR); 
ent = fs_readdir(hnd); 
count = 0; 
while (ent && count < 1025)   { 
if(ent->size != -1)   { /* Here's where to change allowed extensions */ 
char *extension = &ent->name[0] + strlen(ent->name)- 3;
if(stricmp(extension, "mid") && stricmp(extension, "ogg")&& stricmp(extension, "xmm") && stricmp(extension, "S3M") && stricmp(extension, "ITT")&& stricmp(extension, "aif")&& stricmp(extension, "wav") && stricmp(extension, "mod"))  { 
ent = fs_readdir(hnd); 
continue; 
} 
} 
strcpy(fn[count], ent->name);          
count++; 
romcount++; 
ent = fs_readdir(hnd); 
} 
while(done == 0)   { 
SDL_PollEvent(&event); 
switch(event.type)   { 
case SDL_JOYBUTTONDOWN: 
if(event.jbutton.button == 0)   { 
memset(midi_file, 0, sizeof(midi_file)); 
sprintf(realfn, "/cd/music/%s", fn[sel]); 
strcpy(midi_file,realfn); 
/* Load the MIDI file */ 
song1 = Mix_LoadMUS(midi_file);
Mix_PlayMusic(song1, 0); 
Mix_FadeInMusic(song1,looping,2000);
redraw = 1; 
SDL_BlitSurface( play, NULL, screen, NULL);


done = 0; 
} 
break; 
case SDL_JOYHATMOTION: 
if(event.jhat.value == SDL_HAT_UP && sel != 0)   { 
scsel--; 
sel--; 
redraw = 1;
SDL_BlitSurface( up, NULL, screen, NULL); 
} 
if(event.jhat.value == SDL_HAT_DOWN && sel < romcount)   { 
scsel++; 
sel++;       
redraw = 1; 
SDL_BlitSurface( down, NULL, screen, NULL); 
} 
if(event.jhat.value == SDL_HAT_LEFT && sel < romcount)   { 
redraw = 1; 
SDL_BlitSurface( stop, NULL, screen, NULL); 
Mix_FreeMusic(song1); 
song1 = NULL;    
} 
break; 
} 
if(redraw == 1)   { 
redraw = 0; 
if(sel <= romcount)   { 
rect.x = 55; 
rect.y = 109; 
rect.w = 144; 
rect.h = 480; 
SDL_FillRect(screen, &rect, SDL_MapRGB(screen->format, 201, 143, 155)); 
temp = TTF_RenderText_Solid(font, "Select a SONG:", color); 
rect.x = 73; 
rect.y = 109; 
rect.w = 91; 
rect.h = 20; 
SDL_BlitSurface(temp, NULL, screen, &rect); 
if(scsel > 19)   { 
offset++;             
scsel = 19; 
 } 
else if(scsel < 0)   { 
offset--; 
scsel = 0; 
} 
for(count = 0; count < 20; count++)   { 
if(fn[count + offset][0] != '\0')   { 
temp = TTF_RenderText_Solid(font, fn[count + offset], color); 
rect.x = 65; 
rect.y = 148 + (count * 20); 
rect.w = 130; 
rect.h = 20; 
SDL_BlitSurface(temp, NULL, screen, &rect);
SDL_FreeSurface(temp); 
} 
} 
rect.x = 65; 
rect.y = 148 + (scsel * 20); 
rect.w = 133; 
rect.h = 20; 
RectAlpha(screen, &rect, SDL_MapRGB(screen->format, 184, 127, 138), 127);
SDL_Flip(screen);

prevsel = sel; 
} 
else   { 
sel = prevsel; 
scsel = sel - offset; 

}
}
}
}
}
    





	











