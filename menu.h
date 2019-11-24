#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

class Menu{
public:
	sf::Texture texture;
	sf::Sprite backGroundTexture;

	Menu();
	void drawMenu();
	void updateWidgets();
	void createWidgets();
	void handleEvents();
};

