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
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;
const int N = 300333;

bool sieve[N];
string anses[N];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
	
	vector<int> primes;
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i)
		if (!sieve[i]) {
			primes.push_back(i);
			for (int j = i + i; j <= n; j += i)
				sieve[j] = true; 
		}
	//cerr << primes.back() << endl;

	int M = 1;
	while ((1 << M) < primes.back()) ++M; 
	
	for (int i = 0; i < M; ++i) {
		cout << 2 << endl;
		string s;
		cin >> s;
		if (s.size() == 0 || s == "OK") {
			return 0;
		}
		anses[i] = s;
	}

	vector< pair<int, int> > cands;
    for (int it = 0; it < primes.size(); ++it) {
    	ll p = primes[it];

    	ll first = 1;
    	ll board = (p + 1) / 2;
		
		bool good = true;
		for (int i = 0; i < M; ++i) {
			if (anses[i] == ">") {
			    int nxt = (first + first) % p;
				if (nxt <= first) {
					good = false;
					break;
				}

				first = nxt;
			} else {
				ll step = ll(1) << i;
				first += ((board - first) / step) * step;
				
				int nxt = (first + first) % p;
				if (nxt >= first) {
					good = false;
					break;
				}

				first = nxt;
			}
		}

		if (good) {
			cands.push_back(make_pair(int(p), first));
		}
    }	
    

    for (; cands.size() > 1; ++M) {
    	ll p = cands[0].first;
    	int score = 1e9;
    	for (int i = 0; i < cands.size(); ++i) {
    		ll cp = cands[i].first;

    		int sc1 = 0, sc2 = 0;
    		for (int j = 0; j < cands.size(); ++j) {
				ll nxt = (ll(cands[i].second) * cp) % cands[i].first;
				if (nxt < cands[i].second) ++sc1;
				else if (nxt > cands[i].second) ++sc2;
    		}

    		int cscore = max(sc1, sc2);
    		if (cscore < score) {
    			score = cscore;
    			p = cp;
    		}
    	}  

    	cout << p << endl;
    	string s; cin >> s;
    	if (s == "OK" || s == "") {
    		return 0;
    	}

    	vector< pair<int, int> > newcands;
    	for (int i = 0; i < cands.size(); ++i) {
    		ll cur = cands[i].second;
    		ll nxt = (cur * p) % cands[i].first;

    		if (cur == nxt && s == "=") {
    			newcands.push_back(make_pair(cands[i].first, int(nxt)));
    		} else if (nxt < cur && s == "<") {
    			newcands.push_back(make_pair(cands[i].first, int(nxt)));
    		} else if (nxt > cur && s == ">") {
				newcands.push_back(make_pair(cands[i].first, int(nxt)));
    		}
    	}

    	cands = newcands;
    }
    cout << cands[0].first << endl;

    cerr << "fail" << endl;

    return 0;
}
