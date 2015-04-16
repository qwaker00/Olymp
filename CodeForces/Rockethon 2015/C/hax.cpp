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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const double PI = 3.1415926535897932384626433832795;
template<typename T>
T sqr(T x) { return x * x; }

using namespace std;

int n;

/*
double a, b; // входные данные
const int N = 1000*1000; // количество шагов (уже умноженное на 2)
double s = 0;
double h = (b - a) / N;
for (int i=0; i<=N; ++i) {
	double x = a + h * i;
	s += f(x) * ((i==0 || i==N) ? 1 : ((i&1)==0) ? 2 : 4);
}
s *= h / 3
*/

int r[5], l[5];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	cin >> n;	
 	for (int i= 0; i < n; ++i) {
		cin >> l[i] >> r[i];    
	}

	ld sum = 0;
	for (int x = 0; x <= 10000; ++x) {
		for (int i = 0; i < n; ++i) if (l[i] <= x && x <= r[i])
			for (int j = 0; j < n; ++j) if(j != i) {
				int u;
				if (j < i) u = x;else u = x + 1;
				if (u > r[j]) continue;
				ld pr = 1.0 / (r[i] - l[i] + 1);
				pr *= ld(r[j] - max(l[j], u) + 1) / (r[j] - l[j] + 1);
				for (int k = 0; k < n; ++k) if (k != i && k != j) {
					int d;
					if (k < i) d = x - 1;else d = x;

					if (l[k] > d) {
						pr = 0;
						break;
					}else
					if (r[k] < d) {
						continue;
					}
					pr *= ld(d - l[k] + 1) / (r[k] - l[k] + 1);
				}
				sum += pr * x;
			}
	}
	cout.precision(12);
	cout << fixed;
	cout << double(sum) << endl;

    return 0;
}
