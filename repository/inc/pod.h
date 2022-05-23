#ifndef INC_POD_H
#define INC_POD_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Time.hpp>
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
    bool mode_IA;
    int id_;
    int nextCP_, lapCount_;
    float Power_max; //Power maxof the pod
    sf::Time chrono; //Time to finish the run
    double timer;
    sf::Text chrono_text;
    int start; //1 if the pod have just started the run, 0 after, used to know if the pod finished the run in is_finished_run
    int finish;
    
    friend class Game; //allows game to modify pod's private attributes
};

#endif