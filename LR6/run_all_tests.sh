for i in {1..3}; do
    g++ -std=c++23 -lgtest -fsanitize=address,leak,undefined -I./include ./src/MyStr.cpp ./tests/test_task_$i.cpp -o test_$i
    ./test_$i
    rm test_$i
done
