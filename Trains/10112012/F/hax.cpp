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
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n, m;

string s[2222];
set<string> sets;

struct cell {
    int a[26];

    cell(string w = "") {
        for (int i = 0; i < 26; ++i) a[i] = 0;
        for (int i = 0; i < w.size(); ++i)
            a[w[i] - 'A']++;
    }

    bool can(const cell& A) {
        for (int i = 0; i < 26; ++i)
            if (a[i] < A.a[i]) return false;
        return true;
    }

    bool can(string w) {
        return can(cell(w));
    }
};

cell gm[2222];

priority_queue< pair<int, string> > q;

int check(string w) {
    cell cur = w;
    int res = 0;
    for (int i = 0; i < m; ++i)
        res += gm[i].can(cur);
    return res;
}

char bf[2];

vector<string> ans;

int main() {
    freopen("funny.in", "r", stdin);
    freopen("funny.out", "w", stdout);
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
        sets.insert(s[i]);
        gm[i] = cell(s[i]);
    }    


    for (int i = 0; i < 26; ++i) {
        bf[0] = 'A' + i;
        string cur = bf;


        q.push(make_pair(check(cur), cur));
    }

    while (ans.size() < n) {
        pair<int, string> cr = q.top(); q.pop();

        if (sets.find(cr.second) == sets.end()) {
            ans.push_back(cr.second);
        }

        for (int i = 0; i < 26; ++i) {
            string nw = cr.second + char('A' + i);
            q.push(make_pair(check(nw), nw));
        }
    }

    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;


    return 0;
}

