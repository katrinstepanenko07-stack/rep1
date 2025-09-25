#include <iostream>
using namespace std;

int main() {
    for (int i = 32; i <= 126; i++) {
        char letter = (char)i;
        cout << i << ". " << letter << endl;
    }
}