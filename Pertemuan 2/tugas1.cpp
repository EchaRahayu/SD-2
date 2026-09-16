#include <iostream>
using namespace std;

// Deklarasi sebuah struktur node
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// TODO : Insert di Depan
void insertFirst(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if(head == NULL) {
        head = newNode;
        tail = head;
    } else {
        newNode -> next = head;
        head = newNode;
    }

    cout << "Node berhasil ditambahkan di depan \n";
}

// TODO : Insert di belakang
void insertLast(int n) {
    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    if(head == NULL) {
        head = newNode;
        tail = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }

    cout << "Node berhasil ditambahkan di belakang \n";
}

// TODO : Insert setelah nilai tertentu
void insertAfter(int n, int check) {
    if(head == NULL) {
        cout << "List kosong, insert di depan dulu \n";
        return;
    }

    Node *newNode = new Node;
    newNode -> value = n;
    newNode -> next = NULL;

    Node *p = head;

    while(p != NULL && p -> value != check) {
        p = p -> next;
    }

    if(p == NULL) {
        cout << "Node dengan nilai " << check
             << " tidak ada \n";
        delete newNode;
    } else {
        newNode -> next = p -> next;
        p -> next = newNode;

        if(p == tail) {
            tail = newNode;
        }

        cout << "Node berhasil ditambahkan setelah "
             << check << " \n";
    }
}

// TODO : Hapus berdasarkan nilai
void deleteByValue(int check) {
    if(head == NULL) {
        cout << "List kosong, tidak ada yang dihapus \n";
        return;
    }

    Node *p = head;
    Node *prev = NULL;

    while(p != NULL && p -> value != check) {
        prev = p;
        p = p -> next;
    }

    if(p == NULL) {
        cout << "Node dengan nilai " << check
             << " tidak ada \n";
        return;
    }

    if(p == head) {
        head = head -> next;
    } else {
        prev -> next = p -> next;
    }

    if(p == tail) {
        tail = prev;
    }

    delete p;

    if(head == NULL) {
        tail = NULL;
    }

    cout << "Node dengan nilai " << check
         << " berhasil dihapus \n";
}

// Cetak linked list
void printList() {
    Node *p = head;

    cout << "Isi dari linked list : ";

    while(p != NULL) {
        cout << p -> value << " -> ";
        p = p -> next;
    }

    cout << "NULL\n";
}

// Hapus semua node
void deleteAll() {
    Node *p = head;

    while(p != NULL) {
        Node *hapus = p;
        p = p -> next;
        delete hapus;
    }

    head = NULL;
    tail = NULL;
}

// Menu utama tanpa switch-case
int main() {
    int pilihan;
    int n;
    int check;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "===================================\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if(pilihan == 1) {
            cout << "Masukkan nilai: ";
            cin >> n;

            insertFirst(n);
            printList();
        }
        else if(pilihan == 2) {
            cout << "Masukkan nilai: ";
            cin >> n;

            insertLast(n);
            printList();
        }
        else if(pilihan == 3) {
            cout << "Masukkan nilai baru: ";
            cin >> n;

            cout << "Masukkan nilai yang ingin dicari: ";
            cin >> check;

            insertAfter(n, check);
            printList();
        }
        else if(pilihan == 4) {
            cout << "Masukkan nilai yang ingin dihapus: ";
            cin >> check;

            deleteByValue(check);
            printList();
        }
        else if(pilihan == 5) {
            printList();
        }
        else if(pilihan == 0) {
            deleteAll();
            cout << "Program selesai.\n";
        }
        else {
            cout << "Pilihan tidak valid.\n";
        }

    } while(pilihan != 0);

    return 0;
}