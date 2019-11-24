#include <iostream>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ResHolder
{
public:
	sf::Texture button;
	sf::Texture menuBackGroundTexture;
	sf::Texture checkBox;
	sf::Texture locations[5];
	sf::Texture skirmishMenuBackGround;

	sf::Music track;

	sf::Font font;

	void loadResourses();
};

extern ResHolder resHolder;
