/**
 * @file main.cpp
 * @author Ali Akbar A.Rahim (21.11.3987)
 * @author Andri Pebriyanto (21.11.3971)
 * @author Binsar Dwi Jasuma (21.11.4002)
 * @author Eka Marlina Kemala Sari (21.11.4010)
 * @author Rivalsan putra Wattimena (21.11.4016)
 * @brief Sistem Informasi Akademik sederhana
 * @version 0.1
 * @date 2021-12-29
 *
 * Aplikasi AMIKOM menghitung IPK sederhana
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifdef _WIN32 || WIN32
#define OS_Windows 1
#else
#define OS_Windows 0
#endif

#include <iostream>
#include <signal.h>
#include <iomanip>
#include <limits>

#include <../lib/VariadicTable.h>
#include <../lib/files.h>
#include <../lib/string.h>
#include <../lib/io.h>
#include <../include/entity/mahasiswa.h>
#include <../include/entity/mataKuliah.h>
#include <../include/entity/hitungipk.h>
#include <../include/repository/mahasiswa.h>
#include <../include/repository/mataKuliah.h>
#include <../include/repository/hitungipk.h>
#include <../include/services/mahasiswa.h>
#include <../include/services/mataKuliah.h>
#include <../include/services/hitungipk.h>
#include <../include/infrastructure/menu.h>
using namespace std;

int main()
{
    enter(2);
    kotakPrinting("SELAMAT DATANG DI APLIKASI AMIKOM");
    enter(3);
    Menu::display();
    return 0;
}

// #include <iostream>
// #include <iomanip>

// using namespace std;

// /**
//  * @brief Fungsi untuk menentukan nilai yang didapatkan berdasarkan sks dan keterangan
//  *
//  * @param ket
//  * @param sks
//  * @return int
//  */
// int Nilai(char ket, float sks);
// /**
//  * @brief Fungsi program untuk menampilkan hasil
//  *
//  * @param nilai
//  * @param tsks
//  * @param ipk
//  */
// void PrintHasil(int nilai, float tsks, float ipk);
// /**
//  * @brief Cek valid range A-E atau a-e
//  *
//  * @param ket
//  * @return true
//  * @return false
//  */
// bool validRange(char ket);

// int main()
// {
//     int n, nilai = 0;
//     float ipk, sks, tsks;
//     char ket;
//     string matkul;
//     cout << "Input banyak mata kuliah = ";
//     cin >> n;

//     for (int i = 1; i <= n; i++)
//     {
//         cin.ignore(256, '\n');
//         cout << "\n\nData ke = " << i;
//         cout << "\n-----------------\n";
//         cout << "Mata kuliah = ";
//         getline(cin, matkul, '\n');
//         cout << "Jumlah SKS  = ";
//         cin >> sks;
//         cout << "Nilai huruf = ";
//         cin >> ket;

//         if (!validRange(ket))
//         {
//             cout << "Range nilai hanya dari A-E";
//             return 0;
//         }#include <limits>
//         nilai += Nilai(ket, sks);
//         tsks += sks;
//         ipk = nilai / tsks;
//     }
//     cout << "\n\n";
//     PrintHasil(nilai, tsks, ipk);

//     cin.get();
//     return 0;
// }
