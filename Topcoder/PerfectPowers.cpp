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

using namespace std;

typedef long long LL;
typedef long double LD;

class PerfectPowers {
public:
	void Check(LL& ans, LL A, LL B, LL x, LL y) {
		if (x == y) return;
		if (x > y) swap(x, y);
		if (x >= A && y <= B && y - x < ans) ans = y - x;
	}

	LL Pow(LL x, LL y) {
		LL r = 1;
		while (y) {
			if (y &1) {
				if (LD(r) * LD(x) > 9e18)
					return 9e18;else
					r = r * x;
			}
			if (LD(x) * LD(x) > 9e18)
				x = 9e18;else
				x = x * x;
			y >>= 1;
		}
		return r;
	}

	long long nearestCouple(long long A, long long B) {
		LL ans = B - A + 1;
		
		LL l = (LL)sqrtl(A - 1) + 1;
		Check(ans, A, B, l * l, (l + 1) * (l + 1));
		
		vector<LL> all;
		for (int p = 3; p <= 61; ++p) {
			for (int i = 1; ; ++i) {
				LL x = Pow(i, p);
				//cerr << x << endl;
				if (x > B) break;
				if (x >= A) {
					all.push_back(x);
				//	cerr << x << endl;
				}
			}
		}
		cerr << "OK" << endl;
		sort(all.begin(), all.end());
		all.erase(unique(all.begin(), all.end()), all.end());
		
		for (int i = 0; i < all.size(); ++i) {
			if (i > 0) Check(ans, A, B, all[i - 1], all[i]);
			LL up = (LL)sqrtl(all[i] - 1) + 1;
			Check(ans, A, B, all[i], up * up);
			Check(ans, A, B, all[i], (up - 1) * (up - 1));
		}
		
		if (ans == B - A + 1) return -1;
		return ans;		
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, long long p0, long long p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	PerfectPowers *obj;
	long long answer;
	obj = new PerfectPowers();
	clock_t startTime = clock();
	answer = obj->nearestCouple(p0, p1);
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
	
	long long p0;
	long long p1;
	long long p2;
	
	{
	// ----- test 0 -----
	p0 = 1ll;
	p1 = 4ll;
	p2 = 3ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 8ll;
	p1 = 9ll;
	p2 = 1ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 10ll;
	p1 = 15ll;
	p2 = -1ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 1ll;
	p1 = 1000000000000000000ll;
	p2 = 1ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 80000ll;
	p1 = 90000ll;
	p2 = 80ll;
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
