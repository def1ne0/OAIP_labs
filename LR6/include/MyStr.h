#pragma once

#include <iostream>
#include <cstddef>
#include <istream>

namespace str {
    class MyStr {
        char *data_;
        size_t length_;
        size_t capacity_;

        void resize(int new_size);
    public:
        MyStr();
        MyStr(char *c_str);
        ~MyStr() noexcept;

        MyStr(const MyStr &other);
        MyStr(MyStr &&other) noexcept;

        MyStr &operator = (const MyStr &other);
        MyStr &operator = (MyStr &&other) noexcept;
        char &operator [] (size_t index);
        MyStr &operator += (const MyStr &other);
        MyStr &operator += (char *other);

        size_t c_str_length(char *c_str) const;

        size_t length() const;
        size_t capacity() const;
        const char *c_str() const; // НЕ ДЕЛИТАЙ ПАМЯТЬ, ТОКА ДЛЯ ВЫВОДА
        MyStr cut_out_str(int start, int end) const;


        void input_by_getchar();
        void push_back(char element);
        void concat(const MyStr &other);
        void concat(char *other_str);
        void pop();
        void clear();
    };

    std::istream &operator >> (std::istream &in, MyStr &input);
}
