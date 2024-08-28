#include "context/context.h"
#include <memory>
#include <iostream>

int main() {
  std::unique_ptr<Context> game(new Context);
  game->cycle();
  return 0;
}
