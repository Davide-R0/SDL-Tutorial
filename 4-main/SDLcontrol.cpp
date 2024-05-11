#include "SDLcontrol.h"

int init_w_s ( SDL_Window** gWindow, SDL_Surface** gSurface) {

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

    //Assocate window surface
    *gSurface = SDL_GetWindowSurface( *gWindow );
    
    return EXIT_SUCCESS;
}

int loadMedia ( std::string path, SDL_Surface** gImage ) {
    //Load image
    *gImage = SDL_LoadBMP( path.c_str() );
        
    if( *gImage == NULL ) {
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


void clear_w_s ( SDL_Window** gWindow, SDL_Surface** gSurface ) {
    //Deallocate surface
    SDL_FreeSurface( *gSurface );
    *gSurface = NULL;

    //Destroy window
    SDL_DestroyWindow( *gWindow );
    *gWindow = NULL;
    
    //Quit SDL subsystems
    SDL_Quit();

    printf("Window and Surface destroyed!\n");
}

