#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

const int N = 200111;
const int INF = 1 << 30;
char w[N];
int n;

int ans = INF;
vector<int> permutation;
int bestpos = -1;

int cnt[32][2][32];
int a[32][32];
int u[33], v[33], p[33];
int where[32];
int links[32], mins[32], visited[32];

vector<int> hungarian(int height, int width, int& result) {
    memset(where, -1, sizeof(where));
    memset(u, -1, sizeof(u));
    while (true) {
        memset(state, 0, sizeof(state));
        memset(p, -1, sizeof(p));
        memset(v, 127, sizeof(v));
        deque<int> q;
        for (int i = 0; i < height; ++i) if (where[i] == -1) {
            q.push_back(i);
            state[i] = 1;
            v[i] = 0;
        }
        while (!q.empty()) {
            int x = q.front(); q.pop_front();
            for (int i = 0; i < width; ++i)
                if (u[i] == -1 && v[32] > v[x] + a[x][i]) {
                    v[32] = v[x] + a[x][i];
                    p[32] = x;
                }
        }
    }
    

    memset(u, 0, sizeof(u));
    memset(v, 0, sizeof(v));

    for (int i = 0; i < height; ++i) {
        memset(links, -1, sizeof(links));
        memset(mins, 63, sizeof(links));
        memset(visited, 0, sizeof(visited));

        int selectedRow = i, selectedCol = -1;
        while (selectedRow != -1) {
            int minColumn = -1;
            for (int col = 0; col < width; ++col)
                if (!visited[col]) {
                    if (a[selectedRow][col] - u[selectedRow] - v[col] < mins[col]) {
                        mins[col] = a[selectedRow][col] - u[selectedRow] - v[col];
                        links[col] = selectedCol;
                    }
                    if (minColumn == -1 || mins[col] < mins[minColumn]) {
                        minColumn = col;
                    }
                }

            int delta = mins[minColumn];
            for (int col = 0; col < width; ++col) {
                if (visited[col]) {
                    u[ where[col] ] += delta;
                    v[col] -= delta;
                } else {
                    mins[col] -= delta; 
                }
            }
            u[i] += delta;

            visited[minColumn] = true;
            selectedCol = minColumn;
            selectedRow = where[minColumn];
        }
        
        while (links[selectedCol] != -1) {
            where[selectedCol] = where[ links[ selectedCol ] ];
            selectedCol = links[selectedCol];
        }
        where[selectedCol] = i;
    }

    result = 0;
    vector<int> ans(height);
    for (int j = 0; j < width; ++j)
        if (where[j] != -1) {
            ans[ where[j] ] = j;
            result += a[ where[j] ][j];
        }
    return ans;
}

bool used[32];

void rec(int level, int first) {
    if (first >= n) {
        int cost;
        vector<int> cand = hungarian(level, 26, cost);

        if (cost < ans) {
            ans = cost;
            bestpos = (1 << level) - first;
            permutation = cand;
        }
        return;
    }
    
    int step = 1 << level;
    memset(cnt[level], 0, sizeof(cnt[level]));
    int parity = 0;
    int current = first;
    do {
        cnt[level][parity][ w[current] - 'a' ]++;
        parity ^= 1;
        current += step;
    } while (current < n);

    for (int i = 0; i < 2; ++i) {
        int sum = 0;
        for (int j = 0; j < 26; ++j) sum += cnt[level][i][j];
        for (int j = 0; j < 26; ++j) {
            a[level][j] = sum - cnt[level][i][j]; 
        }

        if (sum) {
            rec(level + 1, first + step * (1 - i));
        }
    }
}

int main() {
    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);
    
    gets(w);
    n = strlen(w);

    rec(0, 0);

    printf("%d\n", ans);
    printf("%d\n", bestpos);
    for (int i = 0; i < permutation.size(); ++i) {
        putchar('a' + permutation[i]);
        used[permutation[i]] = true;
    }
    for (int i = 0; i < 26; ++i) 
        if (!used[i]) {
            putchar(i + 'a');
        }
    puts("");

    return 0;
}
