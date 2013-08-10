#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


char s[1111111], cmd[1111111], curv[1111111], d1[1111111], d2[1111111];
int ops[1111111], vals[1111111], on = 0, vn = 0, prior[255], cn = 0;
int used[1111111];
int pr[1111111];

int fs(int x) {
    if (pr[x] != x) pr[x] = fs(pr[x]);
    return pr[x];
}

int Div(int x, int y) {
    if (x < 0 && y < 0) {
        return (-x) / (-y);
    } else
    if (x < 0 && y >= 0) {
        return -((-x) / y);
    } else
    if (x >= 0 && y < 0) {
        return -(x / (-y));
    } else {
        return x / y;
    }
}

int Mod(int x, int y) {
    if (x < 0 && y < 0) {
        return (-x) % (-y);
    } else
    if (x < 0 && y >= 0) {
        return -((-x) % y);
    } else
    if (x >= 0 && y < 0) {
        return -(x % (-y));
    } else {
        return x % y;
    }
}

int Pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

void make_op() {
#ifdef DEBUG
    if (on == 0) {
        cerr << "no op" << endl;
    }
#endif

    char op = ops[--on];
    if (op == '+') {
        int v2 = vals[--vn];
        int v1 = vals[--vn];
        vals[vn++] = v1 + v2;
    } else
    if (op == '-') {
        int v2 = vals[--vn];
        int v1 = vals[--vn];
        vals[vn++] = v1 - v2;
    } else
    if (op == '*') {
        int v2 = vals[--vn];
        int v1 = vals[--vn];
        vals[vn++] = v1 * v2;
    } else
    if (op == '/') {
        int v2 = vals[--vn];
        int v1 = vals[--vn];
        vals[vn++] = Div(v1, v2);
    } else
    if (op == '%') {
        int v2 = vals[--vn];
        int v1 = vals[--vn];
        vals[vn++] = Mod(v1, v2);
    } else
    if (op == '^') {
        int v2 = vals[--vn];
        int v1 = vals[--vn];
        vals[vn++] = Pow(v1, v2);
    }
}

map<std::string, int> ids;
int idcnt;
int real[1111111];

int lower(char x) {
    if (x >= 'A' && x <= 'Z') return x ^ 32;
    return x;
}

int getid(char * s, bool create) {
    map<std::string, int>::iterator ii = ids.find(s);
    if (ii != ids.end()) return ii->second;
    ids[s] = ++idcnt;
    pr[idcnt] = idcnt;
    if ( (s[0] >= '0' && s[0] <= '9') || s[0] == '-' ) {
        sscanf(s, "%d", &real[idcnt]);
    }
    return idcnt;
}

int getv() {
    int id = getid(curv, true);
    return real[fs(id)];
}

int main() {
    freopen("plcool.in", "r", stdin);
    freopen("plcool.out", "w", stdout);

    prior['+'] = prior['-'] = 1;
    prior['*'] = prior['/'] = prior['%'] = 2;
    prior['^'] = 3;
    prior['('] = 0;

    while (gets(s)) {
        int l = strlen(s);
        if (l == 0) continue;

        sscanf(s, "%s ", cmd);
        if (strcmp(cmd, "print") == 0) {
            cn = 0;
            on = 0;
            vn = 0;

            bool lastc = true;
            int cheatc = 0;

            s[l++] = ')';
            s[l] = 0;
            s[5] = '(';
            for (int i = 5; i < l; ++i) {
                if (s[i] == '\t' || s[i] == ' ') continue;
                if ( (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                    curv[cn++] = lower(s[i]);
                    lastc = false;
                } else {
                    if (cn > 0) {
                        curv[cn] = 0;
                        vals[vn++] = getv();
                        cn = 0;
                        if (cheatc) {
                            while (ops[on - 1] != '(') make_op();
                            --on;
                            --cheatc;
                        }
                    }
                    if (s[i] == '(') {
                        ops[on++] = '(';
                    } else
                    if (s[i] == ')') {
                        while (ops[on - 1] != '(') make_op();
                        --on;
                    } else
                    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^') {
                        if ((s[i] == '+' || s[i] == '-') && lastc == true) {
                            vals[vn++] = 0;
                            ops[on++] = '(';
                            cheatc++;
                        }
                        while (on > 0 && (s[i] != '^' && prior[ops[on - 1]] >= prior[s[i]])) make_op();
                        ops[on++] = s[i];
                    }

                    lastc = true;
                }
            }
            printf("%d\n", vals[0]);
        } else 
        if (strcmp(cmd, "define") == 0) {
            sscanf(s + 7, "%s", d1);
            int l1 = strlen(d1);

            sscanf(s + 8 + l1, "%s", d2);
            int l2 = strlen(d2);

            for (int i = 0; i < l1; ++i) d1[i] = lower(d1[i]);
            for (int i = 0; i < l2; ++i) d2[i] = lower(d2[i]);

            int i1 = getid(d1, true);
            int i2 = getid(d2, true);

            if (used[i1]) continue;
            if (fs(i1) == fs(i2)) continue;
            pr[i1] = i2;
            used[i1] = true;
        }
    }
    
    return 0;
}
