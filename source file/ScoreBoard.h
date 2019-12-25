#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "CODESYS.h"
class ScoreBoard
{
    public:
    int finalscore;
    int Tick;
    int Good;
    int Total;
    int Unfinish;
    int CheckFail;
    bool BribeEvent;
    bool Fail=false;

    ScoreBoard(){Good=0;Total=0;Unfinish=0;CheckFail=0;}
    ScoreBoard(int day);
    int Score();
    int Score(Code *Toscore);
    ~ScoreBoard(){};
};
#endif // SCOREBOARD_H
