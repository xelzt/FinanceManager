#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include "../include/Asset.hpp"
#include "../include/Expense.hpp"
#include "../include/MenuGUI.hpp"


bool FinanceManagerApp::OnInit()
{
    FinanceManagerFrame *frame = new FinanceManagerFrame();
    frame->Show(true);
    return true;
}

FinanceManagerFrame::FinanceManagerFrame()
    : wxFrame(NULL, wxID_ANY, "Finance Manager", wxDefaultPosition, wxSize(1200, 1000))
{
    mainPanel = new wxPanel(this, wxID_ANY);
    mainSizer = new wxBoxSizer(wxVERTICAL);
    this->createOptionButtons();
    mainPanel->SetSizer(mainSizer);

    // Load Expense Choices
    for(auto &x : expenseTypes){
        expenseTypeChoices.Add(x.second);
    }
}

void FinanceManagerFrame::createOptionButtons()
{
    mainSizer->Clear(true);
    wxButton* displayAccountBalanceButton = new wxButton(mainPanel, wxID_ANY, "1. Display account balance");
    wxButton* displaySavingsBalanceButton = new wxButton(mainPanel, wxID_ANY, "2. Display savings balance");
    wxButton* displayExpensesButton = new wxButton(mainPanel, wxID_ANY, "3. Display expenses");
    wxButton* setAccountBalanceButton = new wxButton(mainPanel, wxID_ANY, "4. Set account balance");
    wxButton* addIncomeButton = new wxButton(mainPanel, wxID_ANY, "5. Add income to balance");
    wxButton* addExpenseButton = new wxButton(mainPanel, wxID_ANY, "6. Add expense");
    wxButton* addSavingsAssetButton = new wxButton(mainPanel, wxID_ANY, "7. Add new savings asset");
    wxButton* saveExpensesButton = new wxButton(mainPanel, wxID_ANY, "8. Save expenses to file");
    wxButton* saveSavingsAssetsButton = new wxButton(mainPanel, wxID_ANY, "9. Save savings assets");

    mainSizer->Add(displayAccountBalanceButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(displaySavingsBalanceButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(displayExpensesButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(setAccountBalanceButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(addIncomeButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(addExpenseButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(addSavingsAssetButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(saveExpensesButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(saveSavingsAssetsButton, 0, wxALL | wxEXPAND, 5);

    displayAccountBalanceButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnDisplayAccountBalanceClicked, this);
    displaySavingsBalanceButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnDisplaySavingsBalanceClicked, this);
    displayExpensesButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnDisplayExpensesClicked, this);
    setAccountBalanceButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnSetAccountBalanceClicked, this);
    addIncomeButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnAddIncomeClicked, this);
    addExpenseButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnAddExpenseClicked, this);
    addSavingsAssetButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnAddSavingsAssetClicked, this);
    saveExpensesButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnSaveExpensesClicked, this);
    saveSavingsAssetsButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnSaveSavingsAssetsClicked, this);
    mainSizer->Layout();
}

void FinanceManagerFrame::OnDisplayAccountBalanceClicked(wxCommandEvent& event)
{
    double balanceMoney = this->financeManager.balanceWallet.getBalance();
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << balanceMoney;
    std::string message = "Balance: " + stream.str();
    wxMessageBox(message, "Balance", wxOK | wxICON_INFORMATION);
}

void FinanceManagerFrame::OnDisplaySavingsBalanceClicked(wxCommandEvent& event)
{
    mainSizer->Clear(true);
    createReturnButton();
    wxGrid* grid = new wxGrid(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    int rowAmount = this->financeManager.savings.assets.size() + 1;
    int columnAmount = 5;
    int idx = 0;
    grid->CreateGrid(rowAmount, columnAmount);

    grid->SetColLabelValue(0, "ID");
    grid->SetColLabelValue(1, "Name");
    grid->SetColLabelValue(2, "Start Price");
    grid->SetColLabelValue(3, "Actual Price");
    grid->SetColLabelValue(4, "Return rate");
    

    for(Asset a: this->financeManager.savings.assets){
        grid->SetCellValue(idx, 0, std::to_string(a.assetID));

        grid->SetCellValue(idx, 1, a.name);

        std::ostringstream startPriceStream;
        startPriceStream << std::fixed << std::setprecision(2) << a.startPrice;
        grid->SetCellValue(idx, 2, startPriceStream.str());

        std::ostringstream actualPriceStream;
        actualPriceStream << std::fixed << std::setprecision(2) << a.actualPrice;
        grid->SetCellValue(idx, 3, actualPriceStream.str());

        std::ostringstream returnRateStream;
        returnRateStream << std::fixed << std::setprecision(2) << a.returnRate;
        grid->SetCellValue(idx, 4, returnRateStream.str());
        idx += 1;
    }

    grid->SetCellBackgroundColour(0, 0, *wxLIGHT_GREY);
    grid->SetCellTextColour(0, 1, *wxBLUE);
    grid->AutoSizeColumns();

    mainSizer->Add(grid, 1, wxEXPAND | wxALL, 10);
    mainSizer->Layout();
}

void FinanceManagerFrame::OnDisplayExpensesClicked(wxCommandEvent& event)
{
    mainSizer->Clear(true);
    createReturnButton();
    wxGrid* grid = new wxGrid(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    int rowAmount = this->financeManager.balanceWallet.expenses.size() + 1;
    int columnAmount = 4;
    int idx = 0;
    grid->CreateGrid(rowAmount, columnAmount);

    grid->SetColLabelValue(0, "ID");
    grid->SetColLabelValue(1, "Name");
    grid->SetColLabelValue(2, "Type");
    grid->SetColLabelValue(3, "Price");

    for(Expense e: this->financeManager.balanceWallet.expenses){
        grid->SetCellValue(idx, 0, std::to_string(e.expenseID));

        grid->SetCellValue(idx, 1, e.expenseName);
        grid->SetCellValue(idx, 2, expenseTypes[e.expenseTypeCode]);

        std::ostringstream price;
        price << std::fixed << std::setprecision(2) << e.expensePrice;
        grid->SetCellValue(idx, 3, price.str());

        idx += 1;
    }

    grid->SetCellBackgroundColour(0, 0, *wxLIGHT_GREY);
    grid->SetCellTextColour(0, 1, *wxBLUE);
    grid->AutoSizeColumns();

    mainSizer->Add(grid, 1, wxEXPAND | wxALL, 10);
    mainSizer->Layout();
}

void FinanceManagerFrame::OnSetAccountBalanceClicked(wxCommandEvent& event)
{
    mainSizer->Clear(true);
    createReturnButton();

    wxStaticText* label = new wxStaticText(mainPanel, wxID_ANY, "Enter balance money amount:");
    balanceAmountInput = new wxTextCtrl(mainPanel, wxID_ANY, "");
    wxButton* setBalanceButton = new wxButton(mainPanel, wxID_ANY, "Set balance");
    setBalanceButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnSetBalanceAction, this);

    mainSizer->Add(label, 0, wxALL, 5);
    mainSizer->Add(balanceAmountInput, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(setBalanceButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Layout();
}

void FinanceManagerFrame::OnSetBalanceAction(wxCommandEvent& event)
{
    wxString balance = balanceAmountInput->GetValue();
    double castedBalance;
    balance.ToDouble(&castedBalance);
    this->financeManager.balanceWallet.setBalance(castedBalance);
}

void FinanceManagerFrame::OnAddIncomeClicked(wxCommandEvent& event)
{
    mainSizer->Clear(true);
    createReturnButton();

    wxStaticText* label = new wxStaticText(mainPanel, wxID_ANY, "Enter income amount:");
    incomeInput = new wxTextCtrl(mainPanel, wxID_ANY, "");
    wxButton* setIncomeButton = new wxButton(mainPanel, wxID_ANY, "Set balance");
    setIncomeButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnAddToIncomeAction, this);

    mainSizer->Add(label, 0, wxALL, 5);
    mainSizer->Add(incomeInput, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(setIncomeButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Layout();
}

void FinanceManagerFrame::OnAddToIncomeAction(wxCommandEvent& event)
{
    wxString income = incomeInput->GetValue();
    double castedIncome;
    income.ToDouble(&castedIncome);
    this->financeManager.balanceWallet.addIncomeToBalance(castedIncome);
}

void FinanceManagerFrame::OnAddExpenseClicked(wxCommandEvent& event)
{
    mainSizer->Clear(true);
    createReturnButton();

    wxStaticText* expenseNameLabel = new wxStaticText(mainPanel, wxID_ANY, "Enter expense name:");
    expenseNameInput = new wxTextCtrl(mainPanel, wxID_ANY, "");

    wxStaticText* expenseTypeCodeLabel = new wxStaticText(mainPanel, wxID_ANY, "Enter expense type:");
    expenseTypeCodeChoice = new wxChoice(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, expenseTypeChoices);

    wxStaticText* expensePriceLabel = new wxStaticText(mainPanel, wxID_ANY, "Enter expense price:");
    expensePriceInput = new wxTextCtrl(mainPanel, wxID_ANY, "");

    wxButton* addExpenseButton = new wxButton(mainPanel, wxID_ANY, "Add expense");
    addExpenseButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnAddExpenseAction, this);


    mainSizer->Add(expenseNameLabel, 0, wxALL, 5);
    mainSizer->Add(expenseNameInput, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(expenseTypeCodeLabel, 0, wxALL, 5);
    mainSizer->Add(expenseTypeCodeChoice, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(expensePriceLabel, 0, wxALL, 5);
    mainSizer->Add(expensePriceInput, 0, wxALL | wxEXPAND, 5);
    
    
    mainSizer->Add(addExpenseButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Layout();
}

void FinanceManagerFrame::OnAddExpenseAction(wxCommandEvent& event)
{
    std::string expenseNameCasted;
    double expensePriceCasted;

    wxString expenseName = expenseNameInput->GetValue();
    int expenseTypeCode = expenseTypeCodeChoice->GetSelection() + 1;
    wxString expensePrice = expensePriceInput->GetValue();

    expenseNameCasted = expenseName.ToStdString();
    expensePrice.ToDouble(&expensePriceCasted);

    this->financeManager.balanceWallet.addExpense(expenseNameCasted, expenseTypeCode, expensePriceCasted);
}

void FinanceManagerFrame::OnAddSavingsAssetClicked(wxCommandEvent& event)
{
    mainSizer->Clear(true);
    createReturnButton();

    wxStaticText* assetNameLabel = new wxStaticText(mainPanel, wxID_ANY, "Enter saving asset name:");
    assetNameInput = new wxTextCtrl(mainPanel, wxID_ANY, "");

    wxStaticText* startPriceLabel = new wxStaticText(mainPanel, wxID_ANY, "Enter start price:");
    assetStartPriceInput = new wxTextCtrl(mainPanel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0, wxFloatingPointValidator<double>());

    wxStaticText* actualPriceLabel = new wxStaticText(mainPanel, wxID_ANY, "Enter actual price:");
    assetActualPriceInput = new wxTextCtrl(mainPanel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0, wxFloatingPointValidator<double>());

    wxButton* addSavingAssetButton = new wxButton(mainPanel, wxID_ANY, "Add saving asset");
    addSavingAssetButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnAddSavingAssetAction, this);

    mainSizer->Add(assetNameLabel, 0, wxALL, 5);
    mainSizer->Add(assetNameInput, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(startPriceLabel, 0, wxALL, 5);
    mainSizer->Add(assetStartPriceInput, 0, wxALL | wxEXPAND, 5);
    mainSizer->Add(actualPriceLabel, 0, wxALL, 5);
    mainSizer->Add(assetActualPriceInput, 0, wxALL | wxEXPAND, 5);

    mainSizer->Add(addSavingAssetButton, 0, wxALL | wxEXPAND, 5);
    mainSizer->Layout();
}

void FinanceManagerFrame::OnAddSavingAssetAction(wxCommandEvent& event)
{
    wxString assetName = assetNameInput->GetValue();
    std::string assetNameCasted = assetName.ToStdString();

    wxString startPrice = assetStartPriceInput->GetValue();
    double startPriceCasted;
    startPrice.ToDouble(&startPriceCasted);
    
    wxString actualPrice = assetActualPriceInput->GetValue();
    double actualPriceCasted;
    actualPrice.ToDouble(&actualPriceCasted);

    this->financeManager.savings.addNewAsset(assetNameCasted, startPriceCasted, actualPriceCasted);
    
}

void FinanceManagerFrame::OnSaveExpensesClicked(wxCommandEvent& event)
{
    this->financeManager.saveExpensesToFile();
    wxMessageBox("Expenses saved to file", "Expense Save", wxOK | wxICON_INFORMATION);
}

void FinanceManagerFrame::OnSaveSavingsAssetsClicked(wxCommandEvent& event)
{
    this->financeManager.saveSavingsWalletInfo();
    wxMessageBox("Saving assets saved to file", "Saving Assets Save", wxOK | wxICON_INFORMATION);
}

void FinanceManagerFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void FinanceManagerFrame::OnReturnClicked(wxCommandEvent& event)
{
    mainSizer->Clear(true);
    createOptionButtons();
    mainSizer->Layout();
}

void FinanceManagerFrame::createReturnButton(){
    wxButton* returnButton = new wxButton(mainPanel, wxID_ANY, "<< Return");
    mainSizer->Add(returnButton, 0, wxALL | wxEXPAND, 5);
    returnButton->Bind(wxEVT_BUTTON, &FinanceManagerFrame::OnReturnClicked, this);
}