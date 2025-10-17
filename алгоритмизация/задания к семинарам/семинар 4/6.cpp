#include <iostream>

int main() {
    int const n = 2;
    int matrix[n][n];
    double free_terms[n];
    // std::cout << "введите коэфициенты при x и y в первом уравнении, потом во втором: " << std::endl;
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         std::cin >> matrix[i][j];
    //     }
    // }
    // std::cout << "Введите свободные члены в первом уравнении, потом во втором: " << std::endl;
    // for (int i = 0; i < n; ++i) {
    //     std::cin >> free_terms[i];
    // }

    matrix[0][0] = 2;
    matrix[0][1] = 3;
    free_terms[0] = 13;

    matrix[1][0] = 5;
    matrix[1][1] = -1;
    free_terms[1] = 9;


    // Определители
    double det_main = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    double det_x = (free_terms[0] * matrix[1][1]) - (matrix[0][1] * free_terms[1]);
    double det_y = (matrix[0][0] * free_terms[1]) - (free_terms[0] * matrix[1][0]);

    if (det_main == 0) {
        std::cout << "Система не имеет 1 решения (определитель - 0)." << std::endl;
        return 0;
    }

    double x = det_x / det_main;
    double y = det_y / det_main;
    std::cout << "Решение системы уравнений:" << std::endl;
    std::cout << "x = " << x << std::endl; 
    std::cout << "y = " << y << std::endl; 
    return 0;

}