#ifndef UTIL_H
#define UTIL_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>

void scaleToMaxSize(sf::Sprite &object); //Scale a sprite
void scaleToMinSize(sf::Sprite &object); //Scale a sprite
void scaleByRadius(sf::Sprite &object, float radius); //Scale a sprite according to a radius
void SetOriginToCenter(sf::Shape &object); //Set the origins of shape to it center
void SetOriginToCenterSprite(sf::Sprite &object);
void SetOriginToCenterText(sf::Text &object);
float norm2(sf::Vector2f v1);
float prod_scal2(sf::Vector2f v1, sf::Vector2f v2);

#endif