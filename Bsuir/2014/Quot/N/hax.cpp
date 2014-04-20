#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

struct TLong {
    vector<char> a;

    TLong(const vector<char>& v) : a(v) { }

    TLong(ULL x) {
        while (x) {
            a.push_back(x % 10);
            x /= 10;
        }
    }

    bool operator<(const TLong& b) const {
        if (b.a.size() != a.size()) return a.size() < b.a.size();
        for (int i = (int)a.size() - 1; i >= 0; --i)
            if (a[i] != b.a[i])
                return a[i] < b.a[i];
        return false;
    }

    TLong operator*(const ULL b) {
        ULL carry = 0;
        vector<char> c(a.size());
        for (int i = 0; i < (int)a.size(); ++i) {
            carry += b * a[i];
            c[i] = carry % 10;
            carry /= 10;
        }
        while (carry) {
            c.push_back(carry % 10);
            carry /= 10;
        }
        return c;
    }
};


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    ULL A, N, B, M;
    cin >> A >> N >> B >> M;
    TLong AA = TLong(A) * M;
    TLong BB = TLong(B) * N;
    if (AA < BB) {
        puts("Kolya");            
    } else
    if (BB < AA) {
        puts("Sasha");
    } else
        puts("SashaAndKolya");
    
    return 0;
}
