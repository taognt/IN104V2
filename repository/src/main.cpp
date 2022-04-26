#include "example.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>
#include <cstdio>
#include "util.h"

// to_string example
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <math.h>

//Checkpoint
#include "CheckPoint.h"


const int FPS = 100.0f;


int main()
{   
    sf::ContextSettings settings;

    //Def on the fps text
    sf::Text fps_text;
    sf::Font font;
    font.loadFromFile("../repository/Fredoka-Bold.ttf");
    fps_text.setCharacterSize(400);
    fps_text.setFont(font);
    fps_text.setFillColor(sf::Color::Blue);

    //Antialiasing
    settings.antialiasingLevel = 32;

    //Set up of the window
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Shark Shark", sf::Style::Default, settings);
    window.setView(sf::View(sf::Rect(0.f,0.f,16000.f,9000.f)));


    //Set up of the texture
    sf::Texture land_texture;
    land_texture.loadFromFile("/home/ensta/IN104/repository/Images/background.png");


    //Landscape
    sf::Sprite landscape;
    landscape.setTexture(land_texture);
    auto rec = landscape.getGlobalBounds();
    landscape.scale(sf::Vector2f(16000/rec.width, 9000/rec.height));  //Resizing


    //CheckPoint
    sf::Vector2f center1(16000/2,9000/2);
    CheckPoint CP1(center1, 1);

    sf::Vector2f center2(16000/3,9000/3);
    CheckPoint CP2(center2, 0);
    
//////////////////////////////////////////////////////////////////////////////////
    //Set up of the Cylon
    sf::Texture texture_Cylon;
    texture_Cylon.loadFromFile("/home/ensta/IN104/repository/Images/BSGCylon.png");
    sf::Sprite Cylon;
    Cylon.setTexture(texture_Cylon);
    //Scape of the Cylon
    scaleToMaxSize(Cylon);
    SetOriginToCenterSprite(Cylon);
    Cylon.setPosition(16000/4,9000/6); 
//--------------------------------------------------------------------------------------
    //Set up of the Viper
    sf::Texture texture_Viper;
    texture_Viper.loadFromFile("/home/ensta/IN104/repository/Images/BSGViper.png");
    sf::Sprite Viper;
    Viper.setTexture(texture_Viper);
    //Scale
    //scaleToMinSize(Viper);
    scaleToMaxSize(Viper);
    SetOriginToCenterSprite(Viper);
    Viper.setPosition(16000/3,9000/4);

///////////////////////////////////////////////////////////////////////////////////////

    //Set time
    sf::Clock clock;
    float fps = 0;
    //sf::Time time;
    float time;
    int i = 0;

    while (window.isOpen())
    {
        i++; //Des que i = 10*k, on affiche les fps
        //Viper.rotate(50);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
        }
        }

        //Time passed since the last restart
       // time = clock.getElapsedTime();

        while((time = clock.getElapsedTime().asSeconds())<=1.0f/FPS){
            continue;
        }

        fps = 1.0f/time;
        clock.restart();

        int fps2 = round(fps);
        std::string fps_printed = std::to_string(fps2);
        
        if(i%10==0){
            fps_text.setString(fps_printed); 
        }
        //fps_text.setPosition(1920/3,1080/4);


        window.clear();
        window.draw(landscape);
        window.draw(Cylon);
        window.draw(Viper);
        window.draw(fps_text);
        window.draw(CP1);
        window.draw(CP2);
        window.display();
    }

    return 0;
}