# Rendering geometry


- Activation of freesync (in case of hight cpu and gpu usage):
    ``` cpp
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
```

## Rendering single pixels:
``` cpp 
SDL_Point athoms [ SCREEN_HEIGHT*SCREEN_WIDTH ];
//use a cuda kernel function for associate the result of the calcualtion for each of this poinst
//es:
int a[4][4]={
    {1, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

if (a[i][j] == 1) athoms[n] = {i, j};
```
With the possibility to rerenderize only a part of the a matrices each times.

And then rendering them with:
``` cpp
SDL_RenderDrawPoints( renderer, athoms, SCREEN_HEIGHT*SCREEN_WIDTH );
```

Si mappano le modifiche fatte in una matrice `matrice delle modifiche o di attivazione` così da richiamare solo i calcoli necessari (a causa di una modifica). Forse è un iteratore che punta agllle celle della matrice a e cogni volta cambia ciò che punta (aggiunge modifica, ecc).
> Utilizzare un vector bidimensionale puntato da un iteratore? oppure usare un vector monodimensionale (oppure un vector monodimensionale?)


## Conclusion
Source file: [6-main](6-main/)
