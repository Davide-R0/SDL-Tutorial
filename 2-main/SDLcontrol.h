#ifndef SDLCONTROL_H
#define SDLCONTROL_H
#include <SDL2/SDL.h>
//#include <stdio.h>
#include "constant.h"

// Initialization function
int init_w_s ( SDL_Window** gWindow, SDL_Surface** gSurface);

// Clear function 
void clear_w_s ( SDL_Window** gWindow, SDL_Surface** gSurface );

#endif
