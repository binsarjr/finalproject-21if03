#include <../include/entity/mahasiswa.h>
#include <../include/helpers/files.h>
#include <../include/helpers/string.h>
#include <../include/repository/mahasiswa.h>

int main()
{
    Mahasiswa mhs[2];
    mhs[0] = {"21.11.4002", "Binsar Dwi Jasuma"};
    mhs[1] = {"21.11.4003", "Asep"};

    MahasiswaRepository::Create(mhs, 2);
    // MahasiswaRepository::Delete("21.11.4003");
    Mahasiswa mhsSatu = MahasiswaRepository::Find("21.11.4003");
    cout << mhsSatu.nama << endl;
    // string data[] = "21.11.4002,Binsar dwi jasuma".split(",");

    return 0;
}