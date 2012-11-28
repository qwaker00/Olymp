#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <sstream>
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

int n, m, k, smin, smax;
char buf[20000000];
int alfn = 0;
char ch[33];
string let[256][33];

char sa[33], sb[33];
int l;
char field[33][2222];
int f[33][2222];
int rest[2222];
int start[2222];
int freePen[2222][33];
int letPen[256][2222];

int pr[33][2222];

                        
void Min(int& x, int y, int &pr, int j) {
    if (y < x) {
        x = y;
        pr = j;
    }
}

int main() {
    freopen("caption.in", "r", stdin);
    freopen("caption.out", "w", stdout);

    cin >> n >> m >> k >> smin >> smax;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        gets(buf);
        istringstream s(buf); 

        int j = 0;
        while (s) {
            if (i == 0) {
                s >> ch[j];
                if (s.eof()) break;
            }
            s >> let[ ch[j] ][i];
            ++j;
            if (s.eof()) break;
       }
       alfn = max(alfn, j);
    }
    ch[alfn++] = ' ';

    string zero;
    for (int i = 0; i < k; i++) zero += '.';
    for (int i = 0; i < n; i++) let[' '][i] = zero;

    memset(field, '.', sizeof(field));
    memset(freePen, 63, sizeof(freePen));
    memset(letPen, 63, sizeof(letPen));
     
    for (int i =0; i < n; i++) field[i][m] = 0;

    gets(sa);
    int la = strlen(sa);

    int totp = 0;
    for (int i = 0; i < la; i++) {
        int p;
        cin >> p;
        totp += p;

        for (int j = 0; j < n ; j++) 
            for (int l = 0; l < k; l++) {
                field[j][l + totp] = let[ sa[i] ][j][l];
            }
        totp += k;
    }


    rest[m] = 0;
    int cnt = 0;
    for (int i = m - 1; i >= 0; i--) { 
        for (int j = 0; j < n; j++) cnt += field[j][i] == '*';
        rest[i] = cnt;
//        cerr << rest[i] << endl;
    }

    start[0] = 0;
    cnt = 0;
    for (int i = 1; i <= m; i++) { 
        for (int j = 0; j < n; j++) cnt += field[j][i - 1] == '*';
        start[i] = cnt;
//        cerr << rest[i] << endl;
    }

    for (int i = 0; i <= m; i++) {
        int pen = 0;
        for (int j = 0; j <= smax && i + j <= m; j++) {
            freePen[i][j] = pen;
            for (int l = 0; l < n; l++)
                pen += (field[l][i + j] == '*');
        }
    }

    for (int it = 0;  it < alfn; ++it) {
        char c = ch[it];
        for (int x = 0; x + k <= m; x++) {
            letPen[c][x] = 0;

            for (int i = 0; i < n; i ++)
                for (int j = 0; j < k; j++)
                    letPen[c][x] += field[i][j + x] != let[c][i][j]; 
        }
    }
    

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) cout << field[i][j];
//        cout << endl;
//    }


    gets(sb);
    gets(sb);
    int lb = strlen(sb);

    memset(pr, -1, sizeof(pr));

    memset(f, 63, sizeof(f));
    for (int j = 0; j + k <= m; j++)
        f[1][j + k] = letPen[sb[0]][j] + start[j];

    for (int i = 1; i < lb; i++) {
        for (int j = 0; j + k <= m; j++) if (f[i][j] < 1000000000) {
            for (int shift = smin; shift <= smax && j + shift + k <= m; shift++) {

                int penalty = freePen[j][shift] + letPen[ sb[i] ][j + shift];

                Min(f[i + 1][j + shift + k], f[i][j] + penalty, pr[i + 1][j + shift + k], j);
            }
        }
    }
    int ans = 1e9, ansx = -1;
    for (int i = 0; i <= m; i++) if (f[lb][i] + rest[i] < ans) {
        ans = f[lb][i] + rest[i];
        ansx = i;
    } 
    vector<int> out;
    int it = lb;
    while (ansx >= 0) {
        out.push_back(ansx);
        cerr << ansx << endl;
        ansx = pr[it][ansx];
        it--;
    }

//    cout << ans << endl;
    int last = 0;
    for (int i = (int)out.size() - 1; i >= 0; i--) {
//        cerr << letPen[sb[out.size() - i - 1]][out[i] - k] << endl;
//        cerr << sb[out.size() - i - 1] << " " << out[i] - k << endl;
//        cerr << freePen[out[i] - k - 1][1] << endl;
        
        cout << out[i] - k - last << " ";
        last = out[i];
    }
    cout << endl;
    
    return 0;
}
