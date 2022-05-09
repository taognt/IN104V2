#include "util.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>
#include <cstdio>
#include <math.h>
// Set a sprite object to Max or Min size

void scaleToMinSize(sf::Sprite &object){
    float xmin = 200;
    float ymin = 200;
    auto rec = object.getGlobalBounds();
    float x = rec.width;
    float y = rec.height;
    float e = y/x;
    float new_x = xmin/x; float new_y = ymin/x;


    if(x<y){
    e = new_x;
    //object.setScale(sf::Vector2f(new_x, e*new_x));
    object.setScale(sf::Vector2f(e, e));
    
    }

    else{
        e = new_y;
        //object.setScale(sf::Vector2f(new_y/e, new_y));
        object.setScale(sf::Vector2f(e, e));
    }
}
void scaleToMaxSize(sf::Sprite &object){
    float xmin = 800;
    float ymin = 800;
    auto rec = object.getGlobalBounds();
    float x = rec.width;
    float y = rec.height;
    float e = y/x;
    float new_x = xmin/x; float new_y = ymin/x;


    if(x<y){
    e = new_x;
    //object.setScale(sf::Vector2f(new_x, e*new_x));
    object.setScale(sf::Vector2f(e, e));
    
    }

    else{
        e = new_y;
        //object.setScale(sf::Vector2f(new_y/e, new_y));
        object.setScale(sf::Vector2f(e, e));
    }
}

void scaleByRadius(sf::Sprite &object, float radius){
    auto rec = object.getGlobalBounds();
    float x = rec.width; float y = rec.height;
    float e = y/x;
    float x2 = sqrt( (pow(radius,2)) / (1+pow(e,2)));
    object.setScale(sf::Vector2f(x2/x, x2*e/y));
}

//----------------------------------------------------

void SetOriginToCenter(sf::Shape &object){
    auto rec = object.getGlobalBounds();
    object.setOrigin(rec.width/2., rec.height/2.);
} 

void SetOriginToCenterSprite(sf::Sprite &object){
    auto rec = object.getGlobalBounds();
    object.setOrigin(rec.width/2., rec.height/2.);
} 

//---Norme d'un vecteur

float norm2(sf::Vector2f v1){
    return(sqrt(v1.x*v1.x + v1.y*v1.y));
}