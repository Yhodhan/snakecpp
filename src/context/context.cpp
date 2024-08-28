#include "context.h"

// ---------------------
// Display class logic
// ---------------------
static inline void sdl_error() {
  std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
  exit(EXIT_FAILURE);
}

Display::~Display() {
  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(win);
  SDL_Quit();
}

Display::Display() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    sdl_error();

  SDL_CreateWindowAndRenderer(width, height, 0, &win, &render);
  if (win == nullptr or render == nullptr)
    sdl_error();

  SDL_SetWindowTitle(win, "Snake game");
}

void draw_dot(SDL_Renderer *render, Position p) {
  // create the rect from the point
  SDL_Rect rect;
  rect.x = p.x * 20;
  rect.y = p.y * 20;
  rect.h = 20;
  rect.w = 20;

  SDL_RenderDrawRect(render, &rect);
  SDL_RenderFillRect(render, &rect);
}

void Display::draw_background() { SDL_SetRenderDrawColor(render, 0, 0, 0, 0); }

void Display::draw_player(Context *context) {
  std::vector<Position> player_position = context->position();
  for (Position p : player_position)
    draw_dot(render, p);
}

void Display::draw(Context *context) {
  SDL_RenderClear(render);

  draw_player(context);
  draw_background();

  SDL_RenderPresent(render);
}

void Display::events(Context *context) {
  bool close = false;
  while (!close) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        close = true;
        break;
      default:
        draw(context);
        break;
      }
    }
  }
}

// ---------------------
// Context class logic
// ---------------------

Context::Context()
    : player_position({Position{3, 1}, Position{2, 1}, Position{1, 1}}),
      food_position({6, 6}), game_state(State::Playing),
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
  display->events(this);
}
