#include "Menu.h"
#include "util.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>
#include <cmath>

MainMenu :: MainMenu(float width, float height)
{   
    if(!font.loadFromFile("../repository/font/nasa.ttf")){
        printf("No font has been found\n");
    }

    Max_ = max_main_menu;
    if(!Background_texture.loadFromFile("../repository/Images/mars.jpg")){
        printf("No texture has been found\n");
    };  

    Background_sprite.setTexture(Background_texture);
    auto rec = Background_sprite.getGlobalBounds();
    Background_sprite.scale(sf::Vector2f(16000/rec.width, 9000/rec.height));  //Resizing

    //controll indication
    controll_indication.setFont(font);
    SetOriginToCenterText(controll_indication);
    controll_indication.setString("Press Space to select");
    controll_indication.setCharacterSize(300);
    controll_indication.setPosition(12000, 8000);
    controll_indication.setFillColor(sf::Color::White);
    controll_indication.setOutlineColor(sf::Color::Black);
    controll_indication.setOutlineThickness(20);

    //Play
    mainMenu[0].setFont(font);
    SetOriginToCenterText(mainMenu[0]);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(800);
    mainMenu[0].setPosition(6000, 2000);
    mainMenu[0].setFillColor(sf::Color::White);
    mainMenu[0].setOutlineColor(sf::Color::Black);
    mainMenu[0].setOutlineThickness(20);

    //option
    mainMenu[1].setFont(font);
    mainMenu[1].setString("Option");
    SetOriginToCenterText(mainMenu[1]);
    mainMenu[1].setCharacterSize(800);
    mainMenu[1].setPosition(6000, 3500);
    mainMenu[1].setFillColor(sf::Color::Black);
    mainMenu[1].setOutlineColor(sf::Color::Black);
    mainMenu[1].setOutlineThickness(20);

    //Exit
    mainMenu[2].setFont(font);
    mainMenu[2].setString("Exit");
    SetOriginToCenterText(mainMenu[2]);
    mainMenu[2].setCharacterSize(800);
    mainMenu[2].setPosition(6000, 5000);
    mainMenu[2].setFillColor(sf::Color::Black);
    mainMenu[2].setOutlineColor(sf::Color::Black);
    mainMenu[2].setOutlineThickness(20);

    Selected = 0;
}
MainMenu::~MainMenu()
{

}


void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{   
    target.draw(Background_sprite, states);
    for(int i=0;i<max_main_menu; i++){
        target.draw(mainMenu[i]);
    } 

    target.draw(controll_indication, states);
}

void MainMenu::MoveUp()
{
    if(Selected >= 0){
        mainMenu[Selected].setFillColor(sf::Color::Black); //button reset to black
        Selected --;
        if (Selected == -1) { //Cycle Play - Option - Exit - Play - ...
            Selected = max_main_menu-1;
        }
        mainMenu[Selected].setFillColor(sf::Color::White);  //Latest set to white
    }
}

void MainMenu::MoveDown(){
    if(Selected < max_main_menu & Selected >=0){
        mainMenu[Selected].setFillColor(sf::Color::Black);
        Selected ++;
        if(Selected == max_main_menu){
            Selected = 0;
        }
        mainMenu[Selected].setFillColor(sf::Color::White);
    }
}