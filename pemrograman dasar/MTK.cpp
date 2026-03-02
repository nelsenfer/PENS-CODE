#include <iostream>
using namespace std;

double hitungDeterminan(double matrix[3][3])
{
    double a = matrix[0][0];
    double b = matrix[0][1];
    double c = matrix[0][2];
    double d = matrix[1][0];
    double e = matrix[1][1];
    double f = matrix[1][2];
    double g = matrix[2][0];
    double h = matrix[2][1];
    double i = matrix[2][2];

    double determinan = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
    return determinan;
}

int main()
{
    double matrix3x3[3][3];

    // Perulangan untuk baris (i)
    for (int i = 0; i < 3; ++i)
    {
        // Perulangan untuk kolom (j)
        for (int j = 0; j < 3; ++j)
        {
            cout << "Masukkan nilai untuk matriks [" << i << "][" << j << "]: ";
            cin >> matrix3x3[i][j];
        }
    }

    // Opsional: Menampilkan matriks untuk verifikasi
    std::cout << "\nMatriks yang telah Anda masukkan adalah:\n";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << matrix3x3[i][j] << " ";
        }
        cout << endl;
    }

    double matrix4x4[4][4];
    for (int i = 0; i < 4; ++i)
    {
        // Perulangan untuk kolom (j)
        for (int j = 0; j < 4; ++j)
        {
            cout << "Masukkan nilai untuk matriks [" << i << "][" << j << "]: ";
            cin >> matrix4x4[i][j];
        }
    }

    double hasilDeterminan = hitungDeterminan(matrix3x3);
    cout << "Determinan dari matriks adalah: " << hasilDeterminan << endl;
    return 0;
}