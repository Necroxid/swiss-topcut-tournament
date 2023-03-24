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

    int n_rounds = setNroundsSwiss(_teams.size());
    //int n_matches_tot = setNmatchesSwiss(_teams.size());
    int n_matches_per_round = _teams.size()/2;

    //create a test for bindMatches and simulate the matches
    for(auto i=0; i<n_rounds; i++)
    {
        sortTeams(_teams);
        bindMatches(_teams, _matches);
        cout << "Chart pre-round " << i+1 << endl;
        for(auto j=0; j<_teams.size(); j++)
        {
            cout << _teams[j].name << " (wins: " << _teams[j].wins << ", gd: " << _teams[j].gd << ")" << endl;
        }
        //simulate matches using insertmatchresults function and print on output the results
        for(auto j=0; j<n_matches_per_round; j++)
        {
            int _score1 = rand()%10;
            int _score2 = rand()%10;
            insertMatchResults(_matches, _teams, j, _score1, _score2);
            if(j==0) cout << endl;
            cout << _matches[j].team1.name << "(wins: " << _matches[j].team1.wins << ", gd: " << _matches[j].team1.gd << ") " << _matches[j].score1 << " - " << _matches[j].score2 << " " << _matches[j].team2.name << "(wins: " << _matches[j].team2.wins  << ", gd: " << _matches[j].team2.gd << ")" << endl;
        }
        if(i!=n_rounds-1) cout << endl;
        _matches.clear();
    }

}