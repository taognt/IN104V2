#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "CheckPoint.h"
#include "game.h"
#include "util.h"

CheckPoint::CheckPoint(sf::Vector2f center, unsigned int id) : circle_(600,100)
{   
    center_ = center;
    SetOriginToCenter(circle_);
    circle_.setPosition(center);
    
    if(id == 0){
        circle_.setFillColor(sf::Color(255,255,255,63));
        fillingText_.setFillColor(sf::Color(255, 255, 255, 63));
        sf::Texture texture_flag;
        texture_flag.loadFromFile("/home/ensta/IN104/repository/Images/checkeredFlag.png");
        sf::Sprite Flag;
        Flag.setTexture(texture_flag);

        //Position of the flag :
        SetOriginToCenterSprite(Flag);
        Flag.setPosition(center); 
        Flag_ = Flag;
    }
    else{
        circle_.setFillColor(sf::Color(0,0,0,63));
        std::string text_printed = std::to_string(id);
        fillingText_.setString(text_printed);
        font_.loadFromFile("../repository/Fredoka-Bold.ttf");
        fillingText_.setCharacterSize(500);
        fillingText_.setFont(font_);
        fillingText_.setFillColor(sf::Color::Black);

        //Position of the text
        sf::FloatRect textRect = fillingText_.getLocalBounds();
        fillingText_.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
        fillingText_.setPosition(center);
    }

    circle_.setOutlineColor(sf::Color(0,0,0));
    circle_.setOutlineThickness(-50);

}

void CheckPoint::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(circle_, states);
    //setTextCenterPosition(fillingText_, center_);
    target.draw(fillingText_);
    target.draw(Flag_);
};

sf::Vector2f CheckPoint::getPosition()
{
    return circle_.getPosition();
}

void setTextCenterPosition(sf::Text text, sf::Vector2f center){
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    text.setPosition(center);
}

FinalCheckPoint::FinalCheckPoint(sf::Vector2f center) : circle_(600,100)
{
    SetOriginToCenter(circle_);
    circle_.setPosition(center);
    circle_.setFillColor(sf::Color(0,0,0,63));
    circle_.setOutlineColor(sf::Color(0,0,0));
    circle_.setOutlineThickness(-50);
};

void FinalCheckPoint::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(circle_, states);
    target.draw(fillingSprite_, states);
    target.draw(Flag_);
};

sf::Vector2f FinalCheckPoint::getPosition()
{
    return circle_.getPosition();
}
