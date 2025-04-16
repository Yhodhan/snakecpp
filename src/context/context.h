#pragma once

#include "../utils.h"

class Context {
public:
  Context();
  ~Context();
  // getters
  std::vector<Position> position() { return player_position; }
  State state() { return game_state; }
  void update_game();
  void check_position(Position current_position);
  void feed(Position current_head);

private:
  friend class Display;
  std::vector<Position> player_position;
  Position food_position;
  State game_state;
  PlayerMove direction;
};

