#pragma once

struct Position {
  int x;
  int y;
};

enum State { Paused, Playing, End };
enum PlayerMove { Left, Right, Up, Down };
