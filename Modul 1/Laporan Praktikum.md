
## 1. Nama, NIM, Kelas

- **Nama**: Rizki Agung Prasetya

- **NIM**: 103112400263

- **Kelas**: IF 12-05

  

## 2. Motivasi Belajar Struktur Data

Belajar struktur data itu bukan cuma soal bisa bikin kode jalan, tapi tentang bagaimana kita membangun pola pikir yang teratur. Ibarat kita menata buku di perpustakaan, kalau asal taruh pasti bikin pusing saat mencari. Tapi dengan sistem penyimpanan yang jelas, semua jadi mudah ditemukan. Sama halnya dengan struktur data semakin kita paham cara menyusun dan mengelola data, semakin efisien program yang kita buat. Selain bermanfaat di dunia pemrograman, cara berpikir logis dan efisien ini juga terbawa ke kehidupan sehari-hari. Jadi meskipun awalnya terasa berat, anggap saja setiap konsep struktur data adalah fondasi kuat yang akan mempermudah kita menghadapi tantangan teknologi di masa depan.

  

## 3. Dasar Teori

Struktur data bisa diibaratkan sebagai wadah untuk menata dan menyimpan data di dalam komputer supaya mudah diakses dan dikelola dengan lebih cepat. Untuk mendukung pengolahan data tersebut, ada beberapa konsep dasar dalam pemrograman, misalnya loop, increment, dan if

  

## 4. Guided

### 4.1 Guided 1
```c++

#include <iostream>

  

using namespace std;

  

int main(){

    double total_pembelian, diskon;

    cout<<"berapa kamu belanja : Rp. ";

    cin>>total_pembelian;

    if(total_pembelian > 30000){

        diskon = 0.1 * total_pembelian;

        cout<<"kamu dapat diskon sebesar " << diskon << " orang kaya lu";

    }else {

        cout<<"kamu belanjanya masih dikit, tambah lah biar aku kaya";

    }

    return 0;

}
```

**Program di atas dibuat untuk menghitung diskon dari total belanja yang dimasukkan oleh pengguna.**  
Pertama, program akan meminta input berupa jumlah pembelian, kemudian menyimpannya ke dalam variabel `total_pembelian`. Setelah itu, program melakukan pengecekan dengan menggunakan struktur **if-else**.

**Output**

 ![alt text](Output/Modul%201%20Ss.png)
  

### 4.2 Guided 2
```c++

#include <iostream>

  

using namespace std;

  

int main(){

    float celcius,fahrenheit;

    cout<<"Tulis sedingin apa mas dhany: ";

    cin>>celcius;

    fahrenheit=(9.0/5.0) * celcius + 32;

    cout<<"kalau di fahrenheit itu"<<fahrenheit<<"derajat";

    cout<<"lu dingin banget sih";

    return 0;

}
```

**Penjelasan** : **Program di atas dibuat untuk mengonversi suhu dari satuan Celcius ke Fahrenheit.**  
Pertama, program mendeklarasikan dua variabel dengan tipe `float`, yaitu `celcius` untuk menampung input dari pengguna dan `fahrenheit` untuk menyimpan hasil konversi. Selanjutnya, program menampilkan pesan ke layar untuk meminta pengguna memasukkan suhu dalam Celcius, lalu membaca input tersebut menggunakan `cin`. Setelah nilai Celcius diperoleh, program menghitung konversinya ke Fahrenheit

**Output**

 ![alt text](Output/Modul%201%20Ss%20Guided%202.png)

  

### 4.3 Guided 3
```c++

#include <iostream>

  

using namespace std;

  

int main(){

    int r=20;

    int s;

  

    s=20 + ++r;

    cout<<"Nilai r saat ini"<<r<<endl;

    cout<<"Nilai s saat ini"<<s<<endl;

    return 0;

}
```


**Penjelasan : Program ini dibuat untuk memperlihatkan cara kerja operator increment prefix (++r)** pada sebuah variabel. Mula-mula, variabel `r` diberi nilai awal 20, sedangkan variabel `s` hanya dideklarasikan tanpa nilai. Pada baris `s = 20 + ++r;`, operator `++r` akan menambah nilai `r` terlebih dahulu dari 20 menjadi 21, kemudian nilai barunya dipakai dalam perhitungan. Jadi perhitungan berubah menjadi `s = 20 + 21;` sehingga `s` bernilai 41, sedangkan `r` sekarang bernilai 21. Selanjutnya, program mencetak kedua nilai tersebut ke layar dengan `cout`.

**Output**

 ![alt text](Output/Modul%201%20Ss%20Guided%203.png)
  

## 5. Unguided

### 5.1 Unguided 1
```c++

#include <iostream>

using namespace std;

  

int main() {

    float a, b;

    cout << "Masukkan bilangan pertama: ";

    cin >> a;

    cout << "Masukkan bilangan kedua: ";

    cin >> b;

  

    cout << "Hasil penjumlahan = " << a + b << endl;

    cout << "Hasil pengurangan = " << a - b << endl;

    cout << "Hasil perkalian   = " << a * b << endl;

    if (b != 0)

        cout << "Hasil pembagian   = " << a / b << endl;

    else

        cout << "Pembagian tidak bisa (b = 0)" << endl;

  

    return 0;

}
```


**Penjelasan :  Program di atas adalah contoh program sederhana untuk melakukan operasi hitung dasar dengan dua bilangan bertipe float. Pertama, program mendefinisikan dua variabel, yaitu `a` dan `b`. Setelah itu, program meminta pengguna untuk memasukkan dua bilangan melalui **cin**.

Setelah pengguna memberikan input, program langsung menghitung dan menampilkan hasil dari:

- Penjumlahan (`a + b`)
- Pengurangan (`a - b`)
- Perkalian (`a * b`)
    
Khusus untuk operasi pembagian, program menggunakan struktur **if-else** agar tidak terjadi kesalahan ketika membagi dengan nol. Jika nilai `b` tidak sama dengan nol, maka hasil pembagian `a / b` akan ditampilkan. Tetapi jika nilai `b` adalah nol, program akan menampilkan pesan bahwa pembagian tidak bisa dilakukan.

**Output** 

 ![alt text](Output/modul%201%20Ss%20unguided1.png)

  

### 5.2 Unguided 2
```c++

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
```

**Penjelasan :**  Program ini berfungsi untuk mengubah angka yang dimasukkan pengguna menjadi bentuk tulisan dalam bahasa Indonesia dengan rentang 0 sampai 100. Pertama, program mendefinisikan dua buah array string, yaitu satuan yang menyimpan kata untuk angka 0 sampai 9, dan belasan yang menyimpan kata untuk angka 10 sampai 19. Setelah itu, program meminta pengguna memasukkan sebuah angka, lalu angka tersebut diproses menggunakan struktur percabangan if-else. Jika angka kurang dari 10, program langsung menampilkan kata dari array satuan. Jika angka berada di antara 10 sampai 19, program menampilkan kata dari array belasan dengan indeks yang disesuaikan. Untuk angka 20 sampai 99, program akan membagi angka dengan 10 untuk mendapatkan nilai puluhan, lalu menampilkannya dengan tambahan kata "puluh". Jika angka tersebut tidak bulat puluhan, maka sisa bagi 10 akan digunakan untuk menampilkan satuannya. Jika angka yang dimasukkan adalah 100, maka program langsung menampilkan "seratus". Sedangkan jika angka yang dimasukkan berada di luar rentang 0 sampai 100, program akan menampilkan pesan "eror!".

**Output**

 ![alt text](Output/modul%201%20Ss%20unguided2.png)

  

### 5.3 Unguided 3
```c++

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
```



**Penjelasan :**  Program ini berfungsi untuk mencetak pola angka dengan menggunakan perulangan bersarang (nested loop). Pertama, program meminta pengguna memasukkan sebuah bilangan bulat n sebagai batas pola. Pada perulangan pertama, nilai i dimulai dari n dan terus berkurang hingga 1. Di dalamnya terdapat perulangan lain dengan variabel j yang menampilkan deret angka menurun dari i hingga 1. Setelah angka-angka tersebut ditampilkan, program menambahkan sebuah tanda bintang * di akhir baris. Selanjutnya, terdapat perulangan kedua yang menampilkan deret angka naik dari 1 hingga i, kemudian diakhiri dengan pindah baris. Dengan kombinasi kedua perulangan ini, program menghasilkan pola simetris berupa angka menurun di sebelah kiri, tanda bintang di tengah, dan angka menaik di sebelah kanan. Sebagai contoh, jika pengguna memasukkan angka 3, keluaran yang ditampilkan adalah 321_123 pada baris pertama, 21_12 pada baris kedua, dan 1*1 pada baris terakhir.

 **Output**

 ![alt text](Output/modul%201%20Ss%20unguided3.png)
  

## 6. Kesimpulan

Dari praktikum yang telah dilakukan, dapat disimpulkan bahwa tujuan untuk memahami dasar-dasar pemrograman telah tercapai, mulai dari penggunaan percabangan, operasi aritmatika, konversi data, hingga perulangan bersarang. Latihan Guided membantu memahami konsep dasar, sedangkan latihan Unguided melatih logika dalam menyelesaikan masalah secara mandiri. Secara keseluruhan, praktikum ini memperkuat pemahaman tentang hubungan teori dan penerapan dalam pembuatan program sederhana yang bermanfaat.
  

## 7. Referensi

1. GeeksforGeeks. “C++ Programming Language.” [https://www.geeksforgeeks.org/c-plus-plus/](https://www.geeksforgeeks.org/c-plus-plus/)
2. W3Schools. “C++ Tutorial.” [https://www.w3schools.com/cpp/](https://www.w3schools.com/cpp/)