# General Commands

## Package installation
### SDL
`media-libs/libsdl`

`media-libs/sdl-image`

### SDL 2
`media-libs/libsdl2`

`media-libs/sdl2-image`

## Library
In general for ptinting errors to console (`printf()`):
``` cpp
#include <stdio.h>
```

### SDL 1
``` cpp
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
```

### SDL 2
``` cpp
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
```

## Compilation flags
With `g++` and Linker flags:
``` make 
LFLAG = -lSDL2 -SDL2_image
```

Useful Compiler flags:
``` make
CFLAGS = -Wall -g -O2
```
- `-g`      add debug information
- `-Wall`   show comiler warnings 
- `-w`      suppress compiler warnings
- `-O2`     standard optimization
- `-c`      Compiler source(s) to object-code (input to linker). This option is better for incremental compilation when using multiple files.
