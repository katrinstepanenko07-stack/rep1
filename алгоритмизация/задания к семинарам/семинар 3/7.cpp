#include <iostream> 

int main() {
    int n = 5;
    int massiv[n];
    for (int i=0; i < n; i++) {
        std::cin >> massiv[i];
    }
    int min_el = massiv[0];
    int max_el = massiv[0];
    int index_max = 0, index_min = 0;
    for (int i=0; i < n; i++) {
        if (massiv[i] > max_el) {
            max_el = massiv[i];
            index_max = i;
        }
        if (massiv[i] < min_el) {
            min_el = massiv[i];
            index_min = i;
        }
    }
    std::cout << "макс эл: " << max_el << "; индекс: " << index_max << std::endl;
    std::cout << "мин эл: " << min_el << "; индекс: " << index_min << std::endl;


    if (min_el == 0 || max_el == 0) {
        std::cout << "новый массив: ";
        for (int i=0; i < n; i++) {
            if (i < index_min) {
                std::cout << 0 << " ";
            } else {
                std::cout << massiv[i] << " ";
            }
        }
    }
    std::cout << std::endl;
}