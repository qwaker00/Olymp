#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <vector>

using namespace std;

struct cell {
    int x, y, z;

    cell(int ax = 0, int ay = 0, int az = 0)
        : x(ax)
        , y(ay)
        , z(az)
    {}
};

vector<cell> cur;
vector<cell> answer;
int ans;
int a, b, c;
int limit;
typedef long long ll;
ll start;
bool used[11][11][11];

int D[][3] = { {0, 1, 2}, {0, -1, 2}, {0, 1, -2}, {0, -1, -2}, {0, 2, 1}, {0, -2, 1}, {0, 2, -1}, {0, -2, -1},  };

void rec(int l, int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x >= a || y >= b || z >= c || used[x][y][z]) return;
    cur.push_back(cell(x, y, z));
    if (l == limit) {
        ans = 1;
        answer = cur;
        return;
    }
    if (clock() - start > 500 * CLOCKS_PER_SEC) {
        ans = 2;
        return;
    }
    used[x][y][z] = true;

    for (int i = 0; i < 8; ++i) {
        rec(l + 1, x + D[i][0], y + D[i][1], z + D[i][2]);
        if (ans > 0) return;
        rec(l + 1, x + D[i][1], y + D[i][0], z + D[i][2]);
        if (ans > 0) return;
        rec(l + 1, x + D[i][2], y + D[i][0], z + D[i][1]);
        if (ans > 0) return;
    }

    cur.pop_back();
    used[x][y][z] = 0;
    if (l == 1) {
        ans = 0;
    }
}

int main() {
    freopen("out", "w", stdout);

    int N = 5;
    for (a = 1; a <= N; ++a)
        for (b = a; b <= N; ++b)
            for (c = b; c <= N; ++c) {
                ans = -1;
                answer.clear();
                memset(used, 0, sizeof(used));

                start = clock();
                limit = a * b * c;
                rec(1, 0, 0, 0);

                cout << a << " " << b << " " << c << endl;
                if (ans == 1) {
                    cout << "YES" << endl;
                    for (int i = 0; i < answer.size(); ++i) {
                        cout << "\t" << answer[i].x << " " << answer[i].y << " " << answer[i].z << endl;
                    }
                } else if (ans == 0) {
                    cout << "NO" << endl;
                } else {
                    cout << "MAYBE" << endl;
                }
            }

    return 0;
}
