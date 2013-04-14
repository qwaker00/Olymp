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


class EqualSums {
public:
	int count(vector <string> board) {
		int n = board.size();
		vector< vector<int> > a(board.size());
		vector< pair<int, int> > l;
		for (int i = 0; i < n; ++i) {
			a[i].resize(n);
			for (int j = 0; j < n; ++j)
				if (board[i][j] == '-')
					a[i][j] = -1;
				else {
					a[i][j] = board[i][j] - '0';
					l.push_back(make_pair(i, j));
				}
		}
	
		int ans = 1, start = 0;
		
		while (true) {
		
		for (int i = 0; i < l.size(); ++i) {
			int x = l[i].first;
			int y = l[i].second;
			cerr << x << " " << y << endl;
			for (int j = 0; j < i; ++j)
				if (l[j].first != x && l[j].second != y) {
					int xx = l[j].first;
					int yy = l[j].second;
					
					if (a[xx][y] != -1) {
						int t = a[x][y] + a[xx][yy] - a[xx][y];
						if (t < 0 || (a[x][yy] != -1 && a[x][yy] != t)) return -1;
						if (a[x][yy] == -1) {
							a[x][yy] = t;
							l.push_back( make_pair(x, yy) );
						}
					}
					if (a[x][yy] != -1) {
						int t = a[x][y] + a[xx][yy] - a[x][yy];
						if (t < 0 || (a[xx][y] != -1 && a[xx][y] != t)) return -1;
						if (a[xx][y] == -1) {
							a[xx][y] = t;
							l.push_back( make_pair(xx, y) );
						}
					}
				}
		}
		start = l.size();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) if (a[i][j] == -1) cerr << '-'; else cerr << a[i][j];
			cerr << endl;
		}
		bool found = false;
		for (int i = 0; i < n && !found; ++i) {
			for (int j = 0; j < n; ++j) if (a[i][j] == -1) {
				a[i][j] = 0;
				found = true;
				l.push_back(make_pair(i, j));
				break;
			}
		}
		if (!found) break;
		
		}
		
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	EqualSums *obj;
	int answer;
	obj = new EqualSums();
	clock_t startTime = clock();
	answer = obj->count(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"1-","-2"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"123","4--","--9"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"9--","-9-","--9"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 271;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"11","12"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"-4--","-0-2","--1-","4---"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"--2","02-","-10"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 0;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"----------1---------------0-----7-----------------","-----4--------------------------------------------","--------5-------------5-3---5---------------6-----","-------2----------1-------------------------------","-----4--------------------------------------------","-----3--------------------------------------------","-6----------5-------------------------------------","-------------------------------7---5----------6---","--------6-------------6-4---6---------------7-----","-------------4----------------5-------------------","3------------------------------------------6------","3------------------------------------------6------","-------------4----------------5-------------------","---------------2-------------------------3--------","--2------------------------------------------2----","---8---------------1-------------------3----------","---------------3----------------------------------","----7----------------5---0-----------------------5","----------------5-------------------------3---"
			"--1-","----------1---------------0-----7-----------------","-------------5----------------6-------------------","-7----------6-------------------------------------","---8---------------1-------------------3----------","-----------------------3--------------------------","----8----------------6---1-----------------------6","------------------------------------------4-----2-","-----------5---------------5----------------------","-----------------------------6--------------------","----8----------------6---1-----------------------6","----------------5-------------------------3-----1-","-------------------------------6---4--2-------5---","-6----------5-------------------------------------","--------5-------------5-3---5---------------6-----","-------------5----------------6-------------------","-----3--------------------------------------------","---------------2-------------------------3--------","---------4---------------------------6------------","-------------------------------6---4--2-"
			"------5---","------2-------------1------------22---------------","--------5-------------5-3---5---------------6-----","-----------5--3------------5----------------------","--2------------------------------------------2----","---------5---------------------------7------------","-------------4----------------5-------------------","-----------------5------------------4---6------2--","-------------------------------6---4--2-------5---","-----------------------2--------------------------","----------------6-------------------------4-----2-","-------------------------------6---4--2-------5---","--------5-------------5-3---5---------------6-----"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 45094393;
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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