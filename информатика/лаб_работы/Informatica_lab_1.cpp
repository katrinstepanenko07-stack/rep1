#include <iostream>

int main() 
{
    // задание 1
    {
        double toplivo;
        std::cout << "Ввведите объем топлива (в литрах): ";
        std::cin >> toplivo;

        if (toplivo > 50) {
            std::cout << "Топлива достаточно" << std::endl;
        } else if (20 <= toplivo && toplivo <= 50) {
            std::cout << "Рекомендуется заправка" << std::endl;
        } else if (toplivo < 50) {
            std::cout << "Топливо на исходе, срочно заправьтесь" << std::endl;
        }
    }
    //задание 2
    {
        double litr = 0;
        std::cout << "Введите количесво литров: " << std::endl;;
        while (litr >= 0) {
            std::cin >> litr;
            if (litr < 0) {
                std::cout << "Ошибка" << std::endl;
                break;
            }
            else if (std::cin.fail()) {
                std::cout << "Ошибка" << std::endl;
                break;
            }
            }
        }
}