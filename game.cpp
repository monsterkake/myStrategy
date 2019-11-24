#include "game.h"
#include "menu.h"
#include "draw.h"
#include "resHolder.h"
#include "button.h"
#include "checkBox.h"
#include "skirmishSetUp.h"
#include "settings.h"
#include "SettingsMenu.h"

Game::Game()
{
	setScreenMode();
}

void Game::setScreenMode()
{
	if (settings.isFullScreen)
		m_window.create(sf::VideoMode(), "main", sf::Style::Fullscreen);
	else 
		m_window.create(sf::VideoMode(1024, 920), "main");
}

void Game::setFullScreenMode()
{
	m_window.create(sf::VideoMode(), "main", sf::Style::Fullscreen);
}

void Game::setWindowedMode()
{
	m_window.create(sf::VideoMode(1024,920), "main");
}

void Game::closeWindow()
{
	m_window.close();
}

void Game::playMusic()
{
	resHolder.track.play();
	resHolder.track.setVolume(0);
	resHolder.track.setLoop(true);
}

void Game::drawElement(sf::Sprite sprite)
{
	m_window.draw(sprite);
}

void Game::drawElement(sf::Text text)
{
	m_window.draw(text);
}

void Game::drawElement(sf::RectangleShape rect)
{
	m_window.draw(rect);
}

void Game::handleEvents()
{
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Q)
			{
				game.setState("0");
				game.closeWindow();
			}

		case sf::Event::MouseButtonPressed:
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

			}
			break;

		default: break;
		}
	}
}

void Game::setState(sf::String state)
{
	this->state = state;
}

void Game::mainLoop()
{
	while (m_window.isOpen())
	{
		if (game.state == MENU)
		{
			Menu menu;
			while (game.state == MENU)
			{
				menu.drawMenu();
				menu.handleEvents();
			}
		}
		if (game.state == SETTINGSMENU)
		{
			SettingsMenu settingsMenu;
			while (game.state == SETTINGSMENU)
			{
				settingsMenu.draw();
				settingsMenu.handleEvents();
			}
		}
		if (game.state == SKIRMISHSETUP)
		{
			SkirmishSetUp skirmishSetUp;
			while (game.state == SKIRMISHSETUP)
			{
				skirmishSetUp.draw();
				skirmishSetUp.handleEvents();
			}
		}
		if (game.state == SKIRMISH)
		{

		}
	}	
}

Game game;
