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

//globals initialization
const int N_PLAYERS = 16;
const int N_TEAMS_SWISS = (int)N_PLAYERS/2;
const int N_ROUNDS_SWISS = ceil(log(N_PLAYERS));
const int N_MATCHES_SWISS = (N_TEAMS_SWISS/2)*N_ROUNDS_SWISS;
const int N_TEAMS_TOPCUT = 4;
const int N_MATCHES_TOPCUT = N_TEAMS_TOPCUT;
const int N_MATCHES_TOT = N_MATCHES_SWISS + N_MATCHES_TOPCUT;

int main()
{
    srand(time(NULL));
    players _players;
    


}

/*
createEmptyPlayers(_players);
for (int i=0; i<_players.size(); i++)
{
    _players[i].age = i;
    cout << _players[i].age << " ";
}

shufflePlayers(_players);
cout << endl;
for (int i=0; i<_players.size(); i++)
{
    cout << _players[i].age << " ";
}*/


//cout << "Inserisci il numero di giocatori: ";
//while(!checkNumPlayers(_players)) cout << "Il numero di giocatori non corrisponde, ritenta.\n";

//cout << endl << N_PLAYERS << endl << _players.size();