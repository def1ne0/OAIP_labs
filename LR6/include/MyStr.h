#pragma once

#include <cstddef>

namespace str {
    class MyStr {
        private:
            char *data;
            size_t length;
            size_t capacity;
        public:
            MyStr();
            MyStr(char *c_str);
            ~MyStr();

            MyStr(const MyStr &other);
            MyStr(MyStr &&other);

            MyStr &operator=(const MyStr &other);
            MyStr &operator=(MyStr &&other);
            char &operator[](size_t index);

            void resize(int new_size);

            size_t get_length();
            size_t get_capacity();
            char *get_c_str();
            MyStr get_cut_out_str(int start, int end);

            void push_back(char element);
            void pop_pack();
            void clear();

            void execute_task_1(int k);
    };
}
