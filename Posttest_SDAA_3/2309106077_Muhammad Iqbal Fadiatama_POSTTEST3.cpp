#include <iostream>
#include <string>

using namespace std;

struct Sparepart {
    int id;
    string nama;
    string merk;
    int stok;
    Sparepart* next;  
};

Sparepart* head = nullptr;

void tambahSparepart(Sparepart** head) {
    Sparepart* sparepartBaru = new Sparepart;

    cout << "Masukkan ID Sparepart: ";
    cin >> sparepartBaru->id;
    cout << "Masukkan Nama Sparepart: ";
    cin.ignore();
    getline(cin, sparepartBaru->nama);
    cout << "Masukkan Merk Sparepart: ";
    getline(cin, sparepartBaru->merk);
    cout << "Masukkan Stok Sparepart: ";
    cin >> sparepartBaru->stok;

    sparepartBaru->next = *head;  
    *head = sparepartBaru; 

    cout << "Sparepart berhasil ditambahkan!" << endl;
}


void tampilkanSparepart(Sparepart* head) {
    if (head == nullptr) {
        cout << "Belum ada data sparepart." << endl;
        return;
    }

    Sparepart* temp = head;
    cout << "\nDaftar Sparepart:\n";
    while (temp != nullptr) {
        cout << "ID: " << temp->id << endl;
        cout << "Nama: " << temp->nama << endl;
        cout << "Merk: " << temp->merk << endl;
        cout << "Stok: " << temp->stok << endl;
        cout << "---------------------" << endl;
        temp = temp->next;
    }
}


void updateSparepart(Sparepart* head) {
    if (head == nullptr) {
        cout << "Belum ada data sparepart." << endl;
        return;
    }

    int id;
    cout << "Masukkan ID sparepart yang ingin diupdate: ";
    cin >> id;

    Sparepart* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "Masukkan Nama Baru: ";
            cin.ignore();
            getline(cin, temp->nama);
            cout << "Masukkan Merk Baru: ";
            getline(cin, temp->merk);
            cout << "Masukkan Stok Baru: ";
            cin >> temp->stok;

            cout << "Sparepart berhasil diupdate!" << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Sparepart dengan ID tersebut tidak ditemukan." << endl;
}


void hapusSparepart(Sparepart** head) {
    if (*head == nullptr) {
        cout << "Belum ada data sparepart." << endl;
        return;
    }

    int id;
    cout << "Masukkan ID sparepart yang ingin dihapus: ";
    cin >> id;

    Sparepart* temp = *head;
    Sparepart* prev = nullptr;


    if (temp != nullptr && temp->id == id) {
        *head = temp->next; 
        delete temp;  
        cout << "Sparepart berhasil dihapus!" << endl;
        return;
    }


    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Sparepart dengan ID tersebut tidak ditemukan." << endl;
        return;
    }

    prev->next = temp->next;  
    delete temp;  
    cout << "Sparepart berhasil dihapus!" << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu Manajemen Sparepart Mobil\n";
        cout << "1. Tambah Sparepart\n";
        cout << "2. Tampilkan Sparepart\n";
        cout << "3. Update Sparepart\n";
        cout << "4. Hapus Sparepart\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahSparepart(&head);
                break;
            case 2:
                tampilkanSparepart(head);
                break;
            case 3:
                updateSparepart(head);
                break;
            case 4:
                hapusSparepart(&head);
                break;
            case 5:
                cout << "Terima kasih! Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 5);

    return 0;
}
