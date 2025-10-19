#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int n = 100;
    char stroka[n] = "";
    char poisk[n];
    char zamena[n];
    char resultat[n * 2];
    cout << "Введите строку: ";
    cin.getline(stroka, n);
    cout << "Введите подстроку для поиска: ";
    cin.getline(poisk, n);
    cout << "Введите строку для замены: ";
    cin.getline(zamena, n);

    int i = 0, j = 0, k = 0;
    while (i<strlen(stroka)) {
        if (strstr(stroka + i, poisk) == stroka + i) {
            for (int l = 0; l<strlen(zamena); l++) {
                resultat[k] = zamena[l];
                k++;
            }
            i += strlen(poisk);
        } else {
            resultat[k] = stroka[i];
            k++;
            i++;
        }
    }
    resultat[k] = '\0';

    cout << "Результат: " << resultat << endl;
    return 0;
}