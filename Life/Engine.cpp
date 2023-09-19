#include "Engine.h"
#include <iostream>
#include <fstream>
#include <string>

void Engine::Analiza()
{
	for (int i = 0; i < this->getHeigth(); i++)
	{
		for (int j = 0; j < this->getWidth(); j++)
		{
			this->m_tmpMap[i][j] = this->m_map[i][j];
			this->m_map[i][j] = false;
		}
	}

	for (int i = 0; i < this->getHeigth(); i++)
	{
		for (int j = 0; j < this->getWidth(); j++)
		{
			int lives = this->Lives(j, i);
			bool live = this->getMapTmpPos(j, i);
			if (!live) {
				if (lives == 3)
					live = true;
			}
			
			if (live) {
				if (lives < 2 || lives > 3)
					live = false;
			}
			this->m_map[i][j] = live;
		}
	}
}

int Engine::Lives(int x, int y)
{
	int start_x = x - 1;
	int start_y = y - 1;
	int lives = 0;
	for (int i = 0; i < 3; i++)
	{
		start_x = x - 1;
		if (start_y < 0)
		{
			start_y += 1;
			continue;
		}
		if (start_y > this->getHeigth() - 1)
			break;

		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j== 1)
			{
				start_x += 1;
				continue;
			}
			if (start_x < 0)
			{
				start_x += 1;
				continue;
			}
			if (start_x > this->getWidth() - 1)
				break;
			if (this->getMapTmpPos(start_x, start_y))
				lives++;
			start_x += 1;
		}
		start_y += 1;
	}

	return lives;
}

bool Engine::getMapTmpPos(int x, int y)
{
	if ((x < 0 || x > this->getWidth()) &&
		(y < 0 || y > this->getHeigth()))
		return 0;
	return this->m_tmpMap[y][x];
}

Engine::Engine()
{
	this->m_heigth = 10;
	this->m_width = 10;
	this->Init();
}

Engine::~Engine()
{
	for (int i = 0; i < this->m_heigth; i++)
	{
		delete[] this->m_map[i];
	}
	delete[] this->m_map;
}

void Engine::Init()
{
	std::ifstream file;
	file.open("map.txt", std::ios::out);
	std::string line;
	if (file.is_open()) {
		this->m_heigth = 0;
		while (std::getline(file, line)) {
			this->m_heigth++;
			this->m_width = line.size();
		}

		file.clear();
		file.seekg(0, std::ios::beg);
	}


	this->m_map = new bool*[this->m_heigth];
	this->m_tmpMap = new bool* [this->m_heigth];
	for (int i = 0; i < this->m_heigth; i++)
	{
		if (file.is_open())
			std::getline(file, line);
		this->m_map[i] = new bool[this->m_width];
		for (int j = 0; j < this->m_width; j++)
		{
			if (file.is_open()) {
				if (line[j] == '1')
					this->m_map[i][j] = true;
				else
					this->m_map[i][j] = false;
			}
			else {
				this->m_map[i][j] = false;
			}
		}
	}

	if (file.is_open())
		file.close();

	for (int i = 0; i < this->m_heigth; i++)
	{
		this->m_tmpMap[i] = new bool[this->m_width];
		for (int j = 0; j < this->m_width; j++)
		{
			this->m_tmpMap[i][j] = false;
		}
	}
}

bool Engine::getMapPos(int x, int y)
{
	if ((x < 0 || x > this->getWidth()) &&
		(y < 0 || y > this->getHeigth()))
		return 0;
	return this->m_map[y][x];
}

int Engine::getWidth()
{
	return this->m_width;
}

int Engine::getHeigth()
{
	return this->m_heigth;
}
