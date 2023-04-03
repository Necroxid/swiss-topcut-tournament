#include "STC_swiss.h"

int Swiss::setNrounds(int n_teams)
{
    return ceil(log2(n_teams));
}

int Swiss::setNmatches(int n_players)
{
    int n_rounds = setNrounds(n_players);
    int n_teams = n_players/2;
    return (n_teams/2)*n_rounds;
}

void Swiss::bindMatches(teams &_teams, matches &_matches)
{
    //create matches
    for(auto i=0; i<_teams.size(); i+=2)
    {
        newMatch(_teams, _matches, i, i+1);
    }
}