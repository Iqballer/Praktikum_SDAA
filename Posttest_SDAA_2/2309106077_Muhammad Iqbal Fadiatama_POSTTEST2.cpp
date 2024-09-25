#include <iostream>
#include <string>

using namespace std;


struct Sparepart {
    int id;
    string nama;
    string merk;
    int stok;
};


const int MAX_SPAREPART = 100;
Sparepart spareparts[MAX_SPAREPART];
int jumlahSparepart = 0;


void tambahSparepart(Sparepart* spareparts, int* jumlahSparepart) {
    if (*jumlahSparepart >= MAX_SPAREPART) {
        cout << "Data sparepart penuh!" << endl;
        return;
    }
    
    Sparepart sparepartBaru;
    cout << "Masukkan ID Sparepart: ";
    cin >> sparepartBaru.id;
    cout << "Masukkan Nama Sparepart: ";
    cin.ignore();
    getline(cin, sparepartBaru.nama);
    cout << "Masukkan Merk Sparepart: ";
    getline(cin, sparepartBaru.merk);
    cout << "Masukkan Stok Sparepart: ";
    cin >> sparepartBaru.stok;
    
    spareparts[*jumlahSparepart] = sparepartBaru;
    (*jumlahSparepart)++;
    
    cout << "Sparepart berhasil ditambahkan!" << endl;
}


void tampilkanSparepart(Sparepart* spareparts, int jumlahSparepart) {
    if (jumlahSparepart == 0) {
        cout << "Belum ada data sparepart." << endl;
        return;
    }
    
    cout << "\nDaftar Sparepart:\n";
    for (int i = 0; i < jumlahSparepart; i++) {
        cout << "ID: " << spareparts[i].id << endl;
        cout << "Nama: " << spareparts[i].nama << endl;
        cout << "Merk: " << spareparts[i].merk << endl;
        cout << "Stok: " << spareparts[i].stok << endl;
        cout << "---------------------" << endl;
    }
}


void updateSparepart(Sparepart* spareparts, int jumlahSparepart) {
    if (jumlahSparepart == 0) {
        cout << "Belum ada data sparepart." << endl;
        return;
    }

    int id;
    cout << "Masukkan ID sparepart yang ingin diupdate: ";
    cin >> id;

    for (int i = 0; i < jumlahSparepart; i++) {
        if (spareparts[i].id == id) {
            cout << "Masukkan Nama Baru: ";
            cin.ignore();
            getline(cin, spareparts[i].nama);
            cout << "Masukkan Merk Baru: ";
            getline(cin, spareparts[i].merk);
            cout << "Masukkan Stok Baru: ";
            cin >> spareparts[i].stok;
            
            cout << "Sparepart berhasil diupdate!" << endl;
            return;
        }
    }

    cout << "Sparepart dengan ID tersebut tidak ditemukan." << endl;
}


void hapusSparepart(Sparepart* spareparts, int* jumlahSparepart) {
    if (*jumlahSparepart == 0) {
        cout << "Belum ada data sparepart." << endl;
        return;
    }

    int id;
    cout << "Masukkan ID sparepart yang ingin dihapus: ";
    cin >> id;

    for (int i = 0; i < *jumlahSparepart; i++) {
        if (spareparts[i].id == id) {
            for (int j = i; j < *jumlahSparepart - 1; j++) {
                spareparts[j] = spareparts[j + 1];
            }

            (*jumlahSparepart)--;

            cout << "Sparepart berhasil dihapus!" << endl;
            return;
        }
    }

    cout << "Sparepart dengan ID tersebut tidak ditemukan." << endl;
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
                tambahSparepart(spareparts, &jumlahSparepart);
                break;
            case 2:
                tampilkanSparepart(spareparts, jumlahSparepart);
                break;
            case 3:
                updateSparepart(spareparts, jumlahSparepart);
                break;
            case 4:
                hapusSparepart(spareparts, &jumlahSparepart);
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
