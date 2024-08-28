#pragma once

#include "utils.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <vector>

class Display;

class Context {
public:
  Context();
  ~Context();
  void cycle();
  // getters
  std::vector<Position> position() { return player_position; }
  State state() { return game_state; }

private:
  std::vector<Position> player_position;
  Position food_position;
  State game_state;
  PlayerMove direction;
  Display *display;
  // helper functions
  void update_game();
};

class Display {
public:
  Display();
  ~Display();
  void draw_background();
  void draw(Context *context);
  void events(Context *context);
  void draw_food(Context *context);
  void draw_player(Context *context);

private:
  SDL_Window *win;
  int width = 1280;
  int height = 640;
  SDL_Renderer *render;
};
