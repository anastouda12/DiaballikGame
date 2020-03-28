#include <exception>
#include "headers/EventFactory.hpp"
#include "headers/MoveEvent.hpp"
#include "headers/PassEvent.hpp"
#include "headers/SelectEvent.hpp"
#include "headers/PassTurnEvent.hpp"
#include "headers/HelpEvent.hpp"
#include "headers/ExitEvent.hpp"
#include "headers/ShowEvent.hpp"

namespace dblk
{

/**
 * @brief split
 * Cuts the given string s, into a vector of substrings when the delimetator del is found.
 *
 * @param s The string to be splited.
 * @param del The delimitator.
 * @return A vector containing the cuted string.
 */
std::vector<std::string> split(std::string s, std::string del);

/**
 * @brief toLowerCase
 * Transform all letters into lower case.
 *
 * @param s The string to be transformed.
 */
void toLowerCase(std::string & s);

/**
 * @brief parseInt
 * Parses the given string into integer.
 * Throws invalid_argument if the string is not a number.
 *
 * @param nb The string to be parsed.
 * @return The integer value of the string.
 */
int parseInt(std::string nb);


//DiaballikEventFactory Implementation

DiaballikEventFactory::DiaballikEventFactory(Diaballik & model, View & view): model_{model}, view_{view} {}

DiaballikEvent DiaballikEventFactory::generateEvent(std::string input)
{
    toLowerCase(input);
    std::vector<std::string> parser{split(input, std::string(" "))};
    if (parser.empty())
    {
        throw std::runtime_error("No command was given");
    }
    else
    {
        if (parser[0] == "move" || parser[0] == "play")
        {
            if (parser.size() < 3) throw std::invalid_argument("Not enought arguments for play command");
            else return DiaballikEvent{new MoveEvent(model_, view_, Position(parseInt(parser[1]), parseInt(parser[2])))};
        }
        else if (parser[0] == "select")
        {
            if (parser.size() < 3) throw std::invalid_argument("Not enought arguments for select command");
            else return DiaballikEvent{new SelectEvent(model_, view_, Position(parseInt(parser[1]), parseInt(parser[2])))};
        }
        else if (parser[0] == "pass")
        {
            if (parser.size() == 2 && parser[1] == "turn") return DiaballikEvent{new PassTurnEvent(model_)};
            else
            {
                if (parser.size() < 3) throw std::invalid_argument("Not enought arguments for pass command");
                else return DiaballikEvent{new PassEvent(model_, view_, Position(parseInt(parser[1]), parseInt(parser[2])))};
            }
        }
        else if (parser[0] == "passturn")
        {
            return DiaballikEvent{new PassTurnEvent(model_)};
        }
        else if (parser[0] == "help")
        {
            return DiaballikEvent{new HelpEvent(view_)};
        }
        else if (parser[0] == "exit" || parser[0] == "quit")
        {
            return DiaballikEvent{new ExitEvent(view_, model_)};
        }
        else if (parser[0] == "show" || parser[0] == "display")
        {
            return DiaballikEvent{new ShowEvent(view_, model_)};
        }
        else
        {
            throw std::runtime_error("Unknown Command");
        }
    }
}


// Util methods.

int parseInt(std::string nb)
{
    try
    {
        return stoi(nb);
    }
    catch (...)
    {
        throw std::invalid_argument("The argument is not a number");
    }
}

void toLowerCase(std::string & s)
{
    for (char & c : s)
    {
        c = std::tolower(c);
    }
}

std::vector<std::string> split(std::string s, std::string del)
{
    size_t pos = 0;
    std::string token;
    std::vector<std::string> result;
    while ((pos = s.find(del)) != std::string::npos)
    {
        token = s.substr(0, pos);
        result.push_back(token);
        s.erase(0, pos + del.length());
    }
    result.push_back(s);
    return result;
}


} // End namespace dblk
