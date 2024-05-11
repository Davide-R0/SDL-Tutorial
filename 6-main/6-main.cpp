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
    //Window to render on 
    SDL_Window* window = NULL;
    
    //Window renderer creation
    SDL_Renderer* renderer = NULL;
    
    if ( init_w_r( &window, &renderer) ) {
        printf( "Failed to initialize window and renderer!\n" );
    }
    printf( "Window and Renderer initialized!\n" );

    // To get window active and Render loop
    SDL_Event eventSDL; 
    bool quit = false; 
     
    while( !quit ) { 
        while( SDL_PollEvent( &eventSDL ) ) {
            // ...
            if( eventSDL.type == SDL_QUIT ) quit = true; 
        }
        
        //Initialize renderer color
        //Clear screen
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        
        //Render red filled quad
        SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
        SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );        
        SDL_RenderFillRect( renderer, &fillRect );
        
        //Render green outlined quad
        SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
        SDL_SetRenderDrawColor( renderer, 0x00, 0xFF, 0x00, 0xFF );        
        SDL_RenderDrawRect( renderer, &outlineRect );

        //Draw blue horizontal line
        SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0xFF, 0xFF );        
        SDL_RenderDrawLine( renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );
        
        //Draw yellow obliqual line with width of 3px
        SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0xFF );
        for( int i = 0; i < SCREEN_HEIGHT; i++ ) {
            SDL_RenderDrawPoint( renderer, i, i+1 );
            SDL_RenderDrawPoint( renderer, i, i );
            SDL_RenderDrawPoint( renderer, i+1, i );
        }

        //Update screen
        SDL_RenderPresent( renderer );
    } 

    clear_w_r( &window, &renderer );//, &texture );

    return EXIT_SUCCESS;
}
