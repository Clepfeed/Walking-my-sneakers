#include "Header.h";

void main()
{
    setlocale(0, "");
    int button;

    cout << "----\n";
    cout << "||||\n";
    cout << "----\n";

    while (true)
    {
        if (_kbhit())
        {
            button = _getch();

            if (button == 100)
            {
                system("color 3");
            }

            if (button == 115)
            {
                system("color 2");
            }

            if (button == 97)
            {
                system("color 1");
            }

            if (button == 119)
            {
                system("color 4");
            }

        }
    }
}