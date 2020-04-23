#include "headers/ViewUI.hpp"
#include "ui_MainWindow.h"
#include <QFile>
#include <QMessageBox>

namespace dblk
{

ViewUI::ViewUI(QWidget * parent):
    QMainWindow(parent),
    mainWindow_{new Ui::MainWindow},
            evntManager_{nullptr},
            boardUI_{nullptr}
{
    mainWindow_->setupUi(this);
    this->setFixedSize(QSize(1280, 720));
    QFile file(":/resources/qss/stylesheet.qss");
    if (file.exists())
    {
        file.open(QFile::ReadOnly);
        QString style = QLatin1String(file.readAll());
        qApp->setStyleSheet(style);
    }
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
    connect(mainWindow_->btnWelcome_play, SIGNAL(clicked()), this,
            SLOT(displayOptionsMenu()));
    connect(mainWindow_->btnWelcome_exit, SIGNAL(clicked()), this,
            SLOT(displayGoodByeMessage()));
    connect(mainWindow_->btnWelcome_showRules, SIGNAL(clicked()), this,
            SLOT(displayHelp()));
    connect(mainWindow_->btnGameOptions_mainMenu, SIGNAL(clicked()), this,
            SLOT(displayWelcomePage()));
    connect(mainWindow_->btnGameOptions_play, SIGNAL(clicked()), this,
            SLOT(initGame()));
    connect(mainWindow_->btnGamePage_passTurn, SIGNAL(clicked()), this,
            SLOT(passTurnGame()));
    connect(mainWindow_->btnGamePage_leave, SIGNAL(clicked()), this,
            SLOT(leaveGame()));
    // TODO HELP EXIT
}

void ViewUI::initGame()
{
    size_t boardSize = mainWindow_->boardSizeInput->currentText().toInt();
    bool variant = mainWindow_->gameVariantInput->isChecked();
    this->evntManager_->executeEvent(EventType::NEW_GAME, boardSize,
                                     variant);
    this->mainWindow_->stackedWidget->setCurrentIndex(2);
}


void ViewUI::passTurnGame()
{
    this->evntManager_->executeEvent(EventType::PASS_TURN, 0, 0);
}

void ViewUI::leaveGame()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  "Exit", "Are you sure you want to quit your game and return to main menu ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        // TODO delete current game & init new
        this->mainWindow_->stackedWidget->setCurrentIndex(0);
    }
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
    this->boardUI_->refreshBoard(diaballik.getBoard());
}

void ViewUI::displayHelp()
{
    this->mainWindow_->stackedWidget->setCurrentIndex(4);
}

void ViewUI::displayCurrentPlayer(const dblk::Team & team)
{
    this->mainWindow_->textTurnTeam->setText(QString::fromStdString(
                to_string(team)));
}

void ViewUI::displayCounters(unsigned moveCounter, bool canPass)
{
    this->mainWindow_->movesAvailableNumber->display(
        QString::fromStdString(std::to_string(moveCounter)));
    this->mainWindow_->throwAvailableNumber->display(
        QString::fromStdString(std::to_string(canPass)));
}

void ViewUI::displayWinner(const std::optional<dblk::Team> & team)
{
    this->mainWindow_->teamWinnerText->setText(QString::fromStdString(
                to_string(team.value())));
}

void ViewUI:: displayError(std::string errorMsg)
{
    this->mainWindow_->textActionGame->setText("[ERROR] : " +
            QString::fromStdString(errorMsg));
    std::cout << "ERROR: " << errorMsg << std::endl;
}


void ViewUI::displayGoodByeMessage()
{
    this->mainWindow_->textActionGame->setText("Bye..."); // ....
}

void ViewUI::displaySelected(const std::optional<dblk::Position>
                             position)
{
    if (position.has_value())
    {
        this->mainWindow_->textActionGame->setText("[SELECTION] : Piece selected in "
                +
                QString::fromStdString(
                    position.value().to_string()));
    }
}

void ViewUI::displayLeftPlayer(dblk::Team team)
{
    this->mainWindow_->typeWinText->setText("Team " +
                                            QString::fromStdString(to_string(
                                                    team)) + " left the Game");
}

void ViewUI::update(const dblk::Observable * observable,
                    EventType type)
{
    const Diaballik * game = reinterpret_cast<const Diaballik *>
                             (observable);
    this->mainWindow_->textActionGame->clear();
    switch (type)
    {
        case EventType::MOVE:
            this->displayCounters(game->getMoveCount(), game->canPass());
            break;
        case EventType::SELECT:
            this->displaySelected(game->getSelected());
            break;
        case EventType::SQUARE_LEFT_CLICKED:
            this->displaySelected(game->getSelected());
            this->displayCounters(game->getMoveCount(), game->canPass());
            break;
        case EventType::PASS:
            this->displayCounters(game->getMoveCount(), game->canPass());
            break;
        case EventType::NEW_GAME:
            if (boardUI_ != nullptr)
            {
                delete boardUI_;
            }
            boardUI_ = new BoardUI(game->getBoard(), evntManager_);
            this->mainWindow_->boardZone->setLayout(boardUI_);
            this->displayCurrentPlayer(game->getCurrentPlayer());
            this->displayCounters(game->getMoveCount(), game->canPass());
            break;
        case EventType::PASS_TURN:
            this->displayCurrentPlayer(game->getCurrentPlayer());
            this->displayCounters(game->getMoveCount(), game->canPass());
            break;
    }
    this->displayBoard(*game);
}

ViewUI::~ViewUI()
{
    delete mainWindow_;
    delete boardUI_;
}

}

