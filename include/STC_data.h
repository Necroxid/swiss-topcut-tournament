#ifndef STC_DATA_H
#define STC_DATA_H

#include "globals/globals.h"

#include <string>
#include <vector>

using namespace std;

//Player has a name, a surname, the team's name they belong to and an age
struct Player{
    string name;
    string surname;
    string team_name;
    int age;
};

//Team has a name, the two players forming it, the number of wins and the goal difference
struct Team{
    string name;
    Player player1;
    Player player2;
    int wins;
    int gd; //goal difference
};

//Match has the two teams battling each other, the goals made by them and the round the match is playing on
struct Match{
    Team team1;
    Team team2;
    int goal1;
    int goal2;
    int round;
};

typedef vector<Player> players; //The list of players
typedef vector<Team> teams; //The list of teams
typedef vector<Match> matches; //The list of matches

#endif