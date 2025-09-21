#include <iostream>

int main() {
    const int size = 10;
    int sum = 0;

    int numbers[size];
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ") ";
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    std::cout << "массив: ";
    for (int j = 0; j < size; j++) {
        std::cout << numbers[j] << " ";
    }
    std::cout << std::endl;

    // Сортировка выбором 
    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
        if(numbers[j] < numbers[minIndex]) {
            minIndex = j;
        }
    }
        // Меняем местами текущий элемент и найденный минимальный
        std::swap(numbers[i], numbers[minIndex]);
    }

    // Вывод суммы/мин_эл/сорт
    std::cout << "сумма элементов массива: " << sum << std::endl;
    std::cout << "минимальный элемент: " << numbers[0] << std::endl;
    std::cout << "сортировка по возрастанию (сортировка выбором): ";
    for(int i = 0; i < size; i++) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}
