#include <iostream>
#include <cstring>
#include <cctype>

bool palindrom(char* stroka) {
    int len = strlen(stroka);
    int left = 0;
    int right = len - 1;

    while (left < right) {
        while (left < len && std::isspace(stroka[left])) {
            left++;
        }
        while (right >= 0 && std::isspace(stroka[right])) {
            right--;
        }

        if (tolower(stroka[left]) != tolower(stroka[right])) {
            return false;
        }

        left++;
        right--;
    }
    return true;
}

int main() {
    int const n = 100;
    char str[n];
    std::cout << "Введите строку: \n";
    std::cin.getline(str, n);
    
    if (palindrom(str)) {
        std::cout << "Это палиндром." << std::endl;
    } else {
        std::cout << "Это не палиндром." << std::endl;
    }
    return 0;
}