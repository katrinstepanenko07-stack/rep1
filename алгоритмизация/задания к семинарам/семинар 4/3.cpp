#include <iostream>
#include <algorithm>
int main() {
    int n, m;
    std::cout << "Ведите размер матрицы в одну строку (сначала строки, потом столбцы): ";
    std::cin >> n >> m;
    int matrix[n][m];

    std::cout << "Ведите целые числа вашей матрицы: " << std::endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int min_strok[n], max_strok[n];
    for (int i=0; i<n; i++) {
        min_strok[i] = matrix [i][0];
        max_strok[i] = matrix [i][0];
        for (int j=1;j<m; j++) {
            min_strok[i] = fmin(min_strok[i], matrix[i][j]);
            max_strok[i] = fmax(max_strok[i], matrix[i][j]);
        }
    }

    std::cout << "мин у строк" << std::endl;
    for (int i=0; i<n; i++) {
        std::cout << min_strok[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "макс у строк" << std::endl;
    for (int i=0; i<n; i++) {
        std::cout << max_strok[i] << " ";
    }

    int min_stolb[m], max_stolb[m];
    for (int i=0; i<m; i++) {
        min_stolb[i] = matrix [0][i];
        max_stolb[i] = matrix [0][i];
        for (int j=1;j<n; j++) {
            min_stolb[i] = fmin(min_stolb[i], matrix[j][i]);
            max_stolb[i] = fmax(max_stolb[i], matrix[j][i]);
        }
    }

    std::cout << std::endl;
    std::cout << "мин у столб" << std::endl;
    for (int i=0; i<m; i++) {
        std::cout << min_stolb[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "макс у столб" << std::endl;
    for (int i=0; i<m; i++) {
        std::cout << max_stolb[i] << " ";
    }

    //A
    bool found_a = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == min_strok[i] && matrix[i][j] == max_stolb[j]) {
            std::cout << "A " << matrix[i][j] << " " << i + 1 << " " << j + 1 << std::endl;
            found_a = true;
            }
        }
    }
    //B
    bool found_b = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == max_strok[i] && matrix[i][j] == min_stolb[j]) {
            std::cout << "B " << matrix[i][j] << " " << i + 1 << " " << j + 1 << std::endl;
            found_b = true;
            }
        }
    }

    if ((not found_a) && (not found_b)) {
        std::cout << "NONE" << std::endl;
    }
}
