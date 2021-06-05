#include "Header.h";

class Player;
class Puddle;
class Patch;
class Void;

int screen[6][4];
int fps = 0;

class Player
{
    int health;
    int place;
public:
    friend void screen_refresh();

    Player() {

    }

};

class Puddle
{
    int damage;
    int place;
public:
    friend void screen_refresh();

    Puddle() {

    }
};

class Patch
{
    int heal;
    int place;
public:
    friend void screen_refresh();

    Patch() {

    }
}; 

class Void
{

public:
    friend void screen_refresh();

    Void() {

    }


};


void screen_refresh() {
    /*cout << 15 << "\t16" << "\t17\n";

    cout << 12 << "\t13" << "\t16\n";

    cout << 9 << "\t10" << "\t11\n";

    cout << 6 << "\t7" << "\t8\n";

    cout << 3 << "\t4" << "\t5\n";

    cout << 0 << "\t1" << "\t2\n";*/

    /*for (int i = 0; i < 6; i++)
    {
        for (int q = 0; q < 4; q++)
        {
            screen[i][q] = q;
        }
        screen[i][0] = 6 - i;
    }
    for (int i = 0; i < 6; i++)
    {

        for (int q = 0; q < 4; q++)
        {
            if (q != 0) {
                cout << screen[i][q] << "\t";
            }
        }
        cout << "\n";
    }*/



    fps++;
    cout << fps;


    Sleep(1);
}


void main()
{
    int button;

    cout << "Tap to start game";
    while (true)
    {
        if (_kbhit())
        {
            while (true)
            {
                system("CLS");

                screen_refresh();

                if (_kbhit())
                {
                    button = _getch();

                    if (button == 100)
                    {
                        system("pause");
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
                    system("CLS");
                }
            }
        }
    }
}