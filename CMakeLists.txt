cmake_minimum_required(VERSION 3.22.1)

project(FinanceManager)

set(SOURCES
    src/Budget.cpp
    src/SavingsWallet.cpp
    src/Asset.cpp
    src/Expense.cpp
    src/Menu.cpp
    main.cpp
)

include_directories(include)
add_executable(${PROJECT_NAME} ${SOURCES})