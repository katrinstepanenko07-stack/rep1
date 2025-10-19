#include <iostream>
#include <cstring>

int main() {
    char s[100];
    std::cout << "Введите строку: \n";
    std::cin.getline(s, 100);
    int len = strlen(s);
    int arr_len_iniq = 0;
    char arr[len];

    for (int i=0; i<len; i++) {
        bool found = false;
        for (int j=0; j<arr_len_iniq; j++) {
            if (s[i] == arr[j]) {
                found = true;
                break;
            }
        }
        if (not found) {
            arr[arr_len_iniq] = s[i];
            arr_len_iniq++;
        }
    }
    arr[arr_len_iniq] = '\0';
    std::cout << "Количество уникальных символов: " << arr_len_iniq << std::endl;
    std::cout << "Уникальные символы: " << arr << std::endl;

    return 0;

}