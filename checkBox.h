#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <functional>

class CheckBox
{
public:
	CheckBox(sf::String);
	CheckBox();

	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Text text;
	sf::IntRect rectSourseFile;
	bool isActive;
	std::function<void(void)> function = [](){};

	void setFunction(std::function<void(void)>func);
	void draw();
	void setTexture(bool);
	void setPosition(int, int);
	void setState();
	bool check();
};
