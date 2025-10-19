#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, theta;
    cout << "Введите координаты точки (x y): ";
    cin >> x >> y;
    cout << "Введите угол поворота в градусах: ";
    cin >> theta;
    double radians = theta * M_PI / 180.0;

    double rotation_matrix[2][2] = {
        {cos(radians), sin(radians)},
        {-sin(radians), cos(radians)}
    };

    double point[2] = {x, y};
    double result[2];

    result[0] = rotation_matrix[0][0] * point[0] + rotation_matrix[0][1] * point[1];
    result[1] = rotation_matrix[1][0] * point[0] + rotation_matrix[1][1] * point[1];

    cout << "Новые координаты точки: (" << result[0] << ", " << result[1] << ")" << endl;
    return 0;
}