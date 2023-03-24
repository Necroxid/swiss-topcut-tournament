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
    //test for readPlayersFromFile
    ifstream ifs("../txt/players_test.txt");
    readPlayersFromFile(ifs, _players);
    ifs.close();

    shuffleContainer(_players);
    buildTeams(_players, _teams);

    //test for writeTeamsOnFile
    ofstream ofs("../txt/teams_test.txt");
    writeTeamsOnFile(ofs, _teams);
    ofs.close();

    auto teams_size = _teams.size();
    auto n_rounds = setNroundsSwiss(teams_size);
    auto n_matches_per_round = teams_size/2;

    //test for bindMatches and simulate the matches
    for(auto i=0; i<n_rounds; i++)
    {
        bindMatches(_teams, _matches);
        cout << "Chart pre-round " << i+1 << endl;
        for(auto j=0; j<teams_size; j++)
        {
            cout << _teams[j].name << " (wins: " << _teams[j].wins << ", gd: " << _teams[j].gd << ")" << endl;
        }
        //simulate matches using insertmatchresults function and print on output the results
        for(auto j=0; j<n_matches_per_round; j++)
        {
            int _score1 = rand()%11;
            int _score2 = rand()%11;
            while(_score1 == _score2) _score2 = rand()%11;
            insertMatchResults(_matches, _teams, j, _score1, _score2);
            if(j==0) cout << endl;
            cout << _matches[j].team1.name << " (wins: " << _matches[j].team1.wins << ", gd: " << _matches[j].team1.gd << ") " << _matches[j].score1 << " - " << _matches[j].score2 << " " << _matches[j].team2.name << " (wins: " << _matches[j].team2.wins  << ", gd: " << _matches[j].team2.gd << ")" << endl;
        }
        if(i < n_rounds-1) cout << endl;
        sortTeams(_teams);
        _matches.clear();
    }
    cout << "\nChart post-swiss phase" << endl;
    for(auto i=0; i<teams_size; i++)
    {
        cout << _teams[i].name << " (wins: " << _teams[i].wins << ", gd: " << _teams[i].gd << ")" << endl;
    }

}