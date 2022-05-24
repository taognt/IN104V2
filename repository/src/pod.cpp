#include "pod.h"
#include "CheckPoint.h"
#include "game.h"
#include "util.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Decision::Decision(sf::Vector2f target, float power) : target_(target), power_(power)
{

};

Pod::Pod(sf::Vector2f pos, float angle, sf::Vector2f vel) : pos_(pos), vel_(vel), angle_(angle)
{
    nextCP_ = 1;
    lapCount_ = 0;
    timer_complete = 0;
    start =0;

};

Decision Pod::getDecision(Game gameSnapshot) 
{   
    //commands IA or Keyboard
    int KB = 1-mode_IA;
    int IA = mode_IA;

    int left = 0;
    int right = 0;
    int up = 0;
    int down = 0;

    //Power
    float power = Power_max;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        left = 1;
        start += 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        right = 1;
        start += 1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        up = 1;
        start += 1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        down = 1;
        start += 1;
    }

    //Position of the next CP (center)
    sf::Vector2f position;
    //Vector center - surface, directed by the vector center - pod
    sf::Vector2f TS; // T for Target, S for Surface
    sf::Vector2f S; //Position of the S point
    if(KB == 1){

        position.x = pos_.x+(right-left);
        position.y = pos_.y+(down-up);
    }

    if(IA == 1){
        //We are going to reach the surface of the checkpoint, not the center (RADIUS - 300) in order to have a security zone
        //Gain of 0.7 seconds
        if(nextCP_ == 0){
            position = gameSnapshot.finalCP_.getPosition();
            /*  TS = (RADIUS-300)*((pos_-position)/(norm2(pos_-position)));
            S = TS + position;  */

        }
        else{
            position = gameSnapshot.otherCPs_[nextCP_-1].getPosition();
             /* TS = (RADIUS-300)*((pos_-position)/(norm2(pos_-position)));
            S = TS + position;  */
        }
    }

    return Decision(position, power);
};