#include "Game.h"
#include <iostream>

void Game::Play()
{
	char c = 'a';
	while (true) {
		this->View();
		this->Analiza();
		std::cout << "Type q to quit or anything to continue" << std::endl;
		std::cin >> c;
		
		if (c == 'q')
			break;
	}
}
