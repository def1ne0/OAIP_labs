cd ..
for i in {1..5}; do
    g++ -std=c++23 -lgtest -fsanitize=address,leak,undefined ./tests/test_task_$i.cpp -o test_$i
    ./test_$i
    rm test_$i
done
