#ifndef _CODESYS_
#define _CODESYS_

#include <iostream>
#include <cstring>
#include <sstream>
#define _L_NE 0
#define _L_CL 1
#define _L_GL 2
#define _L_GM 3
#define _L_DS 4
#define _L_RM 5
#define _L_DC 6
#define _L_DL -1

class Code
{
    friend class ScoreBoard;
public:
    bool Fatality;
    static int Runcount;  //static Runcount indicator
    bool TestData[10];    //init generated
    int RemainRound = 0;  //used both by Comp and Run
    bool Check = false;   //checked by supervisor
    bool ifError = false; //if Error
    bool Judgeresult;     //After Judge
    bool UserJudge;
    int CompileStatus = 0;
    int RunStatus = 0; //0:no 1:compiling/Running 2:already
    int Location;
    //0:notexist 1:CodeList 2:GCC 3:GCC-Mem 4:DataSegmt 5:Run-mem 6:Declare
    //7: finished -1:deleted

    int CodeNum;
    int AutoPush();
    int HandPush();
    int HandPush(bool Selection[10]);
    bool Judge(bool n[10]);
    void UserJudging(bool);
    int LocPlusPlus();
    //constructor
    Code(bool Error = false, bool CheckMark = false,bool Fatal = false);
};
inline bool Create()
{
    static int firstrun =0;
    if(firstrun<3)
    {
        firstrun++;
        return true;
    }
    return (rand() % 3) ? false : true;
}

int AutoPush(); //Used to autopush all

//Code Lists Function and declaration
int datasetclear();
extern Code *CodeLists[10];
extern Code *GCCLists[4];
extern Code *DSLists[5];
extern Code *MemLists[3];
extern Code *DecLists[2];
extern Code *AllProcess[100];
bool CheckFull(Code *List[]);
int GetLast(Code *list[]);
void deletefromlist(Code *list[], Code *codeptr);
void mendontolist(Code *List[], Code *cdptr);
int GetLength(Code *List[]);
#endif
