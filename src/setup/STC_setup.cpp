#include "STC_setup.h"

#include <algorithm>

/*
//globals initialization

const int N_PLAYERS = 16; -> players.size();
const int N_TEAMS_SWISS = (int)N_PLAYERS/2; -> teams.size();
const int N_ROUNDS_SWISS = ceil(log(N_PLAYERS)); done
const int N_MATCHES_SWISS = (N_TEAMS_SWISS/2)*N_ROUNDS_SWISS; done
//Number of teams in the topcut
const int N_TEAMS_TOPCUT = 4;
//Number of matches in the topcut
const int N_MATCHES_TOPCUT = N_TEAMS_TOPCUT;
//Total number of matches
const int N_MATCHES_TOT = N_MATCHES_SWISS + N_MATCHES_TOPCUT;
*/


void readPlayersFromFile(std::ifstream &ifs, players &_players)
{
    while(!ifs.eof())
    {
        std::string _name, _surname, _team_name = "BLANK";
        int _age;
        ifs >> _name >> _surname >> _age;
        Player new_player;
        new_player.name = _name;
        new_player.surname = _surname;
        new_player.team_name = _team_name;
        new_player.age = _age;
        insertElem(new_player, _players);
    }
}

void newTeam(teams &_teams, Player _player1, Player _player2)
{
    Team new_team;
    new_team.player1 = _player1;
    new_team.player2 = _player2;
    new_team.gd = 0;
    new_team.wins = 0;
    new_team.win_percentage = 0;
    new_team.opp_win_percentage_avg = 0;
    new_team.opp_opp_win_percentage_avg = 0;
    insertElem(new_team, _teams);
}

void buildTeams(players &_players, teams &_teams)
{
    auto j = 1;
    for(auto i=0; i<_players.size(); i+=2)
    {
        newTeam(_teams, _players[i], _players[i+1]);
        setTeamName(_teams, j-1, "Squadra" + std::to_string(j));
        j++;
    }
}

void setTeamName(teams &_teams, int n_team, std::string _name)
{
    _teams[n_team].name = _name;
    _teams[n_team].player1.team_name = _name;
    _teams[n_team].player2.team_name = _name;
}

void writeTeamsOnFile(std::ofstream &ofs, teams &_teams)
{
    for(auto i=0; i<_teams.size(); i++)
    {
        ofs << _teams[i].name << ": " << _teams[i].player1.name << " " << _teams[i].player1.surname << ", " << _teams[i].player2.name << " " << _teams[i].player2.surname;
        if(i < _teams.size()-1)
            ofs << std::endl;
    }
}

void team_members(teams &_teams, int n_team)
{
    std::cout << _teams[n_team].name << ": " << _teams[n_team].player1.name << " " << _teams[n_team].player1.surname << ", " << _teams[n_team].player2.name << " " << _teams[n_team].player2.surname << std::endl;
}

void newMatch(teams &_teams, matches &_matches, int i, int j)
{
    Match new_match;
    new_match.team1 = _teams[i];
    new_match.team2 = _teams[j];
    insertElem(new_match, _matches);
}

double calc_avg(std::vector<double> _opp_win_percentage)
{
    double sum = 0;
    for(auto i=0; i<_opp_win_percentage.size(); i++)
        sum += _opp_win_percentage[i];
    return (sum == 0 || _opp_win_percentage.size() == 0) ? 0 : (double)(sum / _opp_win_percentage.size());
}

double calc_percentage(int _wins, int _rounds)
{
    return (_wins == 0 || _rounds == 0) ? 0 : (double)((double)_wins / (double)_rounds) * 100.0;
}

//insert match results and update team wins and goal difference
void insertMatchResults(matches &_matches, teams &_teams, int num_match, int num_rounds, int _score1, int _score2)
{
    _matches[num_match].score1 = _score1;
    _matches[num_match].score2 = _score2;
    _matches[num_match].team1.wins += (_score1 > _score2) ? 1 : 0;
    _matches[num_match].team2.wins += (_score1 < _score2) ? 1 : 0;
    _matches[num_match].team1.gd += _score1 - _score2;
    _matches[num_match].team2.gd += _score2 - _score1;
    _matches[num_match].team1.win_percentage = calc_percentage(_matches[num_match].team1.wins, num_rounds+1);
    _matches[num_match].team2.win_percentage = calc_percentage(_matches[num_match].team2.wins, num_rounds+1);
    _matches[num_match].team1.opp_win_percentage.emplace_back(_matches[num_match].team2.win_percentage);
    _matches[num_match].team2.opp_win_percentage.emplace_back(_matches[num_match].team1.win_percentage);
    _matches[num_match].team1.opp_win_percentage_avg = calc_avg(_matches[num_match].team1.opp_win_percentage);
    _matches[num_match].team2.opp_win_percentage_avg = calc_avg(_matches[num_match].team2.opp_win_percentage);
    _matches[num_match].team1.opp_opp_win_percentage.emplace_back(_matches[num_match].team2.opp_win_percentage_avg);
    _matches[num_match].team2.opp_opp_win_percentage.emplace_back(_matches[num_match].team1.opp_win_percentage_avg);
    _matches[num_match].team1.opp_opp_win_percentage_avg = calc_avg(_matches[num_match].team1.opp_opp_win_percentage);
    _matches[num_match].team2.opp_opp_win_percentage_avg = calc_avg(_matches[num_match].team2.opp_opp_win_percentage); 
    //update team list with the new values, find the team in the list and update it
    auto it1 = find_if(_teams.begin(), _teams.end(), [&_matches, num_match](Team t) -> bool {return t.name == _matches[num_match].team1.name;});
    auto it2 = find_if(_teams.begin(), _teams.end(), [&_matches, num_match](Team t) -> bool {return t.name == _matches[num_match].team2.name;});
    *it1 = _matches[num_match].team1;
    *it2 = _matches[num_match].team2;
}

//sort teams by number of wins and in case of equality by goal difference and in case of equality by opponent's win percentage and in case of equality by opponent's opponent's win percentage
void sortTeams(teams &_teams)
{
    std::sort(_teams.begin(), _teams.end(), [](Team a, Team b) -> bool {
        auto A_opp_win_rounded = round(a.opp_win_percentage_avg * 100.0)/100.0;
        auto B_opp_win_rounded = round(b.opp_win_percentage_avg * 100.0)/100.0;
        auto A_opp_opp_win_rounded = round(a.opp_opp_win_percentage_avg * 100.0)/100.0;
        auto B_opp_opp_win_rounded = round(b.opp_opp_win_percentage_avg * 100.0)/100.0;

        if(a.wins > b.wins)
            return true;
        else if(a.wins < b.wins)
            return false;
        //case a.wins == b.wins
        if(a.gd > b.gd)
            return true;
        else if(a.gd < b.gd)
            return false;
        //case a.gd == b.gd
        if(A_opp_win_rounded > B_opp_win_rounded)
            return true;
        else if(A_opp_win_rounded < B_opp_win_rounded)
            return false;
        //case A_opp_win_rounded == B_opp_win_rounded
        if(A_opp_opp_win_rounded > B_opp_opp_win_rounded)
            return true;
        else if(A_opp_opp_win_rounded < B_opp_opp_win_rounded)
            return false;
        //case A_opp_opp_win_rounded == B_opp_opp_win_rounded
        return false;
    });
}

//sort teams by number of wins and in case of equality by goal difference and in case of equality by opponent's win percentage and in case of equality by opponent's opponent's win percentage
/*void sortTeams(teams &_teams)
{
    std::sort(_teams.begin(), _teams.end(), [](Team a, Team b) ->
    bool {return (a.wins > b.wins) ? true :
                 (a.wins == b.wins) ? (a.gd > b.gd) ? true :
                                      (a.gd == b.gd) ? (round(a.opp_win_percentage_avg * 100.0)/100.0 > round(b.opp_win_percentage_avg * 100.0)/100.0) ? true :
                                                       (round(a.opp_win_percentage_avg * 100.0)/100.0 == round(b.opp_win_percentage_avg * 100.0)/100.0) ? (round(a.opp_opp_win_percentage_avg * 100.0)/100.0 > round(b.opp_opp_win_percentage_avg * 100.0)/100.0) ? true :
                                                                                                                                                          false : false : false : false;});
}*/