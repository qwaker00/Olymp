#pragma once

#include "base.h"
#include <utility>

namespace qwaker {

template<typename T>
class complex {
public:
    T x, y;

    complex(T x = T(), T y = T()) : x(x), y(y) { }
    complex(std::pair<T, T> coords) : x(coords.first), y(coords.second) { }

    complex operator+(const complex& b) const {
        return complex(x + b.x, y + b.y);
    }
    complex& operator+=(const complex& b) const {
        x += b.x;
        y += b.y;
        return *this;
    }
    complex operator-(const complex& b) const {
        return complex(x - b.x, y - b.y);
    }
    complex& operator-=(const complex& b) const {
        x -= b.x;
        y -= b.y;
        return *this;
    }
    complex operator*(const T& b) const {
        return complex(x * b, y * b);
    }
    complex& operator*=(const T& b) const {
        x *= b;
        y *= b;
        return *this;
    }
    T length() const {
        return sqrtl(x * x + y * y);
    }
    T sqlength() const {
        return x * x + y * y;
    }
};

}