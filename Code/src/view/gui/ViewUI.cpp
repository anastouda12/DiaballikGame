#include "headers/ViewUI.hpp"
#include "ui_MainWindow.h"
#include "src/view/gui/headers/BoardUI.hpp"

namespace dblk
{

ViewUI::ViewUI(QWidget * parent):
    QMainWindow(parent),
    mainWindow_(new Ui::MainWindow),
    evntManager_{nullptr}
{
    mainWindow_->setupUi(this);
    this->setFixedSize(QSize(1280, 720));
    setStyleSheet("MainWindow {background:url(:/resources/images/background.jpg);}");
    mainWindow_->movesAvailableNumber->setPalette(QColor("#ff9100"));
    mainWindow_->throwAvailableNumber->setPalette(QColor("#ff9100"));
    initSlots();
}

void ViewUI::setEventManager(DiaballikEventManager * evntManager)
{
    this->evntManager_ = evntManager;
}

void ViewUI::initSlots()
{
    connect(mainWindow_->btnWelcome_play, SIGNAL(clicked()), this, SLOT(displayOptionsMenu()));
    connect(mainWindow_->btnWelcome_exit, SIGNAL(clicked()), this, SLOT(displayGoodByeMessage()));
    connect(mainWindow_->btnWelcome_showRules, SIGNAL(clicked()), this, SLOT(displayHelp()));
    connect(mainWindow_->btnGameOptions_mainMenu, SIGNAL(clicked()), this, SLOT(displayWelcomePage()));
    connect(mainWindow_->btnGameOptions_play, SIGNAL(clicked()), this, SLOT(initGame()));
    // TODO HELP EXIT
}

void ViewUI::initGame()
{
    size_t boardSize = mainWindow_->boardSizeInput->value();
    bool variant = mainWindow_->gameVariantInput->isChecked();
    this->evntManager_->executeEvent(EventType::NEW_GAME, boardSize, variant);
    this->mainWindow_->stackedWidget->setCurrentIndex(2);
}


void ViewUI::displayWelcomePage()
{
    this->mainWindow_->stackedWidget->setCurrentIndex(0);
}

void  ViewUI::displayOptionsMenu()
{
    this->mainWindow_->stackedWidget->setCurrentIndex(1);
}

void ViewUI::displayBoard(const dblk::Diaballik & diaballik)
{
    //TODO
}

void ViewUI::displayHelp()
{
    this->mainWindow_->stackedWidget->setCurrentIndex(4);
}

void ViewUI::displayCurrentPlayer(const dblk::Team & team)
{
    //TODO
}

void ViewUI::displayCounters(unsigned moveCounter, bool canPass)
{
    //TODO
}

void ViewUI::displayWinner(const std::optional<dblk::Team> & team)
{
    //TODO
}

void ViewUI:: displayError(std::string errorMsg)
{
    std::cout << "ERROR: " << errorMsg << std::endl;
}


void ViewUI::displayGoodByeMessage()
{

}

void ViewUI::displaySelected(const std::optional<dblk::Piece> piece)
{
    //TODO
}

void ViewUI::displayLeftPlayer(dblk::Team team)
{

}

void ViewUI::update(const dblk::Observable * observable)
{
    //TODO
}

ViewUI::~ViewUI()
{
    delete mainWindow_;
}

}

