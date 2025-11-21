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