#include "MailDiag.h"

//(*InternalHeaders(MailDiag)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(MailDiag)
const long MailDiag::ID_STATICTEXT1 = wxNewId();
const long MailDiag::ID_STATICTEXT2 = wxNewId();
const long MailDiag::ID_STATICTEXT3 = wxNewId();
const long MailDiag::ID_BUTTON1 = wxNewId();
const long MailDiag::ID_STATICLINE1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MailDiag, wxDialog)
//(*EventTable(MailDiag)
//*)
END_EVENT_TABLE()

MailDiag::MailDiag(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
{
    //(*Initialize(MailDiag)
    Create(parent, wxID_ANY, _("Mail"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(297,400));
    SetFocus();
    Composer = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxPoint(16,8), wxSize(264,22), 0, _T("ID_STATICTEXT1"));
    Content = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxPoint(16,48), wxSize(264,288), 0, _T("ID_STATICTEXT2"));
    Status = new wxStaticText(this, ID_STATICTEXT3, _("Label"), wxPoint(8,344), wxSize(272,16), 0, _T("ID_STATICTEXT3"));
    OK = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(8,368), wxSize(272,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(16,40), wxSize(264,1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MailDiag::OnOKClick);
    //*)
}

MailDiag::MailDiag(Mail *Mailis, wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size)
{

    Create(parent, id, _("Mail"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
        SetClientSize(wxSize(297,400));
    Move(wxDefaultPosition);
    Center();
    MailPtr = Mailis;
    Father = parent;

    wxString a;
    if (Mailis->Fail)
    {
        a = "You failed!";
    }
    else if (!Mailis->salary)
        a = "Continue...";
    else
    {
        a<< "Score ";
        if(Mailis->salary>0)a <<'+';
        a<< Mailis->salary;
    }

    Composer = new wxStaticText(this, ID_STATICTEXT1,("From: " + Mailis->Composer), wxPoint(16,16), wxSize(264,22), 0, _T("ID_STATICTEXT1"));
    Content = new wxStaticText(this, ID_STATICTEXT2, Mailis->Content, wxPoint(16,48), wxSize(264,288), 0, _T("ID_STATICTEXT2"));
    Status = new wxStaticText(this, ID_STATICTEXT3, a, wxPoint(8,344), wxSize(272,16), 0, _T("ID_STATICTEXT3"));
    OK = new wxButton(this, ID_BUTTON1, _("OK"), wxPoint(8,368), wxSize(272,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MailDiag::OnOKClick);

StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(16,40), wxSize(264,1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
}
MailDiag::~MailDiag()
{
    //(*Destroy(MailDiag)
    //*)
}

void MailDiag::OnOKClick(wxCommandEvent &event)
{
    ;
    if (MailPtr == nullptr || Father == nullptr)
    {
        Close(true);
        return;
    }
    if (MailPtr->Fail)
    {
        Close(true);
        Father->Close();
        /*this could be more beautiful, maybe I can write an End?*/
    }
    else
    {
        Close(true);
    }
    return;
}
