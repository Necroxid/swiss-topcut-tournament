#include "STC_setup.h"

void insertPlayers(Player player, players &_players)
{
    _players.push_back(player);
}

void insertTeams(Team team, teams &_teams)
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
        insertPlayers(new_player, _players);
    }
}

//dopo chiamata shufflePlayers
void buildTeams(players &_players, teams &_teams)
{
    auto j=0;
    for (auto i=0; i<_players.size(); i+=2)
    {   _teams[j].player1 = _players[i];
        _teams[j].player2 = _players[i+1];
        j++;
    }
}

void setTeamName(teams &_teams, int num_team, string _name)
{
    _teams[num_team].name = _name;
}

/*
void readTeamsFromFile(ifstream &ifs, teams &_teams, players _players)
{
    auto i = 0;
    while(!ifs.eof())
    {
        string _name;
        auto _wins = 0, _gd = 0;
        ifs >> _name;
        Team new_team;
        new_team.name = _name;
        new_team.player1 = _players[i];
        new_team.player2 = _players[i+1];
        new_team.wins = _wins;
        new_team.gd = _gd;
        insertTeams(new_team, _teams);
        i += 2;
    }
}*/

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

//shuffle da fare solo all'inizio
void shufflePlayers(players &_players)
{
    random_device rd;
    shuffle(_players.begin(), _players.end(), rd);
}

void shuffleTeams(teams &_teams)
{
    random_device rd;
    shuffle(_teams.begin(), _teams.end(), rd);
}