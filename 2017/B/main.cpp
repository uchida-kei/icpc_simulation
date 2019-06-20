#include <iostream>

int main() {
    while (1) {
        std::string string[2];
        std::string string_const[2];
        std::getline(std::cin, string[0]);
        if (string[0] == ".") {
            break;
        }
        std::getline(std::cin, string[1]);


        if (string[0] == string[1]) {
            std::cout << "IDENTICAL" << std::endl;
            continue;
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < string[i].size(); j++) {
                if (string[i][j] == '"') {
                    j++;
                    while (string[i][j] != '"') {
                        string_const[i] += string[i][j];
                        string[i].erase(string[i].begin() + j);
                    }
                    string_const[i] += '|';
                }
            }
        }

        if (string[0] != string[1]) {
            std::cout << "DIFFERENT" << std::endl;
            continue;
        }

        int i0 = 0;
        int i1 = 0;
        int c_flag = 0;

        while (string_const[0][i0] != '\0' && string_const[1][i1] != '\0') {
            if (string_const[0][i0] != string_const[1][i1]) {
                c_flag++;
                if (c_flag > 1) {
                    break;
                }
                while (string_const[0][i0] != '|') {
                    i0++;
                }
                while (string_const[1][i1] != '|') {
                    i1++;
                }
            }
            i0++;
            i1++;
        }

        if (c_flag == 1) {
            std::cout << "CLOSE" << std::endl;
        } else {
            std::cout << "DIFFERENT" << std::endl;
        }
    }
    return 0;
}