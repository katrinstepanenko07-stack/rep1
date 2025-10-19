#include <iostream>
#include <cctype>
#include <cstring>

int main() {
    char s[100];
    std::cout << "Введите строку: ";
    std::cin.getline(s, 100);
    int len_s = strlen(s);
    int count_a = 0;
    int count_b = 0;

    char a[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int len_a = 6;

    for (int i=0; i<len_s; i++) {
        char lower_s = std::tolower(s[i]);
        if (std::isalpha(lower_s)) {
            bool is_vowel = false;
            for (int j=0; j<len_a; j++) {
                if (lower_s == a[j]) {
                    count_a++;
                    is_vowel = true;
                    break;
                }
            }
            if (not is_vowel) {
                count_b++;
            }
        }
    }

    std::cout << "Гласных: " << count_a << std::endl;
    std::cout << "Согласных: " << count_b << std::endl;

    return 0;
}