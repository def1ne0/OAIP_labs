cd ..
g++ -std=c++23 -lgtest -fsanitize=address,leak,undefined ./tests/test_task_3.cpp -o test_3
./test_3
rm test_3
