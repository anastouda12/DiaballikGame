TEMPLATE = app
CONFIG += console # c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17

SOURCES += \
        main.cpp \
        src/controller/MoveEvent.cpp \
        src/controller/PassEvent.cpp \
        src/controller/SelectEvent.cpp \
        src/model/Board.cpp \
        src/model/Diaballik.cpp \
        src/model/Observable.cpp \
        src/model/Position.cpp \
        src/model/Piece.cpp \
        src/model/Team.cpp \
        src/view/console/View.cpp

QMAKE_CXXFLAGS += -pedantic-errors -std=c++17


HEADERS += \
    src/View/headers/Observer.hpp \
    src/controller/headers/DiaballikEvent.hpp \
    src/controller/headers/MoveEvent.hpp \
    src/controller/headers/PassEvent.hpp \
    src/controller/headers/SelectEvent.hpp \
    src/View/Console/View.hpp \
    src/View/Console/headers/View.hpp \
    src/model/headers/Board.hpp \
    src/model/headers/Configs.hpp \
    src/model/headers/Diaballik.hpp \
    src/model/headers/Observable.hpp \
    src/model/headers/Piece.hpp \
    src/model/headers/Position.hpp \
    src/model/headers/Team.hpp
