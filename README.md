# Dependencies
g++
sudo apt install libsfml-dev

# How to compile
g++ -c main.cpp menger.cpp fractal.cpp

# How to link
g++ main.o menger.o fractal.o -o fractals -lsfml-graphics -lsfml-window -lsfml-system

# Compile, link and run
g++ -c main.cpp menger.cpp fractal.cpp &&
g++ main.o menger.o fractal.o -o fractals -lsfml-graphics -lsfml-window -lsfml-system &&
 ./fractals