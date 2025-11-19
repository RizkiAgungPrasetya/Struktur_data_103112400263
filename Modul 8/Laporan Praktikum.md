
## 1. Nama, NIM, Kelas

- **Nama**: Rizki Agung Prasetya

- **NIM**: 103112400263

- **Kelas**: IF 12-05

  

## 2. Motivasi Belajar Struktur Data

Belajar struktur data itu bukan cuma soal bisa bikin kode jalan, tapi tentang bagaimana kita membangun pola pikir yang teratur. Ibarat kita menata buku di perpustakaan, kalau asal taruh pasti bikin pusing saat mencari. Tapi dengan sistem penyimpanan yang jelas, semua jadi mudah ditemukan. Sama halnya dengan struktur data semakin kita paham cara menyusun dan mengelola data, semakin efisien program yang kita buat. Selain bermanfaat di dunia pemrograman, cara berpikir logis dan efisien ini juga terbawa ke kehidupan sehari-hari. Jadi meskipun awalnya terasa berat, anggap saja setiap konsep struktur data adalah fondasi kuat yang akan mempermudah kita menghadapi tantangan teknologi di masa depan.

  

## 3. Dasar Teori

Queue (antrean) adalah struktur data yang bekerja dengan prinsip FIFO (First-In, First-Out), artinya data yang masuk pertama akan keluar terlebih dahulu. Elemen baru dimasukkan melalui Tail (enqueue) dan elemen yang keluar diambil dari Head (dequeue).

Queue dapat diimplementasikan menggunakan Array, dengan bantuan dua variabel: head dan tail.
Pada metode sederhana, dequeue tidak efisien karena setiap penghapusan membuat seluruh elemen harus digeser ke kiri.

Untuk memperbaikinya, digunakan metode yang hanya memajukan indeks head tanpa menggeser elemen. Namun, cara ini bisa menyebabkan masalah "penuh semu", yaitu ketika tail mencapai akhir array padahal masih ada ruang kosong di depan.

Solusi terbaik adalah Circular Queue, di mana array dianggap melingkar. Ketika head atau tail mencapai indeks terakhir, posisinya kembali ke 0 menggunakan operasi modulo (%). Metode ini membuat enqueue dan dequeue lebih efisien serta menghilangkan masalah penuh semu.
  

## 4. Guided

### 4.1 Guided 1
```c++

#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);

bool isEmpty(Queue Q);

bool isFull(Queue Q);

void enqueue(Queue &Q, int x);

int dequeue(Queue &Q);

void printInfo(Queue Q);

#endif

```

**Penjelasan :** File header queue.h berfungsi sebagai rancangan dasar (blueprint) untuk struktur data Queue. Di dalamnya ditentukan bahwa antrean memiliki kapasitas maksimal sebanyak 5 elemen melalui konstanta MAX_QUEUE. Selain itu, dibuat pula alias tipe data infotype yang menggunakan tipe int.

File ini mendeklarasikan struct Queue, yang berisi array info sebagai tempat menyimpan data antrean serta dua variabel head dan tail sebagai penanda posisi awal dan akhir antrean. Selain itu, queue.h juga berisi daftar prototipe fungsi seperti createQueue, enqueue, dequeue, dan lainnya, yang nanti akan digunakan untuk mengelola antrean. Sementara itu, detail implementasi fungsi-fungsi tersebut berada pada file .cpp yang terpisah.



### 4.2 Guided 2
```c++
#include "queue.h"
#include <iostream>

using namespace std;

void createQueue(Queue &Q){
    Q.head = 0;
    Q.tail = 0;
    Q.count = 0;
}

bool isEmpty(Queue Q){
    return Q.count == 0; 
}

bool isFull(Queue Q){
    return Q.count == MAX_QUEUE; 
}

void enqueue(Queue &Q, int x){
    if(!isFull(Q)){
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
        Q.count++;
    } else {
        cout << "Antrian Penuh!" << endl;
    }
}

int dequeue(Queue &Q){
    if(!isEmpty(Q)){
        int x = Q.info[Q.head];
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--;
        return x;
    } else {
        cout << "Antrian Kosong!" << endl;
        return -1;
    }
}

void printInfo(Queue Q){
    cout << "Isi Queue: [ ";
    if(!isEmpty(Q)){
        int i = Q.head;
        int n = 0;
        while (n < Q.count){
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX_QUEUE;
            n++;
        }
    }
    cout << "]" << endl;
}

```

**Penjelasan** : Kode ini merupakan implementasi Circular Queue yang memanfaatkan variabel count untuk menghitung berapa banyak elemen yang sedang berada di dalam antrean. Pendekatan ini adalah bentuk lain dari Alternatif 3 dalam modul dan membuat proses pengecekan antrean penuh atau kosong menjadi jauh lebih sederhana.

Pada fungsi createQueue, antrean diinisialisasi dengan men-set head, tail, dan count ke nilai 0. Karena sudah ada variabel count, fungsi isEmpty cukup memeriksa apakah count bernilai 0, dan isFull hanya perlu melihat apakah count telah mencapai MAX_QUEUE.

Fungsi enqueue menambahkan elemen baru dengan terlebih dahulu memastikan antrean tidak penuh. Jika masih ada ruang, data dimasukkan ke posisi tail. Setelah itu, tail digeser maju secara melingkar menggunakan (Q.tail + 1) % MAX_QUEUE, lalu count dinaikkan satu.

Fungsi dequeue berjalan dengan cara yang hampir sama. Fungsi ini mengecek apakah antrean memiliki elemen. Jika ada, elemen pada posisi head diambil dan disimpan ke variabel x. Kemudian head dipindahkan ke indeks berikutnya—juga memakai operasi modulo—dan count dikurangi. Nilai elemen yang dihapus kemudian dikembalikan. Jika antrean kosong, fungsi menampilkan pesan peringatan dan mengembalikan nilai -1.

Fungsi printInfo mencetak isi antrean mulai dari posisi head. Alih-alih memikirkan posisi akhir antrean, fungsi ini hanya melakukan perulangan sebanyak jumlah elemen (Q.count). Pada setiap langkah, ia mencetak elemen di indeks saat ini lalu memajukan indeks tersebut secara melingkar, sehingga seluruh isi antrean dapat ditampilkan dengan benar.


### 4.3 Guided 3
```c++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue Q;

    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 Elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    cout << "\n Dequeue 1 Elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 1 Elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\n Dequeue 2 Elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}


```

**Penjelasan** : File main.cpp berfungsi sebagai program utama yang digunakan untuk menguji cara kerja struktur data Queue yang kamu buat. Program ini dimulai dengan menampilkan judul tabel (H - T : Queue Info), lalu memanggil createQueue untuk menginisialisasi antrean Q dan menampilkan kondisinya saat masih kosong.

Selanjutnya, program melakukan simulasi operasi antrean dengan menambahkan tiga data secara berurutan: enqueue(5), enqueue(2), dan enqueue(7). Setelah itu, program menjalankan skenario campuran: dua kali dequeue (mengambil elemen 5 dan 2), kemudian satu kali enqueue(4), lalu mengosongkan antrean sepenuhnya dengan tiga kali pemanggilan dequeue.

Keunggulan dari main.cpp ini adalah setiap operasi selalu diikuti oleh pemanggilan printInfo, sehingga perubahan pada isi antrean serta posisi head dan tail dapat terlihat dengan jelas pada setiap langkah.

**Output** 

 ![alt text](Output/Outpu%20Guided%20Modul%208.png)

  
## 5. Unguided

### 5.1 Unguided 1
```c++

#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX_QUEUE - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0; 
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
        if (Q.tail == -1) { 
            Q.head = -1;    
        }
        return x; 
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " : "; 
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl; 
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

```


**Penjelasan :**  Kode ini adalah implementasi dasar dari struktur data Queue menggunakan array biasa, tanpa menggunakan teknik “circular”. Saat queue diinisialisasi melalui createQueue, nilai head dan tail diatur menjadi -1 untuk menandakan bahwa antrean masih kosong. Fungsi isEmptyQueue menentukan kekosongan dengan mengecek apakah tail == -1, sedangkan isFullQueue memastikan apakah tail telah mencapai indeks maksimum (MAX_QUEUE - 1).

Pada operasi enqueue, jika antrean masih kosong maka head diubah menjadi 0. Setelah itu, tail dinaikkan satu dan elemen baru disimpan pada posisi tersebut. Jika antrean sudah penuh, program menampilkan pesan peringatan.

Untuk operasi dequeue, data yang berada di posisi head diambil terlebih dahulu. Setelah itu, semua elemen yang berada di belakangnya digeser satu langkah ke depan untuk menjaga urutan antrean. Nilai tail kemudian dikurangi satu. Jika setelah penghapusan elemen jumlah data menjadi kosong, maka head dan tail dikembalikan lagi ke -1.

Fungsi printInfo hanya bertugas menampilkan posisi head–tail serta isi antrean saat ini. Secara keseluruhan, kode ini memperlihatkan cara kerja antrean dengan prinsip FIFO, tetapi menggunakan metode penggeseran elemen setiap kali ada penghapusan.


**Output** 

 ![alt text](Output/Unguided1%20modul%208.png)


 ### 5.2 Unguided 2
```c++

#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.tail == -1 || Q.head > Q.tail;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX_QUEUE - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh (Penuh Semu)!" << endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0; 
        }
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        
        Q.head++; 
        
        if (Q.head > Q.tail) { 
            Q.head = -1;       
            Q.tail = -1;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}

```

**Penjelasan :**Kode ini adalah implementasi queue sederhana menggunakan array biasa, namun lebih efisien karena tidak melakukan pergeseran elemen saat proses dequeue. Ketika queue dibuat melalui createQueue, nilai head dan tail diset ke -1 sebagai tanda bahwa antrean masih kosong. Fungsi isEmptyQueue memeriksa dua kondisi: apakah tail == -1, atau apakah head sudah melewati tail, yang berarti antrean menjadi kosong setelah beberapa kali menghapus elemen. Di sisi lain, isFullQueue cukup melihat apakah tail telah mencapai indeks maksimum array.

Pada operasi enqueue, jika antrean penuh maka muncul pesan peringatan. Jika masih tersedia ruang, data dimasukkan ke posisi tail + 1. Jika sebelumnya antrean kosong, head diatur terlebih dahulu menjadi 0. Untuk operasi dequeue, elemen yang berada di head diambil, lalu head dinaikkan satu. Jika setelah peningkatan posisi head menjadi lebih besar dari tail, maka antrean dianggap kembali kosong dan kedua indeks dikembalikan ke -1.

Fungsi printInfo hanya bertugas menampilkan posisi head–tail serta seluruh isi antrean dari indeks head sampai tail. Secara keseluruhan, kode ini menunjukkan penerapan queue berprinsip FIFO, dengan cara yang lebih sederhana karena tidak perlu memindahkan atau menggeser elemen saat penghapusan data.
  

**Output** 

 ![alt text](Output/Unguided2%20modul8.png)



 ### 5.3 Unguided 3
```c++

#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = 0;
    Q.tail = 0;
}

bool isEmptyQueue(Queue Q) {
    return Q.head == Q.tail;
}

bool isFullQueue(Queue Q) {
    return (Q.tail + 1) % MAX_QUEUE == Q.head;
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrean Penuh!" << endl;
    } else {
        Q.info[Q.tail] = x;
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Antrean Kosong!" << endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];
        Q.head = (Q.head + 1) % MAX_QUEUE; 
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | "; 
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        int i = Q.head;
        while (i != Q.tail) {
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX_QUEUE; 
        }
        cout << endl;
    }
}

```

**Penjelasan :**Kode ini adalah implementasi queue model circular, di mana ujung array dapat kembali ke indeks awal ketika mencapai batas. Pada saat createQueue dipanggil, nilai head dan tail diinisialisasi dengan angka 0. Queue dianggap kosong jika head dan tail berada pada posisi yang sama, dan dianggap penuh jika posisi tail berada satu langkah di depan head dalam pola melingkar.

Dalam fungsi enqueue, selama antrean belum penuh, data disimpan pada indeks tail, lalu tail digeser maju menggunakan operasi modulo agar dapat kembali ke indeks 0 ketika mencapai akhir array. Pada fungsi dequeue, elemen di posisi head diambil, kemudian head juga dipindahkan satu langkah dengan teknik modulo. Metode ini menghindari proses penggeseran elemen secara manual sehingga lebih efisien.

Fungsi printInfo menampilkan posisi head–tail dan kemudian mencetak elemen queue mulai dari head, berputar mengikuti indeks circular, dan berhenti ketika mencapai tail. Secara keseluruhan, kode ini menunjukkan mekanisme circular queue yang teratur, hemat operasi, dan cocok untuk antrean dengan kapasitas tetap.


**Output** 

 ![alt text](Output/Unguided3%20modul8.png)



## 6. Kesimpulan

Dari hasil praktikum, dapat disimpulkan bahwa penerapan struktur data Queue berhasil dipahami dengan baik. Melalui operasi enqueue, dequeue, isEmpty, isFull, dan printInfo, saya mengerti bagaimana data dikelola menggunakan prinsip FIFO, di mana elemen pertama masuk menjadi yang pertama keluar. Penggunaan circular queue juga membuat proses lebih efisien karena tidak perlu menggeser elemen. Selain itu, pemisahan fungsi-fungsi membuat program lebih rapi dan mudah dipahami. Secara keseluruhan, praktikum ini memberikan gambaran jelas tentang cara kerja dan implementasi Queue dalam C++.

## 7. Referensi

1. Programiz. “Queue Data Structure.” https://www.programiz.com/dsa/queue
2. GeeksforGeeks. “Queue Data Structure (Introduction and Implementation).” https://www.geeksforgeeks.org/queue-data-structure/
3. Bollina, S. V. T. (2024). What is a circular queue, and how does it differ from a regular queue?