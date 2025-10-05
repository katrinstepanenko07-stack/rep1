#include <iostream>

int main() {
    int n = 6;
    double massiv[n], arr_x[n/2], arr_y[n/2];
    int count_x = 0, count_y = 0;
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

    double s = 0;
    double f, f1, f2, f3;
    f1 = arr_x[0] * (arr_y[1] - arr_y[2]);
    f2 = arr_x[1] * (arr_y[2] - arr_y[0]);
    f3 = arr_x[2] * (arr_y[0] - arr_y[1]);
    f = f1 + f2 + f3;
    s = 0.5 * abs(f);
    std::cout << "Площадь тругольникка: " << s << std::endl;
}