cmake_minimum_required(VERSION 4.2)
project(Mini_system_bankowy)

set(CMAKE_CXX_STANDARD 20)

add_executable(Mini_system_bankowy src/main.cpp
        src/model/Account.cpp
        src/model/Account.h
        src/repository/AccountRepository.h
        src/repository/InMemoryAccountRepository.cpp
        src/repository/InMemoryAccountRepository.h
        src/service/BankService.cpp
        src/service/BankService.h
        src/controller/ConsoleController.cpp
        src/controller/ConsoleController.h)
