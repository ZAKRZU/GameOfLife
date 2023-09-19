#pragma once

class Engine
{
private:
	bool** m_map, **m_tmpMap;
	int m_width;
	int m_heigth;

	int Lives(int x, int y);
	bool getMapTmpPos(int x, int y);
protected:
	void Analiza();
	Engine();
	~Engine();
	void Init();
public:
	bool getMapPos(int x, int y);
	int getWidth();
	int getHeigth();
};

