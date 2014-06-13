#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Tp {
    int x, y;

    bool operator<(const Tp& t) const {
        return x < t.x || x == t.x && y < t.y;
    }
} a[1111];
int n;

inline bool find(int x, int y) {
    Tp p = {x, y};
    int pos = lower_bound(a, a + n, p) - a;
    return (pos < n && a[pos].x == x && a[pos].y == y);
}

int main() {
    freopen("squares.in", "r", stdin);
    freopen("squares.out", "w", stdout);

    scanf("%d", &n);
    while (n != 0) {
        for (int i =0; i < n; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        sort(a, a + n);

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) if (i != j) {
                int dx = a[j].x - a[i].x;
                int dy = a[j].y - a[i].y;
                if (find(a[j].x + dy, a[j].y - dx) && find(a[j].x + dy - dx, a[j].y - dx - dy)) {
                    ++ans;
                }
            }
        }
        printf("%d\n", ans / 4);

        scanf("%d", &n);
    }


    return 0;
}
