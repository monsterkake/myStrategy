#include "menu.h"
#include "game.h"
#include "button.h"
#include "checkBox.h"
#include "resHolder.h"

//Button exitButton("Exit", &resHolder.button);
Button exitButton("Exit");
Button skirmishButton("Skirmish");
Button SettingsMenuButton("Settings");

Menu::Menu()
{
	createWidgets();
}

void end(){ game.setState("0"); game.closeWindow(); }
void skirmish(){ game.setState(SKIRMISHSETUP); }
void SettingsMenu(){ game.setState(SETTINGSMENU); }

void Menu::createWidgets()
{
	exitButton.setTexture();
	exitButton.setPosition(game.m_window.getSize().x / 2 - exitButton.sprite.getLocalBounds().width / 2, game.m_window.getSize().y / 2 + 300);
	exitButton.setFunction(end);

	skirmishButton.setTexture();
	skirmishButton.setPosition(game.m_window.getSize().x / 2 - exitButton.sprite.getLocalBounds().width / 2, game.m_window.getSize().y / 2 + 180);
	skirmishButton.setFunction(skirmish);

	SettingsMenuButton.setTexture();
	SettingsMenuButton.setPosition(game.m_window.getSize().x / 2 - exitButton.sprite.getLocalBounds().width / 2, game.m_window.getSize().y / 2 + 240);
	SettingsMenuButton.setFunction(SettingsMenu);

	backGroundTexture.setTexture(resHolder.menuBackGroundTexture); //its not a widget, but i don't care
}

void Menu::updateWidgets()
{
	exitButton.setPosition(game.m_window.getSize().x / 2 - exitButton.sprite.getLocalBounds().width / 2, game.m_window.getSize().y / 2 + 300);
}

void Menu::drawMenu()
{
	game.m_window.clear();
	game.drawElement(backGroundTexture);
	skirmishButton.draw();
	SettingsMenuButton.draw();
	exitButton.draw();
	game.m_window.display();
}

void Menu::handleEvents()
{
	while (game.m_window.pollEvent(game.event))
	{
		switch (game.event.type)
		{
		case sf::Event::Closed:
			game.closeWindow();
			break;

		case sf::Event::MouseButtonPressed:
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				exitButton.check();
				skirmishButton.check();
				SettingsMenuButton.check();
			}
			break;

		case sf::Event::KeyPressed:
			if (game.event.key.code == sf::Keyboard::Q)
			{
				game.setState("0");
				game.closeWindow();
			}
			break;

		default: break;
		}
	}
}


