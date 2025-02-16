#pragma once

#define SDL_MAIN_HANDLE

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <vector>

#define loop for(;;)

struct Position {
  int x;
  int y;
};

enum State { Paused, Playing, End };
enum PlayerMove { Left, Right, Up, Down };
