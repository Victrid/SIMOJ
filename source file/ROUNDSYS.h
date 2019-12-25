#ifndef ROUNDSYS_H_INCLUDED
#define ROUNDSYS_H_INCLUDED

class Rounds{
public:
    Rounds(int totalRounds);
    int Total;
    int GetRound();
    bool Next();

private:
    int Round;
};

#endif // ROUNDSYS_H_INCLUDED
