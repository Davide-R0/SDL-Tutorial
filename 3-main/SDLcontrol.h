#ifndef SDLCONTROL_H
#define SDLCONTROL_H

#include <SDL2/SDL.h>
#include <string>
//#include <stdio.h>
#include "constant.h"

// Initialization function
int init_w_s ( SDL_Window** gWindow, SDL_Surface** gSurface);

// Load media
int loadMedia ( std::string path, SDL_Surface** gImage );

// Clear function 
void clear_w_s ( SDL_Window** gWindow, SDL_Surface** gSurface );

#endif
