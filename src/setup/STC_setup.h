#ifndef STC_SETUP_H
#define STC_SETUP_H

#include "../../include/STC_data.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>

//Insert players on the list
void insertPlayer(Player player, players &_players);
//Insert teams on the list
void insertTeam(Team team, teams &_teams); //vedere se serve, magari traformarlo in output stream
//Reads the players information from a file
void readPlayersFromFile(ifstream &ifs, players &_players);
//Build the teams binding 2 players
void buildTeams(players &_players, teams &_teams);
//void readTeamsFromFile(ifstream &ifs, teams &_teams, players _players);

//set the name of a team
void setTeamName(teams &_teams, int num_team, string _name);

//Get the number of players from input (for test)
int getNumPlayers();
//Check if the number of players given in input is the same as the one specified in globals.h (for test)
bool checkNumPlayers(players &_players);

//shuffle function for simulating an extraction (of players and teams)
template<typename Container>
void shuffleContainer(Container &c)
{
    random_device rd;
    shuffle(c.begin(), c.end(), rd);
}//da fare solo all'inizio

#endif