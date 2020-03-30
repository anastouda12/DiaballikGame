#include "headers/ViewConsole.hpp"
#include "src/controller/headers/Configs.hpp"


namespace dblk
{

// Utility methods to read input
size_t getSize();
bool getVariant();


//******************************//
//* Implementation Class View *//
//******************************//

std::pair<size_t, bool> ViewConsole::displayMainMenu()
{
    std::cout << "*********************************************" << std::endl;
    std::cout << "        Welcome to the Diaballik Game!       " << std::endl;
    std::cout << "*********************************************" << std::endl;
    return std::pair<int, bool> {getSize(), getVariant()};
}


void ViewConsole::displayWelcomeMessage()
{
    std::cout << "*********************************************" << std::endl;
    std::cout << "The game has been started !" << std::endl;
    std::cout << "Write <help> for help with the commands!";
}

void ViewConsole::displayBoard(const Diaballik & diaballik)
{
    // Display number of column on top of board
    std::cout << std::endl;
    std::cout << "    ";
    for (int x = 0; x < static_cast<int>(diaballik.getBoard().getSize());
            x++)
    {
        std::cout << " " << x << "  ";
    }
    std::cout << std::endl;

    // Display the board
    for (int i = 0; i < static_cast<int>(diaballik.getBoard().getSize());
            i++)
    {
        std::cout << " " << i << "  ";
        for (int j = 0; j < static_cast<int>(diaballik.getBoard().getSize());
                j++)
        {
            Position currentPos{i, j};
            try
            {
                //Displays a piece
                if (diaballik.getBoard().getPieceAt(currentPos).has_value())
                {
                    // Special display selected piece
                    if (diaballik.getSelected().has_value() &&
                            diaballik.getSelected().value() == currentPos)
                    {
                        std::string selectString = diaballik.getBoard().getPieceAt(
                                                       currentPos)->to_string();
                        selectString.at(0) = '|';
                        selectString.at(selectString.size() - 1) = '|';
                        std::cout << selectString;
                    }
                    // No selected piece.
                    else
                    {
                        std::cout << diaballik.getBoard().getPieceAt(currentPos).value();
                    }
                }
                else
                {
                    //Checks if is available position to move the selected piece.
                    if (diaballik.getSelected().has_value())
                    {

                        if (diaballik.getBoard().checkMove(diaballik.getSelected().value(),
                                                           Position(i, j)) > 0 &&
                                diaballik.checksEnoughMovesAvailable(Position(i, j)) > 0)
                        {
                            std::cout << "(..)";
                        }
                        else
                        {
                            std::cout << "(  )";
                        }
                    }
                    //Empty position.
                    else
                    {
                        std::cout << "(  )";
                    }

                }

            }
            // Usually never gets here, if yes big bug.
            catch (std::invalid_argument & ex)
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
    std::cout << "=================================HELP=====================================" <<
              std::endl;
    std::cout << "> SELECT line column - Selects a Piece to move or pass" << std::endl;
    std::cout << "> PASS line column - Pass the ball of the selected piece to another piece." <<
              std::endl;
    std::cout << "> MOVE line column - Moves the selected piece to another position." << std::endl;
    std::cout << "> PASSTURN - Ends the turn." << std::endl;
    std::cout << "> SHOW - Displays the game board." << std::endl;
    std::cout << "> HELP - Displays help." << std::endl;
    std::cout << "> EXIT - Exits the game." << std::endl;
    std::cout << " =========================================================================" <<
              std::endl;
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

void ViewConsole::displayError(std::string errorMsg)
{
    std::cout << "[ERROR]: " << errorMsg << "!" << std::endl;

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
        std::cout << "Piece selected : " << "(" << dblk::to_string(
                      piece.value().getTeam())[0] <<
                  ball << ")" << std::endl;
    }
    else
    {
        std::cout << "No piece selected" << std::endl;
    }
}


void ViewConsole::displayLeftPlayer(Team team)
{
    std::cout << "The player " << team << " left the game!" << std::endl;
    std::cout << "The winner is: " << !team << std::endl;
}

void ViewConsole::update(const Observable * obj)
{
    const Diaballik & diaballik = static_cast<const Diaballik &>(*obj);
    const std::optional<Position> select = diaballik.getSelected();
    std::optional<Piece> pieceSelect;
    if (select.has_value()) pieceSelect = diaballik.getBoard().getPieceAt(
                select.value());
    displayBoard(diaballik);
    displayCurrentPlayer(diaballik.getCurrentPlayer());
    displayCounters(diaballik.getMoveCount(), diaballik.canPass());
    displaySelected(pieceSelect);
}

// ****************
// Utility Methods
// ****************
size_t getSize()
{
    size_t num{};
    std::string input{};
    std::cout << "Enter the board size: [" << SMALL_SIZE << ", " << MEDIUM_SIZE << " OR " << BIG_SIZE <<
              "]: " << std::endl ;
    while ( getline(std::cin, input) )
    {
        try
        {
            num = std::stoi(input);
            if ( num ==  SMALL_SIZE || num == BIG_SIZE || num == MEDIUM_SIZE)
                return num;
        }
        catch (...) {}
        std::cout << "Invalid size, must be " << SMALL_SIZE << ", " << MEDIUM_SIZE  << " or " << BIG_SIZE
                  << " : " << std::endl;
    }
    return num;
}

bool getVariant()
{
    std::string input;
    std::cout << "Play with variant mode? (yes/no): " << std::endl;
    while (getline(std::cin, input))
    {
        if (input[0] == 'y' || input[0] == 'Y') return true;
        else if (input[0] == 'n' || input[0] == 'N') return false;
        else std::cout << "Invalid answer, (yes/no): " << std::endl;
    }
    return false;
}

}// End namespace dblk


