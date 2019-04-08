// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/string.h"
#include "wx/sizer.h"
#include "wx/gbsizer.h"
#include "wx/statline.h"
#include "wx/notebook.h"
#include "wx/spinctrl.h"
#include "wx/wrapsizer.h"
#include "wx/generic/stattextg.h"

#include "resistanceWx.h"
#include "Game.h"
#include "GameAgents.h"
#include "GameRound.h"
#include "Mission.h"
#include "MissionCommand.h"
#include "AgentInMission.h"
#include "AgentVoteFor.h"
#include "Player.h"
#include "MissionCommandPanel.h"
#include "MissionPanel.h"
#include "MultiMissionsPanel.h"
#include "GameRoundPanel.h"
#include "MyNewPlayerDialog.h"

#ifndef wxHAS_IMAGES_IN_RESOURCES
#include "../sample.xpm"
#endif



// ----------------------------------------------------------------------------
// MyNewPlayerDialog
// ----------------------------------------------------------------------------

MyNewPlayerDialog::MyNewPlayerDialog(wxWindow *parent, const wxString &title) : wxDialog(parent, wxID_ANY, wxString(title))
{

	MyFrame* myFr = (MyFrame*)parent;
	if (!myFr->GetGame()->CanRegistryAgents())
	{
		wxMessageBox(wxT("Игроков слишком много!"));
		return;
	}

	size_t num = myFr->GetGame()->GetGameAgents()->GetAgents().size();

	wxFlexGridSizer* playerInfoSizer = new wxFlexGridSizer(2);

	playerInfoSizer->Add(new wxStaticText(this, wxID_ANY, _("&Имя:")), 0, wxALL | wxALIGN_RIGHT, 5);
	m_firstNameTxt = new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("Name %d"), (num + 1)));
	playerInfoSizer->Add(m_firstNameTxt, 0, wxALL, 5);

	playerInfoSizer->Add(new wxStaticText(this, wxID_ANY, _("&Фамилия:")), 0, wxALL | wxALIGN_RIGHT, 5);
	m_secondNameTxt = new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("Fame %d"), (num + 1)));
	playerInfoSizer->Add(m_secondNameTxt, 0, wxALL, 5);

	playerInfoSizer->Add(new wxStaticText(this, wxID_ANY, _("&Ник:")), 0, wxALL | wxALIGN_RIGHT, 5);
	m_nickNameTxt = new wxTextCtrl(this, wxID_ANY, wxString::Format(wxT("Код_имя %d"), (num + 1)));
	playerInfoSizer->Add(m_nickNameTxt, 0, wxALL, 5);

	playerInfoSizer->Add(new wxStaticText(this, wxID_ANY, _("&Рейтинг:")), 0, wxALL | wxALIGN_RIGHT, 5);
	m_spinsRating = new wxSpinCtrl(this, wxID_ANY, wxString::Format(wxT("%d"), (num * 100)));
	playerInfoSizer->Add(m_spinsRating, 0, wxALL, 5);

	playerInfoSizer->Add(new wxStaticText(this, wxID_ANY, _("&Возраст:")), 0, wxALL | wxALIGN_RIGHT, 5);
	m_spinsAge = new wxSpinCtrl(this, wxID_ANY, wxString::Format(wxT("%d"), (num * 5)));
	playerInfoSizer->Add(m_spinsAge, 0, wxALL, 5);

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	mainSizer->Add(playerInfoSizer, 0, wxALL, 5);
	mainSizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxALL, 5);

	SetSizerAndFit(mainSizer);
	Centre();
}

wxString MyNewPlayerDialog::GetFirstName() const
{
	return m_firstNameTxt->GetValue();
};
void MyNewPlayerDialog::SetFirstName(const wxString& firstName)
{
	m_firstNameTxt->SetValue(firstName);
}

wxString MyNewPlayerDialog::GetSecondName() const
{
	return m_secondNameTxt->GetValue();
};
void MyNewPlayerDialog::SetSecondName(const wxString& secondName)
{
	m_secondNameTxt->SetValue(secondName);
}

wxString MyNewPlayerDialog::GetNickName() const
{
	return m_nickNameTxt->GetValue();
};
void MyNewPlayerDialog::SetNickName(const wxString& secondName)
{
	m_nickNameTxt->SetValue(secondName);
}

int MyNewPlayerDialog::GetRating() const
{
	return m_spinsRating->GetValue();
};
void MyNewPlayerDialog::SetRating(int vl)
{
	m_spinsRating->SetValue(vl);
}

int MyNewPlayerDialog::GetAge() const
{
	return m_spinsAge->GetValue();
};
void MyNewPlayerDialog::SetAge(int vl)
{
	m_spinsAge->SetValue(vl);
}
