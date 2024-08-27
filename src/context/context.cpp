#include "context.h"

Context::Context()
    : player_position({Position{1, 1}, Position{1, 2}, Position{1, 3}}),
      game_state(State::Playing), food_position({6, 6}),
      direction(PlayerMove::Right), display(new Display) {}

Context::~Context() { delete display; }

void Context::update_game() {
  Position current_head_position = this->player_position.front();
  Position new_position = {0, 0};
  switch (this->direction) {
  case PlayerMove::Up:
    new_position.x = current_head_position.x;
    new_position.y = current_head_position.y + 1;
  case PlayerMove::Down:
    new_position.x = current_head_position.x;
    new_position.y = current_head_position.y - 1;
  case PlayerMove::Right:
    new_position.x = current_head_position.x + 1;
    new_position.y = current_head_position.y;
  case PlayerMove::Left:
    new_position.x = current_head_position.x - 1;
    new_position.y = current_head_position.y;
  }

  // TODO: check collisions with the end of the map and if food has been eaten
  // check_position()

  // remove last position and insert new one
  this->player_position.pop_back();
  this->player_position.insert(this->player_position.begin(), new_position);

  // spawn new food
}

void Context::cycle() {
  // draw snake
  update_game();
  display.draw();
}
