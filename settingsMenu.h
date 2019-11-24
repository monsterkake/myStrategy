#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

class SettingsMenu
{
public:
	SettingsMenu();

	void drawInterface();
	void updateWidgets();
	void createWidgets();
	void draw();
	void handleEvents();
};
