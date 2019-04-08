
class MissionCommandPanel : public wxPanel
{
private:
	wxPanel* missionPanel;
	wxBoxSizer *missionTopSizer;
	MissionCommand* command;
public:
	MissionCommandPanel(wxPanel* parentPanel, wxBoxSizer *missionSizer, MissionCommand* missionCommand);
	~MissionCommandPanel();
};

