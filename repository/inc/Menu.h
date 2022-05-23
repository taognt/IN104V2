#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>

#define max_main_menu 3 //Nombre de bouttons

class MainMenu : public sf::Drawable
{
    public:
    int Max_; //Number of buttons
    MainMenu(float width, float height);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void MoveUp(); //Function which moveup on the mainMenu[] according to the keyboard
    void MoveDown();
    int MainMenuPressed(){
        return Selected;
    };
    ~MainMenu();
    int Released;
    sf::Font font;


    private:
    int Selected; //Option selected
    sf::Sprite Background_sprite;
    sf::Texture Background_texture;
    sf::Text mainMenu[max_main_menu];
    sf::Text controll_indication;

};

#endif