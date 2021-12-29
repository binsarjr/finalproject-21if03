#include <../include/entity/mahasiswa.h>
#include <../include/helpers/files.h>
#include <../include/helpers/string.h>
#include <../include/repository/mahasiswa.h>

int main()
{
    Mahasiswa mhs[3];
    mhs[0] = {"21.11.4002", "Binsar Dwi Jasuma"};
    mhs[1] = {"21.11.4003", "Asep"};
    mhs[2] = {"21.11.4004", "Saipudin"};

    MahasiswaRepository::Create(mhs, 3);
    int i = 1;
    for (auto mhs : MahasiswaRepository::FindAll())
    {
        cout << i << ". " << mhs.npm << "-" << mhs.nama << endl;
        i++;
    }
    string npm = mhs[0].npm;
    cout << "Cari mahasiswa dengan npm " << npm << endl;
    Mahasiswa mhsSatu = MahasiswaRepository::Find(npm);
    cout << "Mahasiswa ditemukan: " << mhsSatu.npm << "-" << mhsSatu.nama << endl;

    cout << "Hapus mahasiswa dengan npm " << npm << endl;
    MahasiswaRepository::Delete("21.11.4003");
    cout << "Mahasiswa dengan npm " << npm << " telah dihapus" << endl;

    return 0;
}