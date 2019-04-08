#define _CRTDBG_MAP_ALLOC

class Game; //Forward Declare
class Player; //Forward Declare

// Define a new application
class MyApp: public wxApp
{
public:
    MyApp(){};
    bool OnInit();
};

// the main frame class
class MyFrame : public wxFrame
{
public:
    MyFrame();

    void NewPlayer(wxCommandEvent& event);

    void OnAbout(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
	void OnStartBtn(wxCommandEvent& event);
	Game* GetGame();
private:
    wxDECLARE_EVENT_TABLE();

	Game* gm;

};



// controls and menu constants
enum
{
	resistanceWx_CREATE_PLAYER = 101,
	resistanceWx_START_BTN,
    resistanceWx_QUIT = wxID_EXIT,
    resistanceWx_ABOUT = wxID_ABOUT
};

