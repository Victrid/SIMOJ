#include "Mail.h"

Mail::Mail(int arg)
{
    //arglist
    //1        0    default
    //init     fail bribe
    switch (arg)
    {
    case 0:
        Composer = "Aurumis Calculae, SJTU Accountant";
        Content = "  We are sorry to inform you that our employment relationship has terminated because of your performances in some cases.\n";
        Content << "CONCRETE REASON: The balance now is negative. Our work center consider this action as a refusal to work.";
    case 1:
        Composer = "Iustus Dominus, OJ Admin";
        Content = "  We've accepted your application \
for Online Judge. You've now a temporary\
 judge.\n\
  You have certain time, or \'ticks\', Every running procedure \
will cost you ticks. You run into next tick by clicking \'next\'\
 button. We'll calculate your salary by your work count.\n\
  Remember to behave yourself as a \
JUDGE. we'll arrange you some work to do, \
and we're also checking it randomly.";
Content << "\nYou can get a brief license and copyright information by pressing F1 in the mainframe.";
        Fail = false;
        salary = 100;
        break;
    default:
        int selection = rand() % 6;
        switch (selection)
        {
        case 0:
            Composer = "\"||true Principlis II F***nis";
            Content = "  I\'m one of your students, who master cpp very well. ";
            Content << "Unfortunately, My runcode " << arg << " I handed this time may fail. "
                    << "But if you help me to pass this exam, I will get you a backdoor F***n postgraduate, "
                    << "and you will be able to study aboard in our cooperative university.\n"
                    << " I think you should think it over and seize the opportunity. "
                    << "I DO REALLY get some BACKDOOR wink wink";
            Fail = false;
            break;
        case 1:
            Composer = "Sergei Rabinovich Ivanov";
            Content = "The strenuous mathematic analytic exam have really stretched me.";
            Content << " Staying up for several days drives me to the edge of collapse. "
                    << "I am afraid that I may fail to write a correct code before the deadline. "
                    << "But I upload my code anyway.(run " << arg << ") Please show me some sympathy and let me pass.";
            Fail = false;
            break;
        case 2:
            Composer = "Bj**** Str**st*p";
            Content = "  It\'s totally a waste of time for me to write such simple codes.\n";
            Content << "  Real programmers should spend their time doing more interesting things."
                    << " For example, developing a language by adding some object oriented features."
                    << "Life is but a span,so subtraction is necessary. Just let me pass and you won\'t regret. "
                    << "\nMy Code: " << arg;
            Fail = false;
            break;
        case 3:
            Composer = "J*m*s G*sl*ng";
            Content = " Why you guys using such anti-human language\? I suggest Java, it fits me so well as is my right hand.";
            Content << " so I write some codes in Java and realized a Java interpret by C++ in my submit. \n"
                    << " With my excelsior tech, it's faster than C++ itself. But due to my over-excellent skill, "
                    << "it sometimes goes wrong if not running on a 4-digit microprocessor. So help me pass, and I\'ll get you some coffee."
                    << "\nMy Code: " << arg;
            Fail = false;
            break;
        case 4:
            Composer = "R*ym*nd B*bb*tt";
            Content = " I used to love rainy days because of the romantic atmosphere they create. ";
            Content << "However, I have changed my mind recently. The heavy rain didn\'t bring me any relaxion or pleasure, "
                    << "but brought me a heavy cold which have assailed me for several days. I can\'t even focus on my homework."
                    << " Consequently, it is almost impossible for me to finish the codes. I have no choice but to beg you to let me pass."
                    << "\nMy Code: " << arg;
            Fail = false;
            break;
        case 5:
            Composer = "S*n*c the Hedgehog";
            Content = " ARE YOU CURIOUS ABOUT WHAT BONUS YOU WILL GET IF YOU LET ME PASS?\nWHT NOT HAVE A TRY?\nLET ME PASS!";
                      Content << "\nMy Code: " << arg;
            Fail = false;
            break;
        default:
            break;
        }
        break;
    }
}
Mail::Mail(ScoreBoard *Scr)
{
    if (!Scr->Fail)
    {
        Composer = "Aurumis Calculae, SJTU Accountant";
        Content = "  GREETINGS FROM FINANCIAL OFFICER";
        Content << '\n'
                << "You've got " << Scr->Total << " Work distributed, and you've got ";
        Content << Scr->Good << " accepted.\n";
        if (Scr->CheckFail)
        {
            Content << "  We've discovered that you have " << Scr->CheckFail << " failed our manual check.";
            Content << " You can add checking datasets to avoid making mistakes.";
        }
        Fail = false;
        salary = 20 + 3 * Scr->Good - 5 * Scr->CheckFail - Scr->Total;
    }
    else
    {
        Composer = "Iustus Dominus, OJ Admin";
        Content = "  We are sorry to inform you that you are expelled from school because of your performances in some cases.\n";
        Content << "  CONCRETE REASON: Injustice and academic freud is strictly forbidden in our school.";
        Fail = true;
        salary = 0;
    }
}
Mail::~Mail()
{
    //dtor
}
