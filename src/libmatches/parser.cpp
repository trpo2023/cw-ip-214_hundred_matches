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