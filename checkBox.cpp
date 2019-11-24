#include "checkBox.h"
#include "resHolder.h" 
#include "game.h"

CheckBox::CheckBox(sf::String string)
{
	text.setOutlineThickness(2);
	text.setFillColor(sf::Color(200, 100, 50, 255));
	text.setString(string);
	text.setCharacterSize(15);
	text.setScale(1, 1);
	text.setFont(resHolder.font);
}

CheckBox::CheckBox()
{
	text.setFont(resHolder.font);
	text.setScale(1, 1);
}

void CheckBox::setFunction(std::function<void(void)>func)
{
	function = func;
}

void CheckBox::draw()
{
	sprite.setPosition(position);

	game.drawElement(sprite);
	game.drawElement(text);
}

void CheckBox::setTexture(bool state)
{
	sprite.setTexture(resHolder.checkBox);
	if (state)
	sprite.setTextureRect(sf::IntRect(20, 0, 20, 20));
	else
		sprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
}

void CheckBox::setState()
{
	if (isActive)
		sprite.setTextureRect(sf::IntRect(20, 0, 20, 20));
	else
		sprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
	isActive = !isActive;
}

void CheckBox::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
	text.setPosition(x + 60 , y );
}

bool CheckBox::check()
{
	if (sprite.getGlobalBounds().contains(sf::Mouse::getPosition(game.m_window).x, sf::Mouse::getPosition(game.m_window).y))
	{
		setState();
		function();
		return true;
	}
		
	else return false;
}
