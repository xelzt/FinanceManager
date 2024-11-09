#include "../include/MenuGUI.hpp"


bool FinanceManagerApp::OnInit()
{
    FinanceManagerFrame *frame = new FinanceManagerFrame();
    frame->Show(true);
    return true;
}

FinanceManagerFrame::FinanceManagerFrame()
    : wxFrame(NULL, wxID_ANY, "Finance Manager")
{
    // wxMenu *menuFile = new wxMenu;
    // menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
    //                  "Help string shown in status bar for this menu item");
    // menuFile->AppendSeparator();
    // menuFile->Append(wxID_EXIT);
 
    // wxMenu *menuHelp = new wxMenu;
    // menuHelp->Append(wxID_ABOUT);
 
    // wxMenuBar *menuBar = new wxMenuBar;
    // menuBar->Append(menuFile, "&File");
    // menuBar->Append(menuHelp, "&Help");
 
    // SetMenuBar( menuBar );
 
    // CreateStatusBar();
    // SetStatusText("Welcome to wxWidgets!");
 
    // Bind(wxEVT_MENU, &FinanceManagerFrame::OnHello, this, ID_Hello);
    // Bind(wxEVT_MENU, &FinanceManagerFrame::OnAbout, this, wxID_ABOUT);
    // Bind(wxEVT_MENU, &FinanceManagerFrame::OnExit, this, wxID_EXIT);
}

void FinanceManagerFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
 
void FinanceManagerFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
 
void FinanceManagerFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
