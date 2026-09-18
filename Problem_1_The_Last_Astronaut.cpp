#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "Masukkan jumlah astronaut (N): ";
    cin >> N;
    cout << "Masukkan nilai K: ";
    cin >> K;

    if (N <= 0) {
        cout << "N harus lebih dari 0." << endl;
        return 0;
    }

    if (K < 2) K = 2;

    int* astronaut = new int[N];

    for (int i = 0; i < N; i++)
        astronaut[i] = i + 1;

    int jumlah = N;
    int posisi = 0;

    cout << "\nUrutan eliminasi: ";

    while (jumlah > 1) {
        int indeks = (posisi + K - 1) % jumlah;
        int tereliminasi = astronaut[indeks];

        cout << tereliminasi;
        if (jumlah > 2) cout << " -> ";

        // K berubah sesuai nomor astronaut yang dieliminasi.
        if (tereliminasi % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
            if (K < 2) K = 2;
        }

        // Menghapus astronaut dari array.
        for (int i = indeks; i < jumlah - 1; i++)
            astronaut[i] = astronaut[i + 1];

        jumlah--;

        // Hitungan berikutnya dimulai dari astronaut setelah
        // astronaut yang baru saja dieliminasi.
        if (jumlah > 0)
            posisi = indeks % jumlah;
    }

    cout << "\nAstronaut terakhir yang bertahan: "
         << astronaut[0] << endl;

    delete[] astronaut;
    return 0;
}
