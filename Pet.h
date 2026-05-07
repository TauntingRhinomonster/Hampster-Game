#pragma once
#include <string>
#include <vector>

class Pet {
public:
  Pet(std::string name) { _name = name; }
  Pet() { _name = ""; }

  void feed();
  void water();
  void play();
  void update();
  void status();
  bool isAlive();
  void animate();
  std::string getName();
  void setName(std::string);
  void save();
  void load();

private:
  std::string _name;
  int _hunger = 50;
  int _thirst = 50;
  int _happiness = 100;
};