# Rendering geometry


- Activation of freesync (in case of hight cpu and gpu usage):
    ``` cpp
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    ```

## Conclusion
Source file: [6-main](6-main/)
