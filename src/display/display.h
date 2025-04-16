#include "../context/context.h"
#include "../utils.h"

class Display {
public:
  Display(Context *c);
  ~Display();
  void draw_background();
  void draw_dot(Position p);
  void draw();
  bool events();
  void draw_food();
  void draw_player();
  void change_pause_status();

private:
  SDL_Window *win;
  int width = GRID_WIDTH * DOT_SIZE_IN_PXS;
  int height = GRID_HEIGHT * DOT_SIZE_IN_PXS;
  SDL_Renderer *render;
  Context *context;
};
