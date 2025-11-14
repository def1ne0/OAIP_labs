export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
g++ -std=c++23 -fsanitize=address,leak,undefined -I./include ./src/*.cpp main.cpp  -L./lib -ltask_1 -ltask_2 -o main
./main
rm ./main
