#pragma once
#include <string>

class Pet {
    public:
        Pet(std::string name);

        void feed();
        void play();
        void update();
        void status();
        bool isAlive();
    
    private:
        std::string _name;
        int _hunger;
        int _happiness;
};