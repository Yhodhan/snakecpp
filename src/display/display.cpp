#include "display.h"

// ---------------------
// Display class logic
// ---------------------

void sdl_error() {
  std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
  exit(EXIT_FAILURE);
}

Display::~Display() {
  delete context;
  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(win);
  SDL_Quit();
}

Display::Display(Context *c) : context(c) {
  SDL_SetMainReady();
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    sdl_error();

  SDL_CreateWindowAndRenderer(width, height, 0, &win, &render);
  if (win == nullptr || render == nullptr)
    sdl_error();

  SDL_SetWindowTitle(win, "Snake game");
}

void Display::draw_dot(Position p) {
  // create the rect from the point
  SDL_Rect rect = SDL_Rect{
      .x = (int)p.x * 20,
      .y = (int)p.y * 20,
      .w = 20,
      .h = 20,
  };

  SDL_RenderFillRect(render, &rect);
}

void Display::draw_background() {

  switch (context->state()) {
  case State::Playing:
    SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
    break;
  default:
    SDL_SetRenderDrawColor(render, 30, 30, 30, 30);
  }

  SDL_RenderClear(render);
}

void Display::draw_player() {
  SDL_SetRenderDrawColor(render, 0, 255, 0, 255);
  std::vector<Position> player_position = context->position();
  for (Position p : player_position)
    draw_dot(p);
}

void Display::draw() {
  SDL_RenderClear(render);

  draw_background();
  draw_player();

  SDL_RenderPresent(render);
}

void Display::change_pause_status() {
  switch (context->game_state) {
  case State::Paused:
    context->game_state = State::Playing;
    break;
  default:
    context->game_state = State::Paused;
  }
}

bool Display::events() {
  bool running = true;
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      running = false;
      break;
    case SDL_KEYDOWN: {
      switch (event.key.keysym.sym) {
      case SDLK_h:
      case SDLK_a:
        context->direction = PlayerMove::Left;
        break;
      case SDLK_k:
      case SDLK_w:
        context->direction = PlayerMove::Up;
        break;
      case SDLK_l:
      case SDLK_d:
        context->direction = PlayerMove::Right;
        break;
      case SDLK_j:
      case SDLK_s:
        context->direction = PlayerMove::Down;
        break;
      case SDLK_ESCAPE:
        change_pause_status();
        break;
      default:
        break;
      }
    } break;
    default:
      break;
    }
  }
  return running;
}
