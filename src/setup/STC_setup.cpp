#include "STC_setup.h"

void insertPlayer(Player player, players &_players)
{
    _players.push_back(player);
}

void insertTeam(Team team, teams &_teams)
{
    _teams.push_back(team);
}

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
        insertPlayer(new_player, _players);
    }
}

//dopo chiamata shuffleContainer(_players)
//create and build teams
void buildTeams(players &_players, teams &_teams)
{
    auto j=1;
    for(auto i=0; i<_players.size(); i+=2)
    {
        Team new_team;
        new_team.player1 = _players[i];
        new_team.player2 = _players[i+1];
        new_team.name = "Squadra" + to_string(j);
        insertTeam(new_team, _teams);
        setTeamName(_teams, j-1, new_team.name);
        j++;
    }
}

void setTeamName(teams &_teams, int num_team, string _name)
{
    _teams[num_team].name = _name;
    _teams[num_team].player1.team_name = _name;
    _teams[num_team].player2.team_name = _name;
}

void writeTeamsOnFile(ofstream &ofs, teams &_teams)
{
    for(auto i=0; i<_teams.size(); i++)
    {
        ofs << _teams[i].name << ": " << _teams[i].player1.name << " " << _teams[i].player1.surname << ", " << _teams[i].player2.name << " " << _teams[i].player2.surname << endl;
    }
}

int getNumPlayers()
{
    int t;
    cin >> t;
    return t;
}

bool checkNumPlayers(players &_players)
{
    auto input_numplayers = getNumPlayers();
    return input_numplayers == _players.size() && input_numplayers == N_PLAYERS;
}