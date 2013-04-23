#pragma once
#include "base.h"
#include <cstdlib>

namespace qwaker {

int rand32() {
    return (int(rand()) << 20) ^ (int(rand()) << 10) ^ int(rand());
}

LL rand64() {
    return (LL(rand32()) << 32) ^ LL(rand32());
}

uint randu32() {
    return (uint(rand()) << 20) ^ (uint(rand()) << 10) ^ uint(rand());
}

ULL randu64() {
    return (ULL(randu32()) << 32) ^ ULL(randu32());
}

bool flip_coin(const uint a, const uint b) {
    return randu32() % (a + b) < a;
}

int randint(int l, int r) {
    return randu32() % (r - l + 1) + l;
}

double randfloat() {
    return LD(randu64()) / (1ll << 32) / (1ll << 32);
}

}
