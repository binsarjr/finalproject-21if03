#include <fstream>

namespace MahasiswaRepository
{
    string filename = "database/mahasiswa.csv";

    vector<Mahasiswa> FindAll()
    {
        vector<Mahasiswa> mhsAll;
        fstream fin(filename, ios::in);
        string line;
        getline(fin, line); // skip firstline
        while (getline(fin, line))
        {
            Mahasiswa mhs;
            vector<string> v = split(line, ",");

            int col = 1;
            for (auto item : v)
            {
                switch (col)
                {
                case 1:
                    mhs.npm = item;
                    break;
                case 2:
                    mhs.nama = item;
                    break;
                }
                col++;
            }
            mhsAll.push_back(mhs);
        }
        fin.close();
        return mhsAll;
    }

    Mahasiswa Find(string npm)
    {
        Mahasiswa mhs;
        fstream fin(filename, ios::in);
        string line;
        while (getline(fin, line))
        {

            vector<string> v = split(line, ",");

            bool exists = false;
            int col = 1;
            for (auto item : v)
            {
                if (col == 1)
                {
                    if (npm == item)
                    {
                        exists = true;
                        break;
                    }
                }
                col++;
            }

            if (exists)
            {
                fin.close();
                col = 1;
                for (auto item : v)
                {
                    switch (col)
                    {
                    case 1:
                        mhs.npm = item;
                        break;
                    case 2:
                        mhs.nama = item;
                        break;
                    }
                    col++;
                }
            }
        }
        if (fin.is_open())
        {
            fin.close();
        }

        return mhs;
    }

    void Create(Mahasiswa *mhs, int size)
    {
        fstream fin(filename, ios::in);
        string firstLine;
        getline(fin, firstLine);

        fstream fout(filename, ios::out | ios::app);
        if (firstLine == "")
        {
            fout << "npm,nama\n";
        }
        for (int i = 0; i < size; i++)
        {
            if (Find(mhs[i].npm).npm != "")
            {
                cout << "Mahasiswa dengan npm " << mhs[i].npm << " sudah digunakan" << endl;
                continue;
            }
            fout << mhs[i].npm << "," << mhs[i].nama << "\n";
        }
        fout.close();
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
