#include <vector>
#include <wx/wxprec.h>

#include "../include/FinanceManager.hpp"

#ifndef MENU_GUI_HPP
#define MENU_GUI_HPP

#ifndef WX_PRECOMP
    #include <wx/wx.h>
    #include <wx/grid.h>
    #include <wx/arrstr.h>
    #include <wx/valnum.h>
#endif

extern std::map<int, std::string> expenseTypes;

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
    FinanceManager financeManager = FinanceManager();
    wxArrayString expenseTypeChoices;

    wxSizer* mainSizer;
    wxPanel* mainPanel;

    // Balance/Income Inputs 
    wxTextCtrl* balanceAmountInput;
    wxTextCtrl* incomeInput;

    // Expense Inputs
    wxTextCtrl* expenseNameInput;
    wxChoice* expenseTypeCodeChoice;
    wxTextCtrl* expensePriceInput;

    // Savin Asset Input
    wxTextCtrl* assetNameInput;
    wxTextCtrl* assetStartPriceInput;
    wxTextCtrl* assetActualPriceInput;

    void OnExit(wxCommandEvent& event);

    // Generic Actions 
    void createReturnButton();
    void OnReturnClicked(wxCommandEvent& event);
    
    // Finance Manager Actions
    void OnSetBalanceAction(wxCommandEvent& event);
    void OnAddToIncomeAction(wxCommandEvent& event);
    void OnAddExpenseAction(wxCommandEvent& event);
    void OnAddSavingAssetAction(wxCommandEvent& event);

    // MENU OPTIONS
    void createOptionButtons();
    void OnDisplayAccountBalanceClicked(wxCommandEvent& event);
    void OnDisplaySavingsBalanceClicked(wxCommandEvent& event);
    void OnDisplayExpensesClicked(wxCommandEvent& event);
    void OnSetAccountBalanceClicked(wxCommandEvent& event);
    void OnAddIncomeClicked(wxCommandEvent& event);
    void OnAddExpenseClicked(wxCommandEvent& event);
    void OnAddSavingsAssetClicked(wxCommandEvent& event);
    void OnSaveExpensesClicked(wxCommandEvent& event);
    void OnSaveSavingsAssetsClicked(wxCommandEvent& event);
};

#endif