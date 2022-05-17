#ifndef OPTIONS_H
#define OPTIONS_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include "CheckPoint.h"
#include "pod.h"

#define max_options 3 //Nombre d'options

class Options : public sf::Drawable
{   
    public : 
    Options(float width, float height);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void MoveUp();
    void MoveDown();
    int OptionPressed(){
        return Selected;
    };
    ~Options();

    private:
    sf::Font font;
    int Selected;
    sf::Sprite Background_sprite;
    sf::Texture Background_texture;

    sf::Text options_list[max_options];
};

#endif