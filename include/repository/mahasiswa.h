#include <fstream>
#include <algorithm>
namespace MahasiswaRepository
{
    string filename = "database/mahasiswa.csv";
    bool compareByNpm(const Mahasiswa &a, const Mahasiswa &b)
    {
        return a.npm < b.npm;
    }
    vector<Mahasiswa> sortMahasiswa(vector<Mahasiswa> mhs)
    {
        std::sort(mhs.begin(), mhs.end(), compareByNpm);
        return mhs;
    }

    vector<Mahasiswa> Find(string kelas = "")
    {
        vector<Mahasiswa> mhsAll;
        fstream fin(filename, ios::in);
        string line;
        getline(fin, line); // skip firstline
        while (getline(fin, line))
        {
            Mahasiswa mhs;
            vector<string> items = split(line, ",");
            mhs.npm = items.at(0);
            mhs.nama = items.at(1);
            mhs.kelas = items.at(2);
            if (kelas != "" && kelas != mhs.kelas)
            {
                continue;
            }
            mhsAll.push_back(mhs);
        }
        fin.close();
        mhsAll = sortMahasiswa(mhsAll);
        return mhsAll;
    }

    Mahasiswa FindOneByNpm(string npm)
    {
        Mahasiswa mhs;
        fstream fin(filename, ios::in);
        string line;
        while (getline(fin, line))
        {

            vector<string> items = split(line, ",");

            if (items.at(0) == npm)
            {
                mhs.npm = items.at(0);
                mhs.nama = items.at(1);
                mhs.kelas = items.at(2);
                fin.close();
            }
        }
        if (fin.is_open())
        {
            fin.close();
        }

        return mhs;
    }

    bool Create(Mahasiswa mahasiswa)
    {
        fstream fin(filename, ios::in);
        string firstLine;
        getline(fin, firstLine);

        fstream fout(filename, ios::out | ios::app);
        if (firstLine == "")
        {
            fout << "npm,nama,kelas\n";
        }
        if (FindOneByNpm(mahasiswa.npm).npm != "")
        {
            return false;
        }
        fout << mahasiswa.npm << "," << mahasiswa.nama << "," << capitalizeString(mahasiswa.kelas) << "\n";
        fout.close();
        return true;
    }

    void CreateMany(vector<Mahasiswa> mahasiswa)
    {
        for (auto mhs : mahasiswa)
        {
            Create(mhs);
        }
    }

    void Delete(string npm)
    {
        ifstream fin;
        std::string line;
        fin.open(filename);

        int i = 0;
        while (getline(fin, line))
        {
            ++i;
            if (i == 1)
                continue;

            if (line.find(npm + ",") != string::npos)
            {
                delete_line(filename.c_str(), i);
            }
        }
        if (fin.is_open())
        {
            fin.close();
        }
    }
};
