#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool check(const vector<int>& a, double x) {
    double l1 = x * 0.95, r1 = x * 1.05, l2 = 2. * x * 0.95, r2 = 2 * x * 1.05;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if ((l1 <= a[i] && a[i] <= r1) || (l2 <= a[i] && a[i] <= r2)) {

        } else {
            return false;
        }
    }
    return true;
}

map<string, int> q;

int who(string s) {
    if (q.find(s) == q.end()) return -1;
    return q[s];
}

int main() {
    q["00001"] = 0;
    q["10001"] = 1;
    q["01001"] = 2;
    q["11000"] = 3;
    q["00101"] = 4;
    q["10100"] = 5;
    q["01100"] = 6;
    q["00011"] = 7;
    q["10010"] = 8;
    q["10000"] = 9;
    q["00100"] = 10;
    q["00110"] = 11;

    int n;
    int it = 0;
    while (true) {
        scanf("%d", &n);
        ++it;
        if (n == 0) break;
        printf("Case %d: ", it);

        vector<int> a(n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        if ((n % 6) != 5) {
            puts("bad code");
            continue;
        }
        if (n < 29) {
            puts("bad code");
            continue;
        }

        double mn = a[0];
        for (int i = 0; i < n; ++i)
            mn = min(mn, double(a[i]));

        double lmn = a[0] * 0.95;
        double rmn = a[0] / 0.95 * 1.05;

        const int iter = 300;
        int which = -1;
        for (int i = 0; i <= iter; ++i)  {
            double cand = lmn + (rmn - lmn) / iter * i;
            if (check(a, cand)) {
                which = cand;
                break;
            }
        }
        if (which == -1) {
            puts("bad code");
            continue;
        }

        double x = lmn + (rmn - lmn) / iter * which;
        double l1 = 0.95 * x, r1 = 1.05 * x;
        string wide;
        for (int i = 0; i < n; ++i)
            if ( l1 <= a[i] && a[i] <= r1 ) {
                wide += '0';
            } else {
                wide += '1';
            }

        if (who(wide.substr(0, 5)) != 11) {
            reverse(wide.begin(), wide.end());
        }

        bool cool = (who(wide.substr(0, 5)) == 11);
        for (int i = 5; i < n; i += 6)
            if (wide[i] == '1') {
                cool = false;
                break;
            }

        vector<int> chars;
        for (int i = 0; i < n; i += 6) {
            chars.push_back(who(wide.substr(i, 5)));
            if (chars.back() == -1) cool = false;
        }
        if (chars.back() != 11) cool = false;
        for (int i = 1; i + 1 < chars.size(); ++i)
            if (chars[i] == 11) cool = false;
        if (!cool) {
            puts("bad code");
            continue;
        }

        n = chars.size();
        int K = chars[n - 3], C = 0;
        for (int i = 1; i < n - 3; ++i) {
            C += (((n - 4 - i) % 10) + 1) * chars[i];
            K += (((n - 3 - i) % 9) + 1) * chars[i];
        }
        C %= 11;
        K %= 11;

        if (C != chars[n - 3]) {
            puts("bad C");
            continue;
        }
        if (K != chars[n - 2]) {
            puts("bad K");
            continue;
        }

        for (int i = 1; i < n - 3; ++i) {
            int c = chars[i];
            if (c < 10) printf("%d", c);
            else putchar('-');
        }
        puts("");
    }

    return 0;
}
