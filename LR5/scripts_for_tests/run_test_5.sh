cd ..
g++ -std=c++23 -lgtest -fsanitize=address,leak,undefined ./tests/test_task_5.cpp -o test_5
./test_5
rm test_5
