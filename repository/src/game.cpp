#include "game.h"
#include "CheckPoint.h"
#include "util.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

Game::Game(std::vector<sf::Vector2f> checkpointsPositions) : finalCP_(checkpointsPositions[0])
{
    int L = checkpointsPositions.size();
    for(int i = 0;i<L; i++){
        otherCPs_.push_back(CheckPoint(checkpointsPositions[i], i));
    }

    //Background
    backgroundTexture_.loadFromFile("/home/ensta/IN104/repository/Images/background.png");
    backgroundSprite_.setTexture(backgroundTexture_);
    auto rec = backgroundSprite_.getGlobalBounds();
    backgroundSprite_.scale(sf::Vector2f(16000/rec.width, 9000/rec.height));  //Resizing

    //pods
    //addPod();
    
}

/* void Game::addPod()
{
    //TODO
}

void Game::updatePhysics()
{
    //TODO
}

void Game::updateGraphics(sf::Time frameTime)
{
    //TODO
} */

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