# CLI_Pet
A pet hampster game where it needs to be fed, watered, and played with. Sometimes, he just runs away. Sometimes he just dies. This is the Lore Accurate Hampster Game.

## Instructions for Build and Use

Steps to build and/or run the software:

1. You need to download a C++ complier to actually be able to run the code!
2. You need some kind of shell to run the program in.
3. In your shell you will need to first build the software and then run it as though you were debugging it.

Instructions for using the software:

1. Open up PowerShell
2. Run: `cmake --build build; .\build\Debug\CLIPet.exe`
    - You are essentially telling it to build the file and then you are just pasting the path to the Debug folder.
3. Play the game.

## Development Environment

To recreate the development environment, you need the following software and/or libraries with the specified versions:

* I downloaded Visual Studio 2019 since it comes with a C++ complier. Any C++ complier will work though.
* You will **absolutely** need CMake to run this code. You can get the extension from VS Code's extensions.
* I ran all of my code using Cursor's terminal (Visual Studio Code also works).

## Useful Websites to Learn More

I found these websites useful in developing this software:

* [w3schools](https://www.w3schools.com/cpp/default.asp)
* [cplusplus](https://cplusplus.com/doc/tutorial/)
* [YouTube](https://www.youtube.com/playlist?list=PLGLfVvz_LVvQ9S8YSV0iDsuEU8v11yP9M)

## Future Work

The following items I plan to fix, improve, and/or add to this project in the future:

* [ ] Add interactive feeding games so that it is more than just pressing f or w to feed or water your hampster.
* [ ] Add better ASCII animations for the hampster.
* [ ] Add random events that happen over time that effect the lifespan of your hampster like a sudden lightning strike that may damage your hampster's health which would mean that you need to heal him.