#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acosl(-1.);
using namespace std;
 
char w[111];
int a[111];
int b[11111];
int cnt;
 
int ans[11111], ansl = 1;
 
void mul(ull x) {
    ull carry = 0;
    for (int i = 0; i < ansl; ++i) {
        ull res = carry + ans[i] * x;
        ans[i] = res % 10;
        carry = res / 10;
    }
    while (carry) {
        ans[ansl++] = carry % 10;
        carry /= 10;
    }
}
 
int main() {
    freopen("digit.in", "r", stdin);
    freopen("digit.out", "w", stdout);
   
    gets(w);
    int l = strlen(w);
 
    for (int i = l - 1; i >= 0; --i) {
        a[l - 1 - i] = w[i] - '0';
    }
   
    if (l == 1 && a[0] == 0) {
        puts("1");
        return 0;
    }
 
    while (l != 1 || a[0] != 0) {
        if (a[0] & 1) {
            b[cnt++] = 1;
        } else {
            b[cnt++] = 0;
        }
 
        int carry = 0;
        int pos = l - 1;
        while (pos >= 0) {
            int res = a[pos] + carry;
            a[pos] = res / 2;
            carry =  10 * (res & 1);
            --pos;
        }
        while (l > 1 && a[l - 1] == 0) --l;
    }
 
    ansl = 1;
    ans[0] = 1;
    for (int i = 0; i < cnt; ++i) {
        if (b[i] == 0 && b[i + 1] == 1) {
            ull sz = 2;
            for (int j = i + 2; b[j]; ++j) {
                ++sz;
            }
 
            mul(sz);
        }
    }
 
    for (int i = ansl - 1; i >= 0; --i) putchar(ans[i] + '0');
    puts("");
 
    return 0;
}