#include <iostream>
using namespace std;

struct charML{
    string nama;
    charML *next;
} *head, *tail, *curr;

int main(){
    curr = new charML;
    curr->nama = "Lucan";
    curr->next = NULL;
    head = tail = curr;

    curr = new charML;
    curr->nama = "Miya";
    curr->next = NULL;
    tail->next = curr;
    tail = curr;

    curr = new charML;
    curr->nama = "Zilong";
    curr->next = NULL;
    tail->next = curr;
    tail = curr;

    curr = new charML;
    curr->nama = "Valir";
    curr->next = NULL;
    tail->next = curr;
    tail = curr;

    curr = new charML;
    curr->nama = "julian";
    curr->next = NULL;
    tail->next = curr;
    tail = curr;

    cout << "Nama Hero ML:" << endl;
    curr = head;
    while(curr != NULL){
        cout << curr->nama << endl;
        curr = curr->next;
    }

    return 0;
}
