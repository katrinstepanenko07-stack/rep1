#include <iostream>
#include <cstring> 
using namespace std;

void sort(char arr[]) {
    int n = strlen(arr);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void remove(char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count] = str[i];
            count++;
        }
    }
    str[count] = '\0'; 
}

void toLower(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    const int n = 100; 
    char str1[n];
    char str2[n];
    cout << "Введите первую строку: ";
    cin.getline(str1, n);
    cout << "Введите вторую строку: ";
    cin.getline(str2, n);
    remove(str1);
    remove(str2);
    toLower(str1);
    toLower(str2);
    if (strlen(str1) != strlen(str2)) {
        cout << "Нет" << endl;
        return 0;
    }
    sort(str1);
    sort(str2);
    if (strcmp(str1, str2) == 0) {
        cout << "Да" << endl;
    } else {
        cout << "Нет" << endl;
    }

    return 0;
}