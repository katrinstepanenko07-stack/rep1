#include <iostream>
#include <cstring>
#include <cctype>

int main() {
    char s[100];
    std::cout << "Введите строку из 10 слов: " << std::endl;
    std::cin.getline(s, 100);
    std::cout << std::endl;
    char s1[100], s2[100], s3[100], s4[100], s5[100];
    strcpy(s1, s);
    strcpy(s2, s);
    strcpy(s3, s);
    strcpy(s4, s);
    strcpy(s5, s);

//1
    std::cout << "Задание 1)" << std::endl;

    int count_end_a = 0;
    const char delimiters[] = " ";
    char* token = strtok(s1, delimiters); 
    while (token != nullptr) {
        int len = strlen(token);
        if (len > 0 && token[len - 1] == 'a') {
            count_end_a++;
        }
        token = strtok(nullptr, delimiters);
    }
    std::cout << "Количество слов, оканчивающихся на 'a': " << count_end_a << std::endl;

//2
    std::cout << "Задание 2)" << std::endl;

    token = strtok(s2, delimiters); 
    int min_len = strlen(token);
    while (token != nullptr) {
        int tek_len = strlen(token);
        if (tek_len < min_len) {
            min_len = tek_len;
        }
        token = strtok(nullptr, delimiters);
    }
    std::cout << "Длина самого короткого слова: " << min_len << std::endl;

//3
    std::cout << "Задание 3)" << std::endl;


    char* token3 = strtok(s3, delimiters); //  первое слово
    char* second_word = strtok(nullptr, delimiters); //  второе слово

    int b_count = 0;

    for (int i = 0; second_word[i] != '\0'; ++i) {
        if (second_word[i] == 'b') {
            b_count++;
        }
    }
    std::cout << "Количество букв 'b' во втором слове: " << b_count << std::endl;


//4 
    std::cout << "Задание 4)" << std::endl;

    for (int i = 0; s4[i] != '\0'; ++i) {
        s4[i] = tolower(s4[i]);
    }
    std::cout << "Замена всех букв в верхнем регистре на строчные: " << s4 << std::endl;     

//5
    std::cout << "Задание 5)" << std::endl;

    int count = 0;
    token = strtok(s5, delimiters); 
    while (token != nullptr) {
        int len = strlen(token);
        if (len > 0 && (token[len - 1] == token[0])) {
            count++;
        }
        token = strtok(nullptr, delimiters);
    }
    std::cout << "Количество слов, у которых первый и последний символы совпадают между собой: " << count << std::endl;

//*
    std::cout << "Задание *)" << std::endl;

    
}