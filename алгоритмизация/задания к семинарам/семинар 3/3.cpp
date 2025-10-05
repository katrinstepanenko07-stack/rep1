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
    std::cout << "макс эл: " << max_el << " " << index_max << std::endl;
    std::cout << "мин эл: " << min_el << " " << index_min << std::endl;
    
    int tek = massiv[0];
    massiv[0] = massiv[index_min];
    massiv[index_min] = tek;

    int tek2 = massiv[n-1];
    massiv[n-1] = massiv[index_max];
    massiv[index_max] = tek2;

    for (int i=0; i < n; i++) {
        std::cout << massiv[i] << " ";
    }
    std::cout << std::endl;
}