#include "display/display.h"
#include <memory>

int main() {
  std::unique_ptr<Display> display(new Display);
  return 0;
}
