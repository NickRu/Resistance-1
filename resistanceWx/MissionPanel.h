class MissionPanel : public wxPanel
{

private:
	wxNotebook* multiMissionNote;
	Mission* mission;
	wxStaticText  *voteForCrText;
	wxStaticText  *voteAgainstCrText;
	wxStaticText  *voteForExecText;
	wxStaticText  *voteAgainstExecText;
public:
	MissionPanel(wxPanel* missionPanel, wxBoxSizer *missionTopSizer, Mission* miss);
	~MissionPanel();
	void OnCrFor(wxCommandEvent& event);
	void OnCrAgn(wxCommandEvent& event);
	void OnExFor(wxCommandEvent& event);
	void OnExAgn(wxCommandEvent& event);
};

const int ID_CR_FOR = 201;
const int ID_CR_AGAIN = 202;
const int ID_EX_FOR = 203;
const int ID_EX_AGAIN = 204;

