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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 111111

int n, a[N], g[N], ba[N], ans, dsum[N], ddif[N];
int kx[8] = {2, 2, 1, -1, -2, -2, -1, 1}, ky[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

double get_rand(){
	return ((rand() * 1ll * rand() * rand()) % 1000000001) / 1000000000.0;
}

void get_next(int k) {
	int p[N], r[N];
	for (int i = 0; i < n; ++i) p[i] = r[i] = i;
	for (int i = 0; i < k; ++i) swap(p[i], p[n - 1 - rand() % (n - i)]);
	for (int i = k - 1; i > 0; --i) swap(r[i], r[rand() % (i + 1)]);
	for (int i = 0; i < n; ++i) g[i] = a[i];
	for (int i = 0; i < k; ++i) g[p[i]] = a[p[r[i]]];
}

int eval(){
	int res = 0;
	memset(dsum, 0, sizeof(dsum));
	memset(ddif, 0, sizeof(ddif));
	for (int i = 0; i < n; ++i) {
		res += dsum[i + g[i]];
		++dsum[i + g[i]];

		res += ddif[i - g[i] + n];
		++ddif[i - g[i] + n];
	
	    for (int j = 0; j < 4; ++j) {
	    	if (i + kx[j] >= 0 && i + kx[j] < n && g[i + kx[j]] == g[i] + ky[j]) {
	    		++res;
	    	}
	    }
	}
	return res;
}

double prob(int cur, int nw, double t){
	int delta = nw - cur;
	if (delta < 0) return 1.0;
	else return exp(-delta / t);
}

int main(){
	int f1 = 1, f2 = 1, f0;
	for (int i = 0; i < 100000000; ++i) {
		f0 = (f1 + f2) % 1000000007;
		f2 = f1;
		f1 = f0;
	}
	srand(time(0) + clock());

//	scanf("%d",&n);
	n = 10000;
	int cure;
	for (int i = 0; i < n; ++i) g[i]=i;
	random_shuffle(g, g + n);
	for (int i = 0; i < n; ++i) a[i] = ba[i] = g[i];
	cure = ans = eval();
	double mxt = 100.0;
	for (double t = mxt; ans; t*=0.999999999999){
		int k = max(2, (int)(t / mxt * n));
		get_next(k);
		int ne = eval();
		if (prob(cure, ne, t) >= get_rand()){
			cure = ne;
			for (int i = 0; i < n; ++i) a[i] = g[i];
		}
		if (cure < ans){
			ans = cure;
			for (int i = 0; i < n; ++i) ba[i] = a[i];
		}
	}
	cout << f1 << "\t" << f2 << "\t";
	for (int i = 0; i < n; ++i) printf("%d ", ba[i] + 1);
	return 0;
}
