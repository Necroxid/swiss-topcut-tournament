#ifndef GLOBALS_H
#define GLOBALS_H

#include <cmath>

//globals initialization

//Total number of players
const int N_PLAYERS = 16;
//Total number of teams
const int N_TEAMS_SWISS = (int)N_PLAYERS/2;
//Number of rounds in Swiss
const int N_ROUNDS_SWISS = ceil(log(N_PLAYERS));
//Number of matches in Swiss
const int N_MATCHES_SWISS = (N_TEAMS_SWISS/2)*N_ROUNDS_SWISS;
//Number of teams in the topcut
const int N_TEAMS_TOPCUT = 4;
//Number of matches in the topcut
const int N_MATCHES_TOPCUT = N_TEAMS_TOPCUT;
//Total number of matches
const int N_MATCHES_TOT = N_MATCHES_SWISS + N_MATCHES_TOPCUT;

#endif