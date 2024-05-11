#ifndef SDLCONTROL_H
#define SDLCONTROL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
//#include <stdio.h>
#include "constant.h"

// Initialization function
bool init_w_s ( SDL_Window** gWindow, SDL_Renderer** gRenderer );

// Load Texture
SDL_Texture* loadTexture( std::string path, SDL_Renderer** gRenderer);

// Load media
bool loadMedia ( std::string path, SDL_Renderer** gRenderer, SDL_Texture** gTexture );

// Clear function 
void clear_w_s ( SDL_Window** gWindow, SDL_Renderer** gRenderer, SDL_Texture** gTexture );

#endif
