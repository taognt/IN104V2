#include "game.h"
#include "CheckPoint.h"
#include "util.h"
#include "pod.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <type_traits>
#include <vector>

Game::Game(std::vector<sf::Vector2f> checkpointsPositions) : finalCP_(checkpointsPositions[0])
{   
    int L = checkpointsPositions.size();

    otherCPs_.reserve(L-1);
    for(int i = 1;i<L; i++){
        otherCPs_.emplace_back(checkpointsPositions[i], i);
    }

    //Background
    backgroundTexture_.loadFromFile("../repository/Images/background.png");
    backgroundSprite_.setTexture(backgroundTexture_);
    auto rec = backgroundSprite_.getGlobalBounds();
    backgroundSprite_.scale(sf::Vector2f(16000/rec.width, 9000/rec.height));  //Resizing

    
}

/* Game ::Game()
{   
    sf::Vector2f center(0,0);
    FinalCheckPoint CP(center);
    finalCP_ = CP;

} */

void Game::addPod() //ajoute un pod sur le premier checkpoint
{
    sf::Vector2f pos = finalCP_.getPosition();
    float angle = 0;
    sf::Vector2f vel = {0, 0};
    Pod pod(pos, angle, vel);
    pods_.emplace_back(pod);


    sf::Texture podtext;
    //podtext.loadFromFile("../repository/Images/BSGCylon.png");
    podsTextures_.emplace_back(podtext);
    podsTextures_[0].loadFromFile("../repository/Images/BSGCylon.png");

    sf::Sprite podsprite;
    podsSprites_.emplace_back(podsprite);
    
    int L = podsSprites_.size();

    for (int k=0; k<L;k++){
        podsSprites_[k].setTexture(podsTextures_[k]);
        scaleToMaxSize(podsSprites_[k]);
        SetOriginToCenterSprite(podsSprites_[k]);
        podsSprites_[k].setPosition(pods_[k].pos_);
    }
    
    
}

void Game::updatePhysics()
{

    for (Pod &pod : pods_)
    {
        Decision d = pod.getDecision(*this);

        //updatePhysics:
        sf::Vector2f target = d.target_;
        float power = d.power_;
        sf::Vector2f diff;
        diff.x = target.x - pod.pos_.x;
        diff.y = target.y - pod.pos_.y;

        //Old positions
        sf::Vector2f old_pos = pod.pos_;

        float norm_ = norm2(diff);
        if(norm_ != 0){
            pod.vel_.x = FRICTION_COEFF*(pod.vel_.x + power*   ( (target.x - pod.pos_.x)/norm2(diff)));
            pod.vel_.y = FRICTION_COEFF*(pod.vel_.y + power*((target.y - pod.pos_.y)/norm2(diff)));
        }
        else{
            pod.vel_ = FRICTION_COEFF*pod.vel_;
        }

        if(pod.vel_.x != 0){
        if (pod.vel_.x < 0) pod.angle_ = M_PI + std::atan(pod.vel_.y/pod.vel_.x);
        else pod.angle_ = std::atan(pod.vel_.y/pod.vel_.x);
        }
        pod.pos_ = pod.pos_ + pod.vel_;

        sf::Vector2f center2(4000,1500);

        if(is_reached(pod.pos_, target, old_pos) == true){
            if(pod.nextCP_ == otherCPs_[otherCPs_.size()-1].id_){
                pod.nextCP_ = 0;
            }
            else{
                pod.nextCP_ = otherCPs_[pod.nextCP_].id_;
            }
            

        } 

        /* if(!is_reached(pod.pos_, center2, old_pos)){
            targ = 0;
            printf("out of the target \n \n");
        } */
    }

    physicsTime += PHYSICS_TIME_STEP;
    //utiliser PodsSnapShot et pods_ pour vérifier si chaque pod a validé son prochain CP : Si checkpoint atteint, on va au prochain
    // !!! Verifier qu'on est pas au bout de la liste, sinon on reboucle
     
    
}
void Game::updateGraphics(sf::Time frameTime)
{   
    //std::vector<sf::Sprite> Sprites = podsSprites_;

    float c = (physicsTime - frameTime) / (frameTime - lastFrameTime);

    int L = podsSprites_.size();
    for (int k=0; k<L;k++){

        sf::Vector2f pos_sprite = podsSprites_[k].getPosition();

        if(c>1){
        podsSprites_[k].setPosition(pods_[k].pos_ + -(pods_[k].pos_ - pos_sprite )/c);
        }
        else{
            podsSprites_[k].setPosition(pods_[k].pos_);
        }
        podsSprites_[k].setRotation(pods_[k].angle_*180.f/M_PI);
    }

    lastFrameTime = frameTime;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(backgroundSprite_, states);
    target.draw(finalCP_, states);

    for (const auto &cp : otherCPs_)
    {
        target.draw(cp, states);
    }

    for (const auto &podSprite : podsSprites_)
    {
        target.draw(podSprite, states);
    }
    
    target.draw(A_, states);

}

bool Game::is_reached(sf::Vector2f new_pos, sf::Vector2f target, sf::Vector2f old_pos){
    bool val;
    float radius = 850;
    if(norm2(new_pos - target) <=radius){
        val = true;
    }
    else{
        val = false;
    }
    return val;
}

/* bool Game::is_reached(sf::Vector2f new_pos, sf::Vector2f target, sf::Vector2f old_pos){
    float radius = 850;
    bool val;
    sf::Vector2f Proj_center; //Prejection du centre sur la droite directrice
    sf::Vector2f Proj_center2; 
    sf::Vector2f A, B, C, D;

    if(new_pos.x == old_pos.x){     //Cas ou le coef directeur est infini
        Proj_center = {old_pos.x, target.y};
        //printf("Proj center = %f, %f\n", Proj_center.x, Proj_center.y);
        if(norm2(Proj_center - target) <= radius){
            val = true;
        }
        else val = false;
    }

    else if(new_pos.y == old_pos.y){     //Cas ou le coeff directeur a = 0
        Proj_center = {target.x, old_pos.y};
        if(norm2(Proj_center - target) <= radius){
            val = true;
        }
        else val = false;
    }

    else{
        float a = (new_pos.y-old_pos.y+new_pos.y)/(new_pos.x-old_pos.x);   //Coefficient directeur de old_pos à new_pos
        float x = (a/(1+a*a))*((1/a)*target.x + target.y + a*old_pos.x - old_pos.y);
        float y = a*x - a*old_pos.x + old_pos.y;

        //Prejection 1e droite
        Proj_center ={x, y};
        x = sqrt((radius*radius)/(1+(a*a)));
        y = a*x;
        A = {Proj_center.x+x, Proj_center.y+y};
        B = {Proj_center.x-x, Proj_center.y-y};

        //Projection 2e cote
        x = (a/(1+a*a))*((1/a)*new_pos.x + a*target.x + new_pos.y - target.y);
        y = a*x - a*target.x + target.y;
        Proj_center2 = {x, y};

        y = sqrt((radius*radius)/(1+(a*a)));
        x = -a*y; //Ou x = a*y ??
        C = {Proj_center2.x - x, Proj_center2.y - y};
        D = {Proj_center2.x + x, Proj_center2.y + y};

        sf::Vector2f AB = B-A;
    if(prod_scal2(old_pos, AB)/norm2(AB) < 1 & prod_scal2(AB, new_pos)/norm2(AB) > 1 & prod_scal2(new_pos, D-C)/norm2(D-C)>1 & prod_scal2(new_pos, D-C)/norm2(D-C) < 1 ){
        val = true;
        printf("norm target - center < radius \n");
    }
    else{
        val = false;
    }

    }

    sf::Sprite A_1;
    textureA_.loadFromFile("../repository/Images/A.png");
    A_1.setTexture(textureA_);
    scaleToMinSize(A_1);
    SetOriginToCenterSprite(A_1);
    A_1.setPosition(C);

    return val;
    

} */ 