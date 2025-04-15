#include "context.h"

// ---------------------
// Context class logic
// ---------------------

Context::Context()
    : player_position({Position{3, 1}, Position{2, 1}, Position{1, 1}}),
      food_position({6, 6}), game_state(State::Playing),
      direction(PlayerMove::Right) {}

Context::~Context() {}

void Context::update_game() {

  Position current_head_position = this->player_position.front();
  Position new_position = {0, 0};

  switch (this->direction) {
  case PlayerMove::Up:
    new_position.x = current_head_position.x;
    new_position.y = current_head_position.y - 1;
    break;
  case PlayerMove::Down:
    new_position.x = current_head_position.x;
    new_position.y = current_head_position.y + 1;
    break;
  case PlayerMove::Right:
    new_position.x = current_head_position.x + 1;
    new_position.y = current_head_position.y;
    break;
  case PlayerMove::Left:
    new_position.x = current_head_position.x - 1;
    new_position.y = current_head_position.y;
    break;
  }

  // TODO: check collisions with the end of the map and if food has been eaten
  // check_position()

  // remove last position and insert new one
  this->player_position.pop_back();
  this->player_position.insert(this->player_position.begin(), new_position);

  // spawn new food
}
