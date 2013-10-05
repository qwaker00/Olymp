#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
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

const int N = 1111111;

int x[N], y[N], a[N], b[N];

struct cell {
	int x, dx;

	cell(int ax = 0, int adx = 0)
		:x(ax),
		dx(adx)
		{}

	bool operator <(const cell& A) const {
		return x < A.x || (x == A.x && dx < A.dx);
	}

	double get(double t) {
		return double(x) + t * double(dx);
	}
};

int nxt[N];
bool used[N];


void calc(vector<cell>& b, vector<double>& ans, vector<cell>& best) {
	if (b.size() == 0) return;	

	int n = b.size();
	sort(b.begin(), b.end());
	vector<cell> a;
    a.reserve(n);

    a.push_back(b.back());
    for (int i = n - 2; i >= 0; --i) {
    	if (b[i].dx > a.back().dx) {
    		a.push_back(b[i]);
    	}
    } 
    reverse(a.begin(), a.end());

    n = a.size();
    memset(used, 0, sizeof(used));

    priority_queue< pair<double, int> > q;
    for (int i = 0; i + 1 < a.size(); ++i) {
    	q.push( make_pair( -double(a[i + 1].x - a[i].x) / (-a[i + 1].dx + a[i].dx), i) );
    	nxt[i] = i + 1;
	}
	nxt[n - 1] = nxt[n] = n;
	cell last = a.back();

	double t = 0;
	while (!q.empty()) {
		pair<double, int> T = q.top(); q.pop();

        assert(-T.first >= t);
		t = -T.first;
		int x = T.second;
        if (used[x]) continue;

		if (nxt[ nxt[x] ] == n) {
			nxt[x] = n;
			best.push_back(last);
			ans.push_back(t);
			last = a[x];
		} else { 	
			used[ nxt[x] ] = true;
			nxt[x] = nxt[ nxt[x] ];
			double nt = double(a[ nxt[x] ].x - a[x].x) / (a[x].dx - a[ nxt[x] ].dx);
			q.push(make_pair(-nt, x));
		}
	}

	best.push_back(last);
}

vector<double> ts[4];
vector<cell> best[4];
int pos[4] = {0, 0, 0, 0};

inline bool finished() {
	for (int i = 0; i < 4; ++i)
		if (pos[i] < ts[i].size()) {
			return false;
		}
	return true;
}

double getmax(double t, int i, vector<cell>& a) {
	return a[i].get(t);
}
double getmin(double t, int i, vector<cell>& a) {
	return a[i].get(t);
}

double calc2(double t) {
	double maxx = getmax(t, pos[0], best[0]);
	double minx = getmin(t, pos[1], best[1]);
	double maxy = getmax(t, pos[2], best[2]);
	double miny = getmin(t, pos[3], best[3]);
	return max(maxx - minx, maxy - miny);
}

double getMax(double t, double nt) {
	double ans = min(calc2(t), calc2(nt));

	double A = best[0][ pos[0] ].dx - best[1][ pos[1] ].dx;
	double B = best[0][ pos[0] ].x - best[1][ pos[1] ].x;
	double C = best[2][ pos[2] ].dx - best[3][ pos[3] ].dx;
	double D = best[2][ pos[2] ].x - best[3][ pos[3] ].x;

	if (A == C) {
		return ans;
	}

	double c = (D - B) / (A - C);
	if (c < t || c > nt) return ans;
	return min(ans, calc2(c));
}

int main() {
	//freopen("in", "r", stdin);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", x + i, y + i, a + i, b + i);
    }

    
    vector<cell> A;
	A.clear(); A.resize(n);
	for (int i = 0; i < n; ++i) {
		A[i] = cell(x[i], a[i]);	
	}	
	calc(A, ts[0], best[0]);
	
	A.clear(); A.resize(n);
	for (int i = 0; i < n; ++i) {
		A[i] = cell(y[i], b[i]);	
	}	
	calc(A, ts[2], best[2]);

	A.clear(); A.resize(n);
	for (int i = 0; i < n; ++i) {
		A[i] = cell(-x[i], -a[i]);	
	}	
	calc(A, ts[1], best[1]);
	for (int i = 0; i < best[1].size(); ++i) {
		best[1][i].x = -best[1][i].x;
		best[1][i].dx = -best[1][i].dx;
	}

	A.clear(); A.resize(n);
	for (int i = 0; i < n; ++i) {
		A[i] = cell(-y[i], -b[i]);	
	}	
	calc(A, ts[3], best[3]);
	for (int i = 0; i < best[3].size(); ++i) {
		best[3][i].x = -best[3][i].x;
		best[3][i].dx = -best[3][i].dx;
	}

	double t = 0;
	double ans = 1e8;

	while (!finished()) {
		double nt = 1e100;
		int cr = -1;
		for (int i = 0; i < 4; ++i) {
			if (pos[i] < ts[i].size()) {
				if (nt > ts[i][ pos[i] ] || cr == -1) {
					nt = ts[i][ pos[i] ];
					cr = i;
				}
			}
		}

		ans = min(ans, getMax(t, nt));	
		t = nt;

        pos[cr]++;
	} 

	ans = min(ans, getMax(t, t + 1000000));
    
	cout.precision(15);
	cout << fixed;
	cout << ans << endl;

	return 0;
}
