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
    //createEmptyPlayers(_players, N_PLAYERS);
    teams _teams;
    //createEmptyTeams(_teams, N_TEAMS_SWISS);
    matches _matches;
    //createEmptyMatches(_matches, N_MATCHES_TOT);
    //create a test for readPlayersFromFile
    ifstream ifs("../txt/players_test.txt");
    readPlayersFromFile(ifs, _players);
    ifs.close();

    shuffleContainer(_players);
    buildTeams(_players, _teams);
    setTeamName(_teams, 0, "Team1");
    setTeamName(_teams, 1, "Team2");
    setTeamName(_teams, 2, "Team3");
    setTeamName(_teams, 3, "Team4");


    cout << "Players: " << endl;
    for(auto i=0; i<_players.size(); i++)
    {
        cout << _players[i].name << " " << _players[i].surname << " " << _players[i].age << " " << _players[i].team_name << endl;
    }
    cout << endl;
    cout << "Teams: " << endl;
    for(auto i=0; i<_teams.size(); i++)
    {
        cout << _teams[i].name << " " << _teams[i].player1.name << " " << _teams[i].player1.surname << " " << _teams[i].player2.name << " " << _teams[i].player2.surname << endl;
    }
    cout << endl;/*
    cout << "Matches: " << endl;
    for(auto i=0; i<_matches.size(); i++)
    {
        cout << _matches[i].team1.name << " " << _matches[i].team1.player1.name << " " << _matches[i].team1.player1.surname << " " << _matches[i].team1.player2.name << " " << _matches[i].team1.player2.surname << " " << _matches[i].team2.name << " " << _matches[i].team2.player1.name << " " << _matches[i].team2.player1.surname << _matches[i].team2.player2.name << " " << _matches[i].team2.player2.surname << endl;
    }
    cout << endl;*/


}