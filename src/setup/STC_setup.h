#ifndef STC_SETUP_H
#define STC_SETUP_H

#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>

#include "../../include/STC_data.h"

void insertPlayers(Player player, players &_players);
void insertTeams(Team team, teams &_teams);
void readPlayersFromFile(ifstream &ifs, players &_players);
void buildTeams(players &_players, teams &_teams);
//void readTeamsFromFile(ifstream &ifs, teams &_teams, players _players);

int getNumPlayers();
bool checkNumPlayers(players &_players);
//void shufflePlayers(players &_players);
//void shuffleTeams(teams &_teams);

//shuffle da fare solo all'inizio
template<typename Container>
void shuffleContainer(Container &c)
{
    random_device rd;
    shuffle(c.begin(), c.end(), rd);
}

#endif