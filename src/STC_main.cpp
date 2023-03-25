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
    std::ifstream ifs("../txt/players_test.txt");
    readPlayersFromFile(ifs, _players);
    ifs.close();

    shuffleContainer(_players);
    buildTeams(_players, _teams);

    //test for writeTeamsOnFile
    std::ofstream ofs("../txt/teams_test.txt");
    writeTeamsOnFile(ofs, _teams);
    ofs.close();

    auto teams_size = _teams.size();
    auto n_rounds = setNroundsSwiss(teams_size);
    auto n_matches_per_round = teams_size/2;

    std::cout << "Number of teams: " << teams_size << std::endl;
    std::cout << "Number of rounds: " << n_rounds << std::endl;
    //test for bindMatches and simulate the matches
    for(auto i=0; i<n_rounds; i++)
    {
        if(i==0) bindMatches(_teams, _matches);
        else bindMatches_rematchLR(_teams, _matches);
        std::cout << "Chart pre-round " << i+1 << std::endl;
        for(auto j=0; j<teams_size; j++)
        {
            std::cout << _teams[j].name << " (" << _teams[j].wins << "-" << i-_teams[j].wins << ", gd: " << _teams[j].gd << ")" << std::endl;
        }
        std::cout << "\nRound " << i+1;
        //simulate matches using insertmatchresults function and print on output the results
        for(auto j=0; j<n_matches_per_round; j++)
        {
            int _score1 = rand()%11;
            int _score2 = rand()%11;
            while(_score1 == _score2) _score2 = rand()%11;
            insertMatchResults(_matches, _teams, j, _score1, _score2);
            auto losses1 = i+1 - _matches[j].team1.wins;
            auto losses2 = i+1 - _matches[j].team2.wins;
            if(j==0) std::cout << std::endl;
            std::cout << _matches[j].team1.name << " (" << _matches[j].team1.wins << "-" << losses1 << ", gd: " << _matches[j].team1.gd << ") " << _matches[j].score1 << " - " << _matches[j].score2 << " " << _matches[j].team2.name << " (" << _matches[j].team2.wins << "-" << losses2 << ", gd: " << _matches[j].team2.gd << ")" << std::endl;
        }
        if(i < n_rounds-1) std::cout << std::endl;
        sortTeams(_teams);
        _matches.clear();
    }
    std::cout << "\nChart post-swiss phase" << std::endl;
    for(auto i=0; i<teams_size; i++)
    {
        std::cout << _teams[i].name << " (" << _teams[i].wins << "-" << n_rounds-_teams[i].wins << ", gd: " << _teams[i].gd << ")" << std::endl;
    }

}