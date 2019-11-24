#include "resHolder.h"
#include "game.h"

int main()
{
	resHolder.loadResourses();
	game.playMusic();
	game.setScreenMode();
	game.setState("menu");

	game.mainLoop();

	return 0;
}
