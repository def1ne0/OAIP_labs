#include "MyStr.h"

#include <print>
#include <cstddef>
#include <cstring>
#include <stdexcept>

namespace str {
    MyStr::MyStr() {
        this->data = new char [1];
        this->capacity = 1;
        this->length = 0;

        data[0] = '\0';
    }

    MyStr::MyStr(char *c_str) {
        this->length = std::strlen(c_str);
        this->capacity = this->length + 1;
        this->data = new char [this->capacity];
        std::strcpy(this->data, c_str);
    }

    MyStr::~MyStr() {
        delete [] this->data;
        this->data = nullptr;
    }

   MyStr::MyStr(const MyStr &other) {
       this->length = other.length;
       this->capacity = other.capacity;

       if (other.data != nullptr) {
           this->data = new char [this->capacity];
           std::strcpy(this->data, other.data);
       } else {
           this->data = new char [1];
           this->data[0] = '\0';
       }
    }

    MyStr::MyStr(MyStr &&other) {
        this->length = other.length;
        this->capacity = other.capacity;
        this->data = other.data;

        other.data = nullptr;
    }

    void MyStr::resize(int new_size) {
        if (new_size <= 0) return;

        char *new_data = new char [new_size];

        if (this->data != nullptr) {
            std::strncpy(new_data, this->data, new_size - 1);
            new_data[new_size - 1] = '\0';
            delete [] this->data;
        } else {
            new_data[0] = '\0';
        }

        this->data = new_data;
        this->capacity = new_size;

        new_data = nullptr;
    }

    MyStr &MyStr::operator=(const MyStr &other) {
        if (this != &other) {
            delete [] this->data;

            this->length = other.length;
            this->capacity = other.capacity;
            this->data = new char [this->capacity];

            std::strcpy(this->data, other.data);
        }

        return *this;
    }

    MyStr &MyStr::operator=(MyStr &&other) {
        if (this != &other) {
            delete [] this->data;

            this->data = other.data;
            this->length = other.length;
            this->capacity = other.capacity;

            other.data = nullptr;
        }

        return *this;
    }

    char &MyStr::operator[](size_t index) {
        if (index >= this->length) throw std::out_of_range("индекс вышел за пределы MyStr");
        return data[index];
    }

    size_t MyStr::get_length() {
        return this->length;
    }

    size_t MyStr::get_capacity() {
        return this->capacity;
    }

    char *MyStr::get_c_str() {
        return this->data;
    }

    MyStr MyStr::get_cut_out_str(int start, int end) {
        if (start < 0 || end >= this->length || start > end) return MyStr();

        MyStr res;

        for (int i = start; i <= end; i++) {
            res.push_back((*this)[i]);
        }

        return res;
    }

    void MyStr::push_back(char element) {
        if (this->length >= this->capacity - 1) {
            this->resize(this->capacity == 0 ? 1 : this->capacity * 2);
        }

        this->data[this->length] = element;
        this->length++;
        this->data[this->length] = '\0';
    }

    void MyStr::pop_pack() {
        if (this->length > 0) {
            this->length--;
            this->data[this->length] = '\0';
        }
    }

    void MyStr::clear() {
        delete [] this->data;

        this->data = new char [1];
        this->data[0] = '\0';

        this->length = 0;
        this->capacity = 1;
    }



    void MyStr::execute_task_1(int k) {
        if (k >= this->length) {
            std::println("Первая подстрока: {}", this->data);
            std::println("Вторая подстрока: ");

            return;
        } else {
            int breakpoint = -1;

            for (int i = k; i >= 0; i--) {

                if ((*this)[i] == ' ') {

                    breakpoint = i;
                    break;
                }
            }

            if (breakpoint == -1) {
                std::println("Первая подстрока: ");
                std::println("Вторая подстрока: ");

                return;
            }

            std::println("Первая подстрока: {}", get_cut_out_str(0, breakpoint - 1).get_c_str());
            std::println("Вторая подстрока: {}", get_cut_out_str(breakpoint + 1, this->length - 1).get_c_str());
        }
    }
}
