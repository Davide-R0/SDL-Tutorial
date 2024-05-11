# Render texture
The tecxture are a more efficient and newest version of surface.

- Declaration objects:
    ``` cpp
    //Window to render on 
    SDL_Window* window = NULL;

    //Window renderer creation
    SDL_Renderer* renderer = NULL;

    //Current tecture cration 
    SDL_Texture* texture = NULL;
    ```

- See the example...

- In case of hight cpu and GPU usage activate freesync in the renderer creation:
    ``` cpp
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    ```

## Conclusion
Source code [5-image](5-image/)
