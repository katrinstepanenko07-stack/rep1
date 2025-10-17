#include <iostream>

int main() {
    int const n = 3;
    int matrix[n][n];
    double free_terms[n];
    // std::cout << "введите коэфициенты при x, y, z в первом уравнении, потом во втором: " << std::endl;
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         std::cin >> matrix[i][j];
    //     }
    // }
    // std::cout << "Введите свободные члены в первом уравнении, потом во втором: " << std::endl;
    // for (int i = 0; i < n; ++i) {
    //     std::cin >> free_terms[i];
    // }

    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[0][2] = 1;
    free_terms[0] = 6;

    matrix[1][0] = 2;
    matrix[1][1] = -1;
    matrix[1][2] = 3;
    free_terms[1] = 14;

    matrix[2][0] = -1;
    matrix[2][1] = 4;
    matrix[2][2] = -1;
    free_terms[2] = 2;

    // Определители
    double det_main = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    double det_x = free_terms[0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (free_terms[1] * matrix[2][2] - matrix[1][2] * free_terms[2]) + matrix[0][2] * (free_terms[1] * matrix[2][1] - matrix[1][1] * free_terms[2]);
    double det_y = matrix[0][0] * (free_terms[1] * matrix[2][2] - matrix[1][2] * free_terms[2]) - free_terms[0] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])+ matrix[0][2] * (matrix[1][0] * free_terms[2] - free_terms[1] * matrix[2][0]);
    double det_z = matrix[0][0] * (matrix[1][1] * free_terms[2] - free_terms[1] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * free_terms[2] - free_terms[1] * matrix[2][0]) + free_terms[0] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    if (det_main == 0) {
        std::cout << "Система не имеет 1 решения (определитель - 0)." << std::endl;
        return 0;
    }

    double x = det_x / det_main;
    double y = det_y / det_main;
    double z = det_z / det_main;
    std::cout << "Решение системы уравнений:" << std::endl;
    std::cout << "x = " << x << std::endl; 
    std::cout << "y = " << y << std::endl; 
    std::cout << "z = " << z << std::endl;
    return 0;

}