template <typename T = string>
void input(string text, T &data, bool clearIgnore = false)
{
    if (clearIgnore)
    {
        cin.clear();
        cin.ignore();
    }
    cout << text;
    getline(cin, data);
}

void enter(int size)
{
    for (int i = 1; i <= size; i++)
        cout << endl;
}

void clear()
{
    if (OS_Windows)
    {
        system("cls");
    }
    else
    {
        system("clear");
    }
}