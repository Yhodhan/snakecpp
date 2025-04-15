#pragma once

#define SDL_MAIN_HANDLED

#include "../utils.h"

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

