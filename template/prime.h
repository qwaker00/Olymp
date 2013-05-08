#pragma once
#include "base.h"
#include "numeric.h"
#include <vector>

namespace qwaker {

bool __miller_rabin_check(uint a, uint x, uint t, uint s) {
    if (a % x == 0) return true;
    ULL y = pow_mod(a, t, x);
    if (y == 1 || y == x - 1) return true;
    while (s > 1) {
        y = (y * y) % x;
        if (y == 1) return false;
        if (y == x - 1) return true;
        --s;
    }
    return false;
}

bool __lmiller_rabin_check(ULL a, ULL x, ULL t, ULL s) {
    if (a % x == 0) return true;
    ULL y = lpow_mod(a, t, x);
    if (y == 1 || y == x - 1) return true;
    while (s > 1) {
        y = lmul_mod(y, y, x);
        if (y == 1) return false;
        if (y == x - 1) return true;
        --s;
    }
    return false;
}

bool is_prime(uint x) {
    if (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 ||  x == 61) return true;
    if (x == 1 || (x & 1) == 0 || (x % 3) == 0 || (x % 5) == 0 || (x % 7) == 0 || (x % 11) == 0 || (x % 61) == 0) return false;

    uint s = 0, d = x - 1;
    while ((d & 1) == 0) ++s, d >>= 1;

    return __miller_rabin_check(2, x, d, s) && __miller_rabin_check(7, x, d, s) && __miller_rabin_check(61, x, d, s);
}

bool lis_prime(ULL x) {
    if (x == 2 || x == 3 || x == 5 || x == 7 || x == 11 ||  x == 61) return true;
    if (x == 1 || (x & 1) == 0 || (x % 3) == 0 || (x % 5) == 0 || (x % 7) == 0 || (x % 11) == 0 || (x % 61) == 0) return false;

    ULL s = 0, d = x - 1;
    while ((d & 1) == 0) ++s, d >>= 1;

    return __lmiller_rabin_check(2, x, d, s) &&     __lmiller_rabin_check(325, x, d, s) &&      __lmiller_rabin_check(9375, x, d, s) &&
           __lmiller_rabin_check(28178, x, d, s) && __lmiller_rabin_check(450775, x, d, s) &&   __lmiller_rabin_check(9780504, x, d, s) && 
           __lmiller_rabin_check(1795265022, x, d, s);
}

std::vector<bool> sieve(uint n) {
    std::vector<bool> pr(n + 1, true);
    pr[0] = pr[1] = false;
    for (uint j = 4; j <= n; j += 2) pr[j] = false;
    for (uint i = 3; i * i <= n; i += 2) if (pr[i]) {
        for (uint j = i * i; j <= n; j += i) pr[j] = false;
    }
    return pr;
}

std::vector<uint> list_primes(uint n) {
    std::vector<bool> pr(sieve(n));
    std::vector<uint> primes;
    for (uint i = 2; i <= n; ++i) if (pr[i]) primes.push_back(i);
    return primes;
}

}
