#ifndef GAME_H
#define GAME_H

#include <random>
#include <fstream>
#include <map>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "food.h"
#include "player.h"

class Game {
 public:
  Game(Player &player, std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  
 private:
  Snake snake;
  Food food;
  Player _player;
  BorderWall wall;
  std::vector<std::vector<SDL_Point>> obstacles;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int numOfObstacles{4};
  int numOfBlocksInObstacle {2};
  int score{0};
  int difficulty{1};
  
  void PlaceFood();
  void PlaceObstacles();
  void Update();
};

#endif