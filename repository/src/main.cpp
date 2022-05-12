#include "example.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Window.hpp>
#include <cmath>
#include <cstdio>
#include "util.h"

// to_string example
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <math.h>

//Checkpoint
#include "CheckPoint.h"

#include "game.h"



//INFOS
//Radius of checkpoint : 850
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
    sf::RenderWindow window(sf::VideoMode(1600, 900), "IN104", sf::Style::Default, settings);
    window.setView(sf::View(sf::Rect(0.f,0.f,16000.f,9000.f)));

/* 
    //Set up of the texture
    sf::Texture land_texture;
    land_texture.loadFromFile("../repository/Images/background.png");

 */


//////////////////////////////////////////////////////////////////////////////////
/*     //Set up of the Cylon
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
  */
///////////////////////////////////////////////////////////////////////////////////////

    //Set time, reset every 1/fps second
    sf::Clock clock;
    float fps = 0;

    //Global clock
    sf::Clock global_clock;
    float time;
    int i = 0;

    //Game time
    sf::Time physicTime = sf::Time::Zero;

    //Set up of the game
    //CheckPoint
    sf::Vector2f center1(10000,4500);
    //FinalCheckPoint CP1(center1);

    sf::Vector2f center2(12000,2000);
    //CheckPoint CP2(center2, 1);

    sf::Vector2f center3(5333,1000);
    //CheckPoint CP3(center3, 2);

    sf::Vector2f center4(2000, 8000);

    sf::Vector2f center5(6000, 6000);
    

    std::vector<sf::Vector2f> CPs;
    CPs.push_back(center1);
    CPs.push_back(center2);
    CPs.push_back(center3);
    CPs.push_back(center4);
    CPs.push_back(center5);
    Game mygame(CPs);

    mygame.addPod();


    while (window.isOpen())
    {
        i++; //Des que i = 10*k, on affiche les fps

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

        //Time past since the beginning
        sf::Time frameTime = global_clock.getElapsedTime();

        //Reset of the clock
        fps = 1.0f/time;
        clock.restart();

        //Displaying of the fps
        int fps2 = round(fps);
        std::string fps_printed = std::to_string(fps2);
        
        if(i%10==0){
            fps_text.setString(fps_printed); 
        }
        
        if(frameTime >physicTime){
            mygame.updateGraphics(physicTime);
            mygame.updatePhysics();
            physicTime += PHYSICS_TIME_STEP;

            frameTime = global_clock.getElapsedTime();

        }

        //window.clear();
        mygame.updateGraphics(frameTime);
        window.draw(mygame);
        window.draw(fps_text);
        window.display();
    }

    return 0;
}