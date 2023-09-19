#include "GameTxt.h"
#include <iostream>

void GameTxt::View()
{
	for (int i = 0; i < this->getHeigth(); i++)
	{
		for (int j = 0; j < this->getWidth(); j++)
		{
			if (this->getMapPos(j, i))
				std::cout << "1 ";
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
	}

}
