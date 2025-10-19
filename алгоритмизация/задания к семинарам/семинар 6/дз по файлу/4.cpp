#include <iostream>
#include <cstring>

int main() {
    char s_a[100], s_b[100];
    std::cout << "A = ";
    std::cin.getline(s_a, 100);
    std::cout << "B = ";
    std::cin.getline(s_b, 100);
    int len_a = strlen(s_a);
    int len_b = strlen(s_b);
    bool found_all = true;
    for (int i=0; i<len_b; i++) {
        bool found = false;
        for (int j=0; j<len_a; j++) {
            if (s_b[i] == s_a[j]) {
                found = true;
                break;
            }
        }
        if (not found) {
            found_all = false;
            break;
        }
    }
    if (found_all) {
        std::cout << "да\n";
    } else {
        std::cout << "нет\n";
    }

    return 0;

}