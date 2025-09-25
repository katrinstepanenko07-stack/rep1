// #include <iostream>
// using namespace std;

// int main() {
//     char letter;
//     int count = 0;
//     char vowels[] = {'e', 'y', 'u', 'i', 'o', 'a', 'E', 'Y', 'U', 'I', 'O', 'A'};
//     cout << "Строка по символам (до точки): " << endl;
//     while (true) {
//         cin >> letter;
//         if (letter == '\n') {
//             break;
//         } else { 
//             for (int i = 0; i < 12; i++) {
//                 if (letter == vowels[i]) {
//                     count++;
//                 }
//             }
//         }
//     }
//     cout << "Количесво гласных: " << count << endl;
//     return 0;
// }

// поч стопить можно только через символ
// поч в переменной чар читается не один симво
// как вообще сделать проще код
// как посчитать длину массива

#include <iostream>
using namespace std;

int main() {
    char letter;
    int count = 0;
    char vowels[] = {'e', 'y', 'u', 'i', 'o', 'a', 'E', 'Y', 'U', 'I', 'O', 'A'};
    int vowelsCount = sizeof(vowels) / sizeof(char);
    
    cout << "Строка по символам (до точки): " << endl;
    while (true) {
        cin >> letter;
        if (letter == '.') {
            break;
        } else { 
            for (int i = 0; i < vowelsCount; i++) {
                if (letter == vowels[i]) {
                    count++;
                }
            }
        }
    }
    cout << "Количесво гласных: " << count << endl;
    return 0;
}