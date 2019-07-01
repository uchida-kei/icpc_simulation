#include <iostream>
#include <complex>

int main() {
    while (1) {
        int b;
        std::cin >> b;

        if (b == 0) {
            break;
        }

        for (int n = (int) std::sqrt(2 * b); n > 0; n--) {
            auto a = [&]() { return (2 * b / n - n + 1) / 2; };

            auto is_2b_divisor_n = [&]() { return !(2 * b % n); };
            auto is_a_integer = [&]() { return !(2 * b / n - n + 1 & 1); };

            auto is_answer = [&]() { return is_2b_divisor_n() && is_a_integer(); };

            if (is_answer()) {
                std::cout << a() << " " << n << std::endl;
                break;
            }
        }
    }
    return 0;
}