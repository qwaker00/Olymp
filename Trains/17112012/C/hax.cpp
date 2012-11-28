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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

priority_queue<int> q1, q2; 


char w[44];
int n;

void balance() {
//    cerr << q1.size() << " " << q2.size() << endl;

    int need = (n / 2) + 1;
    if (n & 1) need = (n + 1) / 2;

    if (!n) return;

           while (q1.size() > need) {
                int x = q1.top(); q1.pop();
                q2.push(-x);
            } 
            while (q1.size() < need) {
                int x = -q2.top(); q2.pop();
                q1.push(x); 
            }

    while (q1.size() > 0 && q2.size() > 0) {
        int x = q1.top(), y = -q2.top();
        if (x > y) {
            q1.pop();
            q2.pop();
            q1.push(y);
            q2.push(-x);
            //cerr << "swapped " << x << " and " << y << endl;
        } else break;
    }



}


int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    while (gets(w)) {
        int x;

        if (w[0] == '#') {
            printf("%d\n", q1.top());
            q1.pop();
            n--;
            balance();
            
        } else {
            n++;
            sscanf(w, "%d", &x);

            q1.push(x);
            balance();
        }
    }


    return 0;
}
