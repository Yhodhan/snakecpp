#include "context/context.h"
#include "display/display.h"
#include <chrono>
#include <thread>

#define CLOCK_CYCLE 150

inline void simulate_await_cycle() {
  std::this_thread::sleep_for(std::chrono::milliseconds(CLOCK_CYCLE));
}

void next_tick(Context *game) {
  switch (game->state()) {
  case State::Playing:
    game->update_game();
    break;
  default:
    return;
  }
}

void run_game(Display *display, Context *game) {
  loop {
    if (!display->events())
      break;

    simulate_await_cycle();
    next_tick(game);
    display->draw();
  }
}

int main() {
  Context *game(new Context);
  Display *display(new Display(game));

  // game loop
  run_game(display, game);

  delete display;

  return 0;
}
