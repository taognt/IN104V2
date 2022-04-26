#ifndef INC_POD_H
#define INC_POD_H

#include <SFML/System.hpp>
#include <cmath>

class Game;

struct Decision
{
    Decision(sf::Vector2f target, float power);

    sf::Vector2f target_;
    float power_;
};

class Pod
{
    public :
    Pod(sf::Vector2f pos, float angle, sf::Vector2f vel = {0, 0});
    Decision getDecision(Game gameSnapshot) const; 

    private :
    sf::Vector2f pos_, vel_; //position and velocity vectors
    float angle_; //angle in radians
    int nextCP_, lapCount_;
    
    friend class game; //allows game to modify pod's private attributes
};

#endif