add_library(Budget STATIC Budget.cpp)
add_library(Expense STATIC Expense.cpp)
target_include_directories(Budget PUBLIC ../include)
target_include_directories(Expense PUBLIC ../include)