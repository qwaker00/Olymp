#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const int MOD = 1000000009;

const int N = 211;
int f[N][N][N];
int n, r, d;

inline double sqr(double x) {
	return x * x;
}


vector<double> Cx, Cy;
vector<double> ups, downs;

ll fact[N], pow2[N];
ll C[N][N];
double su[N][N], sd[N][N];

void relax(int& x, ll y) {
	x = (x + (y % MOD)) % MOD;
}

double ul[N], ur[N];
double dl[N], dr[N];

int needl[N], needr[N];

void getCenter(double r, double ang, double& cx, double& cy) {
	double l = r * ang;

	double X = cos(ang) * r;
	double Y = sin(ang) * r;
	double C = sqrt(sqr(X - r) + sqr(Y));
	double dy = (2. * r * C) / (3. * l);

	cx = dy * cos(ang / 2.);
	cy = dy * sin(ang / 2.);
}

int main() {
	//freopen("in", "r", stdin);

	cin >> n >> r >> d;	
	
	double cx = 0, cy = 0;

	double ang = (PI + PI) / n;
	getCenter(r, ang, cx, cy);

	Cx.push_back(cx);
	Cy.push_back(cy);
	for (int i = 1; i < n; ++i) {
		double fx = Cx.back(), fy = Cy.back();
		Cx.push_back(fx * cos(ang) - fy * sin(ang));
		Cy.push_back(fx * sin(ang) + fy * cos(ang));
	}

	double whole = 0;
	for (int i = 0; i < n; ++i) {
		if (Cy[i] >= -d) ups.push_back(Cy[i] + d);
		else downs.push_back(Cy[i] + d); 
		whole += Cy[i] + d;
	}

	fact[0] = 1;
	pow2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (fact[i - 1] * i) % MOD;
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	}
	for (int i = 0; i <= n; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < n; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;	
		}
	}

	if (downs.size() == 0) {
		cout << fact[n] << endl;
		return 0;
	}

	ul[1] = ups[0];
	ur[1] = ups.back();
	for (int i = 2; i <= ups.size(); ++i) {
		ul[i] = ups[i - 1] + ul[i - 1];
		ur[i] = ups[ ups.size() - i ] + ur[i - 1];
	}
	dl[1] = downs[0];
	dr[1] = downs.back();
	for (int i = 2; i <= downs.size(); ++i) {
		dl[i] = downs[i - 1] + dl[i - 1];
		dr[i] = downs[ downs.size() - i ] + dr[i - 1];
	}

	double wholedown = dl[ downs.size() ];
	for (int x = 0; x < downs.size(); ++x) {
		int dleft = x;
		int dright = downs.size() - x - 1;

		relax(f[x][x][1], 1);

		for (int i = 0; i < ups.size(); ++i)
			if (whole - ups[i] >= 0) {
				relax(f[n][n][1], 1);
			}
	}

	for (int r = 0; r <= downs.size(); ++r) {
		double sum = dr[r];
		needr[r] = ups.size();
		for (int i = 0; i < ups.size(); ++i) {
			if (sum >= 0) {
				needr[r] = i;
				break;
			}
			sum += ups[ups.size() - i - 1];
		}
	}
	for (int l = 0; l <= downs.size(); ++l) {
		double sum = dl[l];
		needl[l] = ups.size();
		for (int i = 0; i < ups.size(); ++i) {
			if (sum >= 0) {
				needl[l] = i;
				break;
			}
			sum += ups[i];
		}
	}
	for (int i = 0; i < downs.size(); ++i) {
		sd[i][i] = downs[i];
		for (int j = i + 1; j < downs.size(); ++j) {
			sd[i][j] = sd[i][j - 1] + downs[j];
		}
	}

	for (int k = 1; k < n; ++k) {
		
		
		for (int l = 0; l < downs.size(); ++l)
			for (int r = l; r < downs.size(); ++r)
				if (f[l][r][k]) {
					
				}

		
	}

	for (int len = 1; len <= downs.size(); ++len)
		for (int l = 0; l + len <= downs.size(); ++l) {
			int r = l + len - 1;

			int possible = ups.size();
			if (l) {
				possible -= needl[l];
			}
			if (r + 1 < downs.size()) {
				possible -= needr[downs.size() - r - 1];
			}
			for (int k = 0; k < possible; ++k) {
				relax(f[l][r][len + k + 1], (ll(f[l][r][len + k]) * (possible - k)) % MOD);
			}

			for (int k = 0; k <= possible; ++k) {
				if (l) {
					relax(f[l - 1][r][len + k + 1], f[l][r][len + k]);
				}
				if (r + 1 < downs.size()) {
					relax(f[l][r + 1][len + k + 1], f[l][r][len + k]);
				}
			}
		}

        /*
	for (int i = 0; i < downs.size(); ++i)
		for (int j = i; j < downs.size(); ++j)
			for (int k = 0; k <= n; ++k)
				if (f[i][j][k]) {
					cerr << i << " " << j << " " << k << ": " << f[i][j][k] << endl;
				}	
                */
		

	cout << f[0][downs.size() - 1][n] << endl;

	return 0;
}
