/*
 * Author: Davide Rinarelli
 * Date:
 * Name: 2-main.cpp
 * Licence:
 * Description:
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <string>
#include <stdio.h>
//#include <iostream> //for use of std::cerr << "...";

#include "constant.h"
#include "SDLcontrol.h"

int main( int argc, char* args[] ) { 
    //Load Texture creation
    SDL_Texture* loadTexture( std::string path );

    //Window to render on 
    SDL_Window* window = NULL;
    
    //Window renderer creation
    SDL_Renderer* renderer = NULL;

    //Current tecture cration 
    SDL_Texture* texture = NULL;
    
    if ( init_w_s( &window, &renderer) ) {
        printf( "Failed to initialize window and renderer!\n" );
    }
    printf( "Window and Renderer initialized!\n" );

    //Initialize renderer color
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return EXIT_FAILURE;
    }
    
   if( loadMedia( PATH_1, &renderer, &texture ) ) {
        printf( "Falied to load Texture!\n");
        return EXIT_FAILURE;
   }

    // To get window active and Render loop
    SDL_Event eventSDL; 
    bool quit = false; 
     
    while( !quit ) { 
        while( SDL_PollEvent( &eventSDL ) ) { 
            
            // ...
            
            if( eventSDL.type == SDL_QUIT ) quit = true; 
        }

        //Clear screen
        SDL_RenderClear( renderer );

        //Render texture to screen
        SDL_RenderCopy( renderer, texture, NULL, NULL );

        //Update screen
        SDL_RenderPresent( renderer );  //similar to UpdateWindowSurface
    } 

    clear_w_s( &window, &renderer, &texture );

    return EXIT_SUCCESS;
}
