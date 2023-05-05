//
// Created by Maks Krywionek on 02/05/2023.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <iostream>
#include "Vec2.h"


class GameObject {
public:
    virtual void draw() = 0;

    virtual void printPos();

    virtual Vec2<int> getPos() const;
    virtual void setPos(Vec2<int> pos);

    virtual int getPosX() const;
    virtual int getPosY() const;

    virtual void setPosX(int x);
    virtual void setPosY(int y);

private:
    Vec2<int> pos;
};


#endif //GAME_GAMEOBJECT_H
