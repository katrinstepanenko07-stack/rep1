#include <iostream>
#include <cctype>
#include <cstring>

char caesar(char c, int shift) {
    if (std::isalpha(c)) {
        char base;
        if (std::isupper(c)) {
            base = 'A';
        } else {
            base = 'a';
        }
        return (char)(((c - base + shift + 26) % 26) + base);
    } else {
        return c;
    }
}

int main() {
    char text[100];
    int shift;

    std::cout << "Введите текст: ";
    std::cin.getline(text, 100);

    std::cout << "Введите сдвиг: ";
    std::cin >> shift;

    for (int i = 0; i<strlen(text); i++) {
        text[i] = caesar(text[i], shift);
    }

    std::cout << "Зашифрованный текст: " << text << std::endl;

    return 0;
}
