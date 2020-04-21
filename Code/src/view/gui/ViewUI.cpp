#include "headers/ViewUI.hpp"
#include "ui_MainWindow.h"
#include <QFile>

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
    connect(mainWindow_->btnWelcome_play, SIGNAL(clicked()), this, SLOT(displayOptionsMenu()));
    connect(mainWindow_->btnWelcome_exit, SIGNAL(clicked()), this, SLOT(displayGoodByeMessage()));
    connect(mainWindow_->btnWelcome_showRules, SIGNAL(clicked()), this, SLOT(displayHelp()));
    connect(mainWindow_->btnGameOptions_mainMenu, SIGNAL(clicked()), this, SLOT(displayWelcomePage()));
    connect(mainWindow_->btnGameOptions_play, SIGNAL(clicked()), this, SLOT(initGame()));
    // TODO HELP EXIT
}

void ViewUI::initGame()
{
    size_t boardSize = mainWindow_->boardSizeInput->currentText().toInt();
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
    size_t size = 5;
    for (unsigned i = 0; i < size; i++)
    {
        for (unsigned j = 0; j < size; j++)
        {
            //QWidget * rect = new QWidget;
            //rect->setStyleSheet("background-color:green;"); // just for test
            if (diaballik.getBoard().isFree(Position(i, j)))
            {
                // STYLE FREE CASE
            }
            else
            {
                if (diaballik.getBoard().getPieceAt(Position(i, j)).value().getTeam() == dblk::NORTH)
                {
                    // STYLE team NORTH
                }
                else
                {
                    // STYLE team SOUTH
                }
            }
            //this->mainWindow_->gameBoard->addWidget(rect, i, j);
            // rect->show();
        }
    }

}

void ViewUI::displayHelp()
{
    this->mainWindow_->stackedWidget->setCurrentIndex(4);
}

void ViewUI::displayCurrentPlayer(const dblk::Team & team)
{
    this->mainWindow_->textTurnTeam->setText(QString::fromStdString(to_string(team)));
}

void ViewUI::displayCounters(unsigned moveCounter, bool canPass)
{
    this->mainWindow_->movesAvailableNumber->setDigitCount(moveCounter);
    this->mainWindow_->throwAvailableNumber->setDigitCount(canPass);
}

void ViewUI::displayWinner(const std::optional<dblk::Team> & team)
{
    this->mainWindow_->teamWinnerText->setText(QString::fromStdString(to_string(team.value())));
}

void ViewUI:: displayError(std::string errorMsg)
{
    this->mainWindow_->textActionGame->setText("[ERROR] : " + QString::fromStdString(errorMsg));
    std::cout << "ERROR: " << errorMsg << std::endl;
}


void ViewUI::displayGoodByeMessage()
{
    this->mainWindow_->textActionGame->setText("Bye..."); // ....
}

void ViewUI::displaySelected(const std::optional<dblk::Piece> piece)
{
    this->mainWindow_->textActionGame->setText("[SELECTED PIECE] : " + QString::fromStdString(
                piece.value().to_string()));
}

void ViewUI::displayLeftPlayer(dblk::Team team)
{
    this->mainWindow_->typeWinText->setText("Team " + QString::fromStdString(to_string(
            team)) + " left the Game");
}

void ViewUI::update(const dblk::Observable * observable, EventType type)
{
    const Diaballik * game = reinterpret_cast<const Diaballik *>(observable);
    switch (type)
    {
        case EventType::MOVE:
            break;
        case EventType::SELECT:
            break;
        case EventType::PASS:
            break;
        case EventType::NEW_GAME:
            if (boardUI_ != nullptr)
            {
                delete boardUI_;
            }
            boardUI_ = new BoardUI(game->getBoard());
            this->mainWindow_->boardZone->setLayout(boardUI_);
            this->displayCounters(game->getMoveCount(), game->canPass());
            break;
        case EventType::PASS_TURN:
            break;
    }
}

ViewUI::~ViewUI()
{
    delete mainWindow_;
    delete boardUI_;
}

}

