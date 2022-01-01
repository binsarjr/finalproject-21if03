

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