#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <limits> 

using namespace std;

int main() {

    string validName = "Sufi"; 
    string validPass = "101";

    string inputName, inputPass;
    int attempt = 0;
    const int maxAttempt = 4;
    bool loginSuccess = false;
    
    while (attempt < maxAttempt) {
        cout << endl;
        if (attempt == 0) {
            cout << "=== Login ===" << endl;
        } else {
            cout << "=== Login (Sisa Percobaan " << (maxAttempt - attempt) << ") ===" << endl;
        }

        cout << "Masukkan Nama : ";
        cin >> inputName;
        cout << "Masukkan Password : ";
        cin >> inputPass;

        if (inputName == validName && inputPass == validPass) {
            loginSuccess = true;
            break; 
        } else {
            cout << "Nama atau Password Salah" << endl;
            attempt++; 
        }
    }

    if (!loginSuccess) {
        cout << "\nPercobaan Gagal! Silahkan Coba Lagi" << endl;
        return 0; 
    }

    cout << "\nLogin Berhasil! Selamat Datang, " << inputName << "." << endl;
    
    system("pause"); 
    system("cls");   

    int pilihan;
    double nilaiInput;

    do {
        cout << "\n=== MENU KONVERSI WAKTU ===" << endl;
        cout << "1. Konversi Jam -> Menit dan Detik" << endl;
        cout << "2. Konversi Menit -> Jam dan Detik" << endl;
        cout << "3. Konversi Detik -> Jam dan Menit" << endl;
        cout << "4. Keluar" << endl;
        cout << "-------------------------------" << endl;
        cout << "Pilih menu (1-4): ";
        
        if (!(cin >> pilihan)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "\nTidak Valid! Harap Masukkan Angka (1-4)" << endl;
            continue;
        }

        if (pilihan < 1 || pilihan > 4) {
            cout << "\nTidak Valid! Silakan Pilih 1-4." << endl;
            continue;
        }

        if (pilihan == 4) {
            cout << "\n=== Terima Kasih ===" << endl;
            break; 
        }

        cout << "\nMasukkan Nilai Waktu: ";
        
        if (!(cin >> nilaiInput)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nTidak Valid! Harap Masukkan Angka" << endl;
            continue;
        }

        cout << fixed << setprecision(2); 

        if (pilihan == 1) {
            double menit = nilaiInput * 60;
            double detik = nilaiInput * 3600;
            cout << "\nHasil Konversi:" << endl;
            cout << nilaiInput << " Jam = " << menit << " Menit" << endl;
            cout << nilaiInput << " Jam = " << detik << " Detik" << endl;
        } 
        else if (pilihan == 2) {
            double jam = nilaiInput / 60.0;
            double detik = nilaiInput * 60;
            cout << "\nHasil Konversi:" << endl;
            cout << nilaiInput << " Menit = " << jam << " Jam" << endl;
            cout << nilaiInput << " Menit = " << detik << " Detik" << endl;
        } 
        else if (pilihan == 3) {
            double jam = nilaiInput / 3600.0;
            double menit = nilaiInput / 60.0;
            cout << "\nHasil Konversi:" << endl;
            cout << nilaiInput << " Detik = " << jam << " Jam" << endl;
            cout << nilaiInput << " Detik = " << menit << " Menit" << endl;
        }

        cout << "\n--------------------------------" << endl;

    } while (pilihan != 4); 

    return 0;
}