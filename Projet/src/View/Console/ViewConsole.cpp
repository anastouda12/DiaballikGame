#include "headers/ViewConsole.hpp"


namespace dblk
{

//******************************//
//* Implementation Class View *//
//******************************//



void ViewConsole::displayWelcomeMessage()
{
    std::cout << "Bienvenue sur le jeu Diaballik !" << std::endl;
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
    for (int i = 0; i < static_cast<int>(board.getSize()); i++)
    {
        std::cout << " " << i << "  ";
        for (int j = 0; j < static_cast<int>(board.getSize()); j++)
        {
            Position currentPos{i, j};
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
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void ViewConsole::displayHelp()
{
    std::cout << std::endl;
    std::cout << "===========HELP===========" << std::endl;
    std:: cout << "> SELECT ligne colonne" << std::endl;
    std:: cout << "> PASS ligne colonne" << std::endl;
    std:: cout << "> MOVE ligne colonne" << std::endl;
    std:: cout << "> PASSTURN" << std::endl;
    std:: cout << "> HELP" << std::endl;
    std:: cout << "> EXIT" << std::endl;
    std::cout << " =========================" << std::endl;
    std::cout << std::endl;
}

void ViewConsole::displayCurrentPlayer(const Team & team)
{
    std::cout << "C'est le tour de jeu de la team " << team << std::endl;
}

void ViewConsole::displayCounters(unsigned moveCounter, bool canPass)
{
    std::cout << "Mouvements restants : " << moveCounter;
    std::cout << " et " << canPass << " passe" << std::endl;
}

void ViewConsole::displayWinner(const Team * winner)
{
    if (winner == nullptr)
    {
        std::cout << "Pas de vainqueur pour le moment !" << std::endl;
    }
    else
    {
        std::cout << "Le vainqueur est la team : " << winner << std::endl;
    }
}

void ViewConsole::displayError(int typeError, int flagError)
{
    unsigned messagePos = static_cast<unsigned>(abs(flagError));
    std::cout << "Erreur : ";
    if(typeError == dblk::ERROR_MOVE) std::cout << dblk::errorMessagesMove.at(messagePos) << std::endl;
    else if(typeError == dblk::ERROR_SELECT) std::cout << dblk::errorMessageSelect.at(messagePos) << std::endl;
    else if(typeError == dblk::ERROR_THROW) std::cout << dblk::errorMessageThrow.at(messagePos) << std::endl;
    else std::cout << "type d'erreur inconnue" << std::endl;

}


std::string ViewConsole::askCommand()
{
    std::string cmd;
    std::cout << "> Entrez une commande : " << std::endl;
    getline(std::cin, cmd);
    return cmd;
}

void ViewConsole::displayGoodByeMessage()
{
    std::cout << "Bye, on espére te revoir bientôt !" << std::endl;
}

void ViewConsole::displaySelected(const std::optional<Piece> piece)
{
    if(piece.has_value()){
        std::string ball = (piece.value().hasTheBall()) ? "*" : " ";
        std::cout << "Piéce sélectionnée : " << "("<< dblk::to_string(piece.value().getTeam())[0] << ball <<")" << std::endl;
    }else{
        std::cout << "Aucune piéce sélectionnée" << std::endl;
    }
}

void ViewConsole::update(const Observable * obj)
{
    const Diaballik & diaballik = static_cast<const Diaballik&>(*obj);
    const std::optional<Position> select = diaballik.getSelected();
    displayBoard(diaballik.getBoard(),select);
    displayCurrentPlayer(diaballik.getCurrentPlayer());
    displayCounters(diaballik.getMoveCount(), diaballik.canPass());
}

}// End namespace dblk


