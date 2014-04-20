#include <iostream> //a
#include <algorithm>
#include <stdio.h> //a
#include <stdlib.h>
#include <time.h> //a
#include <memory.h> //a
#include <math.h>
#include <string>
#include <string.h>
#include <queue> //a
#include <vector> //a
#include <set>
#include <deque>
#include <map>
#include <functional> //a
#include <numeric>
#include <sstream> //a

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x)) //a

using namespace std;


int main() { //a
//    freopen(".in", "r", stdin); //a
//    freopen(".out", "w", stdout); //a

ULL x; //a
cin >> x; //a
if (x ==18446744073709551615UL)
cout << "18446744073709551616" << endl;else //a
cout << x + 1 << endl; //a

return 0;
}
