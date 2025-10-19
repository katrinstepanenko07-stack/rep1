#include <iostream>
#include <cstring>

int main() {
    char s[100];
    std::cout << "Введите строку: \n";
    std::cin.getline(s, 100);
    int len = strlen(s);
    char s2[100];
    int index_s2 = 0;

    for (int i=0; i<len; i++) {
        if (not std::isdigit(s[i])) {
            s2[index_s2] = s[i];
            index_s2 ++;
        }
    }
    s2[index_s2] = '\0';
    std::cout << s2 << std::endl;

    return 0;

}