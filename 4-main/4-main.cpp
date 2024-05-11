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
    //Window creation
    SDL_Window* window = NULL;
    
    //Sourface creation 
    SDL_Surface* surface = NULL;

    //Image surface creation
    SDL_Surface* image = NULL;
    
    if ( init_w_s( &window, &surface) ) {
        printf( "Failed to initialize window and sourface!\n" );
    }
    printf( "Window and Surface initialized!\n" );

    // fill with a color
    SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ) );
   
    // Load media
    if ( loadMedia(PATH_1, &image) ){
        printf( "Falied to load media!" );
        return EXIT_FAILURE;
    }

    // Update window sourface
    SDL_UpdateWindowSurface( window );
    
    // To get window active and Render loop
    SDL_Event eventSDL; 
    bool quit = false; 
     
    while( !quit ) { 
        while( SDL_PollEvent( &eventSDL ) ) { 
            
            // ...
            
            if( eventSDL.type == SDL_QUIT ) quit = true; 
        }

        //Apply the image
        SDL_BlitSurface( image, NULL, surface, NULL );
            
        //Update the surface
        SDL_UpdateWindowSurface( window );
    } 

    clear_w_s( &window, &surface );

    return EXIT_SUCCESS;
}
