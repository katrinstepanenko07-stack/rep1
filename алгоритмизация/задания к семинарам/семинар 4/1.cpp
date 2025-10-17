#include <iostream>


bool coincided(int matrix_1[100][100], int matrix_2[100][100], int n) {
    bool flag = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix_1[i][j] != matrix_2[i][j]) {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main() {
    int n;
    std::cout << "Ведите размер квадратной матрицы: ";
    std::cin >> n;
    int matrix[100][100], matrix1[100][100], matrix2[100][100], matrix3[100][100], matrix4[100][100]; // Статические массивы

    std::cout << "Ведите целые числа вашей матрицы: " << std::endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Отражение относительно главной диагонали: " << std::endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matrix1[i][j] = matrix[j][i];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::cout << matrix1[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Отражение относительно побочной диагонали: " << std::endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matrix2[i][j] = matrix[(n-1)-j][(n-1)-i];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::cout << matrix2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Зеркальное отражение относительно вертикальной оси: " << std::endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matrix3[i][j] = matrix[i][(n-1)-j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::cout << matrix3[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Зеркальное отражение относительно горизонт оси: " << std::endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matrix4[i][j] = matrix[n-1-i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::cout << matrix4[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int k =0;
    if (coincided(matrix1, matrix2, n)) {
        std:: cout << "матрицы 1 и 2 совпали)" << std::endl;
        k ++;
    } 
    if (coincided(matrix1, matrix3, n)) {
        std:: cout << "матрицы 1 и 3 совпали)" << std::endl;
        k++;
    } 
    if (coincided(matrix1, matrix4, n)) {
        std:: cout << "матрицы 1 и 4 совпали)" << std::endl;
        k++;
    }
    if (coincided(matrix2, matrix3, n)) {
        std:: cout << "матрицы 2 и 3 совпали)" << std::endl;
        k++;
    }
    if (coincided(matrix2, matrix4, n)) {
        std:: cout << "матрицы 2 и 4 совпали)" << std::endl;
        k++;
    }
    if (coincided(matrix3, matrix4, n)) {
        std:: cout << "матрицы 3 и 4 совпали)" << std::endl;
        k ++;
    } 
    if (k == 0){
        std:: cout << "совпадения: NONE" << std::endl;
    }


}
