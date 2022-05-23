#include "game.h"
#include "CheckPoint.h"
#include "util.h"
#include "pod.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

Game::Game(std::vector<sf::Vector2f> checkpointsPositions, int IA_, int Keyboard_) : finalCP_(checkpointsPositions[0]), cpPositions(checkpointsPositions)
{   
    //Loading font
    if(!font.loadFromFile("../repository/font/nasa.ttf")){
        printf("No font has been found\n");
    }

    //
    nb_pod = 0;
    podsSprites_.reserve(MAX_POD);
    podsTextures_.reserve(MAX_POD);
    int L = checkpointsPositions.size();

    otherCPs_.reserve(L-1);
    for(int i = 1;i<L; i++){
        otherCPs_.emplace_back(checkpointsPositions[i], i);
    }

    //Background
    backgroundTexture_.loadFromFile("../repository/Images/background.png");
    backgroundSprite_.setTexture(backgroundTexture_);
    auto rec = backgroundSprite_.getGlobalBounds();
    backgroundSprite_.scale(sf::Vector2f(16000/rec.width, 9000/rec.height));  //Resizing

    //Settings
    IA = IA_;
    Keyboard = Keyboard_;

    //laps
    nb_lap_text.setFont(font);
    SetOriginToCenterText(nb_lap_text);
    nb_lap_text.setString("Lap Count : "+ std::to_string(nb_lap) + " / " + std::to_string(NUMBER_OF_LAPS));
    nb_lap_text.setCharacterSize(300);
    nb_lap_text.setPosition(13000,7000);
    nb_lap_text.setFillColor(sf::Color::White);
    nb_lap_text.setOutlineColor(sf::Color::Black);
    nb_lap_text.setOutlineThickness(20);

    //fps
    fps_text.setCharacterSize(350);
    fps_text.setFont(font);
    fps_text.setPosition(50,10);
    fps_text.setFillColor(sf::Color::White);
    fps_text.setOutlineColor(sf::Color::Black);
    fps_text.setOutlineThickness(30);

    //fps
    fps_ = 0;

    //global time
    global_time_text.setCharacterSize(350);
    global_time_text.setFont(font);
    global_time_text.setPosition(50,500);
    global_time_text.setFillColor(sf::Color::White);
    global_time_text.setOutlineColor(sf::Color::Black);
    global_time_text.setOutlineThickness(30);

    //Adders :
    Game_List[0].setFont(font);
    SetOriginToCenterText(Game_List[0]);
    Game_List[0].setString("Add Pod : press [P]");
    Game_List[0].setCharacterSize(250);
    Game_List[0].setPosition(13000, 8000);
    Game_List[0].setFillColor(sf::Color::White);
    Game_List[0].setOutlineColor(sf::Color::Black);
    Game_List[0].setOutlineThickness(20);
    
}

/* Game ::Game()
{   
    sf::Vector2f center(0,0);
    FinalCheckPoint CP(center);
    finalCP_ = CP;

} */

void Game::addPod() //ajoute un pod sur le premier checkpoint
{   
    sf::Vector2f pos = finalCP_.getPosition();
    sf::Vector2f vel = {0, 0};
    float angle = 0;
    Pod pod(pos, angle, vel);

    int i = nb_pod; //For 0 pod, i = 0 : first pod as position 0 in pods_
    pod.id_ = nb_pod+1;

    //mode
    pod.mode_IA = IA;


    //timer
    pod.chrono = physicsTime;

    //timer text
    pod.chrono_text.setFont(font);
    SetOriginToCenterText(pod.chrono_text);
    pod.chrono_text.setString("Pod "+std::to_string(i+1)+" : ");
    pod.chrono_text.setCharacterSize(0);
    pod.chrono_text.setPosition(14000,1000+500*i);
    pod.chrono_text.setFillColor(sf::Color::White);
    pod.chrono_text.setOutlineColor(sf::Color::Black);
    pod.chrono_text.setOutlineThickness(20);

    if(i==0){
        podsTextures_[i].loadFromFile("../repository/Images/BSGCylon.png");
        pod.Power_max = 150;
    }
    if(i==1){
        podsTextures_[i].loadFromFile("../repository/Images/BSGViper.png");
        pod.Power_max = 120;
    }
    if(i==2){
        podsTextures_[i].loadFromFile("../repository/Images/BSGCylon.png");
        pod.Power_max = 90;
    }
    if(i==3){
        podsTextures_[i].loadFromFile("../repository/Images/NMSFighterY.png");
        pod.Power_max = 100;
    }
    if(i==4){
        podsTextures_[i].loadFromFile("../repository/Images/SWAnakinsPod.png");
        pod.Power_max = 80;
    }
    if(i==5){
        podsTextures_[i].loadFromFile("../repository/Images/SWMilleniumFalcon.png");
        pod.Power_max = 130;
    }

    pods_.emplace_back(pod);
    sf::Sprite podsprite;
    podsSprites_.emplace_back(podsprite);

    podsSprites_[i].setTexture(podsTextures_[i]);
    scaleToMaxSize(podsSprites_[i]);
    SetOriginToCenterSprite(podsSprites_[i]);
    podsSprites_[i].setPosition(pods_[i].pos_);



    nb_pod ++;
    
}

void Game::updatePhysics()
{

    for (Pod &pod : pods_)
    {   
        if(pod.id_> 1 && Keyboard == 1){
            pod.mode_IA = 1;
        }


        if(is_reached(pod.pos_, cpPositions[pod.nextCP_], pod.pos_)){
            pod.nextCP_ +=1;

            if(pod.nextCP_== cpPositions.size()){
                pod.nextCP_ = 0;
            }
            if(pod.nextCP_ ==1){
                pod.lapCount_ +=1;
            }

        }

        Decision d = pod.getDecision(*this);

        

        //updatePhysics:
        sf::Vector2f target = d.target_;
        float power = d.power_;
        sf::Vector2f diff;
        diff = target - pod.pos_;

        //Old positions
        sf::Vector2f old_pos = pod.pos_;

        float norm_ = norm2(diff);
        if(norm_ != 0){
            pod.vel_.x = FRICTION_COEFF*(pod.vel_.x + power*   ( (target.x - pod.pos_.x)/norm2(diff)));
            pod.vel_.y = FRICTION_COEFF*(pod.vel_.y + power*((target.y - pod.pos_.y)/norm2(diff)));
        }
        else{
            pod.vel_ = FRICTION_COEFF*pod.vel_;
        }

        if(pod.vel_.x != 0){
            if (pod.vel_.x < 0) pod.angle_ = M_PI + std::atan(pod.vel_.y/pod.vel_.x);
            else pod.angle_ = std::atan(pod.vel_.y/pod.vel_.x);
        }
        pod.pos_ = pod.pos_ + pod.vel_;



    }
    IA = 0;
    Keyboard = 1;
            
    physicsTime += PHYSICS_TIME_STEP;
    //utiliser PodsSnapShot et pods_ pour vérifier si chaque pod a validé son prochain CP : Si checkpoint atteint, on va au prochain
    // !!! Verifier qu'on est pas au bout de la liste, sinon on reboucle
     
    
}
void Game::updateGraphics(sf::Time frameTime)
{   
    //std::vector<sf::Sprite> Sprites = podsSprites_;

    float c = (physicsTime - frameTime) / (frameTime - lastFrameTime);

    int L = podsSprites_.size();
    for (int k=0; k<L;k++){

        sf::Vector2f pos_sprite = podsSprites_[k].getPosition();
        if(pods_[k].timer_complete ==0 && pods_[k].lapCount_ == NUMBER_OF_LAPS){
            pods_[k].chrono = physicsTime - pods_[k].chrono;
            pods_[k].timer = ((int)(pods_[k].chrono.asSeconds()));
            pods_[k].chrono_text.setString(pods_[k].chrono_text.getString()  + std::to_string(pods_[k].timer) + " s");
            pods_[k].chrono_text.setCharacterSize(300); 
            pods_[k].timer_complete = 1;
        }

        if(c>1){
        podsSprites_[k].setPosition(pods_[k].pos_ + -(pods_[k].pos_ - pos_sprite )/c);
        }
        else{
            podsSprites_[k].setPosition(pods_[k].pos_);
        }
        podsSprites_[k].setRotation(pods_[k].angle_*180.f/M_PI);
    }



    lastFrameTime = frameTime;
}


void Game::updateAdders(sf::Vector2i localPosition){
    //Hitbox of the button add pod
    if(nb_pod < MAX_POD){
        bool val = false;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) val = true;
        if(val) addPod();
        else if((1497<localPosition.x && localPosition.x<1800 && 780<localPosition.y && localPosition.y<800)){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                addPod();

            }
        }
    }
}


void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(backgroundSprite_, states);
    target.draw(finalCP_, states);

    for (const auto &cp : otherCPs_)
    {
        target.draw(cp, states);
    }
    for(const auto &pod : pods_){
        target.draw(pod.chrono_text, states);
        
    }

    for (const auto &podSprite : podsSprites_)
    {
        target.draw(podSprite, states);
    }

    for(int i=0;i<max_list; i++){
        target.draw(Game_List[i]);
    } 

    target.draw(fps_text, states);
    target.draw(global_time_text, states);
    target.draw(nb_lap_text, states);
}


//Thanks to the intertie, the pod will change target before reaching point
bool Game::is_reached(sf::Vector2f new_pos, sf::Vector2f target, sf::Vector2f old_pos){
    bool val;
    float radius = 850;
    if(norm2(new_pos - target) <= radius){
        val = true;
    }
    else{
        val = false;
    }
    return val;
}

 void Game::is_finished_run(){
    for (Pod &pod : pods_){
        if(pod.start == 0 && pod.nextCP_ == 1){
            pod.finish = 1;
            printf("pod.id : %d", pod.id_);
            if(pod.id_== 1){
            printf("TEST\n");
            nb_lap+=1;
            }
        }
    }
}
void Game::reset_finish(){
    for(Pod &pod : pods_){
        pod.finish = 0;
    }
}
 
void Game::fps(){
    //fps
    fps_printed = std::to_string((int)round(fps_));
    fps_text.setString("Fps : " + fps_printed);

    global_time = (int)round(physicsTime.asSeconds()*100)/100;
    global_time_printed = std::to_string(global_time);
    global_time_text.setString("Global Time : " +global_time_printed + " s"); 
}

/* bool Game::is_reached(sf::Vector2f new_pos, sf::Vector2f target, sf::Vector2f old_pos){
    float radius = 850;
    bool val;
    sf::Vector2f Proj_center; //Prejection du centre sur la droite directrice
    sf::Vector2f Proj_center2; 
    sf::Vector2f A, B, C, D;

    if(new_pos.x == old_pos.x){     //Cas ou le coef directeur est infini
        Proj_center = {old_pos.x, target.y};
        //printf("Proj center = %f, %f\n", Proj_center.x, Proj_center.y);
        if(norm2(Proj_center - target) <= radius){
            val = true;
        }
        else val = false;
    }

    else if(new_pos.y == old_pos.y){     //Cas ou le coeff directeur a = 0
        Proj_center = {target.x, old_pos.y};
        if(norm2(Proj_center - target) <= radius){
            val = true;
        }
        else val = false;
    }

    else{
        float a = (new_pos.y-old_pos.y+new_pos.y)/(new_pos.x-old_pos.x);   //Coefficient directeur de old_pos à new_pos
        float x = (a/(1+a*a))*((1/a)*target.x + target.y + a*old_pos.x - old_pos.y);
        float y = a*x - a*old_pos.x + old_pos.y;

        //Prejection 1e droite
        Proj_center ={x, y};
        x = sqrt((radius*radius)/(1+(a*a)));
        y = a*x;
        A = {Proj_center.x+x, Proj_center.y+y};
        B = {Proj_center.x-x, Proj_center.y-y};

        //Projection 2e cote
        x = (a/(1+a*a))*((1/a)*new_pos.x + a*target.x + new_pos.y - target.y);
        y = a*x - a*target.x + target.y;
        Proj_center2 = {x, y};

        y = sqrt((radius*radius)/(1+(a*a)));
        x = -a*y; //Ou x = a*y ??
        C = {Proj_center2.x - x, Proj_center2.y - y};
        D = {Proj_center2.x + x, Proj_center2.y + y};

        sf::Vector2f AB = B-A;
    if(prod_scal2(old_pos, AB)/norm2(AB) < 1 & prod_scal2(AB, new_pos)/norm2(AB) > 1 & prod_scal2(new_pos, D-C)/norm2(D-C)>1 & prod_scal2(new_pos, D-C)/norm2(D-C) < 1 ){
        val = true;
        printf("norm target - center < radius \n");
    }
    else{
        val = false;
    }

    }

    sf::Sprite A_1;
    textureA_.loadFromFile("../repository/Images/A.png");
    A_1.setTexture(textureA_);
    scaleToMinSize(A_1);
    SetOriginToCenterSprite(A_1);
    A_1.setPosition(C);

    return val;
    

} */ 