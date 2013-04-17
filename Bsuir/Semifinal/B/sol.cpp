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
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 1111111;

bool alive[N];

char w[111];

inline void readq(bool& a, bool& b) {
	char c= getchar();
	while (c != '+' && c != '-') c= getchar();
	a = (c == '+');

	c = getchar();
	b = (c == 'L');
}

inline void readi(int& x) {
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	x = 0;
	do {
		x = x * 10 + c - '0';
		c = getchar();
	} while (c >= '0' && c <= '9');
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
	int t;
	readi(t);
	
	deque<pair<int, int> > q;

	deque<pair<int, int> > d1, d2;

	for (int iter = 1; iter <= t; ++iter) {
		pair<int, int> c;

		bool p, l;
		readq(p, l);
		
		if (p) {
			int x;
			readi(x);
			c = make_pair(x, iter);
			alive[iter] = true;

			
			
			if (l) { 
				q.push_front(c);

				
			} else { 
				q.push_back(c);
			}
		} else {
        	if (l) { 
        		c = q.front();		
        		q.pop_front();
            } else {
				c = q.back();
				q.pop_back();
            }

            alive[c.second] = false;
		}

		int ans = -1;
		while (!qq.empty()) {
			c = qq.top();
			if (!alive[c.second]) qq.pop();
			else {
				ans = -c.first; 
				break;
				
			}
		}
		printf("%d\n", ans);

	}
    
    return 0;
}
