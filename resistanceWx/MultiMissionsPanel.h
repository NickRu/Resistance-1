class MultiMissionsPanel : public wxPanel
{
private:
	wxPanel* roundPanel;
	wxBoxSizer *roundSizer;
	GameRound* round;
public:
	MultiMissionsPanel(wxPanel* rPanel, wxBoxSizer *roundTopSizer, GameRound* gRound);
	~MultiMissionsPanel();
};

