#include <iostream>

int main() {
    int age;
    std::cout << "Ведите возраст: ";
    std::cin >> age;
    if (18 <= age && age <= 60) {
        std::cout << "У Вас средний возраст (от 18 до 60)";
    } else if (age > 18) {
        std::cout << "У Вас пожилой возраст (более 60)" << std::endl;
    } else {
        std::cout << "У Вас юный возраст (до 18 лет)" << std::endl;
    }
}