#include "game.h"
#include <iostream>
#include <algorithm>
#include <map>
#include "SDL.h"

Game::Game(Player &player, std::size_t grid_width, std::size_t grid_height)
    : _player(player),
      snake(player.GetDifficulty(), grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  if(_player.GetDifficulty() == 2){
    wall.CreateWall();
  }
  _player.LoadScores();
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  //PlaceObstacles();

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(wall, snake, food, obstacles);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceObstacles(){
  int x, y;

  for(int i = 0; i < numOfObstacles; ++i){
    x = random_w(engine);
    y = random_h(engine);
    std::vector<SDL_Point> obstacle{};
    for(int j = 0; j < numOfBlocksInObstacle; j++){
      obstacle.emplace_back(SDL_Point{x + i, y + i});
    }
    obstacles.emplace_back(obstacle);
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake or wall item item before placing
    // food.
    if(_player.GetDifficulty() == 2){
      if (!snake.SnakeCell(x, y) && x < 30 && x > 2 && y < 30 && y > 2) {
        food.setPosition(x, y);
        return;
      }
    }
    else{
      if (!snake.SnakeCell(x, y) && x < 31 && x > 1 && y < 31 && y > 1) {
        food.setPosition(x, y);
        return;
      }
    }
  }
}

void Game::Update() {
  //Check if snake has died
  if (!snake.alive){
    if(!_player.saved){
      _player.Save();
      _player.saved = true;
    }
    return;
  }

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.getPosition().x == new_x && food.getPosition().y == new_y) {
    _player.SetScore(score++);
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.015;
  }
  
}