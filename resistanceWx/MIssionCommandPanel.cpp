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
#include "MissionCommandPanel.h"



MissionCommandPanel::MissionCommandPanel(wxPanel* parentPanel, wxBoxSizer *missionSizer, MissionCommand* missionCommand)
{
	missionPanel = parentPanel;
	missionTopSizer = missionSizer;
	command = missionCommand;

	wxPanel *multiAgentsPanel = new wxPanel(missionPanel, wxID_ANY);
	//missionTopSizer->Add(multiAgentsPanel, wxSizerFlags().Center());
	missionTopSizer->Add(multiAgentsPanel, wxSizerFlags().Align(wxALIGN_LEFT).Border(wxALL & ~wxBOTTOM, 5));
	wxBoxSizer *multiAgentsSizer = new wxStaticBoxSizer(new wxStaticBox(multiAgentsPanel, wxID_ANY, wxT("Агенты в миссии")), wxHORIZONTAL);
	for (size_t k = 0; k < command->GetCommand().size(); k++)
	{
		Player plr = command->GetCommand()[k].GetAgent().GetPlayer();
		wxString plrName = plr.GetNickName().c_str();
		multiAgentsSizer->Add(new wxToggleButton(multiAgentsPanel, wxID_ANY, plrName), wxSizerFlags().Border(wxALL, 7));
	}
	multiAgentsPanel->SetSizer(multiAgentsSizer);
	multiAgentsSizer->SetSizeHints(this);

	//missionPanel->SetSizer(missionTopSizer);
	//missionTopSizer->SetSizeHints(this);

}


MissionCommandPanel::~MissionCommandPanel()
{
}
