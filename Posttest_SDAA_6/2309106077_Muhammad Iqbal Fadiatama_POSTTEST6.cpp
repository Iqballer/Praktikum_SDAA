#include <iostream>
#include <string>
#include <vector>
#include <cmath> // Untuk fungsi sqrt

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
    cin.ignore(); // Membersihkan buffer sebelum input string
    cout << "Masukkan Nama Sparepart: ";
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
    if (!head) {
        cout << "Belum ada data sparepart." << endl;
        return;
    }

    Sparepart* temp = head;
    cout << "\nDaftar Sparepart:\n";
    while (temp) {
        cout << "ID: " << temp->id << endl;
        cout << "Nama: " << temp->nama << endl;
        cout << "Merk: " << temp->merk << endl;
        cout << "Stok: " << temp->stok << endl;
        cout << "---------------------" << endl;
        temp = temp->next;
    }
}

void updateSparepart(Sparepart* head) {
    if (!head) {
        cout << "Belum ada data sparepart." << endl;
        return;
    }

    int id;
    cout << "Masukkan ID sparepart yang ingin diupdate: ";
    cin >> id;

    Sparepart* temp = head;
    while (temp) {
        if (temp->id == id) {
            cin.ignore();
            cout << "Masukkan Nama Baru: ";
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
    if (!*head) {
        cout << "Belum ada data sparepart." << endl;
        return;
    }

    int id;
    cout << "Masukkan ID sparepart yang ingin dihapus: ";
    cin >> id;

    Sparepart* temp = *head;
    Sparepart* prev = nullptr;

    if (temp && temp->id == id) {
        *head = temp->next;
        delete temp;
        cout << "Sparepart berhasil dihapus!" << endl;
        return;
    }

    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Sparepart dengan ID tersebut tidak ditemukan." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Sparepart berhasil dihapus!" << endl;
}

Sparepart* merge(Sparepart* left, Sparepart* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->id < right->id) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

Sparepart* mergeSort(Sparepart* head) {
    if (!head || !head->next) return head;

    Sparepart* slow = head;
    Sparepart* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Sparepart* mid = slow->next;
    slow->next = nullptr;

    Sparepart* left = mergeSort(head);
    Sparepart* right = mergeSort(mid);

    return merge(left, right);
}

Sparepart* partitionDesc(Sparepart* head, Sparepart* end, Sparepart** newHead, Sparepart** newEnd) {
    Sparepart* pivot = end;
    Sparepart* prev = nullptr, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->id > pivot->id) {
            if (!*newHead) *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Sparepart* temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if (!*newHead) *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Sparepart* quickSortRecurDesc(Sparepart* head, Sparepart* end) {
    if (!head || head == end) return head;

    Sparepart* newHead = nullptr, *newEnd = nullptr;
    Sparepart* pivot = partitionDesc(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Sparepart* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr;

        newHead = quickSortRecurDesc(newHead, temp);
        temp = newHead;
        while (temp->next) temp = temp->next;
        temp->next = pivot;
    }

    pivot->next = quickSortRecurDesc(pivot->next, newEnd);
    return newHead;
}

void quickSortDesc(Sparepart** headRef) {
    *headRef = quickSortRecurDesc(*headRef, nullptr);
}

void cariSparepart() {
    int pilihan;
    cout << "\nPilih metode pencarian:\n";
    cout << "1. Fibonacci Search (ID)\n";
    cout << "2. Jump Search (ID)\n";
    cout << "3. Boyer-Moore Search (Nama)\n";
    cout << "Pilih metode: ";
    cin >> pilihan;

    if (pilihan == 1 || pilihan == 2) {
        int id;
        cout << "Masukkan ID yang dicari: ";
        cin >> id;

        // Panggil fungsi pencarian sesuai pilihan
    } else if (pilihan == 3) {
        string nama;
        cout << "Masukkan Nama yang dicari: ";
        cin.ignore();
        getline(cin, nama);

        // Pencarian berdasarkan nama
    } else {
        cout << "Pilihan tidak valid!" << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\nMenu Manajemen Sparepart Mobil\n";
        cout << "1. Tambah Sparepart\n";
        cout << "2. Tampilkan Sparepart\n";
        cout << "3. Update Sparepart\n";
        cout << "4. Hapus Sparepart\n";
        cout << "5. Sorting Merge Sort\n";
        cout << "6. Sorting Quick Sort Descending\n";
        cout << "7. Cari barang\n";
        cout << "8. Keluar\n";
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
                head = mergeSort(head);
                cout << "Data diurutkan dengan Merge Sort!" << endl;
                break;
            case 6:
                quickSortDesc(&head);
                cout << "Data diurutkan dengan Quick Sort Descending!" << endl;
                break;
            case 7:
                cariSparepart();
                break;
            case 8:
                cout << "Terima kasih! Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 8);

    return 0;
}
