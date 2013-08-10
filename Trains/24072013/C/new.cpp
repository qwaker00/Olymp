#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

vector<int> ans;

int bits(int x) {
    int ans = 0;
    while (x) {
        ++ans;
        x &= x - 1;
    }
    return ans;
}

int main() {
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);

    int N;
    cin >> N;
    ans.push_back(0);
    ans.push_back(2);
    ans.push_back(1);
    ans.push_back(3);
    for (int n = 4; n <= N; n += 2) {
//        cerr << "N: " << n << endl;

        vector<int> ans2;
        set<int> anss;

        for (int j = 0; j < ans.size(); ++j) {
            ans2.push_back(ans[j] * 4 + 2 + (j&1));
            anss.insert(ans2.back());
//            cerr << ans2.back() << " ";
        }
        for (int j = 0; j < ans.size(); ++j) {
            ans2.push_back(ans[j] * 4 + 2 + 1 - (j&1));
            anss.insert(ans2.back());
//            cerr << ans2.back() << " ";
        }
        for (int j = 0; j < ans.size(); ++j) {
            ans2.push_back(ans[j] * 4 + (j&1));
            anss.insert(ans2.back());
//            cerr << ans2.back() << " ";
        }
        for (int j = 0; j < ans.size(); ++j) {
            ans2.push_back(ans[j] * 4 + 1 - (j&1));
            anss.insert(ans2.back());
//            cerr << ans2.back() << " ";
        }
        if (anss.size() != (1 << n)) {
            cerr << "bad size" << endl;
            throw 1;
        }
        for (int j = 1; j < ans2.size(); ++j) {
            if (bits(ans2[j - 1] ^ ans2[j]) < n / 2) {
                cerr << ans2[j - 1] << " " << ans2[j] << endl;
                throw 1;
            }
        }
        if (bits(ans2[0] ^ ans2[ans2.size() - 1]) < n / 2) {
            cerr << ans2[0] << " " << ans2[ans2.size() - 1] << endl;
            throw 1;
        }

        ans = ans2;
    }
    if (N & 1) {
        int n = N;
        vector<int> ans2;
        set<int> anss;

        for (int i = 0; i < ans.size(); ++i) {  
            ans2.push_back(ans[i] * 2 + (i&1));
            anss.insert(ans2.back());            
        }
        for (int i = 0; i < ans.size(); ++i) {  
            ans2.push_back(ans[i] * 2 + 1 - (i&1));
            anss.insert(ans2.back());            
        }
        if (anss.size() != (1 << n)) {
            cerr << "bad size" << endl;
            throw 1;
        }
        for (int j = 1; j < ans2.size(); ++j) {
            if (bits(ans2[j - 1] ^ ans2[j]) < n / 2) {
                cerr << ans2[j - 1] << " " << ans2[j] << endl;
                throw 1;
            }
        }
        if (bits(ans2[0] ^ ans2[ans2.size() - 1]) < n / 2) {
            cerr << ans2[0] << " " << ans2[ans2.size() - 1] << endl;
            throw 1;
        }
        ans = ans2;
    }
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < N; ++j) putchar('0' + ((ans[i] & (1 << j))> 0));
        puts("");
    }
    
    return 0;
}
