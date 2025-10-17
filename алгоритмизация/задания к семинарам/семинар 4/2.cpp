#include <iostream>

int main() {
    int n;
    std::cout << "Ведите размер квадратной матрицы: ";
    std::cin >> n;
    int matrix[n][n];

    std::cout << "Ведите целые числа вашей матрицы: " << std::endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // сумма главной диагонали
    int sum_d1 = 0;
    for (int i = 0; i < n; i++) {
        sum_d1 += matrix[i][i];
    }

    // сумма побочной диагонали
    int sum_d2 = 0;
    for (int i = 0; i < n; i++) {
        sum_d2 += matrix[i][n - 1 - i];
    }

    // std::cout <<  "сумма диагонали 1 - " << sum_d1 << std::endl;
    // std::cout <<  "сумма диагонали 2 - " << sum_d2 << std::endl;

    if (sum_d1 != sum_d2) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    // сумма строк
    int summa_stroki = 0;
    for (int j=0; j<n; j++) {
        summa_stroki += matrix[0][j];
    }
    
    bool flag_stroki = true;
    for (int i = 0; i<n; i++) {
        int tek_summa_stroki = 0;
        for (int j = 0; j < n; j++) {
            tek_summa_stroki += matrix[i][j];
        }
        if (tek_summa_stroki != summa_stroki) {
            flag_stroki = false;
        }
    }
    

    // if (flag_stroki) {
    //     std::cout <<  "сумма строк одинакова и равна - " << summa_stroki << std::endl;
    // }

    // сумма столбцов
    int summa_stold = 0;
    for (int i=0; i<n; i++) {
        summa_stold += matrix[i][0];
    }
    
    bool flag_stolb = true;
    for (int j=0; j<n; j++) {
        int tek_summa_stolb = 0;
        for (int i=0; i< n; i++) {
            tek_summa_stolb += matrix[i][j];
        }
        if (tek_summa_stolb != summa_stold) {
            flag_stolb = false;
        }
    }
    

    // if (flag_stolb) {
    //     std::cout <<  "сумма столбцов одинакова и равна - " << summa_stold << std::endl;
    // }

    if ((not flag_stroki) || (not flag_stroki) || summa_stroki != summa_stold) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    if (sum_d1 == summa_stroki) {
        std::cout << "YES" << std::endl;
        std::cout << "значение общей суммы: " << sum_d1 << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
