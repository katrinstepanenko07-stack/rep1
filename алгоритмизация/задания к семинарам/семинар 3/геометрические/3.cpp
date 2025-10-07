#include <iostream>

int main() {
    int n = 3*2;
    double massiv[n], arr_x[n/2], arr_y[n/2];
    int count_x = 0, count_y = 0;
    std::cout << "Ваши координаты: " << std::endl;
    for (int i=0; i < n; i++) {
        std::cin >> massiv[i];
        if (i % 2 == 0) {
            arr_x[count_x] = massiv[i];
            count_x++;
        } else {
            arr_y[count_y] = massiv[i];
            count_y++;
        }
    }

    std::cout << "массив для x и y: ";
    for (int i=0; i<n; i++) {
        std::cout << massiv[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "массив для x: ";
    for (int i=0; i<n/2; i++) {
        std::cout << arr_x[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "массив для y: ";
    for (int i=0; i<n/2; i++) {
        std::cout << arr_y[i] << " ";
    }
    std::cout << std::endl;

    double c_x = 0, c_y = 0;
    c_x = (arr_x[0] + arr_x[1] + arr_x[2]) / 3;
    c_y = (arr_y[0] + arr_y[1] + arr_y[2]) / 3;
    std::cout << "Координаты центра масс треугольника: " << c_x << ", " << c_y << std::endl;
}
