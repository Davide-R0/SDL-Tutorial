# Image Loading

## Loading
- Create a surface (in `main`) to contain the image:
    ``` cpp
    //Image surface creation
    SDL_Surface* image = NULL;
    ```
    by default this has the image data (pixel) and render the image with CPU (it is possible to use GPU with `Vulkan` or `OpenGL`)

- Create a media initialization function: (Needed: `#include <string>`)
    ``` cpp
    int loadMedia ( std::string path, SDL_Surface** gImage ) {
        //Load image
        *gImage = SDL_LoadBMP( path.c_str() );
        
        if( *gImage == NULL ) {
            printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
    ```

- In `clean w_s()` function add:
    ``` cpp
    //Deallocate surface
    SDL_FreeSurface( gImage );
    gImage = NULL;
    ```
    *Only if needed!*

- In main load the image:
    ``` cpp 
    // Load media
    if ( loadMedia(PATH_1, &image) != 0 ){
        printf( "Falied to load media!" );
        return EXIT_FAILURE;
    }

    //Apply the image
    SDL_BlitSurface( image, NULL, surface, NULL );
    ```

> Note:
> SDL have two buffer: front and end.
> The end buffer si what wou do not see and is the *costruction* of a complex immage (maybe composed by multiple part)
> The front buffer is what you see, the final complete result.

- In main update the window surface tho show the end buffer in the front buffer:
    ``` cpp
    //Update window surface 
    SDL_UpdateWindowSurface( window );
    ```

## Conclusion
Source file [3 main](3-main/)
