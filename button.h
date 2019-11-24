#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
public:
	//Button(sf::String, sf::Texture* );
	Button(sf::String);
	Button::Button();

	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Text text;
	std::function<void(void)> function = [](){};

	void setFunction(std::function<void(void)>func);
	void draw();
	void setTexture(sf::Texture);
	void setTexture();
	void setPosition(int, int);
	bool check();
};

