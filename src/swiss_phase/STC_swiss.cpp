#include "STC_swiss.h"


int setNroundsSwiss(int n_teams)
{
    return ceil(log2(n_teams));
}

int setNmatchesSwiss(int n_players)
{
    int n_rounds = setNroundsSwiss(n_players);
    int n_teams = n_players/2;
    return (n_teams/2)*n_rounds;
}

void newMatch(teams &_teams, matches &_matches, int i, int j)
{
    Match new_match;
    new_match.team1 = _teams[i];
    new_match.team2 = _teams[j];
    insertElem(new_match, _matches);
}

void bindMatches(teams &_teams, matches &_matches)
{
    //create matches
    for(auto i=0; i<_teams.size(); i+=2)
    {
        newMatch(_teams, _matches, i, i+1);
    }
}

void bindMatches_rematchLR(teams &_teams, matches &_matches)
{
    // Create matches, avoiding rematches if possible
    auto teams_size = _teams.size();
    for(auto i=0; i<teams_size-1; i+=2)
    {
        for(auto j=i+1; j<teams_size; j+=2)
        {
            if(_teams[i].name != _teams[j].name)
            { // check that the teams are not the same
                auto rematch_found = false;
                for (int k=0; k<_matches.size(); k++)
                {
                    // check if a match between these two teams has already been played
                    if ((_matches[k].team1.name == _teams[i].name && _matches[k].team2.name == _teams[j].name) ||
                        (_matches[k].team1.name == _teams[j].name && _matches[k].team2.name == _teams[i].name))
                    {
                        rematch_found = true;
                        break;
                    }
                }
                if (!rematch_found)
                {
                    newMatch(_teams, _matches, i, j);
                    break;
                }
            }
        }
    }
}