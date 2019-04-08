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
// MyApp
// ----------------------------------------------------------------------------

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{

  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  if ( !wxApp::OnInit() )
      return false;

  // Create the main frame window
  MyFrame *frame = new MyFrame;

  frame->Show(true);

  return true;
}

// ----------------------------------------------------------------------------
// MyFrame
// ----------------------------------------------------------------------------

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
  EVT_MENU(resistanceWx_ABOUT, MyFrame::OnAbout)
  EVT_MENU(resistanceWx_QUIT, MyFrame::OnQuit)

  EVT_MENU(resistanceWx_CREATE_PLAYER, MyFrame::NewPlayer)
  EVT_MENU(resistanceWx_START_BTN, MyFrame::OnStartBtn)

wxEND_EVENT_TABLE()

// Define my frame constructor
MyFrame::MyFrame()
       : wxFrame(NULL, wxID_ANY, wxT("���� �������������"))
{

	gm = new Game();

    SetIcon(wxICON(sample));

    // Make a menubar
    wxMenu *file_menu = new wxMenu;

    file_menu->Append(resistanceWx_CREATE_PLAYER, wxT("&�������� ������...\tF3"));
    file_menu->Append(resistanceWx_START_BTN, wxT("&��������� ����...\tF4"));

    file_menu->AppendSeparator();
    file_menu->Append(resistanceWx_QUIT, wxT("&�����"), wxT("����� �� ����"));

    wxMenu *help_menu = new wxMenu;
    help_menu->Append(resistanceWx_ABOUT, wxT("&� ��������"), wxT("�� ���� �������������"));

    wxMenuBar *menu_bar = new wxMenuBar;

    menu_bar->Append(file_menu, wxT("&�����������"));
    menu_bar->Append(help_menu, wxT("&������"));

    // Associate the menu bar with the frame
    SetMenuBar(menu_bar);

#if wxUSE_STATUSBAR
    CreateStatusBar(2);
    SetStatusText(wxT("��������� � ����"));
#endif // wxUSE_STATUSBAR

}

void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	delete(gm);
    Close(true);
}

void MyFrame::NewPlayer(wxCommandEvent& WXUNUSED(event) )
{
	MyNewPlayerDialog dialog(this, wxT("������� ������ ������"));
	if (dialog.ShowModal() == wxID_OK)
	{
		//char first[1024];
		//strncpy(first, (const char*)dialog.GetFirstName().mb_str(wxConvUTF8), 1023);
		//char sec[1024];
		//strncpy(sec, (const char*)dialog.GetSecondName().mb_str(wxConvUTF8), 1023);
		//char code[1024];
		//strncpy(code, ((const char*)(dialog.GetNickName().mb_str(wxConvUTF8))), 1023);


		std::string name = dialog.GetFirstName();
		std::string fame = dialog.GetSecondName();
		std::string code = dialog.GetNickName();

		int rate = dialog.GetRating();
		int age = dialog.GetAge();
		Player* pl = new Player(name, fame, code, rate, age);
		gm->RegistryGameAgent(pl);
	}
}

void MyFrame::OnAbout(wxCommandEvent& WXUNUSED(event) )
{
    (void)wxMessageBox(wxT("��������� - ��������\n"),
            wxT("� ���� resistanceWx"), wxOK|wxICON_INFORMATION);
}

void MyFrame::OnStartBtn(wxCommandEvent& WXUNUSED(event))
{

	if (!this->gm->CanStartGame())
	{
		wxMessageBox(wxT("������������ �������!"));
		return;
	}

	gm->ExecuteStart();

	wxPanel* p = new wxPanel(this, wxID_ANY, wxPoint(100, 100), wxSize(600, 400));

	wxBoxSizer *topsizer = new wxBoxSizer(wxVERTICAL);

	wxString roundName = wxString::Format(wxT("%d-� �����"), gm->GetCurrentGameRound()->GetRoundNumber());

	//wxBoxSizer *statsizer = new wxStaticBoxSizer(new wxStaticBox(p, wxID_ANY, roundName), wxVERTICAL);
	//wxPanel *statPanel = new wxPanel(p, wxID_ANY);

	GameRoundPanel(p, topsizer, gm->GetCurrentGameRound());
	//statPanel->SetSizer(statsizer);
	//statsizer->SetSizeHints(this);


	//topsizer->Add(statsizer, wxSizerFlags(1).Expand().Border(wxALL, 10));

	p->SetSizer(topsizer);
	topsizer->SetSizeHints(this);

}

Game * MyFrame::GetGame()
{
	return this->gm;
}



