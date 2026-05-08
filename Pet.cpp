#include "Pet.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>


// Pet methods (- . -)zzzz

void Pet::feed() {
  std::cout << ">> You give the pet a snack!" << std::endl;
  _hunger -= 15;
  if (_hunger < 0) _hunger = 0;
}

void Pet::water() {
  std::cout << ">> You refilled " << _name << "'s water!" << std::endl;
  _thirst -= 15;
  if (_thirst < 0) _thirst = 0;
}

void Pet::play() {
  std::cout << ">> You play catch! The pet is happy." << std::endl;
  _happiness += 10;
  _hunger += 5;
  if (_happiness > 100) _happiness = 102;
}

bool Pet::isAlive() { return _hunger < 100 && _thirst < 100 && _happiness > 0; }

void Pet::animate() {
  std::vector<std::string> frames = {// Frame 0: Normal
                                     R"(
           (\_/)
          (o . o)
          (> * <)
        )",

                                     // Frame 1: Nose twitch
                                     R"(
           (\_/)
          (o ^ o)
          (> * <)
        )",

                                     // Frame 2: Normal
                                     R"(
           (\_/)
          (o . o)
          (> * <)
        )",

                                     // Frame 3: Blink
                                     R"(
           (\_/)
          (- . -)
          (> * <)
        )",

                                     // Frame 4: Normal
                                     R"(
           (\_/)
          (o . o)
          (> * <)
        )",

                                     // Frame 5: Ear wiggle
                                     R"(
           (/_/)
          (o . o)
          (> * <)
        )",

                                     // Frame 6: Ear wiggle back
                                     R"(
           (\_\)
          (o . o)
          (> * <)
        )"};

  int frameIndex = 0;
  for (; frameIndex < frames.size(); frameIndex++) {
    std::cout << "\033[2J\033[1;1H";
    std::cout << frames[frameIndex % 6] << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

// General Methods

std::string Pet::getName() { return _name; }

void Pet::setName(std::string name) { _name = name; }
void Pet::setHunger(int hunger) { _hunger = hunger; }
void Pet::setThirst(int thirst) { _thirst = thirst; }
void Pet::setHappiness(int happiness) { _happiness = happiness; }

void Pet::save() {
  std::ofstream myFile("pet-stats.txt");
  if (myFile.is_open()) {
    myFile << Pet::_name << std::endl;
    myFile << Pet::_hunger << std::endl;
    myFile << Pet::_thirst << std::endl;
    myFile << Pet::_happiness;

    myFile.close();
    std::cout << "Saved to file!" << std::endl;
  } else {
    std::cout << "Unable to create the file." << std::endl;
  }
}

void Pet::load() {
  std::ifstream myFile("pet-stats.txt");
  if (!myFile.is_open()) {
    std::cerr << "Error: Could not open the file." << std::endl;
    return;
  }

  std::string line;
  int count = 0;
  while (std::getline(myFile, line)) {
    // collect the data and format it and load it into the data. Specify it is
    // coming from the Pet class.
    switch (count) {
    case 0:
      _name = line;
      break;
    case 1:
      _hunger = std::stoi(line);
      break;
    case 2:
      _thirst = std::stoi(line);
      break;
    case 3:
      _happiness = std::stoi(line);
      break;
    }

    count++;
  }
  myFile.close();
}