#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_keycode.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

#define loop for (;;)

#define DOT_SIZE_IN_PXS 20
#define GRID_WIDTH 40
#define GRID_HEIGHT 30

struct Position {
  int x;
  int y;
};

class Display;

enum State { Paused, Playing, End };
enum PlayerMove { Left, Right, Up, Down };
