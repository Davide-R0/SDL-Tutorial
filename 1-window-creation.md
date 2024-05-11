# Window Creation
Main initialization:
``` cpp
int main( int argc, char* args[] ) {
    const int SCREEN_HEIGHT = 1040;
    const int SCREEN_WIDTH = 680;   
    
    // ...
 
    return EXIT_SUCCESS;
}
```

## In main function
- Initialization of a window object:
    ``` cpp
    SDL_Window* window = NULL;
    ```

- Initializqation window sourface:
    ``` cpp
    SDL_Surface* surface = NULL;
    ```
    this is a 2D image that will be visualized on the window

- Initialize and chek SDL for video:
    ``` cpp 
    //Initialize SDL
    if( SDL_InitSubSystem( SDL_INIT_VIDEO ) < 0 ){                              //same as SDL_init()
        printf( "SDL Not initialized! SDL_GetError: %s\n", SDL_GetError() );    // SDL_GetError() return the latest error
        return EXIT_FALIURE;
    }
    ```
- Creation of the window:
    ``` cpp
    //Window Creation 
    window = SDL_CreateWindow( "Window Title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        
    if( window == NULL ) {
        printf( "Window not created! SDL_Error: %s\n", SDL_GetError() );
        return EXIT_FALIURE;
    }
    ```

- Associaton window sourface:
    ``` cpp
    //Assocate window surface
    surface = SDL_GetWindowSurface( window );
    ```
    ``` cpp
    // fill with a color
    SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ) );
    ```

- Update the window sourface:
    ``` cpp
    // Update window sourface
    SDL_UpdateWindowSurface( window );
    ```

- Make the window stay active:
    ``` cpp
    //to get window active 
    SDL_Event e; 
    bool quit = false; 
    
    while( quit == false ) { 
        while( SDL_PollEvent( &e ) ) { 
            if( e.type == SDL_QUIT ) quit = true; 
        } 
    }
    ```

- Destroy the window and quit SDL:
    ``` cpp
    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();
    ```

