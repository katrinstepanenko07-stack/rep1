#include <iostream>
#include <algorithm>
#include <cmath>

int rotate(double x1, double y1, double x2, double y2, double x3, double y3) {
    double opr = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1);
    if (opr > 0) return 1;
    if (opr < 0) return -1;
    return 0;
}

bool naotrezke(double x1, double y1, double qx, double qy, double x2, double y2) {
    return (qx >= std::min(x1,x2) && qx <= std::max(x1,x2)) &&
           (qy >= std::min(y1,y2) && qy <= std::max(y1,y2));
}

bool perecex(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4) {
    int o1 = rotate(x1,y1, x2,y2, x3,y3);
    int o2 = rotate(x1,y1, x2,y2, x4,y4);
    int o3 = rotate(x3,y3, x4,y4, x1,y1);
    int o4 = rotate(x3,y3, x4,y4, x2,y2);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && naotrezke(x1,y1, x3,y3, x2,y2)) return true;
    if (o2 == 0 && naotrezke(x1,y1, x4,y4, x2,y2)) return true;
    if (o3 == 0 && naotrezke(x3,y3, x1,y1, x4,y4)) return true;
    if (o4 == 0 && naotrezke(x3,y3, x2,y2, x4,y4)) return true;

    return false;
}

bool polygonsIntersect(double poly1[][2], int n1, double poly2[][2], int n2) {
    for (int i = 0; i < n1; ++i) {
        double x1 = poly1[i][0], y1 = poly1[i][1];
        double x2 = poly1[(i+1)%n1][0], y2 = poly1[(i+1)%n1][1];
        for (int j = 0; j < n2; ++j) {
            double x3 = poly2[j][0], y3 = poly2[j][1];
            double x4 = poly2[(j+1)%n2][0], y4 = poly2[(j+1)%n2][1];
            if (perecex(x1,y1,x2,y2,x3,y3,x4,y4)) return true;
        }
    }
    return false;
}

int main() {
    int n1, n2;
    std::cout << "Введите количество вершин первого многоугольника: ";
    std::cin >> n1;
    double poly1[n1][2];
    std::cout << "Введите координаты вершин первого многоугольника x y:\n";
    for (int i = 0; i < n1; ++i) std::cin >> poly1[i][0] >> poly1[i][1];

    std::cout << "Введите количество вершин второго многоугольника: ";
    std::cin >> n2;
    double poly2[n2][2];
    std::cout << "Введите координаты вершин второго многоугольника x y:\n";
    for (int i = 0; i < n2; ++i) std::cin >> poly2[i][0] >> poly2[i][1];

    if (polygonsIntersect(poly1, n1, poly2, n2))
        std::cout << "Многоугольники пересекаются\n";
    else
        std::cout << "Многоугольники не пересекаются\n";

    return 0;
}
