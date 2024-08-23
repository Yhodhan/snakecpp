#include <cstdint>
#include <vector>

struct Position {
  uint32_t x;
  uint32_t y;
};

enum class State { Paused, Playing, End };

enum class PlayerMove { Left, Right, Up, Down };

class Context {
public:
  Context();
  ~Context();
  void init_game();

private:
  std::vector<Position> player_position;
  Position food_position;
  State game_state;
};
