#ifndef STC_DATA_H
#define STC_DATA_H

#include <string>
#include <vector>

#include "globals/globals.h"

using namespace std;

struct Player{
    string name;
    string surname;
    string team_name;
    int age;
};

struct Team{
    string name;
    Player player1;
    Player player2;
    int wins;
    int gd; //goal difference
};

struct Match{
    Team team1;
    Team team2;
    int goal1;
    int goal2;
};

typedef vector<Player> players;
typedef vector<Team> teams;
typedef vector<Match> matches;

#endif