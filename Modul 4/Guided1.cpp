#include <iostream>
using namespace std;

//Definisi node
struct Node{ //Memiliki 2 bagian yaitu data dan pointer
    int data;
    Node*next; //Pointer ke node berikutnya
};

Node*linearSearch(Node*head, int key){
    Node*current = head;
    while(current != nullptr){ //Selama masih ada node
        if(current -> data == key) return current; //Jika data ketemu
        current = current -> next; //Pindah ke node berikutnya
    }
    return nullptr; //Tidak ditemukan
}

//Prosedur untuk menambah node
void append(Node*&head, int value){ //Parameter head adalah referensi ke pointer head
    Node*newNode = new Node{value, nullptr}; //Membuat pointer baru yang nyimpan alamat node baru
    if(!head)head = newNode; //Jika head null, head diisi node baru
    else{
        Node*temp = head; //mulai dari head
        while(temp -> next)temp = temp -> next; //Pindah ke node berikutnya sampai ketemu node terakhir
        temp -> next = newNode; //node terakhir dihubungkan ke node baru
    }
}

int main(){
    Node*head = nullptr; //inisialisasi head list masih kosong
    append(head, 10); append(head, 20); append(head, 30); //Menambah node

    Node*result = linearSearch(head, 20); //Result ini pointer untuk mencari data 20
    cout << (result?"Found" : "Not Found") << endl;
    return 0;
}