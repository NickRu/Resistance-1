class GameRoundPanel : public wxPanel
{
private:
	wxPanel* _parentPanel;
	wxBoxSizer* _topsizer;
	GameRound* gameRound;
public:
	GameRoundPanel(wxPanel* p, wxBoxSizer *statsizer, GameRound* ground);
	~GameRoundPanel();
};

