#include "SDLcontrol.h"
#include <SDL2/SDL_render.h>

bool init_w_r ( SDL_Window** gWindow, SDL_Renderer** gRenderer) {
    //Initialize SDL
    if( SDL_InitSubSystem( SDL_INIT_VIDEO ) < 0 ){    
        printf( "SDL Not initialized! SDL_GetError: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }
    
    //Window Creation 
    *gWindow = SDL_CreateWindow( "Window Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        
    if( *gWindow == NULL ) {
        printf( "Window not created! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }
    
    //Create renderer for window
    *gRenderer = SDL_CreateRenderer( *gWindow, -1, SDL_RENDERER_ACCELERATED );
    
    if( gRenderer == NULL ){
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

void clear_w_r ( SDL_Window** gWindow, SDL_Renderer** gRenderer ) {
    //Destroy window
    SDL_DestroyRenderer( *gRenderer );
    *gRenderer = NULL;
    SDL_DestroyWindow( *gWindow );
    *gWindow = NULL;
    
    //Quit SDL subsystems
    SDL_Quit();

    printf("Window and Renderer destroyed!\n");
}

