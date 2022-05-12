#ifndef INC_GameLOGIC_H
#define INC_GameLOGIC_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include "CheckPoint.h"
#include "pod.h"
#include <queue>
using namespace std;

const unsigned int NUMBER_OF_LAPS = 3;
const float FRICTION_COEFF = 0.85;
const float ROTA_MAX = M_PI/10.;
const sf::Time PHYSICS_TIME_STEP = sf::milliseconds(100);
const std::string IMAGES_PATH = "../repository/Images/";
const std::string FONT_PATH = "../repository/";

class Game : public sf::Drawable
{
    public :
    Game(); //create a Game with 2 to 8 checkpoints at random positions (they shouldn't overlap)
    Game(std::vector<sf::Vector2f> checkpointsPositions); //create a Game with predefined checkpoints positions

    void addPod(); //can add various arguments here to chose the apparence or the decision making type of the pod
    void updatePhysics();
    void updateGraphics(sf::Time frameTime); //changes pods sprites positions and rotations depending on the frame time
    bool is_reached(sf::Vector2f new_pos, sf::Vector2f target, sf::Vector2f old_pos); //True if pod reached target

    // private :
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Texture backgroundTexture_;
    sf::Sprite backgroundSprite_;
    sf::Sprite A_;
    sf::Texture textureA_;
    /* sf::Sprite B_;
    sf::Texture textureB_;
    sf::Sprite C_;
    sf::Texture textureC_;
    sf::Sprite D_;
    sf::Texture textureD_; */

    std::vector<Pod> pods_;
    std::vector<sf::Texture> podsTextures_;
    std::vector<sf::Sprite> podsSprites_;

    FinalCheckPoint finalCP_;
    std::vector<CheckPoint> otherCPs_;

    sf::Time lastFrameTime;
    sf::Time physicsTime;   
    int targ = 0;
};

#endif