#include "Header.h";

void screen_down();

class Player;
class Puddle;
class Patch;
class Space;
class Line;


int start_time;
int time_now;

class Puddle
{
    int damage = 20;
public:
    friend void screen_refresh();
    friend void player_line();
    friend class Player;
	friend void main();

    Puddle() {}
    void show() {
        cout << "\t|------|";
    }
};

class Patch
{
    int heal = 50;
public:
    friend void screen_refresh();
    friend void player_line();
	friend void main();
    friend class Player;

    Patch() {}
    void show() {
        cout << "\t|++++++|";
    }
};

class Space
{
public:
    friend void screen_refresh();
	friend void main();

    Space() { }

    void show() {
        cout << "\t|      |";
    }

};

class Player
{
    int place;
public:
    int health = 100;
    int x;
    int y = 6;

	friend void main();
    friend class Line;
    friend void screen_refresh();
    friend void player_line();

    Player() {
        x = 2;
    }

    void show() {
        cout << "\t|player|";
    }

    
};

Player player;

class Line {
    bool is_player_on_line;
    int random_num;
    int random_num2;
    int patch_or_padddle;
    Space space;
    Patch patch;
    Puddle puddle;
public:
    friend class Player;
    friend void screen_down();
    friend void check_patch_or_paddle(Line a);
    friend void screen_refresh();
    friend void player_line();

    Line() {
        random_num = rand() % 10;
        random_num2 = rand() % 3 + 1;
        while (random_num2 == 2)
        {
            random_num2 = rand() % 3 + 1;
        }
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
        if (is_player_on_line)
        {
            if (player.x == 1) {
                if (random_num2 == 1)
                {
                    player.show();
                    space.show();
                    space.show();
                    cout << "\n";
                }
                else if (random_num2 == 2)
                {

                    player.show();
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
                else if (random_num2 == 3)
                {
                    player.show();
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
            if (player.x == 2) {
                if (random_num2 == 1)
                {
                    if (patch_or_padddle == 1) {
                        patch.show();
                    }
                    else
                    {
                        puddle.show();
                    }
                    player.show();
                    space.show();
                    cout << "\n";
                }
                else if (random_num2 == 2)
                {

                    space.show();
                    player.show();
                    space.show();
                    cout << "\n";
                }
                else if (random_num2 == 3)
                {
                    space.show();
                    player.show();
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
            if (player.x == 3) {
                if (random_num2 == 1)
                {
                    if (patch_or_padddle == 1) {
                        patch.show();
                    }
                    else
                    {
                        puddle.show();
                    }
                    space.show();
                    player.show();
                    cout << "\n";
                }
                else if (random_num2 == 2)
                {

                    space.show();
                    if (patch_or_padddle == 1) {
                        patch.show();
                    }
                    else
                    {
                        puddle.show();
                    }
                    player.show();
                    cout << "\n";
                }
                else if (random_num2 == 3)
                {
                    space.show();
                    space.show();
                    player.show();
                    cout << "\n";
                }
            }
        }

        else
        {
            if (random_num2 == 1)
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
            else if (random_num2 == 2)
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
            else if (random_num2 == 3)
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
    }
};

Line line1;
Line line2;
Line line3;
Line line4;
Line line5;
Line line6;

bool get_bonus = true;

void player_line() {
    if (player.y == 1)
    {
        if (player.x == line1.random_num2)
        {
            if (line1.patch_or_padddle == 1)
            {
                if (!get_bonus)
                {
                    if (player.health < 100)
                    {
                        player.health += line1.patch.heal;
                    }
                    get_bonus = true;
                }
            }
            else
            {
                if (!get_bonus)
                {
                    player.health -= line1.puddle.damage;
                    get_bonus = true;
                }
            }
        }
        line1.is_player_on_line = true;

        line2.is_player_on_line = false;
        line3.is_player_on_line = false;
        line4.is_player_on_line = false;
        line5.is_player_on_line = false;
        line6.is_player_on_line = false;
    }
    else if (player.y == 2)
    {
        if (player.x == line2.random_num2)
        {
            if (line2.patch_or_padddle == 1)
            {
                if (!get_bonus)
                {
                    if (player.health < 100)
                    {
                        player.health += line2.patch.heal;
                    }
                    get_bonus = true;
                }
            }
            else
            {
                if (!get_bonus)
                {
                    player.health -= line2.puddle.damage;
                    get_bonus = true;
                }
            }
        }
        line2.is_player_on_line = true;

        line1.is_player_on_line = false;
        line3.is_player_on_line = false;
        line4.is_player_on_line = false;
        line5.is_player_on_line = false;
        line6.is_player_on_line = false;
    }
    else if (player.y == 3)
    {
        if (player.x == line3.random_num2)
        {
            if (line3.patch_or_padddle == 1)
            {
                if (!get_bonus)
                {
                    if (player.health < 100)
                    {
                        player.health += line3.patch.heal;
                    }
                    get_bonus = true;
                }
            }
            else
            {
                if (!get_bonus)
                {
                    player.health -= line3.puddle.damage;
                    get_bonus = true;
                }
            }
        }
        line3.is_player_on_line = true;

        line1.is_player_on_line = false;
        line2.is_player_on_line = false;
        line4.is_player_on_line = false;
        line5.is_player_on_line = false;
        line6.is_player_on_line = false;
    }
    else if (player.y == 4)
    {
        if (player.x == line4.random_num2)
        {
            if (line4.patch_or_padddle == 1)
            {
                if (!get_bonus)
                {
                    if (player.health < 100)
                    {
                        player.health += line4.patch.heal;
                    }
                    get_bonus = true;
                }
            }
            else
            {
                if (!get_bonus)
                {
                    player.health -= line4.puddle.damage;
                    get_bonus = true;
                }
            }
        }
        line4.is_player_on_line = true;

        line1.is_player_on_line = false;
        line2.is_player_on_line = false;
        line3.is_player_on_line = false;
        line5.is_player_on_line = false;
        line6.is_player_on_line = false;
    }
    else if (player.y == 5)
    {
        if (player.x == line5.random_num2)
        {
            if (line5.patch_or_padddle == 1)
            {
                if (!get_bonus)
                {
                    if (player.health < 100)
                    {
                        player.health += line5.patch.heal;
                    }
                    get_bonus = true;
                }
            }
            else
            {
                if (!get_bonus)
                {
                    player.health -= line5.puddle.damage;
                    get_bonus = true;
                }
            }
        }
        line5.is_player_on_line = true;

        line1.is_player_on_line = false;
        line2.is_player_on_line = false;
        line3.is_player_on_line = false;
        line4.is_player_on_line = false;
        line6.is_player_on_line = false;
    }
    else if (player.y == 6)
    {
        if (player.x == line6.random_num2)
        {
            if (line6.patch_or_padddle == 1)
            {
                if (!get_bonus)
                {
                    if (player.health < 100)
                    {
                        player.health += line6.patch.heal;
                    }
                    get_bonus = true;
                }

            }
            else
            {
                if (!get_bonus)
                {
                    player.health -= line6.puddle.damage;
                    get_bonus = true;
                }
            }
        }
        line6.is_player_on_line = true;

        line1.is_player_on_line = false;
        line2.is_player_on_line = false;
        line3.is_player_on_line = false;
        line4.is_player_on_line = false;
        line5.is_player_on_line = false;
    }
}

int time_to_next_screen_down = 25;
int how_much_screen_down = 0;
int to_next_minus_time = 10;

void screen_refresh() {
    system("CLS");

    if (time_now == time_to_next_screen_down)
    {
        screen_down();

        time_now = 0;

        get_bonus = false;

        if (how_much_screen_down == to_next_minus_time)
        {
            if (time_to_next_screen_down > 5)
            {
                time_to_next_screen_down--;
                to_next_minus_time += 10;
            }
        }

        how_much_screen_down++;
    }

    cout << "\t\tHP = " << player.health << "\n";
    cout << "\t\tScore = " << how_much_screen_down << "\n";
    cout << "\t\tNext acceleration when score = " << to_next_minus_time << "\n";

    player_line();

    line1.refresh();
    line2.refresh();
    line3.refresh();
    line4.refresh();
    line5.refresh();
    line6.refresh();


    Sleep(1); //25 кадров в секунду (+-) //на компе академии 18
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
    line1.random_num2 = rand() % 3 + 1;

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
        system("CLS");

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
                    if (player.health > 0)
                    {
                        screen_refresh();

                        if (_kbhit())
                        {
                            button = _getch();

                            if (button == 100) // D
                            {
                                if (player.x < 3)
                                {
                                    player.x++;
                                }

                            }

                            if (button == 115) // S
                            {
                                if (player.y < 6)
                                {
                                    player.y++;
                                }
                            }

                            if (button == 97) // A 
                            {
                                if (player.x > 1)
                                {
                                    player.x--;
                                }
                            }

                            if (button == 119) // W
                            {
                                if (player.y > 1)
                                {
                                    player.y--;
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "\t\t$$$$____$$$$___$$___$$_$$$$$\n";
                        Sleep(25);
                        cout << "\t\t$$______$$__$$__$$$_$$$_$$\n";
                        Sleep(25);
                        cout << "\t\t$$_$$$__$$$$$$__$$_$_$$_$$$$\n";
                        Sleep(25);
                        cout << "\t\t$$__$$__$$__$$__$$___$$_$$\n";
                        Sleep(25);
                        cout << "\t\t_$$$$___$$__$$__$$___$$_$$$$$\n\n";
                        Sleep(25);
                        cout << "\t\t_$$$$___$$__$$__$$$$$___$$$$$\n";
                        Sleep(25);
                        cout << "\t\t$$__$$__$$__$$__$$______$$__$$\n";
                        Sleep(25);
                        cout << "\t\t$$__$$__$$__$$__$$$$____$$$$$\n";
                        Sleep(25);
                        cout << "\t\t$$__$$___$$$$___$$______$$__$$\n";
                        Sleep(25);
                        cout << "\t\t_$$$$_____$$____$$$$$___$$__$$\n";
                        Sleep(2500);

                        player.health = 100;
                        player.y = 6;

                        time_to_next_screen_down = 25;
                        how_much_screen_down = 0;
                        to_next_minus_time = 10;

                        break;
                    }
                }
            }
            else if (button == 50) // 50 - 2
            {
                int ans = 0;
                while (ans == 0)
                {
					Patch patch;
					Puddle puddle;
					Space space;
					Player player;

                    system("CLS");
                    cout << "HI!\n";
					cout << "It is a perfect game that named 'Walking my sneakers'\n";
					cout << "In this game you need go as far as possible\n";
					cout << "But this not so easy\n";
					cout << "Here you have 3 roads and 6 steps forward\n";
					cout << "In on each appear 2 safely space and 1 patch or puddle\n";
					cout << "\n";

					cout << "This is patch: ";
					patch.show();
					cout << "\nHe is good boy and heal you on " << patch.heal << " points";
					cout << "\n";

					cout << "\nThis is puddle: ";
					puddle.show();
					cout << "\nHe is asshole and can only reduces your HP on " << puddle.damage << " points\n";
					cout << "\n";

					cout << "And the last one, is space: ";
					space.show();
					cout << "\nHe is do literaly nothing(like me on maths)\n";
					cout << "\n";

					cout << "Yout character in this game is";
					player.show();
					cout << "\nHe can move using WASD and DIE!!!\n";
					cout << "BUGAGAGAGA AND GUD LUCK\n";
					cout << "\n";

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
        
    }
}