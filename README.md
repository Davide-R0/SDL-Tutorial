# Notes on SDL

## General commands
[General Command](0-cmd-general.md)

## Window creation
[Window Creation](1-window-creation.md)

## Useful Habits
[Useful Habits](2-useful-habits.md)

## Image Load
[Image Load](3-image-load.md)



## Userfull information:
- For timing in render loop use: `std::chrono`, `SDL_GetPerformanceFrequency();` or `SDL_GetPerformanceCounter();`.
- If the cpu and gpu usage are hight insert a delay in the render loop `SDL_Delay(1);` or activate `freesync` in the renderer.

---

# More resources:
- [SDL Tutorials](https://wiki.libsdl.org/SDL2/Tutorials)
- [LazyFoo SDL Tutorial](https://lazyfoo.net/tutorials/SDL/index.php)
