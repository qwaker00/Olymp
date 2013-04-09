#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;


class PolygonTraversal {
public:

	long long f[333333][20];

	long long Calc(int msk, int last, int N, int fp) {
		if (msk + 1 == (1 << N)) return ((last + 1) % N) != fp && ((last + N - 1) % N) != fp;

//		cerr << msk << " " << last << endl;
		
		long long& v = f[msk][last];
		if (v != -1) return v;
		
		bool bad[20] = {0};
		int l = (last + N - 1) % N, r = (last + 1) % N;
		while ( ((1 << l) & msk) == 0) {
			bad[l] = 1;
			l = (l + N - 1) % N;
		}
		while ( ((1 << r) & msk) == 0) {
			bad[r] = 1;
			r = (r + 1) % N;
		}
		
		v = 0;
		for (int i = 0; i < N; ++i) {
			if ( !bad[i] && ((1 << i) & msk) == 0) {
				v += Calc(msk | (1 << i), i, N, fp);
			}
		}
		return v;
	}

	long long count(int N, vector <int> points) {
		int msk = 0;
		for (int i =0; i < points.size(); ++i) {
			msk += (1 << (points[i] - 1));
		}
		memset(f, -1, sizeof(f));
		return Calc(msk, points[points.size() - 1] - 1, N, points[0] - 1);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	PolygonTraversal *obj;
	long long answer;
	obj = new PolygonTraversal();
	clock_t startTime = clock();
	answer = obj->count(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	vector <int> p1;
	long long p2;
	
	{
	// ----- test 0 -----
	p0 = 5;
	int t1[] = {1,3,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 6;
	int t1[] = {1,4,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 1ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 7;
	int t1[] = {2,4,7};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 2ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 7;
	int t1[] = {1,2,3,4,6,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 0ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 18;
	int t1[] = {1,7,18};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 4374612736ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
