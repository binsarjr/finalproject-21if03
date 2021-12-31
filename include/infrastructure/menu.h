#include <limits>
namespace Menu
{
    static int pilihan;
    int padding = 10;

    string printWidth(int padding)
    {
        string result = "";
        for (int i = 1; i <= padding; i++)
            result += " ";
        return result;
    }
    void kotakPrinting(string text)
    {
        int minWidth = 50;
        int textLength = (minWidth - text.length() - 1) / 2;
        string left = "| " + printWidth(textLength);
        string right = printWidth(textLength) + " |";
        int width = left.length() + right.length() + text.length();
        char topAndButton[2] = "=";

        if (width <= minWidth)
            width = minWidth;

        for (int i = 1; i <= 3; i++)
        {
            if (i == 1 || i == 3)
            {
                for (int j = 1; j <= width; j++)
                {
                    cout << topAndButton;
                }
                cout << endl;
            }
            else
            {
                cout << left << text << right << endl;
            }
        }
    }
    void welcome()
    {
        kotakPrinting("SELAMAT DATANG DI APLIKASI AMIKOM");
    }
    void exitIfNeeded()
    {
        if (pilihan == 99)
        {
            cout << "selamat tinggal" << endl;
            exit(1);
        }
    }

    void print(vector<string> data)
    {
        int i = 1;
        cout << "\n\n";

        for (auto menu : data)
        {
            if (menu == "")
            {
                cout << endl;
                continue;
            }

            if (menu == "0")
            {
                cout << printWidth(padding) << "[" << 0 << "] Kembali" << endl;
                continue;
            }
            if (menu == "99")
            {
                cout << printWidth(padding) << "[" << 99 << "] Keluar" << endl;
                continue;
            }

            cout << printWidth(padding) << "[" << i << "]"
                 << " " << menu << endl;
            i++;
        }
        cout << "\n\n";
    }

    void pilih(string text = "Pilih> ")
    {
    pilih:
        cout << text;

        if (!(cin >> pilihan))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again \n";
            goto pilih;
        }
    }

    void display()
    {
    daftar_menu:
        kotakPrinting(printWidth(4) + "Daftar Menu" + printWidth(4));
        print({"Manajemen Mahasiswa", "Manajemen Mata Kuliah", "Hitung IPK", "Laporan ipk dll(optional)", "", "", "99"});

        pilih();

        switch (pilihan)
        {
        case 1:
        menu_mahasiswa:
            kotakPrinting("Manajemen Data Mahasiswa");
            print({"List Mahasiswa", "Tambah Mahasiswa", "Hapus Mahasiswa", "", "", "0", "99"});

            pilih();

            switch (pilihan)
            {
            case 1:
                MahasiswaService::Find();
                goto menu_mahasiswa;
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                goto daftar_menu;
                break;

            default:
                exitIfNeeded();
                goto menu_mahasiswa;
                break;
            }
            break;
        case 2:
        menu_matkul:
            kotakPrinting("Manajemen Data Mata Kuliah");
            print({"List Mata Kuliah", "Tambah Mata Kuliah", "Hapus Mata Kuliah", "", "", "0", "99"});

            pilih();

            switch (pilihan)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                goto daftar_menu;
                break;

            default:
                exitIfNeeded();
                goto menu_matkul;
                break;
            }
            break;

        default:
            exitIfNeeded();
            goto daftar_menu;
            break;
        }
    }

}