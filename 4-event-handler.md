# Event Handler
In `main`:
``` cpp
// To get window active and Render loop
    SDL_Event eventSDL; 
    bool quit = false; 
     
    while( !quit ) { 
        while( SDL_PollEvent( &eventSDL ) ) { 
            
            // Input detech
            
            if( eventSDL.type == SDL_QUIT ) quit = true; 
        }

        // Render loop

        //Apply the image
        SDL_BlitSurface( image, NULL, surface, NULL );
            
        //Update the surface
        SDL_UpdateWindowSurface( window );
    }
```

## Conclusion
Source file [3 main](3-main/)
