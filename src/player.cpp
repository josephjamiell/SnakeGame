#include "player.h"


void Player::ShowGreeting()
{
  std::cout << "\n\n";
  std::cout << " ------------------------------------- " << std::endl;
  std::cout << "|     WELCOME TO THE SNAKE GAME!      |" << std::endl;
  std::cout << " ------------------------------------- " << std::endl;
  std::cout << "\nPLEASE ENTER PLAYER NAME: ";
  std::cin >> _name;
  std::transform(_name.begin(), _name.end(), _name.begin(), ::toupper);
  std::cout << "\n ------------------------------------- " << std::endl;
  std::cout << "|   DIFFICULTY:  1 = EASY, 2 = HARD   |" << std::endl;
  std::cout << " ------------------------------------- " << std::endl;
  std::cout << "\nENTER GAME DIFFICULTY (1 or 2): ";
  std::cin >> _difficulty; 
}

void Player::Save(){
  topScores[_name] = _score;
  std::ofstream scoreFile(saveFile);
  if(scoreFile.is_open()){
    for(auto obj : topScores){
      scoreFile << obj.first << " " << obj.second << std::endl;
    }
  }
  scoreFile.close();
}

void Player::LoadScores(){
  std::string line, name, score;
  int s = 0;
  std::ifstream scoreFile(saveFile, std::ios::in);
  if(scoreFile.is_open()){
    while(std::getline(scoreFile, line)){
      std::istringstream linestream(line);
      while(linestream >> name >> score){
          int s = std::stoi(score);
          topScores[name] = s;
      }
    }
    /* if(!topScores.empty()){
      std::cout << "This dictionary is not empty. It has " << topScores.size() << " item." << std::endl;
      std::cout << "Name: " << topScores.begin()->first << " with Score: " << topScores.end()->second << std::endl;
    }
    else{std::cout << "The dictionary is empty." << std::endl;} */
  }
  scoreFile.close();
}

void Player::SetScore(int score){
  if(score >= 0){
    _score = score;
  }
}