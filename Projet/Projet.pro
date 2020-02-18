TEMPLATE = app
CONFIG += console # c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        src/model/Position.cpp

QMAKE_CXXFLAGS += -pedantic-errors -std=c++17


HEADERS += \
    src/model/headers/Board.hpp \
    src/model/headers/Configs.hpp \
    src/model/headers/Diaballik.hpp \
    src/model/headers/Piece.hpp \
    src/model/headers/Position.hpp \
    src/model/headers/Team.hpp
