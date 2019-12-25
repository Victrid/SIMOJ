#include "Intro.h"

//(*InternalHeaders(Intro)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Intro)
const long Intro::ID_STATICBITMAP1 = wxNewId();
const long Intro::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Intro,wxDialog)
    //(*EventTable(Intro)
    //*)
END_EVENT_TABLE()

Intro::Intro(wxWindow* parent)
{
    //(*Initialize(Intro)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(688,298));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(_T(".\\DISIA.bmp")).Rescale(wxSize(671,249).GetWidth(),wxSize(671,249).GetHeight())), wxPoint(8,8), wxSize(671,249), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Continue"), wxPoint(304,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Intro::OnButton1Click);
    //*)
}

Intro::Intro(wxWindow* parent,wxString alal,gameApp *Fatherptr,bool ele)
{
    elem = ele;
    Father = Fatherptr;
    //(*Initialize(Intro)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxNO_BORDER, _T("wxID_ANY"));
    SetClientSize(wxSize(688,298));
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxBitmap(wxImage(alal).Rescale(wxSize(671,249).GetWidth(),wxSize(671,249).GetHeight())), wxPoint(8,8), wxSize(671,249), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Continue"), wxPoint(304,264), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Intro::OnButton1Click);
    Center();
    //*)
}
Intro::~Intro()
{

    //(*Destroy(Intro)
    //*)
}


void Intro::OnButton1Click(wxCommandEvent& event)
{
    if(!elem)
    {
        Intro *Int2=new Intro(0,".\\DLLMGMT.SYS",Father,true);
        Int2->Show();
        Close();
    }
    else
    {
        Close();
        Father->stdinit();
    }
}
