#include "context.h"

Context::Context()
    : player_position({Position{1, 1}, Position{1, 2}, Position{1, 3}}),
      game_state(State::Playing), food_position({6, 6}) {}

Context::~Context() {}
