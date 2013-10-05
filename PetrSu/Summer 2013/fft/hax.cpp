#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <cassert>

#define PI 3.1415926535897932384626433832795

template<typename T>
class complex {
private:
    T x, y;

public:
    complex(T x = T(), T y = T()) : x(x), y(y) { }

    complex operator+(const complex& b) const {
        return complex(x + b.x, y + b.y);
    }
    complex& operator+=(const complex& b) {
        x += b.x;
        y += b.y;
        return *this;
    }
    complex operator-(const complex& b) const {
        return complex(x - b.x, y - b.y);
    }
    complex& operator-=(const complex& b) {
        x -= b.x;
        y -= b.y;
        return *this;
    }
    complex operator*(const T& b) const {
        return complex(x * b, y * b);
    }
    complex& operator*=(const T& b){
        x *= b;
        y *= b;
        return *this;
    }
    complex operator/(const T& b) const {
        return complex(x / b, y / b);
    }
    complex& operator/=(const T& b){
        x /= b;
        y /= b;
        return *this;
    }
    complex operator*(const complex& b) const {
        return complex(x * b.x - y * b.y, x * b.y + b.x * y);
    }
    complex& operator*=(const complex& b){
        return *this = *this * b;
    }
    T real() const {
        return x;
    }
    T img() const {
        return y;
    }
};

using namespace std;

typedef complex<double> cd;
typedef vector<cd> vcd;

struct FFT {
    #define ROOTS_SIZE 524288

    cd roots[ROOTS_SIZE];
    int rev[ROOTS_SIZE];

    FFT() : last_rev_n(0) {
        for (int i = 0; i < ROOTS_SIZE; i++) {
    		double alpha = 2 * PI * i / ROOTS_SIZE;
    		roots[i] = cd(cosl(alpha), sinl(alpha));
    	}
    }

 	int last_rev_n;

    void precalc_rev(int n) {
    	if (n == last_rev_n) return;
    	last_rev_n = n;
    	
    	int k = 0;
    	while ((1 << k) < n) k++;
    	rev[0] = 0;
    	int high1 = -1;
    	for (int i = 1; i < n; i++) {
    		if ((i & (i - 1)) == 0)
    			high1++;
    		rev[i] = rev[i ^ (1 << high1)];
    		rev[i] |= (1 << (k - high1 - 1));
    	}
    }

    vcd fft(const vcd &as, bool isrev = false) {
        assert(as.size() <= ROOTS_SIZE);
    	int n = as.size();
    	precalc_rev(n);
    	vcd cur(n);
    	for (int i = 0; i < n; i++) cur[i] = as[rev[i]];
    	for (int len = 1; len < n; len <<= 1) {
    		vcd ncur(n);
    		int rstep = ROOTS_SIZE / (len + len);
    		for (int pdest = 0; pdest < n;) {
    			int p1 = pdest;
    			for (int i = 0; i < len; i++) {
    				cd val = roots[i * rstep] * cur[p1 + len];
    				ncur[pdest] = cur[p1] + val;
    				ncur[pdest + len] = cur[p1] - val;
    				pdest++, p1++;
    			}
    			pdest += len;
    		}
    		cur.swap(ncur);
    	}
        if (isrev) {
            reverse(cur.begin() + 1, cur.end());
            for (size_t i = 0; i < cur.size(); ++i) cur[i] /= cur.size();
        }
    	return cur;
    }
} fft;


void tocd(const vector<int>& a, vcd& b) {
    size_t s = 1;
    while (s < a.size()) s += s;
    s += s;
    b.assign(s, cd());
    for (size_t i = 0; i < a.size(); ++i) b[i] = a[i];
}

int main() {
	int n, m;

    scanf("%d", &n);
	vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%d", &m);
	vector<int> b(m);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

    vcd aa, bb;
    tocd(a, aa);
    tocd(b, bb);
 	if (aa.size() < bb.size()) aa.resize(bb.size());
   	if (bb.size() < aa.size()) bb.resize(aa.size());
    aa = fft.fft(aa);
    bb = fft.fft(bb);
    for (size_t i = 0; i < aa.size(); ++i) aa[i] *= bb[i];
    aa = fft.fft(aa, true);
    a.resize(aa.size());
    for (size_t i = 0; i < aa.size(); ++i)
    	a[i] = round(aa[i].real());
	while (a.size() > 1 && a.back() == 0) a.pop_back();

    printf("%d\n", a.size());
    for (size_t i = 0; i < a.size(); ++i) printf("%d ", a[i]);
    puts("");
    
    return 0;
}
