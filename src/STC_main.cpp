#include <ctime>
#include <cstdlib>

#include "swiss_phase/STC_swiss.h"
#include "topcut_phase/STC_topcut.h"

/*const auto N_PLAYERS = []() -> auto {
                     int t;
                     cout << "Inserisci il numero di giocatori: ";
                     cin >> t;
                     return t;
                     }();*/

int main()
{
    srand(time(NULL));

    players _players;
    teams _teams;
    matches _matches;
    //create a test for readPlayersFromFile
    ifstream ifs("../txt/players_test.txt");
    readPlayersFromFile(ifs, _players);
    ifs.close();

    shuffleContainer(_players);
    buildTeams(_players, _teams);

    //create a test for writeTeamsOnFile
    ofstream ofs("../txt/teams_test.txt");
    writeTeamsOnFile(ofs, _teams);
    ofs.close();
}