#ifndef TASK_3_H
#define TASK_3_H

#include <expected>
#include <string>

namespace task_3 {
    std::expected<int, std::string> char_to_digit(char c);

    std::expected<char, std::string> digit_to_char(int digit);

    std::expected<int, std::string> compare(const std::string &a, const std::string b);

    std::expected<std::string, std::string> add_positive(const std::string &a, const std::string &b, int base);

    std::expected<std::string, std::string> subtract_positive(const std::string& a, const std::string& b, int base);

    std::expected<std::string, std::string> add(const std::string& a, const std::string& b, int base);

    std::expected<std::string, std::string> subtract(const std::string& a, const std::string& b, int base);

    void do_task3();
}

#endif // TASK_3_H
