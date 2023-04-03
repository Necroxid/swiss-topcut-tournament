#ifndef STC_SWISS_H
#define STC_SWISS_H

#include "../setup/STC_setup.h"

namespace Swiss {
    //set the number of rounds in Swiss
    int setNrounds(int n_teams);
    //set the number of matches in Swiss
    int setNmatches(int n_players);
    //implement swiss algorithm with pairings, based on the number of wins and goal difference (rematch allowed)
    void bindMatches(teams &_teams, matches &_matches);
}
#endif