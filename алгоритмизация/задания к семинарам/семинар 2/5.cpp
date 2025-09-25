#include <iostream>

int main() {
    int n;
    std::cout << "Введите число: ";
    std:: cin >> n;
    if ( n % 5 == 0 && n % 3 == 0) {
        std::cout << "число делится и на 3, и на 5)" << std::endl;
    } else if (n % 5 == 0) {
        std::cout << "число делится только на 5" << std::endl;
    } else if (n % 3 == 0) {
        std::cout << "число делится только на 3" << std::endl;
    } else {
        std::cout << "число не делится НИ на 3, НИ на 5(" << std::endl;
    }
}
