#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;
    for (int i = n; i >= 1; i--) {
        // cetak bagian kiri
        for (int j = i; j >= 1; j--)
            cout << j;

        // cetak tanda *
        cout << "*";

        // cetak bagian kanan
        for (int j = 1; j <= i; j++)
            cout << j;

        cout << endl;
    }
    cout << "*" << endl; // baris terakhir hanya *
    return 0;
}
