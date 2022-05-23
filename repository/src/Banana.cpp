#include "Banana.h"
#include "CheckPoint.h"
#include "game.h"
#include "util.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdio>


Banana::Banana(sf::Vector2i pos) : pos_(pos)
{
    if(!banana_texture.loadFromFile("../repository/Images/banana.png")){
        printf("No font has been found\n");
    }
    banana_sprite.setTexture(banana_texture);
    scaleToMinSize(banana_sprite);
    SetOriginToCenterSprite(banana_sprite);
};

void Banana::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(banana_sprite, states);
    
}


