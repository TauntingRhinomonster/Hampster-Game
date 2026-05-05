#include <iostream>
#include <string>
#include "Pet.h"

Pet::Pet(std::string name) : _name(name), _hunger(50), _happiness(50) {}

void Pet::status() {
  std::cout << "\n--- " << _name << "'s Status ---" << std::endl;
  std::cout << "Hunger: " << _hunger << "/100" << std::endl;
  std::cout << "Happiness: " << _happiness << "/100" << std::endl;
}

void Pet::update() {
  _hunger += 5;
  _happiness -= 2;
}

int main() {
  std::string petName;
  std::cout << "Welcome to C++ Pets! Name your pet: ";
  std::cin >> petName;

  Pet myPet(petName);

  char choice;
  bool running = true;

  while (running) {
    myPet.status();

    if (!myPet.isAlive()) {
      std::cout << "\nRIP... " << petName << " has passed away. :(" << std::endl;
      return 1;
    }

    std::cout << "\n(f)eed, (p)lay, or (q)uit: ";
    std::cin >> choice;

    if (choice == 'q') {
      std::cout << "Saving pet data... Goodbye!" << std::endl;
      running = false;
    }
    else if (choice == 'f') {
      myPet.feed();
    }
    else if (choice == 'p') {
      myPet.play();
    }
    else {
      std::cout << "Invalid command! Your pet looks confused." << std::endl;
    }

    myPet.update();
  }

  std::cout << "Goodbye!" << std::endl;
  return 0;
}