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

#if defined(_WIN32) || defined(WIN32)
#define OS_Windows 1
#include <Windows.h>
#else
#define OS_Windows 0
#include <unistd.h>
#endif

#include <iostream>
#include <iomanip>
#include <../lib/VariadicTable.h>
#include <../lib/files.h>
#include <../lib/string.h>
#include <../lib/io.h>
#include <../lib/color.h>
#include <../include/entity/mahasiswa.h>
#include <../include/entity/mataKuliah.h>
#include <../include/repository/mahasiswa.h>
#include <../include/services/mahasiswa.h>
#include <../include/infrastructure/menu.h>

using namespace std;

int main()
{
    Menu::kotakPrinting("SELAMAT DATANG DI APLIKASI AMIKOM");
    enter(3);
    Menu::display();

    return 0;
}