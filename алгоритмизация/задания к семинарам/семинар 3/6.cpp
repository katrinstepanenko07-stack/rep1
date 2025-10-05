#include <iostream> 

int main() {
    int n = 15;
    double massiv[n];
    for (int i=0; i < n; i++) {
        std::cin >> massiv[i];
    }
    double min_el = massiv[0];
    double max_el = massiv[0];
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


    if (index_min == 1 && index_max == 0) {
        std::cout << "новый массив: ";
        for (int i=0; i < n; i++) {
            std::cout << massiv[i] /2 << " ";
        }
    }
    std::cout << std::endl;
}