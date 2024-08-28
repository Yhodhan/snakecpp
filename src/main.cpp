#include "context/context.h"
#include <memory>
#include <iostream>

int main() {
  Context* game(new Context);
  std::unique_ptr<Display> display(New Display(context));

  display->events();
  return 0;
}
