#include <iostream>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <vector>
#include <string>

using namespace std;
vector<string> ans;


int main() {
    freopen("continued.in", "r", stdin);
    freopen("continued.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    if (n < m) {
        ans.push_back("0");
    }

    if (n > m) {
        string s(n - m + 1, '0');
        int cur = 0;
        while (cur < (int) s.size()) {
            s[cur] = '1';
            cur += m;
        }
        ans.push_back(s);
        n %= m;
        if (n == 0) n = m;
    }

    if (n < m) {
        ans.push_back(string(m - n, '9'));
    }

    ans.push_back("1");
    ans.push_back(string(n, '9'));

    printf("%d\n", ans.size() - 1);
    for (int i = 0; i < (int) ans.size(); ++i) {
        for (int j = 0; j < (int) ans[i].size(); ++j) putchar(ans[i][j]);
        putchar(' ');
    }
    cout << endl;

    return 0;
}