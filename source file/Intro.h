#ifndef INTRO_H
#define INTRO_H

#include "gameApp.h"
//(*Headers(Intro)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/statbmp.h>
//*)

class Intro: public wxDialog
{
	public:
	    gameApp *Father;
	    bool elem=false;
		Intro(wxWindow* parent);
		Intro(wxWindow* parent,wxString alal,gameApp* Father,bool elem=false);
		virtual ~Intro();

		//(*Declarations(Intro)
		wxButton* Button1;
		wxStaticBitmap* StaticBitmap1;
		//*)

	protected:

		//(*Identifiers(Intro)
		static const long ID_STATICBITMAP1;
		static const long ID_BUTTON1;
		//*)

	private:

		//(*Handlers(Intro)
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
