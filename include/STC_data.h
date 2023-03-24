#ifndef STC_DATA_H
#define STC_DATA_H

#include <string>
#include <vector>

using namespace std;

//Player has a name, a surname, the team's name they belong to and an age
struct Player{
    string name;
    string surname;
    int age;
    string team_name;
};

//Team has a name, the two players forming it, the number of wins and the goal difference
struct Team{
    string name;
    Player player1;
    Player player2;
    int wins;
    int gd; //goal difference
};

//Match has the table the match is playing at, the two teams battling each other, the goals made by them and the round the match is playing on
struct Match{
    int table;
    Team team1;
    Team team2;
    int score1;
    int score2;
    int round;
};

typedef vector<Player> players; //The list of players
typedef vector<Team> teams; //The list of teams
typedef vector<Match> matches; //The list of matches

#endif