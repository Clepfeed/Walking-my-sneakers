#include "Header.h";

class Player;
class Puddle;
class Patch;
class Void;
class Line;

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

class Line  {
    Void void1;
    Patch patch;
    Puddle puddle;
public:
    friend void screen_refresh();
    Line() {}
};

void screen_refresh() {
    for (int i = 0; i < 6; i++)
    {
        for (int q = 0; q < 4; q++)
        {
            screen[i][q] = q;
        }
        screen[i][0] = 6 - i;
    }
   /* for (int i = 0; i < 6; i++)
    {

        for (int q = 0; q < 4; q++)
        {
            if (q != 0) {
                cout << screen[i][q] << "\t";
            }
        }
        cout << "\n";
    }*/

    Sleep(1); //25 кадров в секунду (+-)
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
    }
}