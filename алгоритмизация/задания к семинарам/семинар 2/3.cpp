#include <iostream>

int main() {
    double temp_c;
    std::cout << "По Цельсию: ";
    std::cin >> temp_c;
    double tem_f = temp_c * 9 / 5 + 32;
    std::cout << "По Фаренгейту: " << tem_f << std::endl;

}