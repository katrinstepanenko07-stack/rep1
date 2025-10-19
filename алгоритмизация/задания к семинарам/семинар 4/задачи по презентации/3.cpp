#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int rows = 3;
    const int cols = 3;
    double matrix[rows][cols];
    std::cout << "Для каждой из трех точек введите координаты (x y)." << std::endl;
    for (int i = 0; i < rows; i++) {
        cin >> matrix[i][0] >> matrix[i][1]; // Считываем x и y
        matrix[i][2] = 1.0;
    }
    double d = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    if (d == 0) {
        cout << "Точки A, B, C коллинеарны (лежат на одной прямой)." << endl;
    } else {
        cout << "Точки A, B, C не коллинеарны (не лежат на одной прямой)." << endl;
    }
    
    return 0;
}