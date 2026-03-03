#include <iostream>
#include <limits>

void clear_stdin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {

    while (true) {
        std::cout << "\nPilih Operasi (+, -, *, /) atau Q Untuk Keluar: ";
        char op;
        if (!(std::cin >> op))
            break;
        if (op == 'q' || op == 'Q')
            break;
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            std::cout << "Tidak Valid!\n";
            clear_stdin();
            continue;
        }

        double a, b;
        std::cout << "Masukkan Angka Pertama: ";
        if (!(std::cin >> a)) {
            std::cout << "Tidak Valid!\n";
            clear_stdin();
            continue;
        }
        std::cout << "Masukkan Angka Kedua: ";
        if (!(std::cin >> b)) {
            std::cout << "Tidak Valid!\n";
            clear_stdin();
            continue;
        }

        switch (op) {
            case '+':
                std::cout << "\nHasil: " << (a + b) << "\n";
                break;
            case '-':
                std::cout << "\nHasil: " << (a - b) << "\n";
                break;
            case '*':
                std::cout << "\nHasil: " << (a * b) << "\n";
                break;
            case '/':
                if (b == 0)
                    std::cout << "Tidak Valid!\n";
                else
                    std::cout << "\nHasil: " << (a / b) << "\n";
                break;
            default:
                std::cout << "Tidak Valid!\n";
                break;
        }
    }

    std::cout << "Berhasil Keluar\n";
    return 0;
}