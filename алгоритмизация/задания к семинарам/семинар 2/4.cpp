#include <iostream>

int main() {
    int n;
    std::cout << "Целое число: ";
    std::cin >> n;
    if (n % 2 == 1) {
        std::cout << "Число нечетное" << std::endl;
    } else {
        std::cout << "Число четное" << std::endl;
    }
}