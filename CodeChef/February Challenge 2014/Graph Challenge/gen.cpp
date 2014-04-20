#include "testlib.h"
#include <iostream>
#include <set>

using namespace std;
typedef long long LL;

void dfs(vector< vector<int> >& g, int x, vector<int>& num, vector<int>& was, int& counter) {
	num[x] = ++counter;
	was[x] = 1;
	for (int i = 0; i < (int)g[x].size(); ++i)
		if (!was[g[x][i]])
			dfs(g, g[x][i], num, was, counter);
}

void writeTest()
{
	int N = rnd.next(1, 1000);
	int M = rnd.next(min(3ll * N, min(10000ll, LL(N) * (N - 1))), min(LL(N) * (N - 1), 10000ll));
	vector< vector<int> > g(N + 1);
	set< pair<int, int> > e;
	for (int i = 0; i < M; ++i) {
		int x, y;
		do {
			x = rnd.next(1, N);
			y = rnd.next(1, N);
		} while (x == y || e.count(make_pair(x, y)));
		e.insert( make_pair(x, y) );
		g[x].push_back(y);
	}
	vector<int> num(N + 1);
	vector<int> was(N + 1);
	int counter = 0;
	dfs(g, rnd.next(1, N), num, was, counter);
	for (int i = 1; i <= N; ++i) if (!was[i]) {
		writeTest();
		return;
	}

	cout << N << " " << M << " " << N << endl;
	for (set< pair<int, int> >::iterator i = e.begin(); i != e.end(); ++i) {
		cout << num[i->first] << " " << num[i->second] << endl;
	}
	for (int i = 0; i < N; ++i) cout << i + 1 << " ";
	cout << endl;
	cout << endl;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv);

    cout << 10 << endl;
    for (int i = 1; i <= 10; i++) writeTest();
    
    return 0;
}
