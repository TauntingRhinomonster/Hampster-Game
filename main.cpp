#include "Pet.h"
#include <iostream>
#include <string>

void Pet::status() {
  std::cout << "\n--- " << _name << "'s Status ---" << std::endl;
  std::cout << "Hunger: " << _hunger << "/100" << std::endl;
  std::cout << "Thirst: " << _thirst << "/100" << std::endl;
  std::cout << "Happiness: " << _happiness << "/100" << std::endl;
}

void Pet::update() {
  _hunger += 5;
  _happiness -= 2;
  _thirst += 3;
}

int main() {
  Pet myPet;
  myPet.load();
  if (myPet.getName() == "") {
    std::string petName;
    std::cout << "Welcome to C++ Pets! Name your hamster: ";
    std::cin >> petName;
    myPet.setName(petName);
  }

  char choice;
  bool running = true;

  while (running) {
    myPet.status();

    if (!myPet.isAlive()) {
      std::cout << "\nRIP... " << myPet.getName() << " has passed away. :(" << std::endl;
      myPet.setName("");
      myPet.setHunger(50);
      myPet.setThirst(50);
      myPet.setHappiness(100);
      myPet.save();
      return 1;
    }

    std::cout << "\n(f)eed, (w)ater, (p)lay, or (q)uit: ";
    std::cin >> choice;

    if (choice == 'q') {
      myPet.save();
      running = false;
    } else if (choice == 'f') {
      myPet.feed();
    } else if (choice == 'w') {
      myPet.water();
    } else if (choice == 'p') {
      myPet.play();
    } else {
      myPet.animate();
      std::cout << "Invalid command! " << myPet.getName() << " looks confused." << std::endl;
    }

    myPet.update();
  }

  std::cout << "Goodbye!" << std::endl;
  return 0;
}