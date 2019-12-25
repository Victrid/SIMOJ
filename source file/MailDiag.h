#ifndef MAILDIAG_H
#define MAILDIAG_H
#include "Mail.h"
//(*Headers(MailDiag)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/statline.h>
#include <wx/stattext.h>
//*)

class MailDiag: public wxDialog
{
	public:
	    Mail *MailPtr=nullptr;
	    wxWindow *Father = nullptr;
		MailDiag(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		MailDiag(Mail *Mailis,wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~MailDiag();

		//(*Declarations(MailDiag)
		wxButton* OK;
		wxStaticLine* StaticLine1;
		wxStaticText* Composer;
		wxStaticText* Content;
		wxStaticText* Status;
		//*)

	protected:

		//(*Identifiers(MailDiag)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_BUTTON1;
		static const long ID_STATICLINE1;
		//*)

	private:

		//(*Handlers(MailDiag)
		void OnOKClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
