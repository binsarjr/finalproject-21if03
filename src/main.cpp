#include <iostream>
#include <../lib/VariadicTable.h>
#include <../lib/files.h>
#include <../lib/string.h>
#include <../include/entity/mahasiswa.h>
#include <../include/repository/mahasiswa.h>

using namespace std;

void showAllMahasiswa(string kelas = "")
{

    VariadicTable<int, string, string, string> vt({"No.", "NPM", "Nama", "Kelas"}, 4);

    vt.setColumnFormat({VariadicTableColumnFormat::AUTO,
                        VariadicTableColumnFormat::FIXED,
                        VariadicTableColumnFormat::AUTO,
                        VariadicTableColumnFormat::PERCENT});
    vt.setColumnPrecision({1, 3, 1, 2});
    vector<Mahasiswa> mahasiswa = MahasiswaRepository::FindAll(kelas);
    int i = 1;
    for (auto mhs : mahasiswa)
    {
        vt.addRow(i++, mhs.npm, mhs.nama, mhs.kelas);
    }
    vt.print(std::cout);
}

int main()
{

    vector<Mahasiswa> mahasiswa;
    mahasiswa.push_back({"21.11.4004", "Saipudin", "21IF04"});
    mahasiswa.push_back({"21.11.4002", "Binsar Dwi Jasuma", "21IF03"});
    mahasiswa.push_back({"21.11.4003", "Asep", "21if03"});
    MahasiswaRepository::Create(mahasiswa);
    showAllMahasiswa();

    string npm = mahasiswa[0].npm;
    cout << "Cari mahasiswa dengan npm " << npm << endl;

    Mahasiswa mhsSatu = MahasiswaRepository::Find(npm);
    cout << "Mahasiswa ditemukan: " << mhsSatu.npm << "-" << mhsSatu.nama << endl;

    cout << "Hapus mahasiswa dengan npm " << npm << endl;
    MahasiswaRepository::Delete(npm);
    cout << "Mahasiswa dengan npm " << npm << " telah dihapus" << endl;

    return 0;
}