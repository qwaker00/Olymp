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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

struct cell {
    int val, tag, ctag;

    bool operator<(const cell& A) const {
        if (val != A.val) return val > A.val;
        return tag < A.tag;
    }
};
priority_queue<cell> q;

int main() {
    int n, M, T;
    scanf("%d%d%d", &n, &M, &T);
    for (int i = 0; i < n; ++i) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int pos = ((h * 60) + m) * 60 + s;
        cell a;
        a.val = pos;
        a.tag = 1;
        q.push(a);
    }

    vector<int> ans;
    int k = 0;
    map<int, int> un;
    bool cool = false;
    while (!q.empty()) {
        int pos = q.top().val;
        int tag = q.top().tag;
        int ctag = q.top().ctag;
        q.pop();

        if (tag == 1) {
            if (int(un.size()) < M) {
                ++k;
            }
            ans.push_back(k);
            un[k]++;
            cell A;
            A.val = pos + T - 1;
            A.tag = -1;
            A.ctag = k;
            q.push(A);
        } else {
            auto it = un.find(ctag);
            it->second--;
            if (it->second == 0) {
                un.erase(it);
            }
        }

        if (int(un.size()) == M) cool = true;
    }

    if (!cool) {
        puts("No solution");
        return 0;
    }

    printf("%d\n", k);
    for (size_t i = 0; i < ans.size(); ++i) printf("%d\n", ans[i]);

    return 0;
}
