#pragma once
#include <cstdint>

struct Position {
  uint32_t x;
  uint32_t y;
};

enum State { Paused, Playing, End };
enum PlayerMove { Left, Right, Up, Down };
