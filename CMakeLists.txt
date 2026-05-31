cmake_minimum_required(VERSION 4.2)
project(Mini_system_bankowy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS
    Core
    Gui
    Widgets
    REQUIRED)

add_executable(Mini_system_bankowy src/main.cpp
        src/model/Account.cpp
        src/model/Account.h
        src/repository/AccountRepository.h
        src/repository/InMemoryAccountRepository.cpp
        src/repository/InMemoryAccountRepository.h
        src/service/BankService.cpp
        src/service/BankService.h
        src/controller/ConsoleController.cpp
        src/controller/ConsoleController.h
        src/view/mainwindow.cpp
        src/view/mainwindow.h
        src/view/mainwindow.ui
        src/view/mainwindow.cpp
        src/view/mainwindow.h
        src/view/mainwindow.ui
        src/service/IBankService.h)

target_link_libraries(Mini_system_bankowy
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets)