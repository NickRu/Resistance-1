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


MissionPanel::MissionPanel(wxPanel* missionPanel, wxBoxSizer *missionTopSizer, Mission* miss)
{
	//multiMissionNote = multiMissNote;
	mission = miss;

	//// Панель для миссии
	//wxString missionName = wxString::Format(wxT("%d-я миссия"), mission->GetMissionNumber());
	//wxPanel *missionPanel = new wxPanel(multiMissionNote, wxID_ANY);
	//multiMissionNote->AddPage(missionPanel, missionName);
	//wxBoxSizer *missionTopSizer = new wxBoxSizer(wxVERTICAL);

	wxPanel *missionInfoPanel = new wxPanel(missionPanel, wxID_ANY);
	missionTopSizer->Add(missionInfoPanel, wxSizerFlags().Align(wxALIGN_LEFT).Border(wxALL & ~wxBOTTOM, 5));
	wxBoxSizer *missionInfoTopSizer = new wxBoxSizer(wxHORIZONTAL);
	missionInfoTopSizer->Add(new wxStaticText(missionInfoPanel, wxID_ANY, wxT("Результат")),
		wxSizerFlags().Align(wxALIGN_LEFT).Border(wxALL & ~wxBOTTOM, 5));
	missionInfoTopSizer->Add(new wxStaticText(missionInfoPanel, wxID_ANY, wxT("Лидер команды")),
		wxSizerFlags().Align(wxALIGN_LEFT).Border(wxALL & ~wxBOTTOM, 5));
	missionInfoPanel->SetSizer(missionInfoTopSizer);
	missionInfoTopSizer->SetSizeHints(this);

	MissionCommandPanel(missionPanel, missionTopSizer, mission->GetMissionCommand());

	// Панель для голосования
	wxPanel *votesPanel = new wxPanel(missionPanel, wxID_ANY);
	//missionTopSizer->Add(votesPanel, wxSizerFlags().Center());
	missionTopSizer->Add(votesPanel, 1, wxGROW);
	wxBoxSizer *votesSizer = new wxStaticBoxSizer(new wxStaticBox(votesPanel, wxID_ANY, wxT("Голосование")), wxHORIZONTAL);

	// Панель для создания
	wxPanel *votesForCreationPanel = new wxPanel(votesPanel, wxID_ANY);
	votesSizer->Add(votesForCreationPanel, 1, wxGROW);
	wxBoxSizer *votesForCreationSizer = new wxStaticBoxSizer(new wxStaticBox(votesForCreationPanel, wxID_ANY, wxT("Создание")), wxVERTICAL);


	wxPanel *votesForCreationResultPanel = new wxPanel(votesForCreationPanel, wxID_ANY);
	votesForCreationSizer->Add(votesForCreationResultPanel, wxSizerFlags().Align(wxALIGN_LEFT).Border(wxALL & ~wxBOTTOM, 5));
	wxBoxSizer *votesForCreationResultSizer = new wxStaticBoxSizer(new wxStaticBox(votesForCreationResultPanel, wxID_ANY, wxT("Итоги голосования")), wxHORIZONTAL);
	voteForCrText = new wxStaticText(votesForCreationResultPanel, wxID_ANY, wxT("0"), wxPoint(0, 0), wxSize(40, wxDefaultCoord));
	voteAgainstCrText = new wxStaticText(votesForCreationResultPanel, wxID_ANY, wxT("0"), wxPoint(0, 0), wxSize(40, wxDefaultCoord));
	votesForCreationResultSizer->Add(voteForCrText, wxSizerFlags().Border(wxALL, 7));
	votesForCreationResultSizer->Add(voteAgainstCrText, wxSizerFlags().Border(wxALL, 7));
	votesForCreationResultPanel->SetSizer(votesForCreationResultSizer);
	votesForCreationResultSizer->SetSizeHints(this);

	wxPanel *votesForCreationButtonPanel = new wxPanel(votesForCreationPanel, wxID_ANY);
	votesForCreationSizer->Add(votesForCreationButtonPanel, wxSizerFlags().Align(wxALIGN_LEFT).Border(wxALL & ~wxBOTTOM, 5));
	wxBoxSizer *votesForCreationButtonSizer = new wxStaticBoxSizer(new wxStaticBox(votesForCreationButtonPanel, wxID_ANY, wxT("Выберите ЗА или ПРОТИВ")), wxHORIZONTAL);
	votesForCreationButtonSizer->Add(new wxToggleButton(votesForCreationButtonPanel, ID_CR_FOR, wxT("ЗА")), wxSizerFlags().Border(wxALL, 7));
	votesForCreationButtonSizer->Add(new wxToggleButton(votesForCreationButtonPanel, ID_CR_AGAIN, wxT("ПРОТИВ")), wxSizerFlags().Border(wxALL, 7));
	Connect(ID_CR_FOR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MissionPanel::OnCrFor));
	Connect(ID_CR_AGAIN, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MissionPanel::OnCrAgn));


	votesForCreationButtonPanel->SetSizer(votesForCreationButtonSizer);
	votesForCreationButtonSizer->SetSizeHints(this);

	//Сайзер для панели для создания
	votesForCreationPanel->SetSizer(votesForCreationSizer);
	votesForCreationSizer->SetSizeHints(this);


	// Панель для выполнения
	wxPanel *votesForExecutionPanel = new wxPanel(votesPanel, wxID_ANY);
	votesSizer->Add(votesForExecutionPanel, 1, wxGROW);
	wxBoxSizer *votesForExecutionSizer = new wxStaticBoxSizer(new wxStaticBox(votesForExecutionPanel, wxID_ANY, wxT("Выполнение")), wxVERTICAL);


	wxPanel *votesForExecutionResultPanel = new wxPanel(votesForExecutionPanel, wxID_ANY);
	votesForExecutionSizer->Add(votesForExecutionResultPanel, wxSizerFlags().Align(wxALIGN_LEFT).Border(wxALL & ~wxBOTTOM, 5));
	wxBoxSizer *votesForExecutionResultSizer = new wxStaticBoxSizer(new wxStaticBox(votesForExecutionResultPanel, wxID_ANY, wxT("Итоги голосования")), wxHORIZONTAL);
	voteForExecText = new wxStaticText(votesForExecutionResultPanel, wxID_ANY, wxT("0"), wxPoint(0, 0), wxSize(40, wxDefaultCoord));
	voteAgainstExecText = new wxStaticText(votesForExecutionResultPanel, wxID_ANY, wxT("0"), wxPoint(0, 0), wxSize(40, wxDefaultCoord));
	votesForExecutionResultSizer->Add(voteForExecText, wxSizerFlags().Border(wxALL, 7));
	votesForExecutionResultSizer->Add(voteAgainstExecText, wxSizerFlags().Border(wxALL, 7));
	votesForExecutionResultPanel->SetSizer(votesForExecutionResultSizer);
	votesForExecutionResultSizer->SetSizeHints(this);



	wxPanel *votesForExecutionButtonPanel = new wxPanel(votesForExecutionPanel, wxID_ANY);
	votesForExecutionSizer->Add(votesForExecutionButtonPanel, wxSizerFlags().Align(wxALIGN_LEFT).Border(wxALL & ~wxBOTTOM, 5));
	wxBoxSizer *votesForExecutionButtonSizer = new wxStaticBoxSizer(new wxStaticBox(votesForExecutionButtonPanel, wxID_ANY, wxT("Выберите ЗА или ПРОТИВ")), wxHORIZONTAL);
	votesForExecutionButtonSizer->Add(new wxToggleButton(votesForExecutionButtonPanel, ID_EX_FOR, wxT("ЗА")), wxSizerFlags().Border(wxALL, 7));
	votesForExecutionButtonSizer->Add(new wxToggleButton(votesForExecutionButtonPanel, ID_EX_AGAIN, wxT("ПРОТИВ")), wxSizerFlags().Border(wxALL, 7));
	Connect(ID_EX_FOR, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MissionPanel::OnExFor));
	Connect(ID_EX_AGAIN, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MissionPanel::OnExAgn));

	votesForExecutionButtonPanel->SetSizer(votesForExecutionButtonSizer);
	votesForExecutionButtonSizer->SetSizeHints(this);

	//Сайзер для панели для выполнения
	votesForExecutionPanel->SetSizer(votesForExecutionSizer);
	votesForExecutionSizer->SetSizeHints(this);

	//Сайзер для панели для голосования
	votesPanel->SetSizer(votesSizer);
	votesSizer->SetSizeHints(this);

	////Сайзер для панели миссии
	//missionPanel->SetSizer(missionTopSizer);
	//missionTopSizer->SetSizeHints(this);

}


MissionPanel::~MissionPanel()
{
}

void MissionPanel::OnCrFor(wxCommandEvent& WXUNUSED(event))
{
	mission->CreationVote(true, nullptr);
}

void MissionPanel::OnCrAgn(wxCommandEvent& WXUNUSED(event))
{
	mission->CreationVote(false, nullptr);

}

void MissionPanel::OnExFor(wxCommandEvent& WXUNUSED(event))
{
	mission->ExecutionVote(true, nullptr);

}

void MissionPanel::OnExAgn(wxCommandEvent& WXUNUSED(event))
{
	mission->ExecutionVote(false, nullptr);

}
