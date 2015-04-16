#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

int T, J1, J2, B1, B2;

ll pnum, dnum, den;

ll len(int miv, int mav) {
	if (miv > mav) return 0;
	return mav - miv + 1;
}
int have(int x, int y) {
	if (x >= J1 && x <= J2 && y >= B1 && y <= B2) {
		return 1;
	}
	return 0;
}

ll interlen(ll a1, ll a2, ll b1, ll b2) {
	return len(max(a1, b1), min(a2, b2));
}

bool done() {
	if (len(J1, J2) == 0) return true;
	if (len(B1, B2) == 0) return true;
	return false;
}

void doit() {
	den = len(J1, J2) * len(B1, B2);
	pnum = dnum = 0; 
	dnum = have(2,4) + have(4,2) + interlen(J1, J2, B1, B2);

    J1 = max(J1, 2);
    if (done()) return;
    if (B1 == 1) {
    	pnum += len(J1, J2);
    	B1 = 2;	
    	if (done()) return;
    }
    if (J1 == 2) {
    	pnum += interlen(5, B2, B1, B2);
    	J1 = 3;
    	if (done()) return;
    }
    if (B1 == 2) {
    	if (J1 == 3) ++pnum;
    	B1 = 3;
    	if (done()) return;
    }    
    assert(J1 >= 3 && B1 >= 3);
	
	pnum += interlen(J1, J2, 1, B1 - 1) * len(B1, B2);
	J1 = max(J1, B1);
	pnum += len(J1, J2) * interlen(J2 + 1, B2, B1, B2);

	ll L = max(J1, B1);
	ll R = min(J2, B2);
	ll add = len(L, R);
	pnum += (add * (add - 1)) / 2; 
}

ll gcd(ll x, ll y) {
	while (x && y)
		if (x > y) x %= y;
		else y %= x;
	return x + y;
}

void solve() {
//	cout << J1 << " " << J2 << " " << B1 << " " << B2 << ": ";
	doit();
	ll rnum = pnum;
	ll rden = den - dnum;
	ll mul = gcd(rnum, rden);
	rnum /= mul;
	rden /= mul;
	cout << rnum << "/" << rden << " " << rden - rnum << "/" << rden << endl;	
}

int main() {
//	freopen("in", "r", stdin);
    scanf("%d", &T);
    for (int it = 0; it < T; ++it) {
    	scanf("%d%d%d%d", &J1, &J2, &B1, &B2);
    	solve();
    }
    return 0;
}