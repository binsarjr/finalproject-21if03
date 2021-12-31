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

#ifdef _WIN32 || defined(_WIN32) || defined(WIN32)
#define OS_Windows 1
#else
#define OS_Windows 0
#endif

#include <iostream>
#include <iomanip>
#include <../lib/VariadicTable.h>
#include <../lib/files.h>
#include <../lib/string.h>
#include <../lib/io.h>
#include <../include/entity/mahasiswa.h>
#include <../include/repository/mahasiswa.h>
#include <../include/services/mahasiswa.h>
#include <../include/infrastructure/menu.h>

using namespace std;

int main()
{
    Menu::welcome();
    cout << "\n\n\n";
    Menu::display();
    // Menu::Level1();

    // vector<Mahasiswa> mahasiswa;
    // mahasiswa.push_back({"21.11.4004", "Saipudin", "21IF04"});
    // mahasiswa.push_back({"21.11.4002", "Binsar Dwi Jasuma", "21IF03"});
    // mahasiswa.push_back({"21.11.4003", "Asep", "21if03"});
    // MahasiswaRepository::Create(mahasiswa);
    // MahasiswaService::Find();

    // string npm = mahasiswa[0].npm;
    // cout << "Cari mahasiswa dengan npm " << npm << endl;

    // Mahasiswa mhsSatu = MahasiswaRepository::FindOneByNpm(npm);
    // cout << "Mahasiswa ditemukan: " << mhsSatu.npm << "-" << mhsSatu.nama << endl;

    // cout << "Hapus mahasiswa dengan npm " << npm << endl;
    // MahasiswaRepository::Delete(npm);
    // cout << "Mahasiswa dengan npm " << npm << " telah dihapus" << endl;

    return 0;
}