#include <iostream>
using namespace std;
#include <iomanip>

struct item
{
    string nama[5];
    int qty[5];
    int price[5];
};

item barang;

void input()
{
    cout << "==== INVENTORY RPG (STRUCT) ====\n";
    cout << "input 5 barang (nama,qty,price)\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "item ke-" << i + 1 << " nama: ";
        cin >> barang.nama[i];
        cout << "item ke-" << i + 1 << " qty: ";
        cin >> barang.qty[i];
        cout << "item ke-" << i + 1 << " price: ";
        cin >> barang.price[i];
    }
}

int hargaTotalBarang(int index)
{
    return barang.qty[index] * barang.price[index];
}

int total()
{
    int total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += barang.qty[i] * barang.price[i];
    }
    return total;
}

int cariNilaiTertinggi() // Fungsi untuk mencari index barang dengan nilai total tertinggi
{
    int maxNilai = hargaTotalBarang(0); // Inisialisasi dengan nilai barang pertama
    int indexMax = 0;

    for (int i = 1; i < 5; i++)
    {
        int nilaiBarang = hargaTotalBarang(i); // Hitung nilai total untuk barang ke-i
        if (nilaiBarang > maxNilai)
        {
            maxNilai = nilaiBarang;
            indexMax = i;
        }
    }

    return indexMax;
}
void tampil()
{
    int indexMax = cariNilaiTertinggi();

    cout << "\n--- daftar inventory ---\n";
    cout << left << setw(15) << "Nama" << setw(10) << "Qty" << setw(10) << "Price" << setw(10) << "Nilai" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(15) << barang.nama[i] << setw(10) << barang.qty[i] << setw(10) << barang.price[i] << setw(10) << hargaTotalBarang(i) << endl;
    }
    cout << "\nTotal Nilai Inventory: " << total() << endl;
    cout << "Barang dengan nilai tertinggi: " << barang.nama[indexMax] << " dengan nilai " << hargaTotalBarang(indexMax) << endl;
}

int main()
{
    input();
    tampil();
    return 0;
}