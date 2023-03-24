#include "STC_setup.h"


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


void readPlayersFromFile(ifstream &ifs, players &_players)
{
    while(!ifs.eof())
    {
        string _name, _surname, _team_name = "BLANK";
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

void buildTeams(players &_players, teams &_teams)
{
    auto j = 1;
    for(auto i=0; i<_players.size(); i+=2)
    {
        Team new_team;
        new_team.player1 = _players[i];
        new_team.player2 = _players[i+1];
        new_team.gd = 0;
        new_team.wins = 0;
        insertElem(new_team, _teams);
        setTeamName(_teams, j-1, "Squadra" + to_string(j));
        j++;
    }
}

void setTeamName(teams &_teams, int n_team, string _name)
{
    _teams[n_team].name = _name;
    _teams[n_team].player1.team_name = _name;
    _teams[n_team].player2.team_name = _name;
}

void writeTeamsOnFile(ofstream &ofs, teams &_teams)
{
    for(auto i=0; i<_teams.size(); i++)
    {
        ofs << _teams[i].name << ": " << _teams[i].player1.name << " " << _teams[i].player1.surname << ", " << _teams[i].player2.name << " " << _teams[i].player2.surname;
        if(i != _teams.size()-1)
            ofs << endl;
    }
}

void insertMatchResults(matches &_matches, teams &_teams, int num_match, int _score1, int _score2)
{
    //insert match results and update team wins and goal difference
    _matches[num_match].score1 = _score1;
    _matches[num_match].score2 = _score2;
    _matches[num_match].team1.wins += (_score1 > _score2) ? 1 : 0;
    _matches[num_match].team2.wins += (_score1 < _score2) ? 1 : 0;
    _matches[num_match].team1.gd += _score1 - _score2;
    _matches[num_match].team2.gd += _score2 - _score1;
    //update team list with the new values, find the team in the list and update it
    auto it1 = find_if(_teams.begin(), _teams.end(), [&_matches, num_match](Team t) -> bool {return t.name == _matches[num_match].team1.name;});
    auto it2 = find_if(_teams.begin(), _teams.end(), [&_matches, num_match](Team t) -> bool {return t.name == _matches[num_match].team2.name;});
    *it1 = _matches[num_match].team1;
    *it2 = _matches[num_match].team2;
}

//sort teams by number of wins and in case of equality by goal difference
void sortTeams(teams &_teams)
{
    sort(_teams.begin(), _teams.end(), [](Team a, Team b) -> bool {return (a.wins > b.wins) ? true : (a.wins == b.wins) ? (a.gd > b.gd) : false;});
}