#include <iostream>
using namespace std;

int main() {
    char pesan[1000];

    cout << "Masukkan pesan (huruf A-Z): ";
    cin >> pesan;

    cout << "Hasil sandi: ";

    int i = 0;

    while (pesan[i] != '\0') {
        // Huruf pertama tidak berubah.
        if (i == 0) {
            cout << pesan[i];
        } else {
            // A=1, B=2, ..., Z=26
            int nilaiSekarang = pesan[i] - 'A' + 1;
            int nilaiSebelumnya = pesan[i - 1] - 'A' + 1;

            int nilaiBaru = nilaiSekarang + nilaiSebelumnya;

            // Jika melewati Z, kembali dari A.
            while (nilaiBaru > 26)
                nilaiBaru -= 26;

            char hurufBaru = char('A' + nilaiBaru - 1);
            cout << hurufBaru;
        }

        i++;
    }

    cout << endl;
    return 0;
}
