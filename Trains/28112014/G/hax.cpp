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

void out(vector<int>&a) {
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


int idn = 0;
int regist(vector<int>& a) {
	int ph = 0;
	for (int i = 1; i < a.size(); ++i) {
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

	int& id = reg[a];
	if (!id) {
		id = ++idn;
		vec.push_back(a);
		pre.push_back(make_pair(0, 0));
	}
	return id;
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
    	int n;
    	cin >> n;

    	vector<int> all;
		{
			int x;
	   		cin >> x;
	   		vector<int> v(1, x);
	   		int id = regist(v);
	   		all.push_back(id);
	   		pre[id] = make_pair(0, 'l');
	   	}
    	for (int i = 1; i < n; ++i) {
    		int x;
    		cin >> x;
		   	vector<int> q;
    		for (int j = 0; j < all.size(); ++j) {
    			//cout << "try ";
    			//out(vec[all[j]]);
    			//cout << endl;
    			{
	    			vector<int> v = vec[ all[j] ];
	    			int xx = x;
   					while (v.size() && v.front() == xx) {
   						xx += xx;
   						v.erase(v.begin());
    				}
   					v.insert(v.begin(), xx);
   					int id = regist(v);
   					if (id != -1) {
	   					pre[id] = make_pair(all[j], 'l');
   						q.push_back(id); 
   						//output(vec[ all[j] ], v);
   					}
	    		}
    			{
	    			vector<int> v = vec[ all[j] ];
	    			int xx = x;
   					while (v.size() && v.back() == xx) {
   						xx += xx;
   						v.pop_back();
    				}
   					v.push_back(xx);
   					int id = regist(v);
   					if (id != -1) {
	   					pre[id] = make_pair(all[j], 'r');
   						q.push_back(id); 
   						//output(vec[ all[j] ], v);
   					}
	    		}
    		}
//    		cout << endl;
    		sort(q.begin(), q.end());
    		q.erase(unique(q.begin(), q.end()), q.end());
    		all.swap(q);
    	}
    	bool found = 0;
    	for (int i = 0; i < all.size(); ++i)
    		if (vec[all[i]].size() == 1) {
    			int x = all[i];
    			string s;
    			while (x != 0) {
    				s += pre[x].second;
    				x = pre[x].first;
    			}
    			reverse(s.begin(), s.end());
    			cout << s << "\n";
    			found = 1;
    			break;
    		}
    	if (!found) {
    		cout << "no\n";
    	}
    	cerr << clock() << endl;
    }

    return 0;
}
