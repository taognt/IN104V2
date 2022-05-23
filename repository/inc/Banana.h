#ifndef INC_BANANA_H
#define INC_BANANA_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Time.hpp>
#include <cmath>

class Game;

/* struct Decision2
{
    Decision2(sf::Vector2f target, float power);

    sf::Vector2f target_;
    float power_;
};
 */
class Banana : public sf::Drawable
{
    public :
    Banana(sf::Vector2i pos);
    void place_banana(sf::Vector2i localPosition); //Place the banana
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    //private :
    sf::Vector2i pos_; //position 
    int exists; //0 if the banana is already taken    
    sf::Sprite banana_sprite;
    sf::Texture banana_texture;
    
    friend class Game; //allows game to modify pod's private attributes
};

#endif