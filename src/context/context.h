#pragma once

#define SDL_MAIN_HANDLED

#include "utils.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>

class Context {
public:
  Context();
  ~Context();
  // getters
  std::vector<Position> position() { return player_position; }
  State state() { return game_state; }
  void update_game();

private:
  friend class Display;
  std::vector<Position> player_position;
  Position food_position;
  State game_state;
  PlayerMove direction;
};

class Display {
public:
  Display(Context *c);
  ~Display();
  void draw_background();
  void draw_dot(Position p);
  void draw();
  bool events();
  void draw_food();
  void draw_player();

private:
  SDL_Window *win;
  int width = 1280;
  int height = 640;
  SDL_Renderer *render;
  Context *context;
};
