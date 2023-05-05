//
// Created by Maks Krywionek on 02/05/2023.
//

#include "../headers/GameObject.h"

int GameObject::getPosX() const {
    return this->pos.getX();
}
int GameObject::getPosY() const {
    return this->pos.getY();
}
Vec2<int> GameObject::getPos() const {
    return this->pos;
}
void GameObject::setPos(Vec2<int> pos) {
    this->pos = pos;
}
void GameObject::setPosX(int x) {
    this->pos.setX(x);
}
void GameObject::setPosY(int y) {
    this->pos.setY(y);
}

void GameObject::printPos() {
    std::cout << "x: " << this->getPosX() << " y: " << this->getPosY() << std::endl;
}

