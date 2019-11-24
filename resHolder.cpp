#include "resHolder.h"
#include <fstream>
#include <string>

ResHolder resHolder;

void ResHolder::loadResourses()
{
	button.loadFromFile("resourses/button_1.png");
	checkBox.loadFromFile("resourses/checkBox.png");
	menuBackGroundTexture.loadFromFile("resourses/backGround_1.jpg");
	skirmishMenuBackGround.loadFromFile("resourses/backGround_2.jpg");
	track.openFromFile("resourses/AaronSmithDancin.ogg");
	font.loadFromFile("resourses/ALGER.TTF");
	std::cout << "resourses loaded" << std::endl;
}
