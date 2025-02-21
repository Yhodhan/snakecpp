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
  Context *game(new Context);
  Display *display(new Display(game));

  // game loop
  run_game(display, game);

  delete game;
  delete display;

  return 0;
}
