/***************************************************************
 * Name:      gameMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    a ()
 * Created:   2019-12-08
 * Copyright: a ()
 * License:
 **************************************************************/
#include "gameMain.h"
#include <wx/msgdlg.h>
#include "Codesys.h"
#include "Roundsys.h"
#include "MailDiag.h"
//(*InternalHeaders(gameFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f,
    long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f)
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(gameFrame)
const long gameFrame::ID_STATICTEXT8 = wxNewId();
const long gameFrame::ID_LISTBOX1 = wxNewId();
const long gameFrame::ID_LISTBOX2 = wxNewId();
const long gameFrame::ID_LISTBOX3 = wxNewId();
const long gameFrame::ID_LISTBOX4 = wxNewId();
const long gameFrame::ID_BUTTON5 = wxNewId();
const long gameFrame::ID_BUTTON6 = wxNewId();
const long gameFrame::ID_STATICBOX1 = wxNewId();
const long gameFrame::ID_BUTTON7 = wxNewId();
const long gameFrame::ID_LISTBOX5 = wxNewId();
const long gameFrame::ID_CHECKBOX1 = wxNewId();
const long gameFrame::ID_CHECKBOX2 = wxNewId();
const long gameFrame::ID_CHECKBOX3 = wxNewId();
const long gameFrame::ID_CHECKBOX4 = wxNewId();
const long gameFrame::ID_CHECKBOX5 = wxNewId();
const long gameFrame::ID_CHECKBOX6 = wxNewId();
const long gameFrame::ID_CHECKBOX7 = wxNewId();
const long gameFrame::ID_CHECKBOX8 = wxNewId();
const long gameFrame::ID_CHECKBOX9 = wxNewId();
const long gameFrame::ID_CHECKBOX10 = wxNewId();
const long gameFrame::ID_GAUGE1 = wxNewId();
const long gameFrame::ID_BUTTON2 = wxNewId();
const long gameFrame::ID_STATICTEXT1 = wxNewId();
const long gameFrame::ID_BUTTON1 = wxNewId();
const long gameFrame::ID_BUTTON3 = wxNewId();
const long gameFrame::ID_BUTTON8 = wxNewId();
const long gameFrame::ID_STATICLINE1 = wxNewId();
const long gameFrame::ID_BUTTON9 = wxNewId();
const long gameFrame::ID_BUTTON10 = wxNewId();
const long gameFrame::ID_BUTTON11 = wxNewId();
const long gameFrame::ID_STATICTEXT3 = wxNewId();
const long gameFrame::ID_STATICTEXT4 = wxNewId();
const long gameFrame::ID_STATICTEXT2 = wxNewId();
const long gameFrame::ID_STATICTEXT5 = wxNewId();
const long gameFrame::ID_STATICTEXT6 = wxNewId();
const long gameFrame::ID_BUTTON12 = wxNewId();
const long gameFrame::ID_BUTTON4 = wxNewId();
const long gameFrame::ID_STATICTEXT9 = wxNewId();
const long gameFrame::ID_STATICTEXT10 = wxNewId();
const long gameFrame::ID_STATICLINE2 = wxNewId();
const long gameFrame::ID_STATICBITMAP1 = wxNewId();
const long gameFrame::ID_BUTTON13 = wxNewId();
const long gameFrame::ID_PANEL1 = wxNewId();
const long gameFrame::idMenuQuit = wxNewId();
const long gameFrame::idMenuAbout = wxNewId();
//*)

BEGIN_EVENT_TABLE(gameFrame, wxFrame)
//(*EventTable(gameFrame)
//*)
END_EVENT_TABLE()

gameFrame::gameFrame(wxWindow *parent, wxWindowID id)
{
    //(*Initialize(gameFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Game"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, _T("wxID_ANY"));
    SetClientSize(wxSize(750,419));
    SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUBAR));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(750,393), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    Panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    wxFont Panel1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Courier New"),wxFONTENCODING_DEFAULT);
    Panel1->SetFont(Panel1Font);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Powered by \nCopyright © 2011-2019                        . All rights reserved. \n0.0898 - render 0.0454 - instru 0.0108 - 2 queries - 0.0089 @ portal "), wxPoint(16,336), wxSize(384,51), 0, _T("ID_STATICTEXT8"));
    StaticText6->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont StaticText6Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("@Microsoft JhengHei UI"),wxFONTENCODING_DEFAULT);
    StaticText6->SetFont(StaticText6Font);
    Codelisti = new wxListBox(Panel1, ID_LISTBOX1, wxPoint(8,104), wxSize(120,176), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    Codelisti->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUHILIGHT));
    Codelisti->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    GCC = new wxListBox(Panel1, ID_LISTBOX2, wxPoint(136,104), wxSize(120,72), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX2"));
    GCC->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
    GCC->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    Memory = new wxListBox(Panel1, ID_LISTBOX3, wxPoint(304,104), wxSize(168,208), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX3"));
    Memory->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    Memory->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    DataSegment = new wxListBox(Panel1, ID_LISTBOX4, wxPoint(136,200), wxSize(120,112), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX4"));
    DataSegment->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    DataSegment->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    GuideIntoDataSegment = new wxButton(Panel1, ID_BUTTON5, _("<-"), wxPoint(264,200), wxSize(32,24), wxNO_BORDER, wxDefaultValidator, _T("ID_BUTTON5"));
    GuideIntoDataSegment->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GuideIntoDataSegment->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont GuideIntoDataSegmentFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Microsoft YaHei UI"),wxFONTENCODING_DEFAULT);
    GuideIntoDataSegment->SetFont(GuideIntoDataSegmentFont);
    GuideBack = new wxButton(Panel1, ID_BUTTON6, _("->"), wxPoint(264,232), wxSize(32,24), wxNO_BORDER, wxDefaultValidator, _T("ID_BUTTON6"));
    GuideBack->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GuideBack->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont GuideBackFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Microsoft YaHei UI"),wxFONTENCODING_DEFAULT);
    GuideBack->SetFont(GuideBackFont);
    TestData = new wxStaticBox(Panel1, ID_STATICBOX1, _("Test Data"), wxPoint(488,88), wxSize(192,144), 0, _T("ID_STATICBOX1"));
    TestData->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont TestDataFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TestData->SetFont(TestDataFont);
    StartTest = new wxButton(Panel1, ID_BUTTON7, _("Set Test Data"), wxPoint(496,240), wxSize(184,24), wxNO_BORDER, wxDefaultValidator, _T("ID_BUTTON7"));
    StartTest->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    StartTest->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont StartTestFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Malgun Gothic"),wxFONTENCODING_DEFAULT);
    StartTest->SetFont(StartTestFont);
    Result = new wxListBox(Panel1, ID_LISTBOX5, wxPoint(496,272), wxSize(184,48), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX5"));
    Result->SetForegroundColour(wxColour(117,172,255));
    Result->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    Data1 = new wxCheckBox(Panel1, ID_CHECKBOX1, wxEmptyString, wxPoint(496,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    Data1->SetValue(false);
    Data2 = new wxCheckBox(Panel1, ID_CHECKBOX2, wxEmptyString, wxPoint(520,112), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    Data2->SetValue(false);
    Data3 = new wxCheckBox(Panel1, ID_CHECKBOX3, wxEmptyString, wxPoint(496,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
    Data3->SetValue(false);
    Data4 = new wxCheckBox(Panel1, ID_CHECKBOX4, wxEmptyString, wxPoint(520,136), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX4"));
    Data4->SetValue(false);
    Data7 = new wxCheckBox(Panel1, ID_CHECKBOX5, wxEmptyString, wxPoint(496,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX5"));
    Data7->SetValue(false);
    Data8 = new wxCheckBox(Panel1, ID_CHECKBOX6, wxEmptyString, wxPoint(520,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX6"));
    Data8->SetValue(false);
    Data9 = new wxCheckBox(Panel1, ID_CHECKBOX7, wxEmptyString, wxPoint(496,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX7"));
    Data9->SetValue(false);
    Data10 = new wxCheckBox(Panel1, ID_CHECKBOX8, wxEmptyString, wxPoint(520,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX8"));
    Data10->SetValue(false);
    Data10->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    Data5 = new wxCheckBox(Panel1, ID_CHECKBOX9, wxEmptyString, wxPoint(496,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX9"));
    Data5->SetValue(false);
    Data6 = new wxCheckBox(Panel1, ID_CHECKBOX10, wxEmptyString, wxPoint(520,160), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX10"));
    Data6->SetValue(false);
    Time = new wxGauge(Panel1, ID_GAUGE1, 100, wxPoint(184,55), wxSize(360,24), 0, wxDefaultValidator, _T("ID_GAUGE1"));
    Time->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    Time->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    GuideIntoGCC = new wxButton(Panel1, ID_BUTTON2, _("----->"), wxPoint(8,288), wxSize(120,24), wxNO_BORDER, wxDefaultValidator, _T("ID_BUTTON2"));
    GuideIntoGCC->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GuideIntoGCC->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont GuideIntoGCCFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Microsoft YaHei UI"),wxFONTENCODING_DEFAULT);
    GuideIntoGCC->SetFont(GuideIntoGCCFont);
    Day = new wxStaticText(Panel1, ID_STATICTEXT1, _("day"), wxPoint(112,55), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    Day->SetForegroundColour(wxColour(0,0,0));
    wxFont DayFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Swis721 Blk BT"),wxFONTENCODING_DEFAULT);
    Day->SetFont(DayFont);
    NextButton = new wxButton(Panel1, ID_BUTTON1, _("Next Tick"), wxPoint(608,54), wxDefaultSize, wxNO_BORDER, wxDefaultValidator, _T("ID_BUTTON1"));
    NextButton->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    NextButton->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont NextButtonFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Malgun Gothic"),wxFONTENCODING_DEFAULT);
    NextButton->SetFont(NextButtonFont);
    Pass = new wxButton(Panel1, ID_BUTTON3, _("Pass"), wxPoint(496,328), wxSize(88,24), wxNO_BORDER, wxDefaultValidator, _T("ID_BUTTON3"));
    Pass->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Pass->SetBackgroundColour(wxColour(51,132,47));
    wxFont PassFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Malgun Gothic"),wxFONTENCODING_DEFAULT);
    Pass->SetFont(PassFont);
    Fail = new wxButton(Panel1, ID_BUTTON8, _("Fail"), wxPoint(592,328), wxSize(91,24), wxNO_BORDER, wxDefaultValidator, _T("ID_BUTTON8"));
    Fail->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Fail->SetBackgroundColour(wxColour(150,29,60));
    wxFont FailFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Malgun Gothic"),wxFONTENCODING_DEFAULT);
    Fail->SetFont(FailFont);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(544,112), wxSize(1,112), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    TDfull = new wxButton(Panel1, ID_BUTTON9, _("Full Test"), wxPoint(560,112), wxSize(104,24), 0, wxDefaultValidator, _T("ID_BUTTON9"));
    TDfull->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    TDfull->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont TDfullFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Malgun Gothic"),wxFONTENCODING_DEFAULT);
    TDfull->SetFont(TDfullFont);
    Tdhf = new wxButton(Panel1, ID_BUTTON10, _("Half Test"), wxPoint(560,136), wxSize(104,24), 0, wxDefaultValidator, _T("ID_BUTTON10"));
    Tdhf->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Tdhf->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont TdhfFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Malgun Gothic"),wxFONTENCODING_DEFAULT);
    Tdhf->SetFont(TdhfFont);
    TDmin = new wxButton(Panel1, ID_BUTTON11, _("Minimum Test"), wxPoint(560,160), wxSize(104,24), 0, wxDefaultValidator, _T("ID_BUTTON11"));
    TDmin->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    TDmin->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont TDminFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Malgun Gothic"),wxFONTENCODING_DEFAULT);
    TDmin->SetFont(TDminFont);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Compile Override Slot"), wxPoint(136,88), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont StaticText2Font(9,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Linker/Data Segment"), wxPoint(136,184), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont StaticText3Font(9,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Commited Code"), wxPoint(8,88), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont StaticText1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Computing Thread"), wxPoint(304,88), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    StaticText4->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont StaticText4Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    Scre = new wxStaticText(Panel1, ID_STATICTEXT6, _("Score:"), wxPoint(16,55), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    Scre->SetForegroundColour(wxColour(0,0,0));
    wxFont ScreFont(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Swis721 Blk BT"),wxFONTENCODING_DEFAULT);
    Scre->SetFont(ScreFont);
    TDCLR = new wxButton(Panel1, ID_BUTTON12, _("Clear All"), wxPoint(560,184), wxSize(104,24), 0, wxDefaultValidator, _T("ID_BUTTON12"));
    TDCLR->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    TDCLR->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont TDCLRFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Malgun Gothic"),wxFONTENCODING_DEFAULT);
    TDCLR->SetFont(TDCLRFont);
    Release = new wxButton(Panel1, ID_BUTTON4, _("->"), wxPoint(264,112), wxSize(32,24), wxNO_BORDER, wxDefaultValidator, _T("ID_BUTTON4"));
    Release->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Release->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont ReleaseFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("@Microsoft YaHei UI"),wxFONTENCODING_DEFAULT);
    Release->SetFont(ReleaseFont);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT9, _("PHP Technologies | Contributors"), wxPoint(90,336), wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    wxFont StaticText7Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("@Microsoft JhengHei UI"),wxFONTENCODING_DEFAULT);
    StaticText7->SetFont(StaticText7Font);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT10, _("ACM Class"), wxPoint(170,353), wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    StaticText8->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont StaticText8Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("@Microsoft JhengHei UI"),wxFONTENCODING_DEFAULT);
    StaticText8->SetFont(StaticText8Font);
    StaticLine2 = new wxStaticLine(Panel1, ID_STATICLINE2, wxPoint(8,330), wxSize(472,1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    StaticBitmap1 = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxBitmap(wxImage(_T(".\\INT3HOVERRIDE.sys")).Rescale(wxSize(768,40).GetWidth(),wxSize(768,40).GetHeight())), wxPoint(-16,0), wxSize(768,40), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    Button1 = new wxButton(Panel1, ID_BUTTON13, _("Quit"), wxPoint(696,360), wxSize(48,26), 0, wxDefaultValidator, _T("ID_BUTTON13"));
    Button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
    Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    wxFont Button1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    Center();

    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnGuideIntoDataSegmentClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnGuideBackClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnStartTestClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnGuideIntoGCCClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnNextButtonClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnPassClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnFailClick);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnTDfullClick);
    Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnTdhfClick);
    Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnTDminClick);
    Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnTDCLRClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnReleaseClick);
    Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gameFrame::OnQuit);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gameFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gameFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&gameFrame::OnClose);
    //*)
}

gameFrame::~gameFrame()
{
    //(*Destroy(gameFrame)
    //*)
}

void gameFrame::OnQuit(wxCommandEvent &event)
{
    datasetclear();
    this->Destroy();
    exit(0);
}

void gameFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = "OJ judge simulator\n";
    msg <<"2019 Y. CAO, W. JIANG, Y. LIU\n"
    <<"Licensed under the Apache License, Version 2.0\n"
    <<"\n"<<"Original UI Design by Xiao Jia and other contributors.\n\n"
    <<"Declarations above is an unofficial transcription of LICENSE file distributed with the file,"
    <<" and is invalid when contradicted with LICNESE.";
    wxMessageBox(msg, _("The Game Info"));
}

void gameFrame::OnClose(wxCloseEvent &event)
{
    datasetclear();
    this->Destroy();
    exit(0);
}

void ReportWords(string rep, string title)
{
    wxMessageBox((wxString)rep, _((wxString)title));
}

void gameFrame::Next()
{
    static bool Hajime = true; //firstrun indicator
    static bool init = false;  //initiated indicator

    static Mail *mlptr = nullptr;
    static MailDiag *mdptr = nullptr;
    static Rounds *roundptr = nullptr;
    static ScoreBoard *sbptr = nullptr;
    static int day = 0;
    static int Score = 0;
    //initiate with calculating effects.
    if (!init)
    {
        //send salary and firstrun mail
        if (Hajime)
        {
            mlptr = new Mail(1);
            mdptr = new MailDiag(mlptr, this);
            mdptr->Show();
            Score += 100;
        }
        else
        {
            if(mlptr!=nullptr)
                delete mlptr;
            mlptr=nullptr;
            if(mlptr!=nullptr)
                delete mdptr;
            mdptr=nullptr;

            sbptr->Score();
            Score +=(20+3*sbptr->Good-5*sbptr->CheckFail-sbptr->Total);
            if(Score>=0)
            {
                mlptr = new Mail(sbptr);
                mdptr = new MailDiag(mlptr,this);
                mdptr->Show();
            }
            else{
                mlptr = new Mail(0);
                mdptr = new MailDiag(mlptr,this);
                mdptr->Show();
            }

            delete roundptr;
            delete sbptr;
            roundptr = nullptr;
            sbptr = nullptr;
        }
        Hajime = false;
        //initiate the game
        sbptr = new ScoreBoard(day);
        roundptr = new Rounds(sbptr->Tick);

        wxString datedisp="Day ";
        datedisp<<(day+1);
        Day->SetLabel(datedisp);

        wxString scoredisp="Score: ";
        scoredisp<<Score;
        Scre->SetLabel(scoredisp);
        datasetclear();
        init = true;
    }
    ::AutoPush();
    //bribe
    if(roundptr->GetRound()==5&&sbptr->BribeEvent)
    {
        if(mlptr!=nullptr)
            delete mlptr;
        mlptr=nullptr;
        if(mlptr!=nullptr)
            delete mdptr;
        mdptr=nullptr;
        Code *brbptr = new Code(true,true,true);
        mlptr = new Mail(brbptr->CodeNum);
        mdptr = new MailDiag(mlptr,this);
        mdptr ->Show();
    }
    if (::Create())
        new Code;
    Time->SetValue(roundptr->GetRound());
    Time->SetRange(roundptr->Total);
    ShowAll();
    if (!roundptr->Next())
    {
        init = false;
        day++;
    }
}
void gameFrame::ShowAll()
{
    Codelisti->Clear();
    for (int i = 0; i < ::GetLast(::CodeLists); i++)
    {
        wxString str = "run ";
        str << CodeLists[i]->CodeNum;
        Codelisti->AppendAndEnsureVisible(str);
    }
    GCC->Clear();
    for (int i = 0; i < ::GetLast(::GCCLists); i++)
    {
        wxString str = "run ";
        str << GCCLists[i]->CodeNum;
        GCC->AppendAndEnsureVisible(str);
    }

    Memory->Clear();
    for (int i = 0; i < ::GetLast(::MemLists); i++)
    {
        wxString str = "run ";
        str << MemLists[i]->CodeNum;
        if (MemLists[i]->Location == 3)
        {
            str << "C.@";
            switch (MemLists[i]->CompileStatus)
            {
            case 0:
                str << "Loaded";
                break;
            case 1:
                str << "Compiling";
                break;
            case 2:
                str << "Complete";
                break;
            }
        }
        else if (MemLists[i]->Location == 5)
        {
            str << "R.@";
            switch (MemLists[i]->RunStatus)
            {
            case 0:
                str << "Pend.Para";
                break;
            case 1:
                str << "Loaded";
                break;
            case 2:
                str << "Running";
                break;
            case 3:
                str << "Complete";
                break;
            }
        }
        Memory->AppendAndEnsureVisible(str);
    }
    DataSegment->Clear();
    for (int i = 0; i < ::GetLast(::DSLists); i++)
    {
        wxString str = "run ";
        str << DSLists[i]->CodeNum;
        DataSegment->AppendAndEnsureVisible(str);
    }
    Result->Clear();
    for (int i = 0; i < ::GetLast(::DecLists); i++)
    {
        wxString str = "run ";
        str << DecLists[i]->CodeNum;
        str << ((DecLists[i]->Judgeresult) ? " Pass" : " Failed");
        Result->AppendAndEnsureVisible(str);
    }
    return;
}

void gameFrame::OnGuideIntoGCCClick(wxCommandEvent &event)
{
    if (Codelisti->GetSelection() == -1)
        return;
    CodeLists[Codelisti->GetSelection()]->HandPush();
    ShowAll();
    return;
}

void gameFrame::OnReleaseClick(wxCommandEvent &event)
{
    if (GCC->GetSelection() == -1)
        return;
    GCCLists[GCC->GetSelection()]->HandPush();
    ShowAll();
}

void gameFrame::OnGuideIntoDataSegmentClick(wxCommandEvent &event)
{
    if (Memory->GetSelection() == -1)
        return;
    if (MemLists[Memory->GetSelection()]->Location == 3)
    {
        MemLists[Memory->GetSelection()]->HandPush();
        ShowAll();
    }
    else
        ; //ReportWords("Operation Invalid");
    return;
}

void gameFrame::OnGuideBackClick(wxCommandEvent &event)
{
    if (DataSegment->GetSelection() == -1)
        return;
    DSLists[DataSegment->GetSelection()]->HandPush();
    ShowAll();
    return;
}

void gameFrame::OnStartTestClick(wxCommandEvent &event)
{
    ;
    if (Memory->GetSelection() == -1)
        return;
    if (MemLists[Memory->GetSelection()]->Location == 5)
    {
        MemLists[Memory->GetSelection()]->HandPush(GetSelected().st);
        ShowAll();
    }
    else
        ; //ReportWords("Operation Invalid");
    return;
}

Select gameFrame::GetSelected()
{
    Select ret;
    wxCheckBox *AllBox[10]= {Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10};
    for(int i=0; i<10; i++)
    {
        ret.st[i]=AllBox[i]->GetValue();
        AllBox[i]->SetValue(false);
    }
    return ret;
}

void gameFrame::OnPassClick(wxCommandEvent& event)
{
    if (Result->GetSelection() == -1)
        return;
    DecLists[Result->GetSelection()]->UserJudging(true);
    ShowAll();
    return;
}

void gameFrame::OnFailClick(wxCommandEvent& event)
{
    if (Result->GetSelection() == -1)
        return;
    DecLists[Result->GetSelection()]->UserJudging(false);
    ShowAll();
    return;
}

void gameFrame::OnNextButtonClick(wxCommandEvent& event)
{
    Next();
}

void gameFrame::OnTDfullClick(wxCommandEvent& event)
{
    wxCheckBox *AllBox[10]= {Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10};
    for(int i=0; i<10; i++)
    {
        AllBox[i]->SetValue(true);
    }
    return;
}

void gameFrame::OnTdhfClick(wxCommandEvent& event)
{
    wxCheckBox *AllBox[10]= {Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10};
    for(int i=0; i<10; i++)
    {
        if(!(i%2))
            AllBox[i]->SetValue(true);
        else
            AllBox[i]->SetValue(false);
    }
    return;
}

void gameFrame::OnTDminClick(wxCommandEvent& event)
{
    wxCheckBox *AllBox[10]= {Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10};
    for(int i=0; i<10; i++)
    {
        AllBox[i]->SetValue(false);
    }
    AllBox[rand()%10]->SetValue(true);
    AllBox[rand()%10]->SetValue(true);
    AllBox[rand()%10]->SetValue(true);
    return;
}

void gameFrame::OnTDCLRClick(wxCommandEvent& event)
{
        wxCheckBox *AllBox[10]= {Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10};
    for(int i=0; i<10; i++)
    {
        AllBox[i]->SetValue(false);
    }
    return;
}
