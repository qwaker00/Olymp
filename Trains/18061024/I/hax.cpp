#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char s[11111];
int n;

const char * parseGoo(const char * s) {
    if (s[0] == 'D' || s[0] == 'E') {
        if (s[1] == 'F') {
            int i = 1;
            while (s[i] == 'F') ++i;
            if (s[i] == 'G') return s + i + 1;
            const char * goo = parseGoo(s + i);
            if (!goo) return NULL;
            return goo;
        }
        return NULL;
    }
    return NULL;
}

const char * parsePoo(const char * s) {
    if (s[0] == 'A') {
        if (s[1] == 'H') return s + 2;
        if (s[1] == 'B') {
            const char* poo = parsePoo(s + 2);
            if (!poo) return NULL;
            if (*poo == 'C') {
                return poo + 1;
            }
            return NULL;
        }
        const char * goo = parseGoo(s + 1);
        if (!goo) return NULL;
        if (*goo == 'C')
            return goo + 1;
        return NULL;
    }
    return NULL;
}

const char * parseSlurm(const char * s) {
    const char * poo = parsePoo(s);
    if (!poo) return NULL;
    const char * goo = parseGoo(poo);
    if (!goo) return NULL;
    if (*goo) return NULL;
    return goo;
}

int main() {
    freopen("slurm.in", "r", stdin);
    freopen("slurm.out", "w", stdout);

    scanf("%d\n", &n);
    while (n--) {
        gets(s);
        puts( (parseSlurm(s) != NULL) ? "YES" : "NO");
    }


    return 0;
}
