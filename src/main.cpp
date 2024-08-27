#include "context/context.h"
#include <memory>

int main() {
  std::unique_ptr<Context> game(new Context);
  return 0;
}
