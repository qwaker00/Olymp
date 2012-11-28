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


class FoxAndMountainEasy {
public:
	string possible(int n, int h0, int hn, string s) {
		if ( (n & 1) != (abs(hn - h0) & 1) ) return "NO";
		
		int mindiff = 0, diff = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'U') ++diff;else diff--;
			if (diff < mindiff) mindiff = diff;
		}
		
		int toup = max(0, -mindiff - h0);
		int x = h0 + toup + diff;
		int l = 0 + toup + s.size();
		if (l > n) return "NO";
		if ( (n - l) < abs(hn - x)) return "NO";
		return "YES";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, string p3, bool hasAnswer, string p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << "\"" << p3 << "\"";
	cout << "]" << endl;
	FoxAndMountainEasy *obj;
	string answer;
	obj = new FoxAndMountainEasy();
	clock_t startTime = clock();
	answer = obj->possible(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p4 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	int p1;
	int p2;
	string p3;
	string p4;
	
	{
	// ----- test 0 -----
	p0 = 4;
	p1 = 0;
	p2 = 4;
	p3 = "UU";
	p4 = "YES";
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4;
	p1 = 0;
	p2 = 4;
	p3 = "D";
	p4 = "NO";
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 100000;
	p2 = 100000;
	p3 = "DDU";
	p4 = "YES";
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 4;
	p1 = 0;
	p2 = 0;
	p3 = "DDU";
	p4 = "NO";
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 20;
	p1 = 20;
	p2 = 20;
	p3 = "UDUDUDUDUD";
	p4 = "YES";
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 20;
	p1 = 0;
	p2 = 0;
	p3 = "UUUUUUUUUU";
	p4 = "YES";
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 20;
	p1 = 0;
	p2 = 0;
	p3 = "UUUUUUUUUUU";
	p4 = "NO";
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, p3, true, p4) && all_right;
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
