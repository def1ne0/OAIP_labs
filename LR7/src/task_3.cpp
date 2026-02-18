#include <expected>
#include <print>
#include <string>

#include "task_3.h"
#include "check_cin.h"

namespace task_3 {
    std::expected<int, std::string> char_to_digit(char c) {
        if (c >= '0' && c <= '9') {
            return c - '0';
        } else if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 10;
        } else if (c >= 'a' && c <= 'z') {
            return c - 'a' + 10;
        } else {
            return std::unexpected<std::string>("Символ не входит в диапазон от [A; Z], [a; z], [0; 9]");
        }
    }

    std::expected<char, std::string> digit_to_char(int digit) {
        if (digit >= 0 && digit <= 9) {
            return digit + '0';
        } else if (digit >= 10 && digit <= 35) {
            return 'A' + (digit - 10);
        } else {
            return std::unexpected<std::string>("Цифра вне диапазона [0; 35] " + std::to_string(digit));
        }
    }

    std::expected<int, std::string> compare(const std::string &a, const std::string b) { // a < b => -1, a == b => 0, a > b => 1
        bool negA = false;
        bool negB = false;
        std::string absA = a;
        std::string absB = b;

        if (a[0] == '-') {
            negA = true;
            absA = a.substr(1);
        }

        if (b[0] == '-') {
            negB = true;
            absB = b.substr(1);
        }

        if (negA != negB) {
            if (negA) return -1;

            return 1;
        }

        size_t lenA = absA.length();
        size_t lenB = absB.length();

        if (lenA != lenB) {
            if (negA) {
                return (lenA > lenB) ? -1 : 1;
            } else {
                return (lenA > lenB) ? 1 : -1;
            }
        }

        for (size_t i = 0; i < lenA; i++) {
            auto num_a = char_to_digit(absA[i]);
            auto num_b = char_to_digit(absB[i]);

            if (num_a.has_value() && num_b.has_value()) {
                if (num_a != num_b) {
                    if (negA) {
                        return (num_a.value() > num_b.value()) ? -1 : 1;
                    } else {
                        return (num_a.value() > num_b.value()) ? 1 : -1;
                    }
                }
            } else {
                return std::unexpected<std::string>("Ошибка в char_to_digit");
            }
        }

        return 0;
    }

    std::expected<std::string, std::string> add_positive(const std::string &a, const std::string &b, int base) {
        std::string result = "";
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

         while (i >= 0 || j >= 0 || carry) {
            auto digitA = (i >= 0) ? char_to_digit(a[i]) : std::expected<int, std::string>(0);
            auto digitB = (j >= 0) ? char_to_digit(b[j]) : std::expected<int, std::string>(0);

            if (!(digitA.has_value() && digitB.has_value())) {
                return std::unexpected<std::string>("Ошибка в char_to_digit");
            }

            int sum = digitA.value() + digitB.value() + carry;
            carry = sum / base;
            int digit = sum % base;

            auto char_digit = digit_to_char(digit);

            if (!char_digit.has_value()) {
                return char_digit.error();
            }

            result = char_digit.value() + result;

            if (i >= 0) --i;
            if (j >= 0) --j;
        }

        return result;
    }

    std::expected<std::string, std::string> subtract_positive(const std::string& a, const std::string& b, int base) {
        std::string result = "";
        int borrow = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0) {
            auto digitA = (i >= 0) ? char_to_digit(a[i]) : std::expected<int, std::string>(0);
            auto digitB = (j >= 0) ? char_to_digit(b[j]) : std::expected<int, std::string>(0);

            if (!(digitA.has_value() && digitB.has_value())) {
                return std::unexpected<std::string>("Ошибка в char_to_digit");
            }

            int diff = digitA.value() - digitB.value() - borrow;

            if (diff < 0) {
                diff += base;
                borrow = 1;
            } else {
                borrow = 0;
            }

            auto char_diff = digit_to_char(diff);

            if (!char_diff.has_value()) {
                return char_diff.error();
            }

            result = char_diff.value() + result;

            if (i >= 0) --i;
            if (j >= 0) --j;
        }

        return result;
    }

    std::expected<std::string, std::string> add(const std::string& a, const std::string& b, int base) {
        bool negA = (a[0] == '-');
        bool negB = (b[0] == '-');

        std::string absA = negA ? a.substr(1) : a;
        std::string absB = negB ? b.substr(1) : b;

        if (!negA && !negB) { // positive + positive
            return add_positive(absA, absB, base);
        } else if (negA && negB) { // negative + negative
            auto sum = add_positive(absA, absB, base);

            if (sum.has_value()) {
                return "-" + sum.value();
            } else {
                return sum.error();
            }
        } else { // positive + negative || negative + positive
            auto cmp = compare(absA, absB);

            if (!cmp.has_value()) return cmp.error();

            if (cmp == 0) return "0";
            if (cmp.value() > 0) { // |a| > |b|
                auto diff = subtract_positive(absA, absB, base);

                if (diff.has_value()) {
                    return negA ? "-" + diff.value() : diff;
                } else {
                    return diff.error();
                }
            } else { // |a| < |b|
                auto diff = subtract_positive(absB, absA, base);

                if (diff.has_value()) {
                    return negB ? "-" + diff.value() : diff;
                } else {
                    return diff.error();
                }
            }
        }
    }

    std::expected<std::string, std::string> subtract(const std::string& a, const std::string& b, int base) {
        // a - b = a + (-b)
        std::string negB = (b[0] == '-') ? b.substr(1) : "-" + b;
        return add(a, negB, base);
    }

    void do_task3() {
        int base = io::input_value<int>("Введите основание системы счисления (от 2 до 36)", "Ошибка", true, 2, 36);

        std::string a = io::input_value<std::string>("Введите а");
        std::string b = io::input_value<std::string>("Введите b");

        auto sum = add(a, b, base);
        auto sub = subtract(a, b, base);

        if (sum.has_value() && sub.has_value()) {
            std::println("a + b: {} \na - b: {}", sum.value(), sub.value());
        } else {
            std::println("Ошибка");
        }

        return;
    }
}
