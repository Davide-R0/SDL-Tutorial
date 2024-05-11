#include "SDLcontrol.h"
#include <SDL2/SDL_render.h>

bool init_w_s ( SDL_Window** gWindow, SDL_Renderer** gRenderer) {
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
    *gRenderer = SDL_CreateRenderer( *gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ); //freesync activation
    
    if( gRenderer == NULL ){
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

SDL_Texture* loadTexture( std::string path, SDL_Renderer** gRenderer ) {
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    } else {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( *gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

bool loadMedia ( std::string path, SDL_Renderer** gRenderer, SDL_Texture** gTexture ) {
    //Load PNG texture
    *gTexture = loadTexture( path.c_str(), gRenderer);

    if( *gTexture == NULL ) {
        printf( "Unable to load texture image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void clear_w_s ( SDL_Window** gWindow, SDL_Renderer** gRenderer, SDL_Texture** gTexture ) {
    //Deallocate texture
    SDL_DestroyTexture( *gTexture );
    gTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer( *gRenderer );
    *gRenderer = NULL;
    SDL_DestroyWindow( *gWindow );
    *gWindow = NULL;
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

    printf("Window, Renderer and Texture destroyed!\n");
}

