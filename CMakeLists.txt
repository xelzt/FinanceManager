cmake_minimum_required(VERSION 3.22.1)

project(FinanceManager)

set(SOURCES
    src/FinanceManager.cpp
    src/BalanceWallet.cpp
    src/SavingsWallet.cpp
    src/Asset.cpp
    src/Expense.cpp
    src/Menu.cpp
    src/MenuGUI.cpp
    main.cpp
)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

include_directories(include)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})