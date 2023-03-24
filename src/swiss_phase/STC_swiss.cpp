#include "STC_swiss.h"


int setNroundsSwiss(int n_players)
{
    return ceil(log(n_players));
}

int setNmatchesSwiss(int n_players)
{
    int n_rounds = setNroundsSwiss(n_players);
    int n_teams = n_players/2;
    return (n_teams/2)*n_rounds;
}

void bindMatches(teams &_teams, matches &_matches)
{
    //create matches
    for(auto i=0; i<_teams.size(); i+=2)
    {
        Match new_match;
        new_match.team1 = _teams[i];
        new_match.team2 = _teams[i+1];
        insertElem(new_match, _matches);
    }
}