cd ..
g++ -std=c++23 -lgtest -fsanitize=address,leak,undefined ./tests/test_task_2.cpp -o test_2
./test_2
rm test_2
