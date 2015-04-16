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
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

string ans[30] = {
"1",
"2",
"5",
"14",
"42",
"165",
"714",
"3094",
"14858",
"79534",
"447051",
"2714690",
"17395070",
"114371070",
"783152070",
"5708587335",
"43848093003",
"342444658094",
"2803119896185",
"23619540863730",
"201813981102615",
"1793779293633437",
"16342050964565645",
"154170926013430326",
"1518409177581024365",
"15259825120722837478",
"154870329715038713659",
"1601991088154989174258",
"16725278985898957454695",
"177792163538134124432895",
};


int main() {
    freopen("handsome.in", "r", stdin);
    freopen("handsome.out", "w", stdout);

    int it = 0;
    while (true) {
    	int n;
	    cin >> n;
	    if (n == 0) break;
	    ++it;
	    cout << "Case #" << it << ": " << ans[n - 1] << endl;
    }

    return 0;
}
