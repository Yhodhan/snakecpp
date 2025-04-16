#include "context.h"

// ---------------------
// Context class logic
// ---------------------

Context::Context()
    : player_position({Position{3, 1}, Position{2, 1}, Position{1, 1}}),
      food_position({6, 6}), game_state(State::Playing),
      direction(PlayerMove::Right) {}

Context::~Context() {}

void Context::check_position(Position current_position) {
  // check snake does not collide with itself
  for (Position position : this->player_position) {
    if (position.x == current_position.x and position.y == current_position.y) {
      this->game_state = State::End;
      return;
    }
  }

  if (current_position.x > GRID_WIDTH or current_position.x < 0 or
      current_position.y > GRID_HEIGHT or current_position.y < 0)
    this->game_state = State::End;
}

void Context::feed(Position current_head) {
  if (current_head.x == food_position.x and current_head.y == food_position.y) {
    int x_food = rand() % GRID_WIDTH;
    int y_food = rand() % GRID_HEIGHT;
    Position new_food_position({x_food, y_food});

    this->player_position.insert(this->player_position.begin(),
                                 this->food_position);
    this->food_position = new_food_position;
  }
}

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

  check_position(new_position);
  feed(new_position);

  // remove last position and insert new one
  this->player_position.pop_back();
  this->player_position.insert(this->player_position.begin(), new_position);
}
