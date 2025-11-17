#include "MyStr.h"

#include <cstddef>
#include <cstring>
#include <stdexcept>

namespace str {
    void MyStr::resize(int new_size) {
        if (new_size <= 0) return;

        char *new_data = new char [new_size];

        if (data_ != nullptr) {
            std::copy(data_, data_ + length_, new_data);
            new_data[new_size - 1] = '\0';

            delete [] data_;
        } else {
            new_data[0] = '\0';
        }

        data_ = new_data;
        capacity_ = new_size;

        new_data = nullptr;
    }

    MyStr::MyStr()
        : data_(new char [1]), length_(0), capacity_(1){

        data_[0] = '\0';
    }

    MyStr::MyStr(char *c_str) {
        if (c_str == nullptr) {
            data_ = new char [1];
            data_[0] = '\0';
            length_ = 0;
            capacity_ = 1;
        } else {
            length_ = c_str_length(c_str);
            capacity_ = length_ + 1;
            data_ = new char [capacity_];

            std::copy(c_str, c_str + length_, data_);
        }
    }

    MyStr::~MyStr() noexcept {
        delete [] data_;
        data_ = nullptr;
    }

   MyStr::MyStr(const MyStr &other)
        : data_(nullptr), length_(other.length_), capacity_(other.capacity_) {
       if (other.data_ != nullptr) {
           data_ = new char [capacity_];
           std::copy(other.data_, other.data_ + length_, data_);
       } else {
           data_ = new char [1];
           data_[0] = '\0';
       }
    }

    MyStr::MyStr(MyStr &&other) noexcept
        : data_(other.data_), length_(other.length_), capacity_(other.capacity_) {

        other.data_ = nullptr;
    }

    size_t MyStr::c_str_length(char *c_str) const {
        size_t length = 0;

        for (unsigned i = 0; c_str[i] != '\0'; i++) {
            length++;
        }

        return length;
    }


    MyStr &MyStr::operator=(const MyStr &other) {
        if (this != &other) {
            delete [] data_;

            length_ = other.length_;
            capacity_ = other.capacity_;
            data_ = new char [capacity_];

            std::copy(other.data_, other.data_ + length_, data_);
        }

        return *this;
    }

    MyStr &MyStr::operator=(MyStr &&other) noexcept {
        if (this != &other) {
            delete [] data_;

            data_ = other.data_;
            length_ = other.length_;
            capacity_ = other.capacity_;

            other.data_ = nullptr;
        }

        return *this;
    }

    const char &MyStr::operator[](size_t index) const {
        if (index >= length_) throw std::out_of_range("индекс вышел за пределы MyStr");
        return data_[index];
    }

    size_t MyStr::length() const {
        return length_;
    }

    size_t MyStr::capacity() const {
        return capacity_;
    }

    char *MyStr::c_str() const {
        return data_;
    }

    MyStr MyStr::cut_out_str(int start, int end) const {
        if (start < 0 || end >= length_ || start > end) return MyStr();

        MyStr res;

        for (int i = start; i <= end; i++) {
            res.push_back((*this)[i]);
        }

        return res;
    }

    void MyStr::push_back(char element) {
        if (length_ >= capacity_ - 1) {
            this->resize(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        data_[length_] = element;
        length_++;
        data_[length_] = '\0';
    }

    void MyStr::pop() {
        if (length_ > 0) {
            length_--;
            data_[length_] = '\0';
        }
    }

    void MyStr::clear() {
        delete [] data_;

        data_ = new char [1];
        data_[0] = '\0';

        length_ = 0;
        capacity_ = 1;
    }
}
