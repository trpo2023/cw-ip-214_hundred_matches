#include<iostream>
#include <libmatches/parser.hpp>
#include <time.h>

const int       MOD = 11;
int             GAME_MODE;
int             HARD_MODE;
int             USER = 0;
int             cash = 100;

int        clear_cosole()
{
    system("cls||clear");
    return 1;
}

int        InputUserNumber(int& User_Decision, const char* Bad_User_Decision)
{
    User_Decision = 0;

    while (!(std::cin >> User_Decision) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << Bad_User_Decision << std::endl;
    }
    return User_Decision;
}

int        PlayerNumber(int check)
{
    return (check % 2)+1;
}

int        Pause()
{
    std::cin.ignore();
    std::cin.get();
    return 1;
}

void       GameRules_Text() 
{
    clear_cosole();

    std::cout << "Правила игры \n";
    std::cout << "\nИгра 100 спичек.\nИз кучки, первоначально содержащей 100 спичек, двое играющих поочередно берут по несколько спичек:" << "\n";
    std::cout << "не менее одной и не более десяти.Выигрывает взявший последнюю спичку." << "\n";
}

void       Game(int PILE) 
{
    int        check;
    int        cash = PILE;
    int        comp = 1;

    clear_cosole();

    std::cout << "\n Игра 100 спичек.\n _______________________________ \n Выберите режим игры: \n 1. Игра с компьютером \n 2. Игра на двоих \n 3. Правила игры \n 4. Выход \n _______________________________ \n";
    
    InputUserNumber(GAME_MODE, "Выберите пункт меню введя ЧИСЛО от 1 до 4 !");

    switch (GAME_MODE)
    {
        case 1:

            clear_cosole();

            std::cout << " Выберете уровень сложности: \n";
            std::cout << " 1) Без шансов" << "\n";
            std::cout << " 2) Малютка" << "\n";
            InputUserNumber(HARD_MODE, "Выберите пункт введя ЧИСЛО");

            clear_cosole();

            std::cout << " Игра с компьютером \n\n";
            std::cout << " Осталось: " << cash << "\n";


            while (HARD_MODE)
            {
                // ход компьютера:
                if (HARD_MODE == 1)
                {
                    comp = 1;    
                    while ((cash - comp) % MOD) ++comp;
                        
                    if (cash == comp)
                    {
                        std::cout << " Компьютер: Я победил! забераю последние " << cash << " спичек.";
                        break;
                    }

                    cash -= comp;

                    std::cout << " Ход компьютера: " << comp << "\n";
                    std::cout << "\n Осталось: " << cash << "\n";
                }

                if (HARD_MODE == 2)
                {
                    srand(time(0));
                    comp = rand() % 10 + 1;

                    if (cash <= 10)
                    {
                        std::cout << "\n Компьютер: Я победил! забераю последние " << cash << " спичек.";
                        break;
                    }

                    cash -= comp;

                    std::cout << " Ход компьютера: " << comp << "\n";
                    std::cout << "\n Осталось: " << cash << "\n";
                }

                // ход юзверя:
                do
                {
                    
                    std::cout << " \n**Подумайте и сделайте ход " << "\n";
                    std::cout << " Игрок ( >= 1 и <= " << MOD - 1 << "): ";
                    InputUserNumber(USER, "Введите целое число от 1 до 10!");
                    
                    if (cash <= USER)
                    {
                        std::cout << "\n Игрок: Я победил! забераю последние " << USER << " спичек.";
                        HARD_MODE = 0;
                        break;
                    }
                    
                }

                while ((USER >= MOD) || (USER < 1));
                cash -= USER;
                std::cout << "\n Осталось: " << cash << "\n";                                
            }

            Pause();
            Game(PILE);

        case 2:

            clear_cosole();
            check = 0;
            std::cout << " Игра на двоих \n";

            while (cash > 10)
            {
                // игра юзверей:
                do
                {
                    std::cout << "\n Осталось: " << cash << "\n";
                    std::cout << "\n **Подумайте и сделайте ход " << "\n";
                    std::cout << " Игрок "<< PlayerNumber(check) <<" ( >= 1 и <= " << MOD - 1 << "): ";
                    InputUserNumber(USER, "Введите целое число от 1 до 10!");
                    check+=1;

                    if (cash <= 10)
                    {
                        break;
                    }
                }

                while ((USER >= MOD) || (USER < 1));
                cash -= USER;
                //std::cout << "\n Осталось: " << cash << "\n";
            }

            std::cout << "\n Игрок "<< PlayerNumber(check) <<" : Я победил! забераю последние " << cash << " спичек.";
            Pause();
            Game(PILE);

        case 3:

            clear_cosole();
            GameRules_Text();
            Pause();
            Game(PILE);

        case 4:

            exit(0);

        default:

            Game(PILE);
    }
}