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


inline void turnX(string& s) {
    char t = s[0];
    s[0] = s[3];
    s[3] = s[5];
    s[5] = s[1];
    s[1] = t;    
}
inline void turnY(string& s) {
    char t = s[0];
    s[0] = s[4];
    s[4] = s[5];
    s[5] = s[2];
    s[2] = t;    
}
inline void turnZ(string& s) {
    char t = s[2];
    s[2] = s[1];
    s[1] = s[4];
    s[4] = s[3];
    s[3] = t;    
}
string Canon(string s) {
    string ans = s;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                turnX(s);
                if (s < ans) ans = s;
            }
            turnY(s);
        }
        turnZ(s);
    }
    return ans;
}

vector<string> faces;
string all;
int op[7];


int main() {
    freopen("cube.in", "r", stdin);
    freopen("cube.out", "w", stdout);
    
    for (int i = 0; i < 6; ++i) { 
        string face;
        cin >> face;
        sort(face.begin() + 1, face.end());
        all += face[0];
        faces.push_back(face);
    }
    sort(faces.begin(), faces.end());

    op[0] = 5;
    op[5] = 0;
    op[1] = 3;
    op[3] = 1;
    op[2] = 4;
    op[4] = 2;

    set<string> anses;

    sort(all.begin(), all.end());
    do {
        vector<string> nfaces;
        for (int i = 0; i < 6; ++i) {
            string face;
            face += all[i];

            for (int j = 0; j < 6; ++j)
                if (j != i && j != op[i]) face += all[j];

            sort(face.begin() + 1, face.end());
            nfaces.push_back(face);
        }
        sort(nfaces.begin(), nfaces.end());

        if (faces == nfaces) {
            anses.insert(Canon(all));    
        }
    } while (next_permutation(all.begin(), all.end()));

    if (anses.size() == 0) {
        puts("Impossible");
        return 0;
    }

    cout << *anses.begin() << endl;
    if (anses.size() > 1) cout << *anses.rbegin() << endl;

    return 0;
}
