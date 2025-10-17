#include <iostream>

int main() {
    int n;
    std::cout << "Ведите размер квадратной матрицы: ";
    std::cin >> n;
    int matrix[n][n];
    int num = 1;
    int start_stroki = 0, end_stroki = n-1, start_stolb = 0, end_stolb = n-1;
    while (start_stroki <= end_stroki && start_stolb <= end_stolb) {
        //вправо
        for (int i=start_stolb; i<=end_stolb; i++) {
            matrix[start_stroki][i] = num;
            num++;
        }
        start_stroki++;
        //вниз
        for (int i=start_stroki; i<=end_stroki; i++) {
            matrix[i][end_stolb] = num;
            num++;
        }
        end_stolb--;
        //влево
        for (int i=end_stolb; i>=start_stolb; i--) {
            matrix[end_stroki][i] = num;
            num++;
        }
        end_stroki--;
        //вверх
        for (int i=end_stroki; i>=start_stroki; i--) {
            matrix[i][start_stolb] = num;
            num++;
        }
        start_stolb++;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}