#ifndef GLOBALS_H
#define GLOBALS_H

//globals initialization
const int N_PLAYERS = 16;
const int N_TEAMS_SWISS = (int)N_PLAYERS/2;
const int N_ROUNDS_SWISS = ceil(log(N_PLAYERS));
const int N_MATCHES_SWISS = (N_TEAMS_SWISS/2)*N_ROUNDS_SWISS;
const int N_TEAMS_TOPCUT = 4;
const int N_MATCHES_TOPCUT = N_TEAMS_TOPCUT;
const int N_MATCHES_TOT = N_MATCHES_SWISS + N_MATCHES_TOPCUT;

#endif