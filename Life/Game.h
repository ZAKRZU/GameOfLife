#pragma once
#include "Engine.h"

class Game :
    public Engine
{
protected:
    Game() : Engine() {}
    virtual ~Game() {}
public:
    void Play();
    virtual void View() {}
};

