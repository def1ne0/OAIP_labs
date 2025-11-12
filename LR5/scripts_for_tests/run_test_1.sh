cd ..
g++ -std=c++23 -lgtest -fsanitize=address,leak,undefined ./tests/test_task_1.cpp -o test_1
./test_1
rm test_1
