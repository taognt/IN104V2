#include "game.h"
#include "CheckPoint.h"
#include "util.h"
#include "pod.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

Game::Game(std::vector<sf::Vector2f> checkpointsPositions) : finalCP_(checkpointsPositions[0])
{
    int L = checkpointsPositions.size();
    printf("Checkpoint pos = %f, %f, \n%f, %f, \n%f, %f, \n", checkpointsPositions[0].x,checkpointsPositions[0].y, checkpointsPositions[1].x, checkpointsPositions[1].y, checkpointsPositions[2].x, checkpointsPositions[2].y );
    for(int i = 1;i<L; i++){
        ids_.emplace_back(i);
        otherCPs_.emplace_back(checkpointsPositions[i], ids_[i-2]);
    }

    //otherCPs_.emplace_back(checkpointsPositions[L-1], L-1);

    //Background
    backgroundTexture_.loadFromFile("../repository/Images/background.png");
    backgroundSprite_.setTexture(backgroundTexture_);
    auto rec = backgroundSprite_.getGlobalBounds();
    backgroundSprite_.scale(sf::Vector2f(16000/rec.width, 9000/rec.height));  //Resizing

    
}

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
    printf("L= : %d \n", L);

    for (int k=0; k<L;k++){
        podsSprites_[k].setTexture(podsTextures_[k]);
        scaleToMaxSize(podsSprites_[k]);
        SetOriginToCenterSprite(podsSprites_[k]);
        podsSprites_[k].setPosition(pods_[k].pos_);
    }

}

void Game::updatePhysics()
{
    std::vector<Pod> PodsSnapshot = pods_;

    for (Pod &pod : pods_)
    {
        Decision d = pod.getDecision(*this);

        //updatePhysics:
        sf::Vector2f target = d.target_;
        float power = d.power_;
        sf::Vector2f diff;
        diff.x = target.x - pod.pos_.x;
        diff.y = target.y - pod.pos_.y;

        float norm_ = norm2(diff);
        if(norm_ != 0){
            pod.vel_.x = 0.85*(pod.vel_.x + power*   ( (target.x - pod.pos_.x)/norm2(diff)));
            pod.vel_.y = 0.85*(pod.vel_.y + power*((target.y - pod.pos_.y)/norm2(diff)));
        }
        else{
            pod.vel_.x = 0.85*(pod.vel_.x);
            pod.vel_.y = 0.85*(pod.vel_.y);
        }

        pod.pos_ = pod.pos_ + pod.vel_;
        

    }

    physicsTime += PHYSICS_TIME_STEP;
    //utiliser PodsSnapShot et pods_ pour vérifier si chaque pod a validé son prochain CP 
}

void Game::updateGraphics(sf::Time frameTime)
{   
    //std::vector<sf::Sprite> Sprites = podsSprites_;

    int L = podsSprites_.size();
    for (int k=0; k<L;k++){
        podsSprites_[k].setPosition(pods_[k].pos_);
    }
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
}