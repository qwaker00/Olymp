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

vector< pair<char, int> > a, b, c;

void read(vector< pair<char, int> >& a) {
	while (1) {
		char ch;
		cin >> ch;
		if (ch == '$') break;
		int x;
		cin >> x;
		a.push_back(make_pair(ch, x));
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	read(a);
	read(b);
	read(c);

	if (b.size() > 1) {
		for (int i = 0; i + b.size() - 1 < a.size(); ++i) {
			if (a[i].first == b[0].first && a[i].second >= b[0].second &&
			    a[i+b.size()-1].first == b.back().first && a[i+b.size()-1].second >= b.back().second)
		    {
		    	bool ok = true;
		    	for (int j = 1; j + 1 < b.size(); ++j)
		    		if (a[i + j] != b[j]) {
		    			ok = false;
		    			break;
		    		}
		   		if (ok) {
		   			a[i].second -= b[0].second;
		   			a[i+b.size()-1].second -= b.back().second;
		   			if (b.size() > 2) {
			   			a.erase(a.begin() + i + 1, a.begin() + i + b.size() - 1);
			   		}
			   		a.insert(a.begin() + i + 1, c.begin(), c.end());
			   		break;
		   		}		    			
		    }
		}
	} else {
		for (int i = 0; i < a.size(); ++i) 
			if (a[i].first == b[0].first && a[i].second >= b[0].second) {
				a[i].second -= b[0].second;
		   		a.insert(a.begin() + i, c.begin(), c.end());
				break;
			}
	}

	char lastch = -1;
	int lastc = -1;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i].second == 0) continue;
		if (a[i].first != lastch) {
			if (lastc > 0) {
				cout << lastch << " " << lastc << " ";
			}
			lastc = a[i].second;
			lastch = a[i].first;
		} else
			lastc += a[i].second;
	}
	if (lastc > 0) {
		cout << lastch << " " << lastc << " ";
	}
	cout << "$\n";
		
    return 0;
}
