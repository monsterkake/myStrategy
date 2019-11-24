#include "SettingsMenu.h"
#include "resHolder.h"
#include "game.h"
#include "button.h"
#include "checkBox.h"
#include "settings.h"

Button backButton("Back");
CheckBox fullScreenCheckBox("Fullscreen");

SettingsMenu::SettingsMenu()
{
	createWidgets();
} 

void toMenu(){ game.setState(MENU); }

void changeScreenMode()
{
	settings.isFullScreen = !settings.isFullScreen;
	game.setScreenMode();
	game.setState(MENU);
} 

void SettingsMenu::updateWidgets()
{
	backButton.setPosition(game.m_window.getSize().x - 200, game.m_window.getSize().y - 100);
	fullScreenCheckBox.setPosition(100, 300);
}

void SettingsMenu::createWidgets()
{
	backButton.setTexture();
	backButton.setPosition(game.m_window.getSize().x -200 , game.m_window.getSize().y - 100);
	backButton.setFunction(toMenu);

	fullScreenCheckBox.setTexture(settings.isFullScreen);
	fullScreenCheckBox.setPosition(100, 300);
	fullScreenCheckBox.setFunction(changeScreenMode);
}
void SettingsMenu::handleEvents()
{
	while (game.m_window.pollEvent(game.event))
	{
		switch (game.event.type)
		{
		case sf::Event::KeyPressed:
			if (game.event.key.code == sf::Keyboard::Q)
				game.closeWindow();
		case sf::Event::MouseButtonPressed:
			fullScreenCheckBox.check();
			backButton.check();
			break;
		deafult: break;
		}
	}
}

void drawBG()
{
	sf::Text text;
	text.setFont(resHolder.font);
	text.setCharacterSize(40);
	text.setOutlineThickness(2);
	text.setFillColor(sf::Color(200, 100, 50, 255));
	text.setString("SettingsMenu");
	text.setPosition(game.m_window.getSize().x / 2 - text.getLocalBounds().width / 2, 100);
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(float(game.m_window.getSize().x), game.m_window.getSize().y));
	rectangle.setPosition(sf::Vector2f(0, 0));
	rectangle.setFillColor(sf::Color(150, 120, 80, 255));
	game.drawElement(rectangle);
	game.drawElement(text);
}

void SettingsMenu::drawInterface()
{
	backButton.draw();
	fullScreenCheckBox.draw();
}

void SettingsMenu::draw()
{
	game.m_window.clear();
	drawBG();
	drawInterface();
	game.m_window.display();
}
