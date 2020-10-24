#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::string player,
                   const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : _player(player),
      screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(BorderWall &wall, Snake const snake, Food &food, std::vector<std::vector<SDL_Point>>const &obstacles) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 41, 87, 50, 0xFF);
  SDL_RenderClear(sdl_renderer);

  //Render TopBorderWall
  for(int i = 0; i < wall.getTopBorder().size(); ++i){
    if(i % 2 == 0){
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
      block.x = wall.getTopBorder()[i].x;
      block.y = wall.getTopBorder()[i].y;
    }
    else{
      SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 0);
      block.x = wall.getTopBorder()[i].x;
      block.y = wall.getTopBorder()[i].y;
    }
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  //Render LeftBorderWall
  for(int i = 0; i < wall.getLeftBorder().size(); ++i){
    if(i % 2 == 0){
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
      block.x = wall.getLeftBorder()[i].x;
      block.y = wall.getLeftBorder()[i].y;
    }
    else{
      SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 0);
      block.x = wall.getLeftBorder()[i].x;
      block.y = wall.getLeftBorder()[i].y;
    }
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  //Render RightBorderWall
  for(int i = 0; i < wall.getRightBorder().size(); ++i){
    if(i % 2 == 0){
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
      block.x = wall.getRightBorder()[i].x;
      block.y = wall.getRightBorder()[i].y;
    }
    else{
      SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 0);
      block.x = wall.getRightBorder()[i].x;
      block.y = wall.getRightBorder()[i].y;
    }
    SDL_RenderFillRect(sdl_renderer, &block);
  } 

  //Render BottomBorderWall
  for(int i = 0; i < wall.getBottomBorder().size(); ++i){
    if(i % 2 == 0){
      SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
      block.x = wall.getBottomBorder()[i].x;
      block.y = wall.getBottomBorder()[i].y;
    }
    else{
      SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 0);
      block.x = wall.getBottomBorder()[i].x;
      block.y = wall.getBottomBorder()[i].y;
    }
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  //Render obstacle
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for(std::vector<SDL_Point> obs : obstacles){
    for(SDL_Point point : obs){
      block.x = point.x * block.w;
      block.y = point.y * block.h;
      SDL_RenderFillRect(sdl_renderer, &block);
    }
  }

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 150, 87, 42, 0xFF);
  block.x = food.getPosition().x * block.w;
  block.y = food.getPosition().y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xAF, 0xAF, 0xAF, 0xAF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.head_x) * block.w;
  block.y = static_cast<int>(snake.head_y) * block.h;
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{_player + "'s Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
