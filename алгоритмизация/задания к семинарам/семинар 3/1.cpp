#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cout << "Введите количесво символов в массиве: ";
    std::cin >> n;
    int massiv[n];
    int massiv_2k[n];
    int count_k = 0;

    std::cout << "Введите " << n << " натуральных чисел: " << std::endl;
    for (int i=0; i < n; i++) {
        std::cin >> massiv[i];
    }


    for (int i; i<n; i++) {
        if (massiv[i] > pow(2, i)) {
            massiv_2k[count_k] = massiv[i];
            count_k++;
        }
    }
    std::cout << "массив новый: ";
    for (int i; i < count_k; i++) {
        std::cout << massiv[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "количесво эл нового массива: " << count_k << std::endl;
}

