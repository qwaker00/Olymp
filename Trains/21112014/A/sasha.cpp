#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

int T, J1, J2, B1, B2;

ll pnum, dnum, den;

ll len(ll miv, ll mav) {
	if (miv > mav) return 0;
	return mav - miv + 1;
}
ll have(ll x, ll y) {
	if (x >= J1 && x <= J2 && y >= B1 && y <= B2) {
		return 1;
	}
	return 0;
}

void doit() {
	den = len(J1, J2) * len(B1, B2);
	pnum = dnum = 0; 
	ll h42 = have(4,2), h24 = have(2, 4);
	pnum += have(3, 2);
	if (B1 <= 1) {
		pnum += len(max(2, J1), J2);
	} 

	// draw
	dnum = dnum + h42 + h24;
	ll lower = max(J1, B1), upper = min(J2, B2);
	if (lower <= upper) {
		dnum += len(lower, upper);
	}	
	// win
	if (2 >= J1 && 2 <= J2) pnum += len(5, B2);
	J1 = max(J1, 3);
	if (B1 > J2) {
		pnum += len(B1, B2) * len(J1, J2);	
		return;
	}
	if (B2 < J1) return;
	B1 = max(B1, J1);
	ll outlen = len(J2  + 1, B2);
	pnum += outlen * len(J1, J2);
	B2 = min(B2, J2);
	J2 = min(B2, J2);

	pnum += len(J1, B1 - 1) * len(B1, B2);
	J1 = max(J1, B1);
	pnum += (len(J1, J2) * len(J1, J2) - len(J1, J2)) / 2;

}

ll gcd(ll x, ll y) {
	while (x && y)
		if (x > y) x %= y;
		else y %= x;
	return x + y;
}

void solve() {
	//cout << J1 << " " << J2 << " " << B1 << " " << B2 << ": ";
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