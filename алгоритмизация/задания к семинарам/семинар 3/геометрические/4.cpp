#include <iostream>

int main() {
    int n = 4*2;
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

    double max_d = 0;
    double tek_d1 = pow((pow(abs(arr_x[0] - arr_x[1]), 2) + pow(abs(arr_y[0] - arr_y[1]), 2)), 0.5);
    double tek_d2 = pow((pow(abs(arr_x[0] - arr_x[2]), 2) + pow(abs(arr_y[0] - arr_y[2]), 2)), 0.5);
    double tek_d3 = pow((pow(abs(arr_x[0] - arr_x[3]), 2) + pow(abs(arr_y[0] - arr_y[3]), 2)), 0.5);
    double tek_d4 = pow((pow(abs(arr_x[1] - arr_x[2]), 2) + pow(abs(arr_y[1] - arr_y[2]), 2)), 0.5);
    double tek_d5 = pow((pow(abs(arr_x[1] - arr_x[3]), 2) + pow(abs(arr_y[1] - arr_y[3]), 2)), 0.5);
    double tek_d6 = pow((pow(abs(arr_x[2] - arr_x[3]), 2) + pow(abs(arr_y[2] - arr_y[3]), 2)), 0.5);

    double massiv2[6] = {tek_d1, tek_d2, tek_d3, tek_d4, tek_d5, tek_d6};
    for (int i=0; i < n; i++) {
        if (massiv2[i] > max_d) {
            max_d = massiv2[i];
        }
    }
    std::cout << "Диагональ: " << max_d << std::endl;
}
