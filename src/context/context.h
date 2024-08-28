#pragma once

#include "utils.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <iostream>
#include <vector>

class Context {
public:
  Context();
  ~Context();
  // getters
  std::vector<Position> position() { return player_position; }
  State state() { return game_state; }

private:
  std::vector<Position> player_position;
  Position food_position;
  State game_state;
  PlayerMove direction;
  // helper functions
  void update_game();
};

class Display {
public:
  Display(Context *c);
  ~Display();
  void draw_background();
  void draw_dot(Position p);
  void draw();
  void events();
  void draw_food();
  void draw_player();

private:
  SDL_Window *win;
  int width = 1280;
  int height = 640;
  SDL_Renderer *render;
  Context *context;
};
