#include "display.h"
#include <cstdint>
#include <vector>

struct Position {
  uint32_t x;
  uint32_t y;
};

enum State { Paused, Playing, End };

enum PlayerMove { Left, Right, Up, Down };

class Context {
public:
  Context();
  ~Context();
  void cycle();

private:
  std::vector<Position> player_position;
  Position food_position;
  State game_state;
  PlayerMove direction;
  Display *display;
  // helper functions
  void update_game();
};
