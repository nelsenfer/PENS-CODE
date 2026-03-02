#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double total_belanja;

    cout << "masukkan total belanja: ";
    cin >> total_belanja;

    if (total_belanja >= 100000)
    {
        double diskon = total_belanja * 0.1;
        double total_setelah_diskon = total_belanja - diskon;
        cout << "Anda mendapatkan diskon 10%!" << endl;
        cout << "==============================" << endl;
        cout << left << setw(19) << "Total belanja:" << "Rp " << fixed << setprecision(2) << total_belanja << endl;
        cout << left << setw(19) << "Total diskon:" << "Rp " << fixed << setprecision(2) << diskon << endl;
        cout << left << setw(19) << "Total bayar:" << "Rp " << fixed << setprecision(2) << total_setelah_diskon << endl;
        cout << "==============================" << endl;
    }
    else
    {
        cout << "Tidak ada diskon" << endl;
        cout << "==============================" << endl;
        cout << left << setw(19) << "Total belanja:" << "Rp " << fixed << setprecision(2) << total_belanja << endl;
        cout << left << setw(19) << "Total bayar:" << "Rp " << fixed << setprecision(2) << total_belanja << endl;
        cout << "==============================" << endl;
    }
    return 0;
}