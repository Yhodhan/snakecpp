#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <cstdlib>
#include <iostream>

class Display {
public:
  Display();
  ~Display();
  void events();
  void draw();

private:
  SDL_Window *win;
  SDL_Renderer *render;
  int width = 1280;
  int height = 640;
};
