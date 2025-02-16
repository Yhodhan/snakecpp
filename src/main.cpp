#include "context/context.h"
#include <iostream>
#include <memory>

void run_game(Display *display, Context *game) {

  loop {

    game->update_game();
    display->draw();

    if (!display->events())
      break;
  }
}

int main() {
  std::unique_ptr<Context> game(new Context);
  std::unique_ptr<Display> display(new Display(game));

  // game loop
  run_game(display, game);

  return 0;
}
