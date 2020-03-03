#include "headers/View.hpp"


namespace dblk
{

//******************************//
//* Implementation Class View *//
//******************************//


View::View(const Diaballik * diaballik): diaballik_{diaballik}
{}

void View::displayWelcomeMessage()
{
    std::cout << "Bienvenue sur le jeu Diaballik !" << std::endl;
}

void View::displayBoard()
{
    // Display number of column on top of board
    std::cout << std::endl;
    std::cout << "    ";
    for (int x = 0;x <static_cast<int>(this->diaballik_->getSizeBoard());x++)
    {
        std::cout << " " << x << "  ";
    }
    std::cout << std::endl;

    // Display the board
    for (int i = 0; i< static_cast<int>(this->diaballik_->getSizeBoard()); i++)
    {
        std::cout << " " << i << "  ";
        for(int j = 0; j< static_cast<int>(this->diaballik_->getSizeBoard()); j++)
        {
            if(this->diaballik_->getPieceAt(Position(i,j)).has_value()){
                std::cout << this->diaballik_->getPieceAt(Position(i,j)).value();
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

void View::displayCurrentPlayer()
{
    std::cout << "C'est le tour de jeu de la team " << this->diaballik_->getCurrentPlayer() << std::endl;
}

void View::displayCounters()
{
    std::cout << "Mouvements restants : " << this->diaballik_->getMoveCount();
    std::cout << " et " << this->diaballik_->canPass() <<" passe" << std::endl;
}

void View::displayWinner()
{
    dblk::Team * winner = this->diaballik_->getWinner();
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
    std::cin >> cmd;
    return cmd;
}

}// End namespace dblk


