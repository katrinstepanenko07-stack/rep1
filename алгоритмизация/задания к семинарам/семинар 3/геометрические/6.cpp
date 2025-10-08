#include <iostream>
#include <cmath>

int rotate(int x1, int y1, int x2, int y2, int x3, int y3) {
    int opr = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (opr > 0) return 1;   
    if (opr < 0) return -1;
    return 0;
}

bool naotrezke(int x1, int y1, int qx, int qy, int x2, int y2) {
    return ( (x1 <= qx && qx <= x2) || (x2 <= qx && qx <= x1) ) && ( (y1 <= qy && qy <= y2) || (y2 <= qy && qy <= y1) );
}

bool perecek(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) {
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

int main() {
    int n = 4*2;
    double massiv[n], arr_x[n/2], arr_y[n/2];
    int count_x = 0, count_y = 0;
    std::cout << "Ваши координаты: " << std::endl;
    for (int i=0; i < n; i++) {
        if (i == 0) {
            std::cout << "A: " << std::endl;
        } else if (i == 2) {
            std::cout << "B: " << std::endl;
        } else if (i == 4) {
            std::cout << "C: " << std::endl;
        } else if (i == 6) {
            std::cout << "D: " << std::endl;
        }
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

    // Проверка, лежит ли точка c или d на отрезке 
    double ab_ac = (arr_x[1] - arr_x[0]) * (arr_y[2] - arr_y[0]) - (arr_y[1] - arr_y[0]) * (arr_x[2] - arr_x[0]);
    if (ab_ac == 0) {
        std::cout << "точка с лежит на прямой!" << std::endl;
    } else {
        std::cout << "точка с НЕ лежит на прямой!" << std::endl;
    }
    
    double ab_ad = (arr_x[1] - arr_x[0]) * (arr_y[3] - arr_y[0]) - (arr_y[1] - arr_y[0]) * (arr_x[3] - arr_x[0]);
    if (ab_ad == 0) {
        std::cout << "точка d лежит на прямой!" << std::endl;
    } else {
        std::cout << "точка d НЕ лежит на прямой!" << std::endl;
    }
    

    if (perecek(x1, y1, x2, y2, x3, y3, x4, y4)) {
        std::cout << "ИТОГО: Отрезки пересекаются.";
    } 
    else {
        std::cout << "ИТОГО: Отрезки не пересекаются.";
    }
    return 0;

}
