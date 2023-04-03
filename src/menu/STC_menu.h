#ifndef STC_MENU_H
#define STC_MENU_H

#include "../setup/STC_setup.h"

//create terminal menu functions for the tournament
namespace Menu {
    void mainMenu();
    void startTournamentMenu();
    void viewRules();
    void drawPlayers();
    void buildMatches();


    void printChooseOption();
    void printYourChoice();
    int selectChoice();
    void printInvalidChoice();
}
    void printLine();
#endif