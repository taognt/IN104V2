#ifndef UTIL_H
#define UTIL_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>

void scaleToMaxSize(sf::Sprite &object);
void scaleToMinSize(sf::Sprite &object);
void scaleByRadius(sf::Sprite &object);
void SetOriginToCenter(sf::Shape &object);
void SetOriginToCenterSprite(sf::Sprite &object);

#endif