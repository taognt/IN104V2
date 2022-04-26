#include "pod.h"
#include "game.h"
#include <SFML/System/Vector2.hpp>

Decision::Decision(sf::Vector2f target, float power) : target_(target), power_(power) 
{

};

Pod::Pod(sf::Vector2f pos, float angle, sf::Vector2f vel) : pos_(pos), vel_(vel), angle_(angle)
{

};

/* Decision Pod::getDecision(Game gameSnapshot) const
{
    int left, right;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    left = 1;
    }
    else{
        right = 1;
    }
    

    return Decision({8000, 4500}, 100);
}; */