#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[200];
    char b;
    cout << "Введите строку: ";
    cin.getline(s, 200);
    cout << "Введите символ для удаления: ";
    cin >> b;
    int len = strlen(s);
    int k = 0;

    for (int i = 0; i < len; ++i) {
        if (s[i] != b) {
            s[k] = s[i];
            k++;
        }
    }

    s[k] = '\0';
    cout << "Результат: " << s << endl;
    return 0;
}