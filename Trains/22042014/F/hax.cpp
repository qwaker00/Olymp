#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <vector>

const int MOD = 1000000007;
typedef long long LL;

char s[111111];

int shift(int x, int y) {
    if (y > 30) {
        return 0;
    }
    return x >> y;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    gets(s);
    int l = strlen(s);

    {
        int ll = 0;
        for (int i = 0; i < l; ++i)
            if (s[i] != ' ')
                s[ll++] = s[i];
        l = ll;
    }

    int i = l - 1;
    int last = 0;
    std::vector<int> vals;
    std::vector<int> ops;
    while (i >= 0) {
        if (s[i] == '<') {
            --i;
            assert(i >= 0 && s[i] == 'S');
            --i;

            while (ops.size() && ops.back() == '>') {
                assert(vals.size() > 1);
                int x = vals.back(); vals.pop_back();
                vals.back() = shift(x,  vals.back());
                ops.pop_back();
            }

            assert(ops.size() && ops.back() == 'S');
            vals.back() = ((LL)vals.back() * vals.back()) % MOD;
            ops.pop_back();

            last = 1;
        } else
        if (s[i] == '>') {
            if (last == 1) { // >>
                --i;
                assert(i >= 0 && s[i] == '>');
                --i;
                ops.push_back('>');
                last = 0;
            } else {
                ops.push_back('S');
                --i;
                last = 0;
            }
        } else {
            int x = 0;
            int j = i;
            while (j >= 0 && s[j] >= '0' && s[j] <= '9') --j;
            for (int di = j + 1; di <= i; ++di) {
                x = x * 10 + s[di] - '0';
            }
            i = j;
            vals.push_back(x);
            last = 1;
        }
    }
    while (ops.size() && ops.back() == '>') {
        assert(vals.size() > 1);
        int x = vals.back(); vals.pop_back();
        vals.back() = shift(x, vals.back());
        ops.pop_back();
    }
    assert(vals.size() == 1);
    printf("%d\n", vals[0]);

    return 0;
}

