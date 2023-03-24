#ifndef STC_SWISS_H
#define STC_SWISS_H

#include "../setup/STC_setup.h"

//set the number of rounds in Swiss
int setNroundsSwiss(int n_players);
//set the number of matches in Swiss
int setNmatchesSwiss(int n_players);
//implement swiss algorithm with pairings, based on the number of wins and goal difference
void bindMatches(teams &_teams, matches &_matches);

#endif