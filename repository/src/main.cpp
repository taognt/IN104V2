//Graphic
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>



#include <cmath>
#include <cstdio>
#include "util.h"
#include "Menu.h"
#include "options.h"

// to_string example
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <math.h>

//Checkpoint
#include "CheckPoint.h"
//Game
#include "game.h"

int main(){
    sf::ContextSettings settings;

    //Antialiasing
    settings.antialiasingLevel = 4;

    //Menu
    sf::RenderWindow MENU(sf::VideoMode(1600, 900), "Main Menu", sf::Style::Default, settings);
    MENU.setView(sf::View(sf::Rect(0.f,0.f,16000.f,9000.f)));
    MainMenu myMenu(MENU.getSize().x, MENU.getSize().y);

    //Default settings
    int IA = 1;
    int Keyboard_ = 0;


    while (MENU.isOpen()) {
        sf::Event event;
        while(MENU.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                MENU.close();
            }

            if(event.type == sf::Event::KeyReleased){
                if(event.key.code == sf::Keyboard::Up){
                    myMenu.MoveUp();
                    break;
                }

                if(event.key.code == sf::Keyboard::Down){
                    myMenu.MoveDown();
                    break;
                }

                if(event.key.code == sf::Keyboard::Space){
                    sf::RenderWindow PLAY(sf::VideoMode(1600, 900), "Game", sf::Style::Default, settings);
                    PLAY.setView(sf::View(sf::Rect(0.f, 0.f, 16000.f, 9000.f)));
                    sf::RenderWindow OPTIONS(sf::VideoMode(1600, 900), "Options", sf::Style::Default, settings);
                    OPTIONS.setView(sf::View(sf::Rect(0.f, 0.f, 16000.f, 9000.f)));
                    Options myOptions(OPTIONS.getSize().x, OPTIONS.getSize().y);

                    int x = myMenu.MainMenuPressed();

                    //Play is pressed
                    if(x==0){
                        //Set time, reset every 1/fps second
                        sf::Clock clock;

                        //Global clock
                        sf::Clock global_clock;

                        int i = 0;

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
                        Game mygame(CPs, IA, Keyboard_);

                        //Game time
                        mygame.physicsTime = sf::Time::Zero;

                        mygame.addPod();

                        while (PLAY.isOpen()){
                            i++; //Des que i = 10*k, on affiche les fps
                            sf::Event event;
                            while (PLAY.pollEvent(event)){
                                if (event.type == sf::Event::Closed){
                                    PLAY.close();
                                    }
                                if(event.type == sf::Event::KeyPressed){
                                    if(event.key.code == sf::Keyboard::Escape){
                                        PLAY.close();
                                    }
                                }
                            }
                        while((mygame.time = mygame.clock_.getElapsedTime().asSeconds())<=1.0f/FPS){
                            continue;
                            }

                        //Time past since the beginning
                        sf::Time frameTime = global_clock.getElapsedTime();

                        //Reset of the clock
                        mygame.fps_ = 1.0f/mygame.time;
                        mygame.clock_.restart();

        
                        if(frameTime >mygame.physicsTime){
                            //mygame.reset_finish();
                            mygame.updateGraphics(mygame.physicsTime);
                            mygame.updatePhysics();
                            //mygame.is_finished_run();
                            if(i%10==0){
                                mygame.fps();
                            }

                            //mouse position:
                            sf::Vector2i localPosition = sf::Mouse::getPosition(PLAY);
                            mygame.updateAdders(localPosition);

                            //physicTime += PHYSICS_TIME_STEP;
                            frameTime = global_clock.getElapsedTime();
                            }


                            PLAY.clear();
                            mygame.updateGraphics(frameTime);
                            PLAY.draw(mygame);
                            /* PLAY.draw(fps_text);
                            PLAY.draw(global_time_text); */
                            OPTIONS.close();
                            PLAY.display();  
                        }
                    }


                    //Option is pressed
                    if(x==1){

                        while(OPTIONS.isOpen()){
                            sf::Event aevent;
                            while(OPTIONS.pollEvent(aevent)){
                                if(aevent.type == sf::Event::Closed){
                                    OPTIONS.close();
                                }

                                if(aevent.type == sf::Event::KeyReleased){
                                    if(aevent.key.code == sf::Keyboard::Up){
                                        myOptions.MoveUp();
                                        break;
                                    }

                                    if(aevent.key.code == sf::Keyboard::Down){
                                        myOptions.MoveDown();
                                        break;
                                    }
                                

                                    if(event.key.code == sf::Keyboard::Space){
                                        int x2 = myOptions.OptionPressed();

                                        //IA is pressed
                                        if(x2 ==0){
                                            IA = 1;
                                            Keyboard_ = 0;
                                            x = 0;
                                            OPTIONS.close();
                                            break;
                                        }
                                        //Keyboard is pressed
                                        if(x2 == 1){
                                            IA = 0;
                                            Keyboard_ = 1;
                                            x = 0;
                                            OPTIONS.close();
                                            break;
                                        }
                                        if(x2 == 2){
                                            OPTIONS.close();
                                            break;
                                        }

                                    }
                                }



                                if(aevent.type == sf::Event::KeyPressed){
                                    if(aevent.key.code == sf::Keyboard::Escape){
                                        OPTIONS.close();
                                    }
                                }
                            }

                            OPTIONS.clear();
                            OPTIONS.draw(myOptions);
                            OPTIONS.display();
                        }
                        PLAY.close();
                        OPTIONS.clear();
                        OPTIONS.display();
                    }


                    if(x==2)
                        MENU.close();
                    break;
                    
                }



            }

            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Escape){
                    MENU.close();
                }
            }

        }
        MENU.clear();
        MENU.draw(myMenu);
        MENU.display();



    }
}