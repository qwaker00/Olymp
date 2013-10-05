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
#include <time.h>
#include <assert.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

char s[11];
int r, c;
vector<string> ss;

void rec(int l) {
	if (l > 0) {
		ss.push_back(string(s, s + l));
	}
	if (l == 4) return;

	for (char c = 'A'; c <= 'Z'; ++c) {
		s[l] = c;
		rec(l + 1);
	}
}

bool cmp(const string& a, const string& b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}

char w[111];

int main() {
	//freopen("in", "r", stdin);

	int r, c;
	scanf("%d%d", &r, &c);

	rec(0);
    sort(ss.begin(), ss.end(), cmp);
    //for (int i = 0; i < ss.size(); ++i) puts(ss[i].c_str());
	
	int q; scanf("%d\n", &q);

	while (q--) {
		gets(w);
		int l = strlen(w);

		int first = -1;
		for (int i = 0; i < l; ++i) 
			if (w[i] >= '0' && w[i] <= '9') {
				first = i;
				break;
			}

		if (first == 0) {
			ll num = 0;
			for (int i = 0; i < l; ++i) {
				num = num * 10 + w[i] - '0';
			}
			--num;

			ll x = num / c, y = num % c;
			printf("%s%I64d\n", ss[y].c_str(), x + 1);
		} else {
			string res;
			for (int i = 0; i < first; ++i) {
				res += w[i];
			}

			int L = 0, R = ss.size() - 1;
			while (L < R) {
				int mid = (L + R + 1) >> 1;
				if (cmp(res, ss[mid])) R = mid - 1;
				else L = mid;
			}
			int y = L;
			//assert(res == ss[y]);
			int x = 0;
			for (int i = first; i < l; ++i) {
				x = x * 10 + w[i] - '0';
			}
			printf("%I64d\n", ll(x - 1) * ll(c) + ll(y) + 1);
		}
	}

	//cerr << clock() << endl;

	return 0;
}
