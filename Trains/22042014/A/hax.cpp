#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int a[1111], n, unk[1111], h[5555], hn = 0;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d\n", &n);
    char buf[11];
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        if (strcmp(buf, "x") == 0) {
           unk[i] = 1;
        } else {
            a[i] = atoi(buf);
        }
        for (int j = -2; j <= 2; ++j)
            h[hn++] = a[i] + j;
    }
    std::sort(h, h + hn);
    hn = std::unique(h, h + hn) - h;

    int cnt = 0, last = -1;
    for (int i = 0; i < hn; ++i) {
        int x = h[i], good = 1;
        for (int j = 0; j < n; ++j) {
            if (unk[j]) a[j] = x;
            if (j) {
                if (j & 1 && a[j] <= a[j - 1]) {
                    good = 0;
                    break;
                } else
                    if (!(j & 1) && a[j] >= a[j - 1]) {
                        good = 0;
                        break;
                    }
            }
        }
        if (good) {
            ++cnt;
            last = x;
        }
    }
    if (cnt < 1)
        puts("none");
    else if (cnt > 1)
        puts("ambiguous");
    else {
        printf("%d\n", last);
    }

    return 0;
}

