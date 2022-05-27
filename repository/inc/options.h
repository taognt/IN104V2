#ifndef OPTIONS_H
#define OPTIONS_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include <SFML/Audio.hpp>
#include "CheckPoint.h"
#include "pod.h"

#define max_options 3 //Nombre d'options

class Options : public sf::Drawable
{   
    public : 
    Options();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void MoveUp(); //Function which moveup on the mainMenu[] according to the keyboard
    void MoveDown(); //Function which move down on the mainMenu[] according to the keyboard
    int OptionPressed(){
        return Selected;
    };
    ~Options();

    //sounds
    sf::SoundBuffer buffer;
    sf::Sound sound_selection;

    private:
    sf::Font font;
    sf::Text controll_indication;
    int Selected;
    sf::Sprite Background_sprite;
    sf::Texture Background_texture;
    sf::Texture IA_texture;
    sf::Sprite IA_sprite;
    sf::Texture Arrow_texture;
    sf::Sprite Arrow_sprite;

    sf::Text options_list[max_options];
};

#endif