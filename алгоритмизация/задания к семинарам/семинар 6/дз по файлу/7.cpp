#include <iostream>
#include <cstring>

void rle_encode(const char* input, char* output) {
    char a = input[0];
    int count = 1;
    int index = 0;
    for (int i = 1; i<strlen(input); ++i) {
        if (input[i] == a) {
            count++;
        } else {
            output[index++] = a;
            output[index++] = count + '0';

            a = input[i];
            count = 1;
        }
    }
    output[index++] = a;
    output[index++] = count + '0'; //число в символ
    output[index] = '\0';
}

int main() {
    char input_string[100];
    char encoded_string[200];
    std::cout << "Введите строку: ";
    std::cin >> input_string;
    rle_encode(input_string, encoded_string);
    std::cout << "Сжатая строка: " << encoded_string << std::endl;
    return 0;
}