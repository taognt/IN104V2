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
    start = 0;
    passed1 = 0;

};

bool Pod::is_win(Game gameSnapshot){
    bool val = true;
    for(Pod &pod : gameSnapshot.pods_){
        if((gameSnapshot.finish != gameSnapshot.nb_pod) || chrono.asSeconds()>pod.chrono.asSeconds()){
            val = false;
        }
    }
    return val;

}

Decision Pod::getDecision(Game gameSnapshot) 
{   
    //commands IA or Keyboard
    int KB = 1-mode_IA;
    int IA = mode_IA;

    int left = 0;
    int right = 0;
    int up = 0;
    int down = 0;

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

    //Position of the next CP (center) and the next next CP
    sf::Vector2f position;
    sf::Vector2f position2;
    //Vector center - surface, directed by the vector center - pod
    sf::Vector2f TS; // T for Target, S for Surface
    sf::Vector2f S; //Position of the S point
    if(KB == 1){

        position.x = pos_.x+(right-left);
        position.y = pos_.y+(down-up);
    }


//IA with different power according to the next 2 Checkpoints
    if(IA == 1){
        //We are going to reach the surface S of the checkpoint, not the center (RADIUS - 300) in order to have a security zone
        //Gain of 0.7 seconds
        if(nextCP_ == 0){
            position = gameSnapshot.cpPositions[0];
            position2 = gameSnapshot.cpPositions[1];
            TS = (RADIUS-300)*((pos_-position)/(norm2(pos_-position)));
            S = TS + position;  

        }
        else{
            position = gameSnapshot.cpPositions[nextCP_];
            if(nextCP_ == gameSnapshot.cpPositions.size()-1){
                position2 = gameSnapshot.cpPositions[0];
            }
            else {
                position2 = gameSnapshot.cpPositions[nextCP_+1];
            }
             TS = (RADIUS-300)*((pos_-position)/(norm2(pos_-position)));
            S = TS + position;  
        }


        //Power according to the angle between pod-next Cp and pod-next nextCP
        if(passed1==1){
        sf::Vector2f pod_target = position-pos_; //Vector pod-target
        sf::Vector2f pod_target2 = position2 - pos_; //vector pod-target+1
        intensity = (   (prod_scal2(pod_target, pod_target2))/(norm2(pod_target)*norm2(pod_target2))   );

        if(intensity<0.5){
            intensity = 0.5;
        }
        else{
            power = intensity*Power_max;
        }   
        }
        position = S;

    }
    if(gameSnapshot.nb_pod==gameSnapshot.finish){
            power = 0;
        }

    return Decision(position, power);
};