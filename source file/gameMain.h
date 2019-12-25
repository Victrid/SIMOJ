/***************************************************************
 * Name:      gameMain.h
 * Purpose:   Defines Application Frame
 * Author:    a ()
 * Created:   2019-12-08
 * Copyright: a ()
 * License:
 **************************************************************/

#ifndef GAMEMAIN_H
#define GAMEMAIN_H
#include "ScoreBoard.h"
#include "MailDiag.h"

//(*Headers(gameFrame)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/listbox.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statbmp.h>
#include <wx/statbox.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)
using std::string;
struct Select
{
    bool st[10];
};
class gameFrame: public wxFrame
{
    friend class Code;
    friend class gameApp;
public:
    gameFrame(wxWindow* parent,wxWindowID id = -1);
    void ShowAll();
    Select GetSelected();
    virtual ~gameFrame();
private:
    //(*Handlers(gameFrame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);
    void OnPanel1Paint(wxPaintEvent& event);
    void Next();
    void OnGuideIntoGCCClick(wxCommandEvent& event);
    void OnReleaseClick(wxCommandEvent& event);
    void OnGuideIntoDataSegmentClick(wxCommandEvent& event);
    void OnGuideBackClick(wxCommandEvent& event);
    void OnStartTestClick(wxCommandEvent& event);
    void OnPassClick(wxCommandEvent& event);
    void OnFailClick(wxCommandEvent& event);
    void OnNextButtonClick(wxCommandEvent& event);
    void OnTDfullClick(wxCommandEvent& event);
    void OnTdhfClick(wxCommandEvent& event);
    void OnTDminClick(wxCommandEvent& event);
    void OnData6Click(wxCommandEvent& event);
    void OnTDCLRClick(wxCommandEvent& event);
    //*)

    //(*Identifiers(gameFrame)
    static const long ID_STATICTEXT8;
    static const long ID_LISTBOX1;
    static const long ID_LISTBOX2;
    static const long ID_LISTBOX3;
    static const long ID_LISTBOX4;
    static const long ID_BUTTON5;
    static const long ID_BUTTON6;
    static const long ID_STATICBOX1;
    static const long ID_BUTTON7;
    static const long ID_LISTBOX5;
    static const long ID_CHECKBOX1;
    static const long ID_CHECKBOX2;
    static const long ID_CHECKBOX3;
    static const long ID_CHECKBOX4;
    static const long ID_CHECKBOX5;
    static const long ID_CHECKBOX6;
    static const long ID_CHECKBOX7;
    static const long ID_CHECKBOX8;
    static const long ID_CHECKBOX9;
    static const long ID_CHECKBOX10;
    static const long ID_GAUGE1;
    static const long ID_BUTTON2;
    static const long ID_STATICTEXT1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON3;
    static const long ID_BUTTON8;
    static const long ID_STATICLINE1;
    static const long ID_BUTTON9;
    static const long ID_BUTTON10;
    static const long ID_BUTTON11;
    static const long ID_STATICTEXT3;
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT5;
    static const long ID_STATICTEXT6;
    static const long ID_BUTTON12;
    static const long ID_BUTTON4;
    static const long ID_STATICTEXT9;
    static const long ID_STATICTEXT10;
    static const long ID_STATICLINE2;
    static const long ID_STATICBITMAP1;
    static const long ID_BUTTON13;
    static const long ID_PANEL1;
    static const long idMenuQuit;
    static const long idMenuAbout;
    //*)

    //(*Declarations(gameFrame)
    wxButton* Button1;
    wxButton* Fail;
    wxButton* GuideBack;
    wxButton* GuideIntoDataSegment;
    wxButton* GuideIntoGCC;
    wxButton* NextButton;
    wxButton* Pass;
    wxButton* Release;
    wxButton* StartTest;
    wxButton* TDCLR;
    wxButton* TDfull;
    wxButton* TDmin;
    wxButton* Tdhf;
    wxCheckBox* Data10;
    wxCheckBox* Data1;
    wxCheckBox* Data2;
    wxCheckBox* Data3;
    wxCheckBox* Data4;
    wxCheckBox* Data5;
    wxCheckBox* Data6;
    wxCheckBox* Data7;
    wxCheckBox* Data8;
    wxCheckBox* Data9;
    wxGauge* Time;
    wxListBox* Codelisti;
    wxListBox* DataSegment;
    wxListBox* GCC;
    wxListBox* Memory;
    wxListBox* Result;
    wxPanel* Panel1;
    wxStaticBitmap* StaticBitmap1;
    wxStaticBox* TestData;
    wxStaticLine* StaticLine1;
    wxStaticLine* StaticLine2;
    wxStaticText* Day;
    wxStaticText* Scre;
    wxStaticText* StaticText1;
    wxStaticText* StaticText2;
    wxStaticText* StaticText3;
    wxStaticText* StaticText4;
    wxStaticText* StaticText6;
    wxStaticText* StaticText7;
    wxStaticText* StaticText8;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // GAMEMAIN_H
