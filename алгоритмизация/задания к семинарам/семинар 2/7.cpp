#include <iostream>

int main() {
    double n;
    std::cout << "Введите число: ";
    std::cin >> n;
    std::cout << "Квадраты: ";
    for (int i=1; i<=n; i++) {
        std::cout << i*i << " ";
    }
}