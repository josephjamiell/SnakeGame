# CPPND: Capstone Snake Game

This is a Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="images/snake_game.gif"/>

## Description
The main objective is to eat as much food as possible without dying. As the snake eats food, it gets larger and faster making the game
that more difficult.

In this game, the user will be prompted to enter a player name and level of difficult.
<img src="/images/image1.png"/>

Once this is done, the game window will be rendered. The snake can be controlled by using
the Up, Left, Right and Down arrow keys. 

Difficulty Level One(1)
<img src="images/image2.png"/>

In this difficulty level, the snake can only die by eating it's body.

Difficulty Level Two(2)
<img src="images/image3.png"/>

In this difficultly level, the snake will die if it enters the border wall or eats it's body.


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Ruberic Points Addressed:

### Loops, Functions, I/O

1. The project demonstrates an understanding of C++ functions and control structures.

2. The project reads data from a file and process the data, or the program writes data to a file.

3. The project accepts user input and processes the input.

### Object Oriented Programming

1. The project uses Object Oriented Programming techniques.

2. Classes use appropriate access specifiers for class members.

3. Class constructors utilize member initialization lists.

4. Classes abstract implementation details from their interfaces.

5. Classes encapsulate behavior.

### Memory Management

1. The project makes use of references in function declarations.

2. The project uses smart pointers instead of raw pointers.

### Concurrency

1. The project uses multithreading.

2. A mutex or lock is used in the project.


