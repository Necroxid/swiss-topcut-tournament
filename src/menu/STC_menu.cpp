#include "STC_menu.h"
#include "../swiss_phase/STC_swiss.h"
#include "../topcut_phase/STC_topcut.h"

#include <iomanip>
#include <fstream>

//Menu namespace
/************************************************************/
void Menu::mainMenu()
{
    std::cout << "Main Menu\n";
    printLine();
    printChooseOption();
    std::cout << "1. Start the Tournament\n";
    std::cout << "2. View rules\n";
    std::cout << "Q/q. Exit\n";

    auto _choice = selectChoice();

    switch(_choice)
    {
        case 1:
            startTournamentMenu();
            break;
        case 2:
            viewRules();
            break;
        default:
            printInvalidChoice();
            mainMenu();
            break;
    }
}

void Menu::startTournamentMenu()
{
    std::cout << "\nStart Tournament Menu\n";
    printLine();
    printChooseOption();
    std::cout << "1. Draw players and build teams\n"; //read from file, shuffle, build teams, write teams on file
    std::cout << "2. Bind matches for round 1\n"; //read teams from file, shuffle, bind matches, write matches on file
    std::cout << "Start the tournament\n"; //read matches from file, update results on input and write on file
    std::cout << "99. Back to Main Menu\n";

    auto _choice = selectChoice();

    switch(_choice)
    {
        case 1:
            //read from file, shuffle, build teams, write teams on file
            drawPlayers();
            break;
        case 2:
            //read teams from file, shuffle, bind matches, write matches on file
            buildMatches();
            break;
        case 3:
            //read matches from file, update results on input and write on file
            break;
        case 99:
            mainMenu();
            break;
        default:
            printInvalidChoice();
            startTournamentMenu();
            break;
    }
}

void Menu::printChooseOption()
{
    std::cout << "\nChoose an option:\n";
}

void Menu::printYourChoice()
{
    std::cout << "Your choice: ";
}

int Menu::selectChoice()
{
    printYourChoice();
    int _choice;
    std::cin >> _choice;
return _choice;
}

void Menu::printInvalidChoice()
{
    std::cout << "Invalid choice! Try again.\n";
}
/************************************************************/

void printLine()
{
    std::cout << "--------------------------------------------\n";
}