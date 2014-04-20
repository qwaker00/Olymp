#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
#include <unordered_map>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;
namespace std {
template<>
struct hash< std::vector<int> > {
    unsigned operator()(const vector<int>& v) const {
        unsigned ans = 0, p = 1;
        for (int i = 0; i < v.size(); ++i) {
            p *= (i + 1);
            ans ^= v[i] * p;
        }
        return ans;
    }
};
}

const int MAXC = 1111111;

unordered_map< vector<int>, int > key;
vector<int> value[MAXC];
int iter = 0;
int D[MAXC];
pair<int, int> P[MAXC];
queue<int> q;

int getid(const vector<int>& v) {
    int& res = key[v];
    if (!res) {
        res = ++iter;
        value[iter] = v;
    }

    return res;
}

int N;
int A[11111];
vector< pair<int, int> > ans;

void qsort(int l, int r) {
    if (r - l + 1 <= 8) {
        vector< pair<int, int> > v;
        for (int i = l; i <= r; ++i) v.push_back(make_pair(A[i], i));
        sort(v.begin(), v.end());

        vector<int> b(r - l + 1);
        for (int i = l; i <= r; ++i) b[ v[i - l].second - l ] = i - l;
        while (b.size() < 8) b.push_back(b.size());

        int t = getid(b);
        while (t != 1) {
            ans.push_back(make_pair(P[t].first + l + 1, P[t].second + l + 1));
            reverse(b.begin() + P[t].first, b.begin() + P[t].second + 1);
            t = getid(b);
        }

        return;
    }

    int p = rand() % (r - l + 1);
    int c = A[l + p];
    int i = l;
    int j = r;
    while (i < j) {
        while (A[i] < c) ++i;
        while (A[j] > c) --j;
        if (i <= j) {
            if (j > i) {
                reverse(A + i, A + j + 1);
                ans.push_back(make_pair(i + 1, j + 1));
            }
            ++i;
            --j;
        }
    }
    if (i < r) qsort(i, r);
    if (l < j) qsort(l, j);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> a;
    for (int i = 0; i < 8; ++i) a.push_back(i);
    
    {
        int x = getid(a);
        D[x] = 1;
        q.push(x);
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        int d = D[x];
        
        vector<int>& t = value[x];
        for (int i = 0; i < t.size(); ++i)
            for (int j = i + 1; j < t.size(); ++j) {
                reverse(t.begin() + i, t.begin() + j + 1);
                
                int y = getid(t);
                if (D[y] == 0 || D[y] > d + N + j - i + 1 ) {
                    D[y] = d + N + j - i + 1;
                    P[y].first = i;
                    P[y].second = j;
                    q.push(y);
                }

                reverse(t.begin() + i, t.begin() + j + 1);
            }
    }

    for (int ii = 0; ii < N; ii += 8) {
        priority_queue< pair<int, int> > q;
        for (int k = ii; k < N; ++k) {
            q.push(make_pair(A[k], k));
            if (q.size() > 8) q.pop();
        }

        vector<int> cand;
        while (!q.empty()) {
            cand.push_back(q.top().second);
            q.pop();
        }

        sort(cand.begin(), cand.end());

        while (true) {
            int r = cand.back();
            int l = 0;
            while (l < cand.size() && cand[(int)cand.size() - l - 1] == r - l) ++l;
            if (l == cand.size()) break;

            ans.push_back( make_pair(cand[(int)cand.size() - l - 1] + 1, r) );
            reverse(A + cand[(int)cand.size() - l - 1] + 1, A + r + 1);

            for (int j = 0; j < l; ++j) {
                cand.pop_back();
            }
            for (int j = 0; j < l; ++j) {
                cand.push_back(cand.back() + 1);
            }
        }
        {
            vector< pair<int, int> > v;
            int l = ii;
            int r = min(ii + 7, N - 1);
            for (int i = l; i <= r; ++i) v.push_back(make_pair(A[i], i));
            sort(v.begin(), v.end());

            vector<int> b(r - l + 1);
            for (int i = l; i <= r; ++i) b[ v[i - l].second - l ] = i - l;
            while (b.size() < 8) b.push_back(b.size());

            int t = getid(b);
            while (t != 1) {
                ans.push_back(make_pair(P[t].first + l, P[t].second + l));
                reverse(b.begin() + P[t].first, b.begin() + P[t].second + 1);
                t = getid(b);
            }
        }

    }

    int res = 0;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
        res += N + ans[i].second - ans[i].first + 1;
    }

    cerr << res << endl;
//    cerr << clock() << endl;

    return 0;
}
