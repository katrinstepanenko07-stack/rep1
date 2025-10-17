#include <iostream>

int main() {
    int n;
    std::cout << "Ведите размер квадратной матрицы: ";
    std::cin >> n;
    int matrix[n][n], spiral[n*n];
    for (int i=0;i<n; i++){
        for (int j=0; j<n; j++) {
            std::cin >> matrix[i][j];
        }
    }


    int num = 0;
    int start_stroki = 0, end_stroki = n-1, start_stolb = 0, end_stolb = n-1;
    while (start_stroki <= end_stroki && start_stolb <= end_stolb) {
        //вправо
        for (int i=start_stolb; i<=end_stolb; i++) {
            spiral[num] = matrix[start_stroki][i];
            num++;
        }
        start_stroki++;
        //вниз
        for (int i=start_stroki; i<=end_stroki; i++) {
            spiral[num] = matrix[i][end_stolb];
            num++;
        }
        end_stolb--;
        //влево
        for (int i=end_stolb; i>=start_stolb; i--) {
            spiral[num] = matrix[end_stroki][i];
            num++;
        }
        end_stroki--;
        //вверх
        for (int i=end_stroki; i>=start_stroki; i--) {
            spiral[num] = matrix[i][start_stolb];
            num++;
        }
        start_stolb++;
    }
    std::cout << "элементы матрицы в пордяке обхода по спирали:";
    for (int i=0; i<n*n; i++) {
        std::cout << spiral[i] << " ";
    }
}

