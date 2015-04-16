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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#include <map>
map< vector<int>, int> reg;
vector< vector<int> > vec(1);
vector< pair<int, char> > pre(1);

void out(const vector<int>&a) {
	cout << "{";
	for (int i = 0; i < a.size(); ++i) {
		if (i) cout << ", ";
		cout << a[i];
	}
	cout << "}";
}

void output(vector<int>&a, vector<int>& b) {
	out(a);
	cout << " -> ";
	out(b);
	cout << endl;
}


int regist(const vector<int>& a) {
	int ph = 0, s = 0;
	for (int i = 0; i < a.size(); ++i) {
		s += a[i];
		if (!i) continue;
		if (ph == 0) {
			if (a[i - 1] > a[i]) ph = 1;
		} else {
			if (a[i - 1] < a[i]) {
				//cout << "reject ";
				//out(a);
				//cout << endl;
				return -1;
			}
		}
	}
	if (s > 8192) return -1;

	int& id = reg[a];
	if (!id) {
		id = vec.size();
		vec.push_back(a);
		pre.push_back(make_pair(0, 0));
		if (id % 10000 == 0) cerr << id << endl;
//		out(a);
//		cout << "\n";
		return id;
	} else
		return -1;
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);




	  	queue<int> q;
   		int id = regist(vector<int>());
   		q.push(id);
   		pre[id] = make_pair(0, 'l');
	   	while (!q.empty()) {
	   		int X = q.front(); q.pop();
	   		for (int x = 1; x <= 8192; x += x) {
	   			{
	    			vector<int> v = vec[X];
	    			int xx = x;
   					while (v.size() && v.front() == xx) {
   						xx += xx;
   						v.erase(v.begin());
    				}
   					v.insert(v.begin(), xx);
   					int id = regist(v);
   					if (id != -1) {
	   					pre[id] = make_pair(X, 'l');
   						q.push(id); 
   					}
   				}
	   			{	   			
	    			vector<int> v = vec[X];
	    			int xx = x;
   					while (v.size() && v.back() == xx) {
   						xx += xx;
   						v.pop_back();
    				}
   					v.push_back(xx);
   					int id = regist(v);
   					if (id != -1) {
	   					pre[id] = make_pair(X, 'l');
   						q.push(id); 
   					}
   				}
	   		}
	   	}

	   	cerr << reg.size() << endl;
    	cerr << clock() << endl;

    return 0;
}
