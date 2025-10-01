#include <iostream>
using namespace std;

string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                   "enam", "tujuh", "delapan", "sembilan"};

string terbilang(int n) {
    if (n == 0) return "nol";
    if (n == 10) return "sepuluh";
    if (n == 11) return "sebelas";
    if (n < 10) return satuan[n];
    if (n < 20) return satuan[n % 10] + " belas";
    if (n < 100) {
        string hasil = satuan[n / 10] + " puluh";
        if (n % 10 != 0) hasil += " " + satuan[n % 10];
        return hasil;
    }
    if (n == 100) return "seratus";
    return "";
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
    } else {
        cout << angka << " : " << terbilang(angka) << endl;
    }
    return 0;
}
