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

#include "wx/tglbtn.h"
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
#include "MIssionCommandPanel.h"
#include "MissionPanel.h"
#include "MultiMissionsPanel.h"
#include "GameRoundPanel.h"



GameRoundPanel::GameRoundPanel(wxPanel* pp, wxBoxSizer *topSizer, GameRound* gmround)
{
	_parentPanel = pp;
	_topsizer = topSizer;
	gameRound = gmround;

	wxString roundName = wxString::Format(wxT("%d-й раунд"), gameRound->GetRoundNumber());
	wxPanel *roundPanel = new wxPanel(_parentPanel, wxID_ANY);
	wxBoxSizer *roundTopSizer = new wxStaticBoxSizer(new wxStaticBox(_parentPanel, wxID_ANY, roundName), wxVERTICAL);
	_topsizer->Add(roundPanel, 1, wxGROW);
	wxPanel *infoPanel = new wxPanel(roundPanel, wxID_ANY);
	roundTopSizer->Add(infoPanel, wxSizerFlags().Align(wxALIGN_LEFT).Border(wxALL & ~wxBOTTOM, 5));
	wxBoxSizer *infoTopSizer = new wxBoxSizer(wxHORIZONTAL);
	infoTopSizer->Add(new wxStaticText(infoPanel, wxID_ANY, wxT("Результат")), wxSizerFlags().Align(wxALIGN_LEFT).Border(wxALL & ~wxBOTTOM, 5));
	infoTopSizer->Add(new wxStaticText(infoPanel, wxID_ANY, wxT("Размер команды")), wxSizerFlags().Align(wxALIGN_LEFT).Border(wxALL & ~wxBOTTOM, 5));
	infoPanel->SetSizer(infoTopSizer);
	infoTopSizer->SetSizeHints(this);

	MultiMissionsPanel(roundPanel, roundTopSizer, gameRound);

	roundPanel->SetSizer(roundTopSizer);
	roundTopSizer->SetSizeHints(this);

}


GameRoundPanel::~GameRoundPanel()
{
}
