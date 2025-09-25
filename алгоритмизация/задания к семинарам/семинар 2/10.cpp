#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите число: ";
    cin >> n;
    if (n == 0) {
        cout << "число равно нулю" << endl;
    } else if (n > 0) {
        cout << "число положительное" << endl;
    } else {
        cout << "число отрицательное" << endl;
    }
}