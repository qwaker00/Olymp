#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <memory.h>

using namespace std;

const int N = 16;

int n;
int a[N], b[N], c[N];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        int s = 0;
        for (int i = 0; i < n; ++i) { 
            scanf("%d", a + i);
            --a[i];
            s += a[i];
            b[i] = i;
        }        
        bool done = (s % n) == 0; 
        if (done) { 
            puts("Sepehr");
        }
        else puts("Sohrab");
    }

    return 0;
}