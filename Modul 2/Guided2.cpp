#include <iostream>

using namespace std;

int main(){
    float hargaproduk = 50000.0;
    //Deklarasi pointer
    float* ptrharga;
    ptrharga = &hargaproduk;
    
    cout<<"Harga Awal Produk Rp"<< hargaproduk<<endl;
    cout<<"Alamat memori harga"<<ptrharga<<endl;

    cout<<"\n..memberikan diskon 10% melalui pointer..." << endl;
    *ptrharga = *ptrharga * 0.9;
    
    cout<<"Harga Akhir Produk Rp"<< *ptrharga<<endl;
    return 0;
}