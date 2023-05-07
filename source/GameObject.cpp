//
// Created by Maks Krywionek on 02/05/2023.
//

#include "../headers/GameObject.h"


Vec2<int> GameObject::getPos() const {
    return this->pos;
}
void GameObject::setPos(Vec2<int> pos) {
    this->pos = pos;
}


