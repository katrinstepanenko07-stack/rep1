#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[200]; 
    char longest_Word[100] = ""; 
    char str2[100];
    int max_l = 0;
    cout << "Введите строку: ";
    cin.getline(str, 200);

    char* token = strtok(str, " "); 
    while (token != nullptr) { 
        strcpy(str2, token); 
        int len_str2 = strlen(str2); 

        if (len_str2 > max_l) { 
            max_l = len_str2; 
            strcpy(longest_Word, str2); 
        }
        token = strtok(nullptr, " "); 
    }
    cout << "Самое длинное слово: " << longest_Word << endl;
    return 0;
}