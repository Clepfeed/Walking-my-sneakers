#include "Header.h";

void screen_down();

class Player;
class Puddle;
class Patch;
class Space;
class Line;

int start_time;
int time_now;

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

    Puddle() {}
    void show() {
        cout << "\tPuddle";
    }
};

class Patch
{
    int heal;
    int place;
public:
    friend void screen_refresh();

    Patch() {}
    void show() {
        cout << "\tPatch";
    }
};

class Space
{

public:
    friend void screen_refresh();

    Space() { }

    void show() {
        cout << "\tSpace";
    }

};

class Line {
    int random_num;
    int random_num2;
    int patch_or_padddle;
    Space space;
    Patch patch;
    Puddle puddle;
public:
    friend void screen_down();
    friend void check_patch_or_paddle(Line a);
    friend void screen_refresh();
    Line() {
        random_num = rand() % 10;
        random_num2 = rand() % 2;
        if (random_num == 0)
        {
            patch_or_padddle = 1;
        }
        else
        {
            patch_or_padddle = 2;

        }
    }

    void check_patch_or_paddle() {
        if (random_num == 0)
        {
            patch_or_padddle = 1;
        }
        else
        {
            patch_or_padddle = 2;
        }

    }

    void refresh() {
        if (random_num2 == 0)
        {
            if (patch_or_padddle == 1) {
                patch.show();
            }
            else
            {
                puddle.show();
            }
            space.show();
            space.show();
            cout << "\n";
        }
        else if (random_num2 == 1)
        {

            space.show();
            if (patch_or_padddle == 1) {
                patch.show();
            }
            else
            {
                puddle.show();
            }
            space.show();
            cout << "\n";
        }
        else if (random_num2 == 2)
        {
            space.show();
            space.show();
            if (patch_or_padddle == 1) {
                patch.show();
            }
            else
            {
                puddle.show();
            }
            cout << "\n";
        }


    }
};

Line line1;
Line line2;
Line line3;
Line line4;
Line line5;
Line line6;

void screen_refresh() {
    system("CLS");

    if (time_now == 75)
    {
        screen_down();

        time_now = 0;
    }

    line1.refresh();
    line2.refresh();
    line3.refresh();
    line4.refresh();
    line5.refresh();
    line6.refresh();


    Sleep(1); //25 ������ � ������� (+-) //�� ����� �������� 18
    time_now++;
}

void screen_down() {

    line6.random_num = line5.random_num;
    line6.random_num2 = line5.random_num2;

    line5.random_num = line4.random_num;
    line5.random_num2 = line4.random_num2;

    line4.random_num = line3.random_num;
    line4.random_num2 = line3.random_num2;

    line3.random_num = line2.random_num;
    line3.random_num2 = line2.random_num2;

    line2.random_num = line1.random_num;
    line2.random_num2 = line1.random_num2;

    line1.random_num = rand() % 10;
    line1.random_num2 = rand() % 3;

    line1.check_patch_or_paddle();
    line2.check_patch_or_paddle();
    line3.check_patch_or_paddle();
    line4.check_patch_or_paddle();
    line5.check_patch_or_paddle();
    line6.check_patch_or_paddle();

}

void main()
{
    system("color 3");

    srand(time(0));

    int button;

    while (true)
    {
        cout << "$$___$$_$$$$$___$$_______$$$$____$$$$___$$___$$_$$$$$\n";
        cout << "$$___$$_$$______$$______$$__$$__$$__$$__$$$_$$$_$$\n";
        cout << "$$_$_$$_$$$$____$$______$$______$$__$$__$$_$_$$_$$$$\n";
        cout << "$$$$$$$_$$______$$______$$__$$__$$__$$__$$___$$_$$\n";
        cout << "_$$_$$__$$$$$___$$$$$$___$$$$____$$$$___$$___$$_$$$$$\n\n\n";

        cout << "1 - star the game\n";
        cout << "2 - rules\n";
        cout << "3 - quit";
        if (_kbhit())
        {
            button = _getch();
            if (button == 49) //49 = 1
            {
                while (true)
                {
                    screen_refresh();

                    if (_kbhit())
                    {
                        button = _getch();

                        if (button == 100) // D
                        {
                            //system("color 3");
                        }

                        if (button == 115) // S
                        {
                            //system("color 2");
                        }

                        if (button == 97) // A 
                        {
                            //system("color 1");
                        }

                        if (button == 119) // W
                        {
                            //system("color 4");
                            screen_down();
                        }
                    }
                }
            }
            else if (button == 50) // 50 - 2
            {
                int ans = 0;
                while (ans == 0)
                {
                    system("CLS");
                    cout << "nothing here now\n";
                    cout << "\n1 - quit";
                    button = _getch();
                    if (button == 49) {
                        ans = 1;
                    }
                }
            }
            else if (button == 51) // 51 - 3
            {
                break;
            }
        }
        system("CLS");
    }
}