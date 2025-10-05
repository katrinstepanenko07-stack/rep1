#include <iostream>

int main() {
    int n;
    std::cout << "размер массива: ";
    std::cin >> n;
    int massiv[n];
    std::cout << "целые числа: " << std::endl;
    for (int i=0; i<n; i++) {
        std::cin >> massiv[i];
    }
    int max_add = 0;
    int count_even = 0;
    for (int i=0; i < n; i++) {
        if (massiv[i] % 2 != 0) {
            if (massiv[i] > max_add) {
                max_add = massiv[i];
            }
        } else {
            count_even++;
        }
    }
    std::cout << "макс нечет эл: " << max_add << std::endl;
    std::cout << "колич чет эл: " << count_even << std::endl;
}