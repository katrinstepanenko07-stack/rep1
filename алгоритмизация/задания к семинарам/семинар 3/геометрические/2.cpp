#include <iostream>

int main() {
    int n;
    std::cout << "Введите колич вершин: ";
    std::cin >> n;
    std::cout << "Введите координаты: " << std::endl;
    double massiv[n*2], arr_x[n/2], arr_y[n/2];
    int count_x = 0, count_y = 0;
    for (int i=0; i < n*2; i++) {
        std::cin >> massiv[i];
        if (i % 2 == 0) {
            arr_x[count_x] = massiv[i];
            count_x++;
        } else {
            arr_y[count_y] = massiv[i];
            count_y++;
        }
    }
    
    std::cout << "Ваш массив: ";
    for (int i=0; i<n*2; i++) {
        std::cout << massiv[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "массив для x: ";
    for (int i=0; i<n; i++) {
        std::cout << arr_x[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "массив для y: ";
    for (int i=0; i<n; i++) {
        std::cout << arr_y[i] << " ";
    }
    std::cout << std::endl;
}