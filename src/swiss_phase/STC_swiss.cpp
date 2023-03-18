#include "STC_swiss.h"

void createEmptyPlayers(players &_players)
{
    _players = players(N_PLAYERS, Player ());
}

void createEmptyTeams(teams &_teams)
{
    _teams = teams(N_TEAMS_SWISS, Team ());
}

void createEmptyMatches(matches &_matches)
{
    _matches = matches(N_MATCHES_SWISS, Match ());
}