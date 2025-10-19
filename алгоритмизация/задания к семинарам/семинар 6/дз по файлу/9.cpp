#include <iostream>
#include <cstring>
using namespace std;
const int MAX_LEN = 100; 

int main() {
    char str1[MAX_LEN + 1], str2[MAX_LEN + 1];
    cout << "Введите первую строку: ";
    cin.getline(str1, MAX_LEN + 1);
    cout << "Введите вторую строку: ";
    cin.getline(str2, MAX_LEN + 1);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dp[MAX_LEN + 1][MAX_LEN + 1];
    for (int i = 0; i <= len1; ++i) {
       for (int j = 0; j <= len2; ++j) {
           dp[i][j] = 0; 
       }
   }
   
    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << "Самая длинная общая подстрока: ";
    if (maxLength == 0) {
        cout << "Общих подстрок не найдено" << endl;
    } else {
        char str[MAX_LEN + 1];
        int start_index = endIndex - maxLength;
        for (int i = 0; i < maxLength; i++) {
            str[i] = str1[start_index + i];
        }
        str[maxLength] = '\0';
        cout << str << endl;
    }
    return 0;
}
