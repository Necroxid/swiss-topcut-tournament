#ifndef STC_DATA_H
#define STC_DATA_H

#include <string>
#include <vector>
#include <utility>

//Player has a name, a surname, the team's name they belong to and an age
struct Player{
    std::string name;
    std::string surname;
    int age;
    std::string team_name;
};

//Team has a name, the two players forming it, the number of wins and the goal difference
struct Team{
    std::string name;
    Player player1;
    Player player2;
    int gd; //goal difference
    int wins;
    double win_percentage;
    std::vector<double> opp_win_percentage;
    double opp_win_percentage_avg;
    std::vector<double> opp_opp_win_percentage;
    double opp_opp_win_percentage_avg;
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

typedef std::vector<Player> players; //The list of players
typedef std::vector<Team> teams; //The list of teams
typedef std::vector<Match> matches; //The list of matches
typedef std::vector<std::pair<Team, Team>> pairings_list; //The list of pairings

#endif