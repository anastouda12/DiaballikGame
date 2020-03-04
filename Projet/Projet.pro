TEMPLATE = app
CONFIG += console # c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17

SOURCES += \
        main.cpp \
        src/controller/EventFactory.cpp \
        src/controller/ExitEvent.cpp \
        src/controller/HelpEvent.cpp \
        src/controller/MoveEvent.cpp \
        src/controller/PassEvent.cpp \
        src/controller/PassTurnEvent.cpp \
        src/controller/SelectEvent.cpp \
        src/controller/ShowEvent.cpp \
        src/model/Board.cpp \
        src/model/Diaballik.cpp \
        src/model/Observable.cpp \
        src/model/Position.cpp \
        src/model/Piece.cpp \
        src/model/Team.cpp \
        src/view/console/ViewConsole.cpp

QMAKE_CXXFLAGS += -pedantic-errors -std=c++17


HEADERS += \
    src/View/Console/headers/ViewConsole.hpp \
    src/View/headers/Observer.hpp \
    src/View/headers/View.hpp \
    src/controller/headers/DiaballikEvent.hpp \
    src/controller/headers/EventFactory.hpp \
    src/controller/headers/ExitEvent.hpp \
    src/controller/headers/HelpEvent.hpp \
    src/controller/headers/MoveEvent.hpp \
    src/controller/headers/PassEvent.hpp \
    src/controller/headers/PassTurnEvent.hpp \
    src/controller/headers/SelectEvent.hpp \
    src/View/Console/View.hpp \
    src/controller/headers/ShowEvent.hpp \
    src/model/headers/Board.hpp \
    src/model/headers/Configs.hpp \
    src/model/headers/Diaballik.hpp \
    src/model/headers/Observable.hpp \
    src/model/headers/Piece.hpp \
    src/model/headers/Position.hpp \
    src/model/headers/Team.hpp
