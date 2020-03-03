#include "headers/View.hpp"


namespace dblk
{

//******************************//
//* Implementation Class View *//
//******************************//


View::View()
{}

void View::displayWelcomeMessage()
{
    std::cout << "Bienvenue sur le jeu Diaballik !" << std::endl;
}

void View::displayBoard(const Diaballik & game)
{
    // Display number of column on top of board
    std::cout << std::endl;
    std::cout << "    ";
    for (int x = 0;x <static_cast<int>(game.getSizeBoard());x++)
    {
        std::cout << " " << x << "  ";
    }
    std::cout << std::endl;

    // Display the board
    for (int i = 0; i< static_cast<int>(game.getSizeBoard()); i++)
    {
        std::cout << " " << i << "  ";
        for(int j = 0; j< static_cast<int>(game.getSizeBoard()); j++)
        {
            if(game.getPieceAt(Position(i,j)).has_value()){
                std::cout << game.getPieceAt(Position(i,j)).value();
            }else{
                std::cout << "(  )";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void View::displayHelp()
{
    std::cout << std::endl;
    std::cout << "===========HELP===========" << std::endl;
    std:: cout <<"> SELECT ligne colonne" << std::endl;
    std:: cout <<"> PASS ligne colonne" << std::endl;
    std:: cout <<"> MOVE ligne colonne" << std::endl;
    std:: cout <<"> PASSTURN" << std::endl;
    std:: cout <<"> HELP" << std::endl;
    std:: cout <<"> QUIT" << std::endl;
    std::cout << " =========================" << std::endl;
    std::cout << std::endl;
}

void View::displayCurrentPlayer(const Team & team)
{
    std::cout << "C'est le tour de jeu de la team " << team << std::endl;
}

void View::displayCounters(unsigned moveCounter, bool canPass)
{
    std::cout << "Mouvements restants : " << moveCounter;
    std::cout << " et " << canPass <<" passe" << std::endl;
}

void View::displayWinner(const Team * winner)
{
    if(winner == nullptr){
        std::cout << "Pas de vainqueur pour le moment !" << std::endl;
    }else{
        std::cout << "Le vainqueur est la team : " << winner << std::endl;
    }
}

void View::displayError(std::string errorMsg)
{
    std::cout << "> Erreur : " << errorMsg << std::endl;
}


std::string View::askCommand()
{
    std::string cmd;
    std::cout << "> Entrez une commande : " << std::endl;
    getline(std::cin, cmd);
    return cmd;
}

void View::update(const Observable *obj) {
    //TODO
}

}// End namespace dblk


