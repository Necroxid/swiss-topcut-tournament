#ifndef STC_SETUP_H
#define STC_SETUP_H

#include "../../include/STC_data.h"

#include <fstream>
#include <iostream>
#include <random>

//Read the players information from a file
void readPlayersFromFile(std::ifstream &ifs, players &_players);
//Build the teams binding 2 players
void buildTeams(players &_players, teams &_teams);
//set the name of a team
void setTeamName(teams &_teams, int num_team, std::string _name);
//Output the teams on a file
void writeTeamsOnFile(std::ofstream &ofs, teams &_teams);
//list the members of a team
void team_members(teams &_teams, int n_team);
//create a new match between the team i and the team j
void newMatch(teams &_teams, matches &_matches, int i, int j);
//insert match results
void insertMatchResults(matches &_matches, teams &_teams, int num_match, int num_rounds, int _score1, int _score2);
//sort teams by wins and goal difference
void sortTeams(teams &_teams);

//template functions

//template function for inserting a player or a team on the list
template<typename T, typename Container>
void insertElem(T elem, Container &c)
{
    c.emplace_back(elem);
}

//shuffle template function for simulating an extraction (of players and teams)
template<typename Container>
void shuffleContainer(Container &c)
{
    std::random_device rd;
    std::shuffle(c.begin(), c.end(), rd);
}//da fare solo all'inizio

#endif