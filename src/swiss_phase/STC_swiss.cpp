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