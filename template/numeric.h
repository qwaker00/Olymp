#pragma once
#include "base.h"


namespace qwaker {

ULL lmul_mod(ULL x, ULL y, ULL m) {
    ULL r = 0;
    while (y > 0) {
        if (y & 1) r = (r + x) % m;
        x = (x + x) % m;
        y >>= 1;
    }
    return r;
}                

inline ULL mul_mod(ULL x, ULL y, ULL m) {
    return (x * y) % m;
}

ULL pow_mod(ULL x, ULL y, ULL m) {
    ULL r = 1;
    while (y > 0) {
        if (y & 1) r = (r * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return r;
}

ULL lpow_mod(ULL x, ULL y, ULL m) {
    ULL r = 1;
    while (y > 0) {
        if (y & 1) r = lmul_mod(r, x, m);
        x = lmul_mod(x, x, m);
        y >>= 1;
    }
    return r;
}

}
