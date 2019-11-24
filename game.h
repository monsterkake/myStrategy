#include <iostream>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define MENU "menu"
#define GAME "game"
#define SKIRMISHSETUP "skirmishSetUp"
#define SETTINGSMENU "SettingsMenu"
#define SKIRMISH "skirmish"

using namespace std;

class Game
{
public:
	sf::String state;
	sf::RenderWindow m_window;
	sf::Event event;
	sf::Music track;
	bool isFullscreen = true;

	Game();
	void playMusic();
	void mainLoop();
	void createWindow();
	void setState(sf::String);
	void closeWindow();
	void drawElement(sf::Sprite);
	void drawElement(sf::Text);
	void drawElement(sf::RectangleShape);	
	void setFullScreenMode();
	void setWindowedMode();
	void setScreenMode();
	void handleEvents();
};

extern Game game;

