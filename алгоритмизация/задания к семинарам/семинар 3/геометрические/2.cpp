#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cout << "Введите колич вершин: ";
    std::cin >> n;
    if (n < 3) {
        std::cout << "Нельзя построить многоугольник";
        return 0;
    }
    std::cout << "Введите координаты: " << std::endl;
    double massiv[n+n], arr_x[n], arr_y[n];
    int count_x = 0, count_y = 0;
    for (int i=0; i < n+n; i++) {
        std::cin >> massiv[i];
        if (i % 2 == 0) {
            arr_x[count_x] = massiv[i];
            count_x++;
        } else if (i % 2 == 1) {
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

    double summa_d = 0;
    for (int i = 0; i<n-1; i++) {
        double tek_d = 0;
        tek_d += pow((pow(abs(arr_x[i+1] - arr_x[i]), 2) + pow(abs(arr_y[i+1] - arr_y[i]), 2)), 0.5);
        std::cout << i+1 << " сторона) " << tek_d << std::endl;
        summa_d += tek_d;
    }

    double ost = 0;
    ost = pow((pow(abs(arr_x[0] - arr_x[n-1]), 2) + pow(abs(arr_y[0] - arr_y[n-1]), 2)), 0.5);
    std::cout << n << " сторона) " << ost << std::endl;
    summa_d += ost;

    std::cout << "Периметр вашего многоугольника: " << summa_d << std::endl;
}
