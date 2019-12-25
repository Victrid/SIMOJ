#include "CODESYS.h"
//predefine dataset.

Code *CodeLists[10] = {nullptr};
Code *GCCLists[4] = {nullptr};
Code *DSLists[5] = {nullptr};
Code *MemLists[3] = {nullptr};
Code *DecLists[2] = {nullptr};
Code *AllProcess[100] = {nullptr};

int Code::Runcount = 7000;

Code::Code(bool Fatal/*= false*/,bool Error /*= false*/, bool CheckMark /* = false*/)
{
    //code number process
    CodeNum = Runcount;
    Runcount++;
    Fatality=Fatal;
    Location = _L_NE;
    Judgeresult=false;
    UserJudge=false;
    Location=0;
    //defines if been checked
    if (CheckMark || !(rand() % 3))
        //10 get 1;or predefined
        Check = true;
    else
        Check = false;
    //defines its correct dataset
    for (int i = 0; i < 10; i++)
        if (rand() % 20)
            TestData[i] = true;
        else
        {
            ifError = true;
            TestData[i] = false;
        }
    if (Error && (!ifError))
    {
        TestData[rand() % 10] = false;
        ifError = true;
    }
    //Push itself into Lists.
    AutoPush();
}
bool Code::Judge(bool n[10])
{
    for (int i = 0; i < 10; i++)
        if (n[i])
            if (!TestData[i])
            {
                Judgeresult = false;
                return false;
            };
    Judgeresult = true;
    return true;
}
// two pushes are used to update data.
//AutoPush: Happened when new Code is defined,
//or "Next Round" button is pressed.
//HandPush: Happened when an action, for example,
//click the button.
int Code::AutoPush()
{
    switch (Location)
    {
    case 0:
        //None exist
        if (CheckFull(CodeLists) || CheckFull(AllProcess))
        {
            delete this;
            Runcount--;
            return 0;
        }
        LocPlusPlus(); //location process
        break;
    case 3:
        //Compiling
        switch (CompileStatus)
        {
        case 0:
            CompileStatus++;
            RemainRound = rand() % 5 + 1;
            break;
        case 1:
            if (RemainRound)
                RemainRound--;
            else
                CompileStatus++;
            break;
        case 2:
            break;
        default:
            break;
        }
        break;
    case 5:
        switch (RunStatus)
        {
        case 0:
            break;
        case 1:
            RunStatus++;
            break;
        case 2:
            if (RemainRound)
                RemainRound--;
            else
                RunStatus++;
            break;
        case 3:
            if (!CheckFull(DecLists))
                LocPlusPlus();
            break;
        default:
            break;
        }
        break;

    default:
        break;
    }
    return 0;
}
int AutoPush()
{
    //all precess push
    for (int i = 0; i < GetLength(AllProcess); i++)
    {
        if (AllProcess[i] == nullptr)
            break;
        AllProcess[i]->AutoPush();
    }
    return 0;
}
int Code::HandPush()
{
    try
    {
        switch (Location)
        {
        case 1:
            if (CheckFull(GCCLists))
                throw 1;
            LocPlusPlus();
            break;
        case 2:
            if (CheckFull(MemLists))
                throw 2;
            LocPlusPlus();
            break;
        case 3:
            if (CompileStatus != 2)
                throw 'A';
            if (CheckFull(DSLists))
                throw 3;
            LocPlusPlus();
            break;
        case 4:
            if (CheckFull(MemLists))
                throw 2;
            LocPlusPlus();
            break;
        default:
            break;
        }
        return 0;
    }
    catch (int Exe)
    {
        switch (Exe)
        {
        case 1:
            //ReportWords("GCC Full!");
            break;
        case 3:
            //ReportWords("Data Segment Full!");
            break;
        case 2:
            //ReportWords("Memory Full!");
            break;
        default:
            break;
        }
        return -1;
    }
    catch (char Exe)
    {
        switch (Exe)
        {
        case 'A':
            //ReportWords("Compile not Complete!");
            break;
        case 'B':
            //ReportWords("Operation Invalid!");
            break;
        default:
            break;
        }
    }
    return 0;
}
int Code::HandPush(bool Selection[10])
{
    int select=0;
    for (int i = 0; i < 10; i++)
    {
        if (Selection[i])
        {
            select++;
        }
    }
    if (RunStatus != 0)
    {
        //ReportWords("Operation Invalid!");
        return 0;
    }
    if (!select) //ReportWords("No test data set!");
    {
        return 0;
    }
    Judge(Selection);
    RunStatus++;
    RemainRound=(select+rand()%3);
    return 0;
}
void Code::UserJudging(bool judge){
    UserJudge = judge;
    LocPlusPlus();
}
//Used to update Location to Lists.
int Code::LocPlusPlus()
{
    switch (Location)
    {
    case 0:
        mendontolist(CodeLists, this);
        mendontolist(AllProcess, this);
        break;
    case 1:
        deletefromlist(CodeLists, this);
        mendontolist(GCCLists, this);
        break;
        break;
    case 2:
        deletefromlist(GCCLists, this);
        mendontolist(MemLists, this);
        break;
        break;
    case 3:
        deletefromlist(MemLists, this);
        mendontolist(DSLists, this);
        break;
        break;
    case 4:
        deletefromlist(DSLists, this);
        mendontolist(MemLists, this);
        break;
    case 5:
        deletefromlist(MemLists, this);
        mendontolist(DecLists, this);
        break;
    case 6:
        deletefromlist(DecLists, this);
        break;
    default:
        break;
    }
    Location++;
    return 0;
}

void deletefromlist(Code *list[], Code *codeptr)
{
    int i = 0;
    int length = GetLength(list);
    for (; i < length; i++)
    {
        if (list[i] == codeptr)
            break;
    }
    for (; i < length-1; i++)
    {
        list[i] = list[i + 1];
    }
    list[length - 1] = nullptr;
}
void inline mendontolist(Code *List[], Code *cdptr)
{
    List[GetLast(List)] = cdptr;
    return;
}
bool CheckFull(Code *List[])
{
    int Length = GetLength(List);
    if (GetLast(List) != Length)
        return false;
    else
        return true;
}
int GetLast(Code *List[])
{
    for (int i = 0; i < GetLength(List); i++)
        if (List[i] == nullptr)
            return i;
    return GetLength(List);
}
int GetLength(Code *List[])
{
    Code **Listptr[6] = {CodeLists, GCCLists, DSLists, MemLists, DecLists, AllProcess};
    int ret[6] = {10, 4, 5, 3, 2, 100};
    for (int i = 0; i < 6; i++)
    {
        if (List == Listptr[i])
            return ret[i];
    }
    return 0;
}
int datasetclear()
{
    for (int i = 0; i < GetLength(AllProcess); i++)
    {
        //delete -- new
        if (AllProcess[i] == nullptr)
            break;
        delete AllProcess[i];
    }
    //clear codespace
    while (CodeLists[0] != nullptr)
        deletefromlist(CodeLists, CodeLists[GetLast(CodeLists) - 1]);
    while (GCCLists[0] != nullptr)
        deletefromlist(GCCLists, GCCLists[GetLast(GCCLists) - 1]);
    while (DecLists[0] != nullptr)
        deletefromlist(DecLists, DecLists[GetLast(DecLists) - 1]);
    while (DSLists[0] != nullptr)
        deletefromlist(DSLists, DSLists[GetLast(DSLists) - 1]);
    while (MemLists[0] != nullptr)
        deletefromlist(MemLists, MemLists[GetLast(MemLists) - 1]);
    while (AllProcess[0] != nullptr)
        deletefromlist(AllProcess, AllProcess[GetLast(AllProcess) - 1]);
    return 0;
}
