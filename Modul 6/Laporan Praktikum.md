
## 1. Nama, NIM, Kelas

- **Nama**: Rizki Agung Prasetya

- **NIM**: 103112400263

- **Kelas**: IF 12-05

  

## 2. Motivasi Belajar Struktur Data

Belajar struktur data itu bukan cuma soal bisa bikin kode jalan, tapi tentang bagaimana kita membangun pola pikir yang teratur. Ibarat kita menata buku di perpustakaan, kalau asal taruh pasti bikin pusing saat mencari. Tapi dengan sistem penyimpanan yang jelas, semua jadi mudah ditemukan. Sama halnya dengan struktur data semakin kita paham cara menyusun dan mengelola data, semakin efisien program yang kita buat. Selain bermanfaat di dunia pemrograman, cara berpikir logis dan efisien ini juga terbawa ke kehidupan sehari-hari. Jadi meskipun awalnya terasa berat, anggap saja setiap konsep struktur data adalah fondasi kuat yang akan mempermudah kita menghadapi tantangan teknologi di masa depan.

  

## 3. Dasar Teori

Struktur data merupakan cara untuk menyimpan dan mengatur data di dalam komputer agar dapat diakses dan dikelola dengan efisien. Salah satu jenis struktur data linear yang umum digunakan adalah Stack (Tumpukan).

Stack bekerja berdasarkan prinsip LIFO (Last In, First Out), artinya elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan. Konsep ini bisa diibaratkan seperti tumpukan piring — piring terakhir yang diletakkan di atas tumpukan akan menjadi yang pertama diambil. Semua proses penambahan (push) dan penghapusan (pop) elemen hanya dilakukan dari satu sisi saja, yaitu bagian atas yang disebut TOP.

Dalam materi ini, stack diimplementasikan menggunakan Static Array Implementation, yaitu dengan menggunakan array berukuran tetap (ditentukan oleh konstanta MaxEl dalam file stack.h). Sebuah variabel integer bernama TOP digunakan untuk menandai posisi elemen paling atas pada stack. Saat stack masih kosong, nilai TOP diatur menjadi Nil (biasanya -1). Stack dianggap penuh (IsFull) ketika nilai TOP sudah mencapai batas maksimum, yaitu MaxEl - 1.

Selain operasi dasar, kode program ini juga memuat beberapa algoritma yang menerapkan konsep stack. Misalnya, fungsi balikStack yang digunakan untuk membalik urutan elemen. Prosesnya dilakukan dengan memindahkan elemen-elemen dari stack utama ke stack bantu menggunakan operasi push dan pop, sehingga urutannya menjadi terbalik. Ada juga fungsi pushAscending, yang menunjukkan bagaimana stack dapat dimanipulasi agar elemen-elemen di dalamnya tetap dalam urutan tertentu (misalnya descending dari TOP ke bawah) dengan bantuan stack sementara.
  

## 4. Guided

### 4.1 Guided 1
```c++

#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x);
void getInputStream(Stack &S);


#endif
```

**Penjelasan :** File stack.h berperan sebagai header file atau “cetak biru” yang mendefinisikan struktur data dan prototipe fungsi untuk Stack (Tumpukan). Fungsinya adalah sebagai antarmuka (interface) yang memberi tahu file lain seperti stack.cpp dan main.cpp mengenai fungsi serta struktur yang tersedia.

Pada bagian awal, terdapat header guard (#ifndef, #define, #endif) yang penting untuk mencegah terjadinya kesalahan redeclaration jika file ini di-include lebih dari sekali. Di bawahnya, beberapa konstanta didefinisikan menggunakan #define, yaitu:

MaxEl (biasanya bernilai 20) untuk menentukan kapasitas maksimum stack, menandakan bahwa implementasinya bersifat statis, dan

Nil (biasanya bernilai -1) sebagai penanda bahwa stack sedang kosong.

Kemudian, terdapat typedef int infotype yang digunakan untuk memberi alias tipe data elemen stack. Dengan cara ini, jika di kemudian hari tipe data yang disimpan ingin diubah (misalnya dari int ke float), cukup mengubah satu baris ini saja tanpa mengubah kode lain.

Bagian utama file ini adalah deklarasi struktur Stack, yang terdiri dari dua komponen:

infotype info[MaxEl], yaitu array statis sebagai tempat menyimpan data, dan

int TOP, variabel yang menunjukkan posisi elemen teratas stack.

Di akhir file, terdapat daftar prototipe fungsi yang akan diimplementasikan di stack.cpp, seperti CreateStack, IsEmpty, IsFull, Push, Pop, dan printInfo. Selain itu, terdapat juga fungsi tambahan seperti balikStack, pushAscending, dan getInputStream, yang memperluas kemampuan dasar dari struktur stack ini.



### 4.2 Guided 2
```c++
#include "stack.h"

using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return S.top == Nil;
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack Kosong!" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);

        while (!isEmpty(S)) { push(temp1, pop(S)); }

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }
    }
}

void pushAscending(Stack &S, int x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] < x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    cout << "Masukkan angka : ";
    string input;
    cin >> input;

    for (char c : input) {
        push(S, c - '0'); 
    }
}
```

**Penjelasan** : File stack.cpp berisi implementasi dari seluruh fungsi yang telah dideklarasikan dalam stack.h. Di dalamnya, setiap fungsi menjalankan logika utama untuk mengelola operasi pada struktur data Stack.

Fungsi CreateStack digunakan untuk menginisialisasi stack kosong dengan cara mengatur nilai TOP ke -1. Fungsi isEmpty dan isFull masing-masing berperan untuk memeriksa apakah stack sedang kosong atau sudah mencapai kapasitas maksimum.

Fungsi push bertugas menambahkan elemen baru ke posisi teratas stack selama stack belum penuh, sedangkan pop berfungsi menghapus sekaligus mengambil elemen teratas selama stack tidak kosong.

Selain itu, fungsi printInfo menampilkan seluruh isi stack mulai dari elemen paling atas hingga paling bawah. Jika stack kosong, maka akan ditampilkan pesan khusus yang memberi tahu bahwa tidak ada data di dalamnya.

Terakhir, terdapat fungsi balikStack yang digunakan untuk membalik urutan isi stack dengan memanfaatkan dua stack bantu (sementara). Dengan cara ini, elemen yang tadinya berada di bawah akan berpindah ke atas, dan sebaliknya.

Secara keseluruhan, file stack.cpp berisi implementasi logika operasional stack — mencakup proses penambahan, penghapusan, penampilan, dan pembalikan data dalam struktur tumpukan.


### 4.3 Guided 3
```c++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}

```

**Penjelasan** : File main.cpp berfungsi sebagai program utama atau driver yang digunakan untuk menjalankan sekaligus menguji struktur data Stack yang telah didefinisikan dalam stack.h dan diimplementasikan di stack.cpp. File ini meng-include "stack.h" agar dapat mengakses struktur dan fungsi-fungsi stack, serta meng-include <iostream> untuk menampilkan output ke layar menggunakan cout.

Di dalam fungsi main(), program terlebih dahulu mendeklarasikan sebuah variabel stack bernama S, kemudian memanggil CreateStack(S) untuk menginisialisasi stack agar kosong. Setelah itu, dilakukan serangkaian operasi untuk menguji fungsi dasar stack, seperti Push dan Pop, dalam urutan berikut: Push(3), Push(4), Push(8), Pop(), Push(2), Push(3), Pop(), dan Push(9).

Setelah beberapa elemen dimasukkan dan dihapus, program menampilkan kondisi stack dengan mencetak tulisan "Stack sebelum dibalik:", lalu memanggil printInfo(S) untuk menampilkan isi stack dari elemen teratas hingga terbawah.

Berikutnya, program menguji fungsi balikStack(S) untuk membalik urutan elemen di dalam stack. Setelah proses pembalikan selesai, ditampilkan kembali hasilnya dengan mencetak "Stack sesudah dibalik:", diikuti pemanggilan printInfo(S) untuk memperlihatkan perbedaan urutan sebelum dan sesudah dibalik.

Secara keseluruhan, main.cpp bertugas menguji apakah semua fungsi stack—mulai dari inisialisasi, penambahan, penghapusan, penampilan, hingga pembalikan—berjalan dengan benar sesuai konsep LIFO (Last In, First Out).

**Output** 

 ![alt text](Output/Output%20compile.png)

  
## 5. Unguided

### 5.1 Unguided 1
```c++

#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

```


**Penjelasan :**  Program ini merupakan implementasi sederhana dari struktur data stack (tumpukan) dalam bahasa C++. Pada awal program, ditampilkan pesan “Hello world!” kemudian dibuat sebuah stack kosong dengan memanggil fungsi CreateStack(S). Setelah itu, program menambahkan beberapa elemen ke dalam stack menggunakan operasi push, seperti angka 3, 4, dan 8. Selanjutnya dilakukan operasi pop untuk menghapus elemen teratas. Program kembali menambahkan elemen lain (2, 3, dan 9) dengan urutan tertentu menggunakan kombinasi push dan pop. Setelah semua proses selesai, isi stack ditampilkan melalui fungsi printInfo(S). Kemudian program menampilkan teks “balik stack” dan memanggil fungsi balikStack(S) untuk membalik urutan elemen yang ada di dalam stack, lalu menampilkan hasilnya kembali. Secara keseluruhan, program ini menunjukkan bagaimana operasi dasar stack bekerja — yaitu push, pop, dan pembalikan elemen.


**Output** 

 ![alt text](Output/Unguided1%20Modul6.png)


 ### 5.2 Unguided 2
```c++

#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;
    Stack S;

    CreateStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);

    cout << "balik stack" << endl;
    
    balikStack(S);
    printInfo(S);

    return 0;
}

```

**Penjelasan :**Program ini merupakan contoh penggunaan stack dengan fitur pushAscending, yaitu menambahkan elemen ke dalam stack secara otomatis dalam urutan menaik (dari nilai terkecil ke terbesar). Pada awalnya, program menampilkan teks “Hello World!” dan membuat stack kosong menggunakan CreateStack(S). Selanjutnya, beberapa nilai seperti 3, 4, 8, 2, 3, dan 9 dimasukkan melalui fungsi pushAscending, sehingga isi stack tersusun secara berurutan berdasarkan nilai elemen. Setelah itu, fungsi printInfo(S) digunakan untuk menampilkan isi stack. Program kemudian menampilkan teks “balik stack” dan memanggil fungsi balikStack(S) untuk membalik urutan elemen di dalam stack. Hasil pembalikan tersebut kembali ditampilkan dengan printInfo(S). Secara keseluruhan, program ini memperlihatkan cara menyisipkan elemen secara terurut naik serta melakukan pembalikan isi stack dengan mudah.
  

**Output** 

 ![alt text](Output/Unguided2%20Modul6.png)



 ### 5.3 Unguided 3
```c++

#include "stack.h"
#include <iostream>
using namespace std;


int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);
    getInputStream(S);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}

```

**Penjelasan :**Program ini berfungsi untuk membaca data dari pengguna, menyimpannya ke dalam stack, dan menampilkan isi stack sebelum sertssa sesudah dibalik. Pertama, program mencetak teks “Hello world!” lalu membuat stack kosong menggunakan CreateStack(S). Setelah itu, fungsi getInputStream(S) digunakan untuk menerima input angka dari pengguna dan menambahkannya ke dalam stack secara berurutan. Setelah semua data dimasukkan, isi stack ditampilkan menggunakan printInfo(S) dari elemen teratas hingga terbawah. Selanjutnya, program menampilkan pesan “balik stack”, memanggil fungsi balikStack(S) untuk membalik urutan elemen di dalam stack, dan kembali menampilkan hasil akhirnya dengan printInfo(S). Secara keseluruhan, program ini memperlihatkan cara mengambil input dari pengguna, menyimpannya dalam struktur stack, serta membalik urutan elemennya.


**Output** 

 ![alt text](Output/Unguided3%20Modul6.png)



## 6. Kesimpulan

Berdasarkan hasil pelaksanaan program di atas, dapat disimpulkan bahwa tujuan pembelajaran mengenai penerapan struktur data Stack (Tumpukan) telah tercapai. Melalui implementasi berbagai operasi seperti push, pop, pushAscending, getInputStream, printInfo, dan balikStack, saya memahami bagaimana cara penyimpanan dan pengelolaan data dengan prinsip LIFO (Last In, First Out). Struktur data Stack memungkinkan pengaturan data secara efisien, terutama dalam proses pembalikan urutan maupun pengambilan elemen terakhir yang dimasukkan. Selain itu, penggunaan fungsi-fungsi yang terpisah membuat program menjadi lebih terstruktur, mudah dipahami, serta mendukung konsep modularisasi. Secara keseluruhan, praktikum ini memberikan pemahaman yang lebih mendalam mengenai konsep dasar serta penerapan nyata dari struktur data Stack dalam bahasa C++.

## 7. Referensi

1. Programiz. “Stack Data Structure.” https://www.programiz.com/dsa/stack
2. Fathurrozi, M., & WN, H. (2024). Application of Stack Data Structure in Application Development. JASIC (Journal of Applied Science, Informatics, and Computing), 2(1), 1-8.
3. GeeksforGeeks. “Stack Data Structure (Introduction and Implementation).” https://www.geeksforgeeks.org/stack-data-structure/