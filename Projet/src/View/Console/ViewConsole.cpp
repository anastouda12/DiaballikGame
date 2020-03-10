#include "headers/ViewConsole.hpp"


namespace dblk
{

//******************************//
//* Implementation Class View *//
//******************************//



void ViewConsole::displayWelcomeMessage()
{
    std::cout << "Welcome to the Diaballik game !" << std::endl;
}

void ViewConsole::displayBoard(const Board & board, const std::optional<Position> selected)
{
    // Display number of column on top of board
    std::cout << std::endl;
    std::cout << "    ";
    for (int x = 0; x < static_cast<int>(board.getSize()); x++)
    {
        std::cout << " " << x << "  ";
    }
    std::cout << std::endl;

    // Display the board
    for (int i = 0; i < board.getSize(); i++)
    {
        std::cout << " " << i << "  ";
        for (int j = 0; j < board.getSize(); j++)
        {
            Position currentPos{i, j};
            try
            {
                if (board.getPieceAt(currentPos).has_value())
                {
                    if (selected.has_value() && selected.value() == currentPos)
                    {
                        std::string selectString = board.getPieceAt(currentPos)->to_string();
                        selectString.at(0) = '|';
                        selectString.at(selectString.size() - 1) = '|';
                        std::cout << selectString;
                    }
                    else
                    {
                        std::cout << board.getPieceAt(currentPos).value();
                    }
                }
                else
                {
                    std::cout << "(  )";
                }

            }
            catch (std::invalid_argument ex)
            {
                std::cout << "error: " << ex.what() << std::endl;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void ViewConsole::displayHelp()
{
    std::cout << std::endl;
    std::cout << "===========HELP===========" << std::endl;
    std:: cout << "> SELECT line column" << std::endl;
    std:: cout << "> PASS line column" << std::endl;
    std:: cout << "> MOVE line column" << std::endl;
    std:: cout << "> PASSTURN" << std::endl;
    std:: cout << "> HELP" << std::endl;
    std:: cout << "> EXIT" << std::endl;
    std::cout << " =========================" << std::endl;
    std::cout << std::endl;
}

void ViewConsole::displayCurrentPlayer(const Team & team)
{
    std::cout << "It's the turn of the team " << team << std::endl;
}

void ViewConsole::displayCounters(unsigned moveCounter, bool canPass)
{
    std::cout << "Moves available : " << moveCounter;
    std::cout << " and " << canPass << " throw" << std::endl;
}

void ViewConsole::displayWinner(const std::optional<Team> & winner)
{
    if (!winner.has_value())
    {
        std::cout << "No winner yet !" << std::endl;
    }
    else
    {
        std::cout << "The winner is the team : " << *winner << std::endl;
    }
}

void ViewConsole::displayError(int typeError, int flagError)
{
    unsigned messagePos = static_cast<unsigned>(abs(flagError));
    std::cout << "Error : ";
    if (typeError == dblk::ERROR_MOVE) std::cout << dblk::errorMessagesMove.at(messagePos) << std::endl;
    else if (typeError == dblk::ERROR_SELECT) std::cout << dblk::errorMessageSelect.at(
                    messagePos) << std::endl;
    else if (typeError == dblk::ERROR_THROW) std::cout << dblk::errorMessageThrow.at(
                    messagePos) << std::endl;
    else std::cout << "unknow error type" << std::endl;

}


std::string ViewConsole::askCommand()
{
    std::string cmd;
    std::cout << "> Enter a command : " << std::endl;
    getline(std::cin, cmd);
    return cmd;
}

void ViewConsole::displayGoodByeMessage()
{
    std::cout << "Bye, we hope see you soon !" << std::endl;
}

void ViewConsole::displaySelected(const std::optional<Piece> piece)
{
    if (piece.has_value())
    {
        std::string ball = (piece.value().hasTheBall()) ? "*" : " ";
        std::cout << "Piece selected : " << "(" << dblk::to_string(piece.value().getTeam())[0] <<
                  ball << ")" << std::endl;
    }
    else
    {
        std::cout << "No piece selected" << std::endl;
    }
}

void ViewConsole::update(const Observable * obj)
{
    const Diaballik & diaballik = static_cast<const Diaballik &>(*obj);
    const std::optional<Position> select = diaballik.getSelected();
    std::optional<Piece> pieceSelect;
    if (select.has_value()) pieceSelect = diaballik.getBoard().getPieceAt(select.value());
    displayBoard(diaballik.getBoard(), select);
    displayCurrentPlayer(diaballik.getCurrentPlayer());
    displayCounters(diaballik.getMoveCount(), diaballik.canPass());
    displaySelected(pieceSelect);
}

}// End namespace dblk


