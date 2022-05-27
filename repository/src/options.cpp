#include "options.h"
#include "util.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>
#include <cmath>


Options :: Options()
{   
    if(!font.loadFromFile("../repository/font/nasa.ttf")){
        printf("No font has been found\n");
    }

    //Background
    Background_texture.loadFromFile("../repository/Images/mars.jpg");
    Background_sprite.setTexture(Background_texture);
    auto rec = Background_sprite.getGlobalBounds();
    Background_sprite.scale(sf::Vector2f(16000/rec.width, 9000/rec.height));  //Resizing

    //sounds
    if (!buffer.loadFromFile("../repository/music/selection3.wav")){
        printf("no sound found\n");
    }
    sound_selection.setBuffer(buffer);
    sound_selection.setVolume(10);

    //controll indication
    controll_indication.setFont(font);
    SetOriginToCenterText(controll_indication);
    controll_indication.setString("Press Space to select");
    controll_indication.setCharacterSize(300);
    controll_indication.setPosition(12000, 8000);
    controll_indication.setFillColor(sf::Color::White);
    controll_indication.setOutlineColor(sf::Color::Black);
    controll_indication.setOutlineThickness(20);

    //Images
    IA_texture.loadFromFile("../repository/Images/IA.png");
    IA_sprite.setTexture(IA_texture);
    scaleToMaxSize(IA_sprite);
    SetOriginToCenterSprite(IA_sprite);
    IA_sprite.setPosition(8000, 2700);

    Arrow_texture.loadFromFile("../repository/Images/arrow.png");
    Arrow_sprite.setTexture(Arrow_texture);
    scaleToMaxSize(Arrow_sprite);
    SetOriginToCenterSprite(Arrow_sprite);
    Arrow_sprite.setPosition(10500, 3850);


    //IA
    options_list[0].setFont(font);
    SetOriginToCenterText(options_list[0]);
    options_list[0].setString("IA");
    options_list[0].setCharacterSize(800);
    options_list[0].setPosition(6000, 2000);
    options_list[0].setFillColor(sf::Color::White);
    options_list[0].setOutlineColor(sf::Color::Black);
    options_list[0].setOutlineThickness(20);

    //Direction
    options_list[1].setFont(font);
    options_list[1].setString("Direction");
    SetOriginToCenterText(options_list[1]);
    options_list[1].setCharacterSize(800);
    options_list[1].setPosition(6000, 3500);
    options_list[1].setFillColor(sf::Color::Black);
    options_list[1].setOutlineColor(sf::Color::Black);
    options_list[1].setOutlineThickness(20);

    //Exit
    options_list[2].setFont(font);
    options_list[2].setString("Exit");
    SetOriginToCenterText(options_list[2]);
    options_list[2].setCharacterSize(800);
    options_list[2].setPosition(6000, 5000);
    options_list[2].setFillColor(sf::Color::Black);
    options_list[2].setOutlineColor(sf::Color::Black);
    options_list[2].setOutlineThickness(20);


    Selected = 0;
}
Options::~Options()
{

}


void Options::draw(sf::RenderTarget& target, sf::RenderStates states) const
{   
    target.draw(Background_sprite, states);
    for(int i=0;i<max_options; i++){
        target.draw(options_list[i]);
    } 
    target.draw(IA_sprite, states);
    target.draw(Arrow_sprite, states);
    target.draw(controll_indication, states);

}

void Options::MoveUp()  
{
    sound_selection.play();
    if(Selected >= 0){
        options_list[Selected].setFillColor(sf::Color::Black); //button selected
        Selected --;
        if (Selected == -1) { //Cycle Play - Option - Exit - Play - ...
            Selected = max_options-1;
        }
        options_list[Selected].setFillColor(sf::Color::White);  //Latest button reset to Black
    }
}

void Options::MoveDown()
{
    sound_selection.play();
    if(Selected < max_options & Selected >=0){
        options_list[Selected].setFillColor(sf::Color::Black);
        Selected ++;
        if(Selected == max_options){
            Selected = 0;
        }
        options_list[Selected].setFillColor(sf::Color::White);
    }
}