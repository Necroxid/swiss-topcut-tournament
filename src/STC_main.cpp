#include "STC_menu.h"
#include "swiss_phase/STC_swiss.h"
#include "topcut_phase/STC_topcut.h"

#include <ctime>
#include <cstdlib>
#include <iomanip>

/*const auto N_PLAYERS = []() -> auto {
                     int t;
                     cout << "Inserisci il numero di giocatori: ";
                     cin >> t;
                     return t;
                     }();*/

int main()
{
    srand(time(NULL));
    std::cout << "\nWelcome to the Table Football Tournament!\n";
    printLine();
    players _players;
    teams _teams;
    matches _matches;
    //test for readPlayersFromFile
    std::ifstream ifs("../txt/players_test.txt");
    readPlayersFromFile(ifs, _players);
    ifs.close();

    shuffleContainer(_players);
    buildTeams(_players, _teams);
    shuffleContainer(_teams);

    //test for writeTeamsOnFile
    std::ofstream ofs("../txt/teams_test.txt");
    writeTeamsOnFile(ofs, _teams);
    ofs.close();

    auto teams_size = _teams.size();
    auto n_rounds = Swiss::setNrounds(teams_size);
    auto n_matches_per_round = teams_size/2;

    std::cout << std::setprecision(4);
    std::cout << "Number of teams: " << teams_size << std::endl;
    std::cout << "Number of rounds: " << n_rounds << std::endl;
    //test for bindMatches and simulate the matches
    for(auto i=0; i<n_rounds; i++)
    {
        Swiss::bindMatches(_teams, _matches);
        std::cout << "Chart pre-round " << i+1 << std::endl;
        for(auto j=0; j<teams_size; j++)
        {
            std::cout << _teams[j].name << " (" << _teams[j].wins << "-" << i-_teams[j].wins << ", gd: " << _teams[j].gd << ", win%: " << _teams[j].win_percentage << "%, opp_win%: " << _teams[j].opp_win_percentage_avg << "%, opp_opp_win%: " << _teams[j].opp_opp_win_percentage_avg << "%)" << std::endl;
        }
        std::cout << "\nRound " << i+1;
        //simulate matches using insertmatchresults function and print on output the results
        for(auto j=0; j<n_matches_per_round; j++)
        {
            int _score1 = rand()%11;
            int _score2 = rand()%11;
            while(_score1 == _score2) _score2 = rand()%11;
            insertMatchResults(_matches, _teams, j, i, _score1, _score2);
            auto losses1 = i+1 - _matches[j].team1.wins;
            auto losses2 = i+1 - _matches[j].team2.wins;
            if(j==0) std::cout << std::endl;
            std::cout << _matches[j].team1.name << " (" << _matches[j].team1.wins << "-" << losses1 << ", gd: " << _matches[j].team1.gd << ", win%: " << _matches[j].team1.win_percentage << "%, opp_win%: " << _matches[j].team1.opp_win_percentage_avg << "%, opp_opp_win%: " << _matches[j].team1.opp_opp_win_percentage_avg << "%) ";
            std::cout << _matches[j].score1 << " - " << _matches[j].score2 << " ";
            std::cout << _matches[j].team2.name << " (" << _matches[j].team2.wins << "-" << losses2 << ", gd: " << _matches[j].team2.gd << ", win%: " << _matches[j].team2.win_percentage << "%, opp_win%: " << _matches[j].team2.opp_win_percentage_avg  << "%, opp_opp_win%: " << _matches[j].team2.opp_opp_win_percentage_avg<< "%)" << std::endl;
        }
        if(i < n_rounds-1) std::cout << std::endl;
        sortTeams(_teams);
        _matches.clear();
    }
    std::cout << "\nChart post-swiss phase" << std::endl;
    for(auto i=0; i<teams_size; i++)
    {
        std::cout << _teams[i].name << " (" << _teams[i].wins << "-" << n_rounds-_teams[i].wins << ", gd: " << _teams[i].gd << ", win%: " << _teams[i].win_percentage  << "%, opp_win%: " << _teams[i].opp_win_percentage_avg << "%, opp_opp_win%: " << _teams[i].opp_opp_win_percentage_avg << "%)" << std::endl;
    }

}