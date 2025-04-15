#include "../utils.h"
#include "../context/context.h"

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
  int width = 1280;
  int height = 640;
  SDL_Renderer *render;
  Context *context;
};
