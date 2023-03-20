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
    
    cout << N_PLAYERS << endl << N_TEAMS_SWISS << endl << N_ROUNDS_SWISS << endl;


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