#include "display.h"

static inline void sdl_error() {
  std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
  exit(EXIT_FAILURE);
}

Display::~Display() {
  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(win);
  SDL_Quit();
}

Display::Display() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    sdl_error();

  SDL_CreateWindowAndRenderer(width, height, 0, &win, &render);
  if (win == nullptr or render == nullptr)
    sdl_error();

  SDL_SetWindowTitle(win, "Snake game");
  events();
}

void Display::events() {
  bool close = false;
  while (!close) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        close = true;
        break;
      }
    }
  }
}
