#ifndef INC_GameLOGIC_H
#define INC_GameLOGIC_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <cmath>
#include "CheckPoint.h"
#include "pod.h"
using namespace std;

const unsigned int NUMBER_OF_LAPS = 1;
const float RADIUS = 850;
const float FRICTION_COEFF = 0.85;
const float ROTA_MAX = M_PI/10.;
const sf::Time PHYSICS_TIME_STEP = sf::milliseconds(100);
const std::string IMAGES_PATH = "../repository/Images/";
const std::string FONT_PATH = "../repository/";
const int max_list = 1;
const int MAX_POD = 4;

class Game : public sf::Drawable
{
    public :
    Game(); //create a Game with 2 to 8 checkpoints at random positions (they shouldn't overlap)
    Game(std::vector<sf::Vector2f> checkpointsPositions, int IA, int Keyboard); //create a Game with predefined checkpoints positions

    void addPod(); //can add various arguments here to chose the apparence or the decision making type of the pod
    void updatePhysics();
    void updateGraphics(sf::Time frameTime); //changes pods sprites positions and rotations depending on the frame time
    bool is_reached(sf::Vector2f new_pos, sf::Vector2f target, sf::Vector2f old_pos); //True if pod reached target
    void updateAdders(sf::Vector2i localPosition); //update the adders relatively to the <indow PLAY
    void is_finished_run(); //set finish to 1 et 0 if the pod have finished the run
    void reset_finish(); //reset the finish test 
    int nb_pod; //Nb pod already placed

    // private :
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Texture backgroundTexture_;
    sf::Sprite backgroundSprite_;

    std::vector<Pod> pods_;
    std::vector<sf::Texture> podsTextures_;
    std::vector<sf::Sprite> podsSprites_;

    FinalCheckPoint finalCP_;
    std::vector<CheckPoint> otherCPs_;
    std::vector<sf::Vector2f> cpPositions;

    //Settings
    int IA;
    int Keyboard;

    sf::Time lastFrameTime;
    sf::Time physicsTime;   
    int targ = 0;

    //adders
    sf::Font font;
    sf::Text Game_List[max_list];
};

#endif