#ifndef MAIL_H
#define MAIL_H
#include "ScoreBoard.h"
#include <wx/string.h>
class Mail
{
public:
    /** Default constructor */
    Mail();
    Mail(int arg = 0);
    Mail(wxString comp, wxString);
    Mail(ScoreBoard* Scr);
    /** Default destructor */
    virtual ~Mail();
    wxString Composer;
    wxString Content;
    bool Fail;
    int salary;
};

#endif // MAIL_H
