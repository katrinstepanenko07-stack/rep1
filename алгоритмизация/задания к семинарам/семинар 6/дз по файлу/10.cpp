#include <iostream>
#include <algorithm> // std::reverse
using namespace std;

void revers(char* sentence) {
    char* wordStart = sentence;
    char* wordEnd = sentence;

    while (*wordEnd) {
        if (*wordEnd == ' ') {
            reverse(wordStart, wordEnd);
            wordStart = wordEnd + 1;
        }
        wordEnd++;
    }
    reverse(wordStart, wordEnd);
}

int main() {
    char sentence[100];
    cout << "Введите строку: ";
    cin.getline(sentence, 100);
    revers(sentence);
    cout << "Вывод: " << sentence << endl;
    return 0;
}