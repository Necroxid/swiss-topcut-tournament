#ifndef STC_SETUP_H
#define STC_SETUP_H

#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>

#include "../../include/STC_data.h"

//Insert players on the list
void insertPlayers(Player player, players &_players);
//Insert teams on the list
void insertTeams(Team team, teams &_teams);
//Reads the players information from a file
void readPlayersFromFile(ifstream &ifs, players &_players);
//Build the teams binding 2 players
void buildTeams(players &_players, teams &_teams);
//void readTeamsFromFile(ifstream &ifs, teams &_teams, players _players);

//Get the number of players from input (for test)
int getNumPlayers();
//Check if the number of players given in input is the same as the one specified in globals.h
bool checkNumPlayers(players &_players);
//void shufflePlayers(players &_players);
//void shuffleTeams(teams &_teams);

//shuffle function for simulating an extraction (of players and teams)
template<typename Container>
void shuffleContainer(Container &c)
{
    random_device rd;
    shuffle(c.begin(), c.end(), rd);
}//da fare solo all'inizio

#endif