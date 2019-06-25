#include <iostream>
#include <complex>

int main() {
    while (1) {
        int b;
        std::cin >> b;

        if (b == 0) {
            break;
        }

        int a, n;
        int max = 0;

        for (int i = 1; std::sqrt(2 * b) > i; i++) {
            if (((2 * b) % i) == 0) {
                if ((((2 * b) / i - i + 1) % 2) == 0) {
                    max = std::max(max, [=]() {
                        if (((2 * b / i - i + 1) / 2) >= 0) {
                            return i;
                        } else {
                            return 0;
                        }
                    }());
                }
            }
        }

        n = max;
        a = (2 * b / n - n + 1) / 2;

        std::cout << a << " " << n << std::endl;
    }

    return 0;
}