#include <iostream>
#include <cctype>
#include <cstring>

void correct(char* text) {
    bool new_sentence = true;
    for (int i = 0; i<strlen(text); ++i) {
        if (new_sentence && std::isalpha(text[i])) {
            text[i] = std::toupper(text[i]);
            new_sentence = false; 
        } else {
            if (std::isalpha(text[i])) {
                text[i] = std::tolower(text[i]);
            }
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            new_sentence = true; 
        }
    }
}

int main() {
    char text[200]; 
    std::cout << "Введите текст: ";
    std::cin.getline(text, 200); 
    correct(text); 
    std::cout << "Исправленный текст: " << text << std::endl; 
    return 0;
}