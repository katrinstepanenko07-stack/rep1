#include <iostream>

int main() {
    int a, b;
    std::cout << "Ввведите длину: ";
    std::cin >> a;
    std::cout << "Ведите ширину: ";
    std::cin >> b;
    std::cout << "Площадь прямоугольника: " << a*b << std::endl;
}