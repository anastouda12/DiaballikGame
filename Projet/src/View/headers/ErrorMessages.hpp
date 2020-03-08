#ifndef ERRORMESSAGES_HPP
#define ERRORMESSAGES_HPP

#include <vector>
#include <string>

namespace dblk
{

constexpr unsigned ERROR_MOVE = 2;
constexpr unsigned ERROR_SELECT = 1;
constexpr unsigned ERROR_THROW = 3;

static std::vector<std::string> errorMessagesMove =
{
    "Aucune position sélectionnée",
    "Pas assez de mouvement disponible",
    "Hors limite du plateau de jeu",
    "Position déjà occupé",
    "Obstacle rencontré"
};

static std::vector<std::string> errorMessageThrow =
{
    "Aucune position sélectionnée",
    "Impossible de passer la balle",
    "Aucune balle",
    "Hors limite du plateau de jeu",
    "Pas de piéce",
    "Piéce de la team adverse",
    "Non-alignées",
    "Obstacle rencontré"
};

static std::vector<std::string> errorMessageSelect =
{
    "Pas de piéce",
    "Hors limite du plateau de jeu",
    "Piéce de la team adverse"
};



} // end namespace dblk

#endif // ERRORMESSAGES_HPP
