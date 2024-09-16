#include <iostream>
using namespace std;

void Menarahanoi(int i, char asal, char tujuan, char sementara) {
    if (i == 1) {
        cout << "Pindahkan piringan 1 dari " << asal << " ke " << tujuan << endl;
    } else {
        Menarahanoi(i - 1, asal, sementara, tujuan);
        cout << "Pindahkan piringan " << i << " dari " << asal << " ke " << tujuan << endl;
        Menarahanoi(i - 1, sementara, tujuan, asal);
    }
}

int main() {
    int jumlah_piringan = 3;
    Menarahanoi(jumlah_piringan, 'A', 'C', 'B');
    return 0;
}
