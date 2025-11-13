cd ..
g++ -std=c++23 -lgtest -fsanitize=address,leak,undefined ./tests/test_task_4.cpp -o test_4
./test_4
rm test_4
