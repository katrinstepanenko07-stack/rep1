#include <iostream>
using namespace std;

int main() {
    int n, summa = 0;
    cout << "Ведите число: ";
    cin >> n;
    for (int i=1; i<=n; i++) {
        if (i % 2 == 0 || i % 5 == 0) {
            summa += i;
        }
    }
    cout << "Сумма: " << summa << endl;
} 