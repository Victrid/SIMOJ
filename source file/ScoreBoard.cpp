#include "ScoreBoard.h"

//EVENT TABLE
bool Event[10]= {1,0,1,0,1,1,0,0,0,1};
int TT[10]= {100,120,130,150,170,190,200,200,200,240};
int ScoreBoard::Score(Code *Toscore)
{
    if(!Toscore->Check)
    {
        if(Toscore->Location != 7)
        {
            Unfinish++;
        }
        else
        {
            Good++;
        }
    }
    else
    {
        if(Toscore->Location != 7)
        {
            Unfinish++;
        }
        else
        {
            if(Toscore->ifError==Toscore->UserJudge)
            {
                CheckFail++;
                if(Toscore->Fatality)
                    Fail=true;
            }
            else
            {
                Good++;
            }
        }
    }
    Total++;
    return 0;
}
ScoreBoard::ScoreBoard(int Day)
{
    Good=0;
    Total=0;
    Unfinish=0;
    CheckFail=0;
    if(Day<10)
    {
        if(Event[Day])
            BribeEvent=true;
        else
            BribeEvent=false;
    }
    else
    {
        if(!Day%5)
            BribeEvent=true;
        else
            BribeEvent = false;
    }
    if(Day<10)
    {
        Tick = TT[Day];
    }
    else
    {
        Tick = 250;
    }
}
int ScoreBoard::Score()
{
    for (int i = 0; i < GetLength(AllProcess); i++)
    {
        if (AllProcess[i] == nullptr)
            break;
        Score(AllProcess[i]);
    }
    return 0;
}
