#pragma once
class MyNewPlayerDialog : public wxDialog
{
public:
	MyNewPlayerDialog(wxWindow *parent, const wxString &title);
	wxString GetFirstName() const;
	void SetFirstName(const wxString& user);
	wxString GetSecondName() const;
	void SetSecondName(const wxString& user);
	wxString GetNickName() const;
	void SetNickName(const wxString& secondName);
	int GetRating() const;
	void SetRating(int vl);
	int GetAge() const;
	void SetAge(int vl);
private:
	wxPanel*            m_panel;
	wxTextCtrl*         m_firstNameTxt;
	wxTextCtrl*         m_secondNameTxt;
	wxTextCtrl*         m_nickNameTxt;
	wxSpinCtrl*			m_spinsRating;
	wxSpinCtrl*			m_spinsAge;
};
