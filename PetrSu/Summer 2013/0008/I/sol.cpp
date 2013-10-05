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

const int N = 555666;

struct cell {
	ll l, r;
	int id;

	cell(ll al = 0, ll ar = 0, int aid = 0)
		: l(al)
	 	, r(ar)
	    , id(aid)
	    {}	

	bool operator<(const cell& A) const {
		return l < A.l;
	}
} evs[N];
int ke;

int n, m;
int p[N];



int main() {
	freopen("intelligent.in", "r", stdin);
	freopen("intelligent.out", "w", stdout);

	scanf("%d", &n);
	while (n) {

	ke = 0;
	for (int i = 1; i <= n; ++i) {
		long long d;
		scanf("%I64d%d", &d, p + i);
		++p[i];
		evs[ke++] = cell(d, d, i);
	}
	scanf("%d", &m);
	while (m--) {
		ll s, t;
		scanf("%I64d%I64d", &s, &t);
		evs[ke++] = cell(s, t, -1);
	}

	evs[ke++] =  cell(0, 0, -1);
    sort(evs, evs + ke);

    vector<int> ans;
	priority_queue< pair<int, int> > q;	
	for (int i = ke - 1; i >= 1; --i) {
		ll r = evs[i].l - 1;
		if (evs[i].id != -1) {
			q.push(make_pair(-p[ evs[i].id ], evs[i].id));
			r++;
		}

		ll l = evs[i - 1].r + 1;
		ll cnt = r - l + 1;

	   	while (cnt && !q.empty()) {
			pair<int, int> T = q.top(); q.pop();

			ll days = min(cnt, ll(-T.first));
			if (days == -T.first) {
				ans.push_back(T.second);
			} else {
				q.push(make_pair(days + T.first, T.second));
			}
			cnt -= days;
	   	}
	}

	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d ", ans[i]);
	}
	puts("");


	scanf("%d", &n);	
    }

	return 0;
}
