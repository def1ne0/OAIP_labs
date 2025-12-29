#pragma once

#include <istream>
#include <optional>

namespace str {
    class MyStr {
        char *data_;
        size_t length_;
        size_t capacity_;

        void resize(size_t new_size);
    public:
        MyStr();
        explicit MyStr(char *c_str);
        ~MyStr() noexcept;

        MyStr(const MyStr &other);
        MyStr(MyStr &&other) noexcept;

        MyStr &operator = (const MyStr &other);
        MyStr &operator = (MyStr &&other) noexcept;
        char &operator [] (size_t index) const;
        MyStr &operator += (const MyStr &other);
        MyStr &operator += (char *other);

        static size_t c_str_length(const char *c_str);

        [[nodiscard]] size_t length() const;
        [[nodiscard]] size_t capacity() const;
        [[nodiscard]] const char *c_str() const; // НЕ ДЕЛИТАЙ ПАМЯТЬ, ТОКА ДЛЯ ВЫВОДА
        [[nodiscard]] MyStr cut_out_str(int start, int end) const;
        [[nodiscard]] std::optional<int> to_unsigned_int() const;


        void input_by_getchar();
        void push_back(char element);
        void concat(const MyStr &other);
        void concat(char *other_str);
        void pop();
        void clear();
    };

    std::istream &operator >> (std::istream &in, MyStr &input);
}
