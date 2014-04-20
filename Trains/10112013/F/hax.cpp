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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef LL ll;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int forbidden;
long long ans;

ll gcd(ll a, ll b) {
    while (a && b)
        if (a > b) a %= b;
        else b %= a;
    return a + b;
}

int who[444]; 
bool used[11];
vector<char> a;
string s; 
bool done = false;
int iter = 0;

const int ITER = 70000;

void rec(int l) {
    if (l == a.size()) {
        ll val = 0;
        for (int i = 0; i < s.size(); ++i)
            val = val * 10 + who[s[i]];
        ans = gcd(ans, val);
        if (ans == 1) done = true;
        return;
    } 
    if (++iter > ITER) { 
        done = true;
        return;
    }

    if (a[l] != forbidden && !used[0]) {
        who[a[l]] = 0;
        used[0] = true;
        rec(l + 1);
        if (done) return;
        used[0] = false;
    }

    for (int d = 1; d < 10; ++d)
       if (!used[d]) {
            who[a[l]] = d;
            used[d] = true;
            rec(l + 1);
            if (done) return;
            used[d] = false;
       }
} 

const int N = 10000004;

vector<ll> primes;
int f[N];

vector< pair<ll, int> > divs;
vector<ll> cans;

void calc(int l, ll val) {
    if (l == divs.size()) {
        cans.push_back(val);
        return;
    }

    for (int i = 0; i <= divs[l].second; ++i) {
        calc(l + 1, val);
        val *= divs[l].first;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    for (int i = 2; i < N; ++i)
        if (!f[i]) {
            primes.push_back(i);
            //if (ll(i) * i >= N) continue;
            for (int j = i; j < N; j += i)
                f[j] = i;
        }

    int T;
    cin >> T;
    int ttt = 0;
    while (T--) {
        ++ttt;
        cin >> s;
        done = false;
        iter = 0;
        
        set<char> q(s.begin(), s.end());
        a = vector<char>(q.begin(), q.end());

        forbidden = s[0];
        ans = 0;
        rec(0);
        memset(used, 0, sizeof(used));
        if (iter >= ITER) {
            iter = 0;
            done = false;
            random_shuffle(a.begin(), a.end());
            rec(0);
            memset(used, 0, sizeof(used));
        }

        divs.clear();
        cans.clear();        
        for (int i = 0; i < primes.size(); ++i) {
            int cnt = 0;
            while (!(ans % primes[i])) {
                ++cnt;
                ans /= primes[i];    
            }    
            if (cnt) divs.push_back(make_pair(primes[i], cnt));

            if (primes[i] * primes[i] > ans) break;

            if (ans < N) {
                while (ans != 1) {
                    int p = f[ans];
                    cnt = 0;
                    while (f[ans] == p) {
                        ++cnt;
                        ans /= p;
                    }

                    divs.push_back(make_pair(ll(p), cnt));
                }
            }
        }
        if (ans != 1) divs.push_back(make_pair(ans, 1));

        calc(0, 1);

        sort(cans.begin(), cans.end());
        printf("Case %d:", ttt);
        for (int i = 0; i < cans.size(); ++i) printf(" %I64d", cans[i]);
        puts("");
    }

    cerr << clock() << endl;

    
    return 0;
}
