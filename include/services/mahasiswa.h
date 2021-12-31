

namespace MahasiswaService
{
    void Find(string kelas = "")
    {
        VariadicTable<int, string, string, string> vt({"No.", "NPM", "Nama", "Kelas"}, 4);

        vt.setColumnFormat({VariadicTableColumnFormat::AUTO,
                            VariadicTableColumnFormat::FIXED,
                            VariadicTableColumnFormat::AUTO,
                            VariadicTableColumnFormat::PERCENT});
        vt.setColumnPrecision({1, 3, 1, 2});
        vector<Mahasiswa> mahasiswa = MahasiswaRepository::Find(kelas);
        int i = 1;
        for (auto mhs : mahasiswa)
        {
            vt.addRow(i++, mhs.npm, mhs.nama, mhs.kelas);
        }
        vt.print(std::cout);
    }

    void Create()
    {
        Mahasiswa mahasiswa;

        input("NPM       : ", mahasiswa.npm, true);
        input("Nama      : ", mahasiswa.nama);
        input("Kode Kelas: ", mahasiswa.kelas);

        if (!MahasiswaRepository::Create(mahasiswa))
        {
            cout << "\nMahasiswa dengan npm " + mahasiswa.npm + " sudah ada" << endl;
        }
    }

    void Delete()
    {
        string npm;
        input("NPM : ", npm, true);
        MahasiswaRepository::Delete(npm);
        cout << "Mahasiswa dengan NPM " + npm + " telah dihapus" << endl;
    }
}
