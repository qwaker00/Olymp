#pragma once
#include <cassert>

namespace qwaker {

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#ifdef DEBUG
    #define ASSERT(x) assert(x)
#else
    #define ASSERT(x) void()
#endif

}
