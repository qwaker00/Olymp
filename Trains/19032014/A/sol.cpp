#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
const int N = 1000111;
const int INF = 1e9;
int a[N];
int n, k;
int order[N + N];
int PS[N*2];
vector<int> st;
int* pos = PS + N;
int nexto[N], nextc[N];


int main() {
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);

		for (int i = 0; i < k + k; ++i) {
			scanf("%d", order + i);
			pos[ order[i] ] = i;
		}
		nexto[k + k - 1] = INF;
		nextc[k + k - 1] = INF; 
		for (int i = k + k - 2; i >= 0; --i) {
			if (order[i + 1] > 0) {
				nexto[i] = i + 1;
				nextc[i] = nextc[i + 1];
			} else {
				nextc[i] = i + 1;
				nexto[i] = nexto[i + 1];
			}
		}
		for (int i = 0; i < n + n; ++i) {
			scanf("%d", a + i);
		}

		st.clear();
		int where = -1;
		int who = -1;
		for (int i = 0; i < n + n; ++i) {
			int balance = st.size();
			int len = n + n - i -1;
			int position = pos[ a[i] ];

			if (a[i] < 0) {
				if (nexto[position] != INF) {
					if (balance + 1 <= len && !( (len - 1 - balance) & 1 )) {
						where = i;
						who = order[nexto[position]];
					}
				}
			} else {
				if (nexto[position] != INF) {
					where = i;
					who = order[nexto[position]];
				}
				if (balance > 0) {
					if (!( (len + 1 - balance) & 1) && pos[-st.back()] > position) {
						if (where < i || pos[-st.back()] < pos[who]) {
							where = i;
							who = -st.back();
						}
					}
				}
			}
			
			if (a[i] < 0) {
				st.pop_back();
			} else {
				st.push_back(a[i]);	
			}
		}

		int coolo = nexto[0] == INF? order[0] : order[nexto[0]];
		if (order[0] > 0) coolo = order[0];
		st.clear();

		if (where != -1) a[where] = who;
		for (int i = 0; i <= where; ++i) {
			if (a[i] > 0) st.push_back(a[i]);
			else st.pop_back();
		}

		for (int i = where + 1; i < n + n; ++i) {
			int balance = st.size();
			int len = n + n - 1 - i;

			if (st.size() == 0) {
				a[i] = coolo;
				st.push_back(coolo);
				continue;
			}

			if (len < balance + 1) {
				a[i] = -st.back();
				st.pop_back();
				continue;
			}
		
			if (pos[coolo] < pos[-st.back()]) {
				a[i] = coolo;
				st.push_back(a[i]);
			} else {
				a[i] = -st.back();
				st.pop_back();
			}
		}

		for (int i = 0; i < n + n; ++i) printf("%d ", a[i]);
		puts("");
	}
	
	return 0;
}



