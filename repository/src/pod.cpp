#include "pod.h"
#include "game.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Decision::Decision(sf::Vector2f target, float power) : target_(target), power_(power) 
{

};

Pod::Pod(sf::Vector2f pos, float angle, sf::Vector2f vel) : pos_(pos), vel_(vel), angle_(angle)
{

};

Decision Pod::getDecision(Game gameSnapshot) const
{   
    //commands tests
    int FLECHE = 1;
    int IA = 0;



    int left = 0;
    int right = 0;
    int up = 0;
    int down = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        left = 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        right = 1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        up = 1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        down = 1;
    }

    //Position of the next CP
    sf::Vector2f position;
    if(FLECHE == 1){

        position.x = pos_.x+(right-left);
        position.y = pos_.y+(down-up);
    }

    if(IA == 1){
        position = gameSnapshot.otherCPs_[nextCP_].getPosition();
    }

    return Decision(position, 100);
};