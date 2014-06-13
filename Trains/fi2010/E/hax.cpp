#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

int cnt = 0;
int mark[33];
int n, s;
LL ans = 0;

struct Seq {
    vector< vector<LL> > after;
    vector<LL> usage;
    int first;
    int last;

    Seq() : after(n + 1, vector<LL>(n + 1)), usage(n + 1) {}
};

void rec(int i, int bc, LL sum) {
    if (sum >= ans) return;
    if (i > n) {
        ans = sum;
        return;
    }
    for (int j = 0; j <= bc && j < s; ++j) {
        mark[i] = j;

        LL sum2 = sum;
        for (int k = 1; k < j; ++k) if (mark[j] != mark[k])
            sum2 += after[k][j];

        rec(i + 1, max(j + 1, bc), sum2);
    }
}

int main() {
    //freopen(".in", "r", stdin);

    int n, s;
    cin >> n >> s;

    vector<LL> cyc;
    vector<Seq> st;

    st.push_back(Seq());

    string token;
    while (cin >> token) {
        if (token[0] == 'R') {
            LL c;
            sscanf(token.c_str() + 1, "%lld", &c);
            cyc.push_back(c);
        } else
            if (token == "E") {
                for (int i = 1; i <= n; ++i)
            }
    }

    LL preans = 0;
    for (int i = 1; i <= n; ++i) preans += usage[i];

    rec(1, 0, 0);


    cout << ans + preans << endl;

    return 0;
}
