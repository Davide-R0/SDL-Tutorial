#ifndef SDLCONTROL_H
#define SDLCONTROL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
//#include <stdio.h>
#include "constant.h"

// Initialization function
bool init_w_r ( SDL_Window** gWindow, SDL_Renderer** gRenderer );

// Clear function 
void clear_w_r ( SDL_Window** gWindow, SDL_Renderer** gRenderer );

#endif
