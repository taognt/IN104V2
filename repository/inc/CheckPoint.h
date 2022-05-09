#ifndef INC_CHECKPOINT_H
#define INC_CHECKPOINT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include "util.h"

class CheckPoint : public sf::Drawable
{
    public :
    CheckPoint(sf::Vector2f center, unsigned int id); //creates a Checkpoint from a position and its number
    sf::Vector2f getPosition(); //returns Checkpoint's position


    private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setTextCenterPosition(sf::Text text, sf::Vector2f center); //Set the position of the text to center

    sf::CircleShape circle_;
    unsigned int id_;
    sf::Vector2f center_;
    sf::Font font_;
    sf::Sprite Flag_;
    sf::Texture fillingTexture_;
    sf::Text fillingText_;
};

class FinalCheckPoint : public sf::Drawable
{
    public :
    FinalCheckPoint(sf::Vector2f center);
    sf::Vector2f getPosition();
    void setTextCenterPosition(sf::Text text, sf::Vector2f);

    private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::CircleShape circle_;
    sf::Vector2f center_;
    sf::Texture fillingTexture_;
    sf::Sprite fillingSprite_;
};

#endif