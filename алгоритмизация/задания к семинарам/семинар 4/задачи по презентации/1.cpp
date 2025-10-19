#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int a = 3;
    const int b = 3;
    double matrix[a][b];
    cout << "Введите элементы матрицы 3x3:" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> matrix[i][j];
        }
    }
    double x1 = matrix[0][0];
    double y1 = matrix[0][1];
    double x2 = matrix[1][0];
    double y2 = matrix[1][1];
    double x3 = matrix[2][0];
    double y3 = matrix[2][1];
    matrix[0][2] = 1;
    matrix[1][2] = 1;
    matrix[2][2] = 1;
    double d = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    double area = 0.5 * fabs(d);
    cout << "Площадь треугольника: " << area << endl;
    return 0;
}