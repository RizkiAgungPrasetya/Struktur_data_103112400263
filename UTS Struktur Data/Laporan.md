UJIAN TENGAH SEMESTER
PRAKTIKUM STRUKTUR DATA
CLO 3

Identitas Pengumpul

Nama: Rizki Agung Prasetya

NIM: 103112400263

Kelas: IF 12-05

1. Kode Program

Berikut adalah kode program untuk [jelaskan singkat tujuan kode, misal: "program C++ untuk mengecek bilangan ganjil/genap"].

(Silakan ganti bahasa dan kode di bawah ini sesuai tugas Anda)

```File: soal1.cpp
 * Author: Rizki Agung Prasetya
 * NIM: 103112400263
 * Deskripsi: Kode ini mengimplementasikan Single Linked List untuk menyimpan daftar nama (bertipe string). Setiap elemen (Node) dalam list memiliki data nama dan pointer next yang menunjuk ke elemen

```c++

#include <iostream>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = NULL;

void insertAkhir(string n) {
    Node* baru = new Node;
    baru->nama = n;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }

    cout << "Nama \"" << n << "\" berhasil ditambahkan.\n";
}

void deleteNama(string n) {
    if (head == NULL) {
        cout << "[DELETE] List kosong.\n";
        return;
    }

    if (head->nama == n) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << "[DELETE] Nama \"" << n << "\" berhasil dihapus.\n";
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->nama != n) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "[DELETE] Nama \"" << n << "\" tidak ditemukan.\n";
    } else {
        Node* hapus = temp->next;
        temp->next = temp->next->next;
        delete hapus;
        cout << "[DELETE] Nama \"" << n << "\" berhasil dihapus.\n";
    }
}

void viewList() {
    if (head == NULL) {
        cout << "[VIEW] List kosong.\n";
        return;
    }

    Node* temp = head;
    cout << "Isi Linked List:\n";

    while (temp != NULL) {
        cout << "- " << temp->nama << endl;
        temp = temp->next;
    }
}

void hitungGenap() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->nama.length() % 2 == 0) {
            count++;
        }
        temp = temp->next;
    }

    cout << "[GENAP] Jumlah nama dengan huruf genap = " << count << endl;
}

int main() {
    int pilih;
    string nama;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert nama\n";
        cout << "2. Delete nama\n";
        cout << "3. View list\n";
        cout << "4. Hitung nama huruf genap\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                insertAkhir(nama);
                break;

            case 2:
                cout << "Masukkan nama yang ingin dihapus: ";
                cin >> nama;
                deleteNama(nama);
                break;

            case 3:
                viewList();
                break;

            case 4:
                hitungGenap();
                break;

            case 0:
                cout << "Keluar...\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 0);

    return 0;
}

```

2. Penjelasan Kode

Berikut adalah penjelasan alur logika dari kode program di atas:

Program ini menggunakan struktur Singly Linked List untuk menyimpan data nama mahasiswa. Setiap nama disimpan dalam sebuah node, dan program menyediakan beberapa operasi seperti memasukkan data, menghapus data, menampilkan seluruh data, serta menghitung nama dengan jumlah huruf genap.

struct Node {
    string nama;
    Node* next;
};

Struktur tersebut digunakan untuk wadah data
 - nama (untuk menyimpan nama mahasiswa)
 - next (untuk menunjuk node berikutnya)

 Node* head = NULL;
 Head digunakan sebagai pointer utama yang menandai node pertama

 Fungsi insert akhir
 Digunakan untuk menambahkan nama dibagian akhir linked list

 Alur logikanya :
- Membuat node baru.
- Mengisi node dengan nama yang dimasukkan user.
- ika list kosong -> node baru langsung menjadi head.
- Jika list sudah berisi:
    lakukan traversal hingga node terakhir,
    letakkan node baru pada posisi paling akhir.
- Menampilkan pesan bahwa nama berhasil ditambahkan.

Fungsi ini memastikan bahwa setiap nama yang ditambahkan selalu berada pada akhir list.

Fungsi delete nama
Berfungsi untuk menghapus nama pertama yang ditemukan

Alur logika:
- Jika list kosong -> tampilkan pesan bahwa list kosong.
- Jika nama yang ingin dihapus berada di node pertama (head):
    geser head ke node berikutnya,
    hapus node lama.
- Jika bukan di node pertama:
    lakukan traversal untuk mencari node yang memiliki nama sesuai input.
- Jika ditemukan:
    putuskan node tersebut dari list,
    hapus node tersebut dari memori.
- Jika tidak ditemukan -> tampilkan pesan bahwa nama tidak ada.

Fungsi ini hanya menghapus nama pertama yang sesuai dengan input.

Fungsi view list
Untuk menampilkan seluruh isi linked list yang sudah di input sebelumnya

Alur logika:
- Jika list kosong → tampilkan pesan “[VIEW] List kosong”.
- Jika terdapat data:
    mulai dari head,
    tampilkan setiap nama hingga node terakhir.

Fungsi ini menampilkan isi list secara berurutan dari awal sampai akhir.

Fungsi hitung genap
Berfungsi untuk menghitung jumlah nama yang jumlah hurufnya genap

Alur logika:
- Siapkan variabel penghitung (count = 0).
- Lakukan traversal dari head ke node terakhir.
- Pada setiap node:
    hitung panjang nama menggunakan .length(),
    jika panjangnya genap, tambahkan 1 ke count.
- Setelah traversal selesai, tampilkan jumlah nama huruf genap.

Program main
Program utamanya menggunakan menu loop sehingga user dapat memilih operasi berkali kali

Menu terdiri dari:
- insert nama
- hapus nama
- hitung nama huruf genap
- exit

3. Output Program

**Output** 

 ![alt text](Output/output%201.png)
![alt text](Output/Output%202.png)
![alt text](Output/Output%203.png)

4. Penjelasan 

User memilih menu 1 (Insert nama)
Lalu memasukkan nama Rizki
Output:
Nama "Rizki" berhasil ditambahkan.

Penjelasan:
Program membuat node baru berisi nama “Rizki”. Karena list masih kosong (head == NULL), maka node ini menjadi node pertama atau head.
List sekarang:
Rizki

2. Insert Nama Kedua: “Agung”
User kembali memilih menu 1, kemudian memasukkan nama Agung.
Output:
Nama "Agung" berhasil ditambahkan.

Penjelasan:
Node baru dibuat dengan nilai “Agung”. Karena list sudah memiliki satu node, program menelusuri hingga node terakhir lalu menambahkannya di bagian akhir.
List sekarang:
Rizki
Agung

3. Insert Nama Ketiga: “Prasetya”
User kembali memilih menu 1, lalu memasukkan Prasetya.
Output:
Nama "Prasetya" berhasil ditambahkan.

Penjelasan:
Node “Prasetya” ditempatkan di urutan terakhir setelah “Agung”.
List sekarang:
Rizki
Agung
Prasetya

4. View List
User memilih menu 3 (View list).
Output:
Isi Linked List:
- Rizki
- Agung
- Prasetya

Penjelasan:
Program melakukan traversal dari node pertama (head) hingga node terakhir, kemudian menampilkan semua nama secara berurutan.

5. Delete Nama: “Agung”
User memilih menu 2 (Delete nama) dan memasukkan nama Agung.
Output:
[DELETE] Nama "Agung" berhasil dihapus.

Penjelasan:
Program mencari node dengan nama "Agung".
Node tersebut ditemukan di posisi tengah (setelah Rizki dan sebelum Prasetya).
Node dihapus, dan pointer list disesuaikan agar loncat dari “Rizki” langsung ke “Prasetya”.
List setelah penghapusan:
Rizki
Prasetya

6. View List Setelah Penghapusan
User kembali memilih menu 3.
Output:
Isi Linked List:
- Rizki
- Prasetya

Penjelasan:
Program menampilkan isi list setelah node “Agung” dihapus.
Nama yang tersisa adalah “Rizki” dan “Prasetya”.

7. Menghitung Nama dengan Jumlah Huruf Genap
User memilih menu 4 (Hitung nama huruf genap).
Output:
[GENAP] Jumlah nama dengan huruf genap = 1

Penjelasan per nama:
Rizki → 5 huruf → ganjil
Prasetya → 8 huruf → genap
Hanya 1 nama yang jumlah hurufnya genap.
Karena itu hasilnya adalah 1.

8. Exit Program
User memilih menu 0.
Output:
Keluar

Penjelasan:
Program berhenti karena user memilih keluar dari menu.

5. Kesimpulan
Program Singly Linked List berhasil dijalankan dengan baik. Semua operasi—mulai dari menambahkan nama, menghapus nama tertentu, menampilkan seluruh isi list, hingga menghitung jumlah nama dengan huruf genap—berfungsi sesuai yang diharapkan. Urutan data berubah dinamis mengikuti input pengguna, dan hasil perhitungan maupun tampilan list sudah sesuai dengan logika yang diterapkan. Secara keseluruhan, program berjalan lancar dan memenuhi ketentuan tugas.
