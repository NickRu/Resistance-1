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



MultiMissionsPanel::MultiMissionsPanel(wxPanel* rPanel, wxBoxSizer *roundTopSizer, GameRound* gRound)
{
	roundPanel = rPanel;
	roundSizer = roundTopSizer;
	round = gRound;

	wxPanel *missionsPanel = new wxPanel(roundPanel, wxID_ANY);
	roundSizer->Add(missionsPanel, 1, wxGROW);
	wxString missionName = wxString::Format(wxT("%d-я миссия"), round->GetCurrentPropMission()->GetMissionNumber());

	wxBoxSizer *missionTopSizer = new wxStaticBoxSizer(new wxStaticBox(missionsPanel, wxID_ANY, missionName), wxVERTICAL);
	//wxNotebook *multiMissionsNotebook = new wxNotebook(missionsPanel, wxID_ANY);
	//missionsSizer->Add(multiMissionsNotebook, 1, wxEXPAND);


	MissionPanel(missionsPanel, missionTopSizer, round->GetCurrentPropMission());

	//for (size_t j = 0; j < round->GetPropMission().size(); j++)
	//{
	//	MissionPanel(multiMissionsNotebook, round->GetPropMission()[j]);
	//}

	missionsPanel->SetSizer(missionTopSizer);
	missionTopSizer->SetSizeHints(this);


	//roundPanel->SetSizer(roundSizer);
	//roundSizer->SetSizeHints(this);

}


MultiMissionsPanel::~MultiMissionsPanel()
{
}
