//
// Created by Maks Krywionek on 02/05/2023.
//

#ifndef GAME_VEC2_H
#define GAME_VEC2_H

#include <deque>

template <typename T>
class Vec2 {
public:
    Vec2() = default;
    constexpr Vec2(T x, T y) : x(x), y(y) {

    }
    static bool elementInDeque(Vec2<T> vec, std::deque<Vec2<T>> deque) {
        for(unsigned int i = 0; i < deque.size(); i++) {
            if(deque[i] == vec) {
                return true;
            }
        }
        return false;
    }

    constexpr T getX() const {return this->x;};
    constexpr T getY() const {return this->y;};
    constexpr void setX(T x) { this->x = x;};
    constexpr void setY(T y) { this->y = y;};

public:
    constexpr bool operator==(const Vec2& rhs) {
        return (x == rhs.x && y == rhs.y);
    }
    constexpr bool operator!=(const Vec2& rhs) {
        return !(*this == rhs);
    }
    constexpr Vec2 operator+(const Vec2& rhs) const {
        return {x + rhs.x, y + rhs.y};
    }
    constexpr Vec2 operator+(const int rhs) const{
        return {x + rhs, y + rhs};
    }
    constexpr Vec2& operator +=(const Vec2& rhs) {
        return *this = *this + rhs;
    }
    constexpr Vec2 operator-(const Vec2& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }
    constexpr Vec2 operator-(const int rhs) const {
        return {x - rhs, y - rhs};
    }
    constexpr Vec2& operator -=(const Vec2& rhs) {
        return *this = *this - rhs;
    }
    constexpr Vec2 operator*(const Vec2& rhs) const{
        return {x * rhs.x, y * rhs.y};
    }
    constexpr Vec2 operator*(const int rhs) const{
        return {x * rhs, y * rhs};
    }
    constexpr Vec2& operator *=(const Vec2& rhs) {
        return *this = *this * rhs;
    }

private:
    T x;
    T y;
};

#endif //GAME_VEC2_H
