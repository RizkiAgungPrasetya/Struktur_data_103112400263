#include <iostream>

using namespace std;

int main(){
    int BukuPerHari[7] = {2,1,3,2,4,5,1};
    int TotalBuku = 0;

    cout << "Laporan baca buku mingguan" << endl;

    for (int i = 0; i < 7; i ++){
        cout << "Hari ke-" << i + 1 << ":" << BukuPerHari[i] << " buku." << endl;
        TotalBuku += BukuPerHari[i];
    }
    cout << "total buku yang dibaca minggu ini : " << TotalBuku << " buku." << endl;
}