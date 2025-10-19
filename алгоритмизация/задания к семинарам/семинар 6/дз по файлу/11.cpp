#include <iostream>
#include <cstring>
using namespace std;

bool Repeat(const char* str, int k) {
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
            if (str[i] == str[j]) {
                return true; 
            }
        }
    }
    return false; 
}

void Uniq(const char* str, int k) {
    int len = strlen(str);
    if (len < k || k <= 0) {
        cout << "" << endl;
        return;
    }

    for (int i = 0; i <= len - k; ++i) {
        char sub[k + 1];
        strncpy(sub, str + i, k);
        sub[k] = '\0'; 
        if (not Repeat(sub, k)) {
            cout << sub << endl; 
        }
    }
}

int main() {
    char str[100];
    int k;
    cout << "Введите строку: ";
    cin.getline(str, 100);
    cout << "Введите длину подстроки k: ";
    cin >> k;

    cout << "Уникальные подстроки длины " << k << ":" << endl;
    Uniq(str, k);
    return 0;
}