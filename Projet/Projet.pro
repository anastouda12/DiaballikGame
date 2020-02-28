TEMPLATE = app
CONFIG += console # c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17

SOURCES += \
        main.cpp \
        src/model/Board.cpp \
        src/model/Diaballik.cpp \
        src/model/Position.cpp \
        src/model/Piece.cpp \
        src/model/Team.cpp \
        src/view/console/View.cpp

QMAKE_CXXFLAGS += -pedantic-errors -std=c++17


HEADERS += \
    src/View/Console/View.hpp \
    src/View/Console/headers/View.hpp \
    src/model/headers/Board.hpp \
    src/model/headers/Configs.hpp \
    src/model/headers/Diaballik.hpp \
    src/model/headers/Piece.hpp \
    src/model/headers/Position.hpp \
    src/model/headers/Team.hpp
