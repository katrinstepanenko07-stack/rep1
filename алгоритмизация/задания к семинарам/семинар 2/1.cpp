// сдать до 26.09

#include <iostream>

int main() {
    int s;
    std::cout << "Сантиметры: ";
    std::cin >> s;
    int metr = s / 100;
    int ost_s = s % 100;
    std::cout << "Полные метры: " << metr << ", оставшиеся сантиметры: " << ost_s << std::endl;
}