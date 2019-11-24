#include "game.h"
#include "button.h"
#include "checkBox.h"
#include "resHolder.h"
#include "skirmishSetUp.h"

Button startButton("Start");

SkirmishSetUp::SkirmishSetUp()
{
	backGround.setTexture(resHolder.skirmishMenuBackGround);
	createWidgets();
}

void SkirmishSetUp::draw()
{
	game.m_window.clear();
	game.drawElement(backGround);
	startButton.draw();
	game.m_window.display();
}

void start(){ game.setState(SKIRMISH); }

void SkirmishSetUp::createWidgets()
{
	startButton.setTexture();
	startButton.setPosition(game.m_window.getSize().x - 200, game.m_window.getSize().y - 100);
	startButton.setFunction(start);

	backGround.setTexture(resHolder.skirmishMenuBackGround);
}
void SkirmishSetUp::updateWidgets()
{

}
void SkirmishSetUp::handleEvents()
{
	while (game.m_window.pollEvent(game.event))
	{
		switch (game.event.type)
		{
		case sf::Event::KeyPressed:
			if (game.event.key.code == sf::Keyboard::Q)
			{
				game.setState("0");
				game.closeWindow();
			}

		case sf::Event::MouseButtonPressed:
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				startButton.check();
			}
			break;

		default: break;
		}
	}
}
void SkirmishSetUp::drawInterface()
{

}
