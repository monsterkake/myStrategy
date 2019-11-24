#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

class SkirmishSetUp
{
public:
	sf::Sprite backGround;

	SkirmishSetUp();
	void draw();
	void drawInterface();
	void updateWidgets();
	void createWidgets();
	void handleEvents();
};

