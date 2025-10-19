#include <iostream>
#include <cstring> 

int main() {
    const int n = 100;
    char stroka[n]; 
    char stroka_copy[n]; 

    std::cout << "Введите строку: ";
    std::cin.getline(stroka, n); 
    strcpy(stroka_copy, stroka);

    const char delimiters[] = " "; 
    char* token = strtok(stroka_copy, delimiters);

    while (token != nullptr) {
        std::cout << token << std::endl;
        token = strtok(nullptr, delimiters); 
    }

    return 0;
}