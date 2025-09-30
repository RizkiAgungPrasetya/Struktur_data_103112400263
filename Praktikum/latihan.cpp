#include <iostream>
#include <string>
#include <vector>


int main(){
    std::string kampus[] = {"Universitas Telkom","Uiversitas Indonesia","Institusi Teknologi Bandung","Universitas Gadjah Mada","Universitas Airlangga"};

    std::cout<<"Daftar Nama Kampus:" << std::endl;

    for(const std::string&namaKampus : kampus){
        std::cout<<"-"<<namaKampus<<std::endl;
    }
    return 0;
}