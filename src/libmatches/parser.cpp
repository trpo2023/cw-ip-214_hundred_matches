#include <iostream>
#include <libmatches/parser.hpp>

const int MOD = 11;
int GAME_MODE;
int USER = 0;

int clear_cosole()
{
    system("cls||clear");
    return 1;
}

int InputUserNumber(int& User_Decision, const char* Bad_User_Decision)
{
    User_Decision = 0;

    while (!(std::cin >> User_Decision) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n')
            ;
        std::cout << Bad_User_Decision << std::endl;
    }
    return User_Decision;
}

int Pause()
{
    std::cin.ignore();
    std::cin.get();
    return 1;
}

void GameRules_Text()
{
    clear_cosole();

    std::cout << "Правила игры \n";
    std::cout << "\nИгра 100 спичек.\nИз кучки, первоначально содержащей 100 "
                 "спичек, двое играющих поочередно берут по несколько спичек:"
              << "\n";
    std::cout << "не менее одной и не более десяти.Выигрывает взявший "
                 "последнюю спичку."
              << "\n";
}

void Game(int PILE)
{
    int cash = PILE;
    int comp = 1;

    clear_cosole();

    std::cout << "\n Игра 100 спичек.\n _______________________________ \n "
                 "Выберите режим игры: \n 1. Игра с компьютером \n 2. Правила "
                 "игры \n 3. Выход \n _______________________________ \n";

    InputUserNumber(GAME_MODE, "Выберите пункт меню введя ЧИСЛО от 1 до 3 !");

    switch (GAME_MODE) {
    case 1:

        clear_cosole();

        std::cout << " Игра с компьютером \n\n";
        std::cout << " Осталось: " << cash << "\n";

        while (1) {
            comp = 1;

            // ход компьютера:
            while ((cash - comp) % MOD)
                ++comp;
            if (cash == comp) {
                break;
            }
            cash -= comp;

            std::cout << " Ход компьютера: " << comp << "\n";
            std::cout << "\n Осталось: " << cash << "\n";

            // ход юзверя:
            do {
                std::cout << "Подумайте и сделайте ход "
                          << "\n";
                std::cout << " Игрок ( >= 1 и <= " << MOD - 1 << "): ";
                InputUserNumber(USER, "Введите целое число от 1 до 10!");
            }

            while ((USER >= MOD) || (USER < 1));
            cash -= USER;
            std::cout << "\n Осталось: " << cash << "\n";
        }

        std::cout << " Компьютер: Я победил! забераю последние " << cash
                  << " спичек.";

        Pause();
        Game(PILE);

    case 2:

        clear_cosole();
        GameRules_Text();
        Pause();
        Game(PILE);

    case 3:

        exit(0);

    default:

        Game(PILE);
    }
}