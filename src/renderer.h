#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "food.h"
#include "borderwall.h"

class Renderer {
 public:
  Renderer(const std:: string player, const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(BorderWall &wall, Snake const snake, Food &food, std::vector<std::vector<SDL_Point>>const &obstacles);
  void UpdateWindowTitle(int score, int fps);

 private:
  std::string _player;

  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif