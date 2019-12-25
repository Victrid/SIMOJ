#include "ROUNDSYS.h"
Rounds::Rounds(int total){
Total=total;
Round =0;
}
int Rounds::GetRound(){
    return Round;
}
bool Rounds::Next(){
    Round++;
    if(Round==Total)return false;
    else return true;
}
