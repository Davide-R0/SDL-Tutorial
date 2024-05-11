# Useful habits

## Create an `init_w_s` function for the initialization window and sourface
``` cpp
bool init_w_s ( SDL_Window* gWindow, SDL_Surface* gSurface ) {
    //Initialize SDL
    if( SDL_InitSubSystem( SDL_INIT_VIDEO ) < 0 ){    
        printf( "SDL Not initialized! SDL_GetError: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }
    
    //Window Creation 
    gWindow = SDL_CreateWindow( "Window Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        
    if( window == NULL ) {
        printf( "Window not created! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FAILURE;
    }

    //Assocate window surface
    gSurface = SDL_GetWindowSurface( gWindow );
    
    return EXIT_SUCCESS;
}
```
So in the `main` will be:
``` cpp
    if ( !init_w_s(window, surface) ) {
        printf( "Failed to initialize window and sourface!\n" );
    }
```

## Create an `clear_w_s` function for destroing SDL 
``` cpp
void clear_w_s ( SDL_Window* gWindow, SDL_Surface* gSurface ) {
    //Deallocate surface
    SDL_FreeSurface( gSurface );
    gSurface = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );

    //Quit SDL subsystems
    SDL_Quit();
}
```
To the end of `main`:
``` cpp
    clear_w_s( window, surface );
```
## Conclusion
At this point the `main` shuld look like [2-main](2-main/)
