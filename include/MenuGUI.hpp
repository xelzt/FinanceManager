#include <wx/wxprec.h>

#ifndef MENU_GUI_HPP
#define MENU_GUI_HPP

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

enum
{
    ID_Hello = 1
};

class FinanceManagerApp : public wxApp
{
public:
    virtual bool OnInit();
};

class FinanceManagerFrame : public wxFrame{
public:
    FinanceManagerFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

#endif