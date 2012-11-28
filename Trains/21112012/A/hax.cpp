#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


int main() {
    freopen("auxiliary.in", "r", stdin);
    freopen("auxiliary.out", "w", stdout);
    
    string s;
    cin >> s;

    string w;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == ')') {
            w += "(0)";
        } else w += s[i];
    }
    
    w = "0" + w + "0";
    //cout << w << endl;

    s = "";
    for (int i = 0; i + 1 < w.size(); ++i) {
        if (w[i] == '+') {
            s += '+';
            if (w[i + 1] == '+') s += '0'; 
        } else if (w[i] >= '0' && w[i] <= '9') {
            s += w[i];
            if (w[i + 1] == '(') s += '+';        
        } else if (w[i] == ')') {
            s += w[i];
            if (w[i + 1] == '(' || (w[i + 1] >= '0' && w[i + 1] <= '9')) {
                s += '+';
            }
        } else s += w[i];
    }


    cout << s << "0" << endl;

    return 0;
}
