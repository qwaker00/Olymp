#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <memory.h>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

#define ch(x, y) ((x) >= 0 && (y) >= 0 && (x) <= 3 && (y) <= 3 && f[x][y] == '.')

unordered_map<string, int > id;
vector<int> g1[22222], g1r[22222];
vector<int> g2[22222];
int win[22222], was[22222];

int getnewid(const vector<string> & f) {
    const string ff = f[0] + f[1] + f[2] + f[3];
    auto fi = id.find(ff);
    if (fi == id.end()) {
        id[ff] = id.size() + 1;
        return id.size();
    }
    return -1;
}

int getid(const vector<string> & f) {
    const string ff = f[0] + f[1] + f[2] + f[3];
    auto fi = id.find(ff);
    if (fi == id.end()) {
        id[ff] = id.size() + 1;
        return id.size();
    }
    return fi->second;
}

vector<string> rev(const vector<string>& f) {
    vector<string> res(f);
    for (int i= 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
        if (f[i][j] == '*')
            res[i][j] = '#';
        else if (f[i][j] == '#')
            res[i][j] = '*';
    return res;
}

int main() {
    freopen("lgame.in", "r", stdin);
    freopen("lgame.out", "w", stdout);

    int total = 0;

    vector<string> f(4, "....");
    for (int i1 = 0; i1 < 4; ++i1)
    for (int j1 = 0; j1 < 4; ++j1) {
        f[i1][j1] = 'x';
        for (int i2 = 0; i2 < 4; ++i2)
        for (int j2 = 0; j2 < 4; ++j2) if (f[i2][j2] == '.') {
            f[i2][j2] = 'x';
            for (int d1 = 0; d1 < 4; ++d1)
            for (int dd1 = -1; dd1 <= 1; dd1 += 2)
            for (int p1x = 0; p1x < 4; ++p1x)
            for (int p1y = 0; p1y < 4; ++p1y)
                if (ch(p1x, p1y) &&
                    ch(p1x + dx[d1], p1y + dy[d1]) &&
                    ch(p1x + dx[d1] * 2, p1y + dy[d1] * 2) &&
                    ch(p1x + dx[d1] * 2 - dd1 * dy[d1], p1y + dy[d1] * 2 + dd1 * dx[d1])
                    )
                {
                    f[p1x][p1y] = f[p1x + dx[d1]][p1y + dy[d1]] =
                       f[p1x + dx[d1] * 2][p1y + dy[d1] * 2] =
                       f[p1x + dx[d1] * 2 - dd1 * dy[d1]][p1y + dy[d1] * 2 + dd1 * dx[d1]] = '*';

                    for (int d2 = 0; d2 < 4; ++d2)
                    for (int dd2 = -1; dd2 <= 1; dd2 += 2)
                    for (int p2x = 0; p2x < 4; ++p2x)
                    for (int p2y = 0; p2y < 4; ++p2y)
                        if (ch(p2x, p2y) &&
                            ch(p2x + dx[d2], p2y + dy[d2]) &&
                            ch(p2x + dx[d2] * 2, p2y + dy[d2] * 2) &&
                            ch(p2x + dx[d2] * 2 + dd2 * dy[d2], p2y + dy[d2] * 2 - dd2 * dx[d2])
                            )
                        {
                            f[p2x][p2y] = f[p2x + dx[d2]][p2y + dy[d2]] =
                               f[p2x + dx[d2] * 2][p2y + dy[d2] * 2] =
                               f[p2x + dx[d2] * 2 + dd2 * dy[d2]][p2y + dy[d2] * 2 - dd2 * dx[d2]] = '#';

                            int X = getid(f);
                            if (!was[X]) {
                            was[X] = 1;
                            ++total;

                            // moves of first
                            {
                                f[p2x][p2y] = f[p2x + dx[d2]][p2y + dy[d2]] =
                                   f[p2x + dx[d2] * 2][p2y + dy[d2] * 2] =
                                   f[p2x + dx[d2] * 2 + dd2 * dy[d2]][p2y + dy[d2] * 2 - dd2 * dx[d2]] = '.';

                                {
                                for (int d2 = 0; d2 < 4; ++d2)
                                for (int dd2 = -1; dd2 <= 1; dd2 += 2)
                                for (int p2x = 0; p2x < 4; ++p2x)
                                for (int p2y = 0; p2y < 4; ++p2y)
                                    if (ch(p2x, p2y) &&
                                        ch(p2x + dx[d2], p2y + dy[d2]) &&
                                        ch(p2x + dx[d2] * 2, p2y + dy[d2] * 2) &&
                                        ch(p2x + dx[d2] * 2 + dd2 * dy[d2], p2y + dy[d2] * 2 - dd2 * dx[d2])
                                        )
                                    {
                                        f[p2x][p2y] = f[p2x + dx[d2]][p2y + dy[d2]] =
                                           f[p2x + dx[d2] * 2][p2y + dy[d2] * 2] =
                                           f[p2x + dx[d2] * 2 + dd2 * dy[d2]][p2y + dy[d2] * 2 - dd2 * dx[d2]] = '#';

                                        f[i1][j1] = '.';
                                        {
                                        for (int i1 = 0; i1 < 4; ++i1)
                                        for (int j1 = 0; j1 < 4; ++j1) if (ch(i1, j1)) {
                                            f[i1][j1] = 'x';

                                            if (getid(f) != X) {
                                                int Y = getid(rev(f));
                                                g1[X].push_back(Y);
                                                g1r[Y].push_back(X);
                                                ++total;
                                            }

                                            f[i1][j1] = '.';
                                        }
                                        }
                                        f[i1][j1] = 'x';

                                        f[i2][j2] = '.';
                                        {
                                        for (int i2 = 0; i2 < 4; ++i2)
                                        for (int j2 = 0; j2 < 4; ++j2) if (ch(i2, j2)) {
                                            f[i2][j2] = 'x';

                                            if (getid(f) != X) {
                                                int Y = getid(rev(f));
                                                g1[X].push_back(Y);
                                                g1r[Y].push_back(X);
                                                ++total;
                                            }

                                            f[i2][j2] = '.';
                                        }
                                        }
                                        f[i2][j2] = 'x';

                                        f[p2x][p2y] = f[p2x + dx[d2]][p2y + dy[d2]] =
                                           f[p2x + dx[d2] * 2][p2y + dy[d2] * 2] =
                                           f[p2x + dx[d2] * 2 + dd2 * dy[d2]][p2y + dy[d2] * 2 - dd2 * dx[d2]] = '.';
                                    }
                                }

                                f[p2x][p2y] = f[p2x + dx[d2]][p2y + dy[d2]] =
                                   f[p2x + dx[d2] * 2][p2y + dy[d2] * 2] =
                                   f[p2x + dx[d2] * 2 + dd2 * dy[d2]][p2y + dy[d2] * 2 - dd2 * dx[d2]] = '#';
                            }

                            /*
                            // moves of second
                            {
                                f[p1x][p1y] = f[p1x + dx[d1]][p1y + dy[d1]] =
                                   f[p1x + dx[d1] * 2][p1y + dy[d1] * 2] =
                                   f[p1x + dx[d1] * 2 - dd1 * dy[d1]][p1y + dy[d1] * 2 + dd1 * dx[d1]] = '.';

                                {
                                    for (int d1 = 0; d1 < 4; ++d1)
                                    for (int dd1 = -1; dd1 <= 1; dd1 += 2)
                                    for (int p1x = 0; p1x < 4; ++p1x)
                                    for (int p1y = 0; p1y < 4; ++p1y)
                                    if (ch(p1x, p1y) &&
                                            ch(p1x + dx[d1], p1y + dy[d1]) &&
                                            ch(p1x + dx[d1] * 2, p1y + dy[d1] * 2) &&
                                            ch(p1x + dx[d1] * 2 - dd1 * dy[d1], p1y + dy[d1] * 2 + dd1 * dx[d1])
                                       )
                                    {
                                        f[p1x][p1y] = f[p1x + dx[d1]][p1y + dy[d1]] =
                                           f[p1x + dx[d1] * 2][p1y + dy[d1] * 2] =
                                           f[p1x + dx[d1] * 2 - dd1 * dy[d1]][p1y + dy[d1] * 2 + dd1 * dx[d1]] = '*';

                                        f[i1][j1] = '.';
                                        {
                                        for (int i1 = 0; i1 < 4; ++i1)
                                        for (int j1 = 0; j1 < 4; ++j1) if (ch(i1, j1)) {
                                            f[i1][j1] = 'x';

                                            int Y = getid(f);
                                            g2[X].push_back(Y);
                                            ++total;

                                            f[i1][j1] = '.';
                                        }
                                        }
                                        f[i1][j1] = 'x';

                                        f[i2][j2] = '.';
                                        {
                                        for (int i2 = 0; i2 < 4; ++i2)
                                        for (int j2 = 0; j2 < 4; ++j2) if (ch(i2, j2)) {
                                            f[i2][j2] = 'x';

                                            int Y = getid(f);
                                            g2[X].push_back(Y);
                                            ++total;

                                            f[i2][j2] = '.';
                                        }
                                        }
                                        f[i2][j2] = 'x';

                                        f[p1x][p1y] = f[p1x + dx[d1]][p1y + dy[d1]] =
                                           f[p1x + dx[d1] * 2][p1y + dy[d1] * 2] =
                                           f[p1x + dx[d1] * 2 - dd1 * dy[d1]][p1y + dy[d1] * 2 + dd1 * dx[d1]] = '.';

                                    }
                                }

                                f[p1x][p1y] = f[p1x + dx[d1]][p1y + dy[d1]] =
                                   f[p1x + dx[d1] * 2][p1y + dy[d1] * 2] =
                                   f[p1x + dx[d1] * 2 - dd1 * dy[d1]][p1y + dy[d1] * 2 + dd1 * dx[d1]] = '*';
                            }
                            */
                            }

                            f[p2x][p2y] = f[p2x + dx[d2]][p2y + dy[d2]] =
                               f[p2x + dx[d2] * 2][p2y + dy[d2] * 2] =
                               f[p2x + dx[d2] * 2 + dd2 * dy[d2]][p2y + dy[d2] * 2 - dd2 * dx[d2]] = '.';
                        }
                    f[p1x][p1y] = f[p1x + dx[d1]][p1y + dy[d1]] =
                       f[p1x + dx[d1] * 2][p1y + dy[d1] * 2] =
                       f[p1x + dx[d1] * 2 - dd1 * dy[d1]][p1y + dy[d1] * 2 + dd1 * dx[d1]] = '.';

                }
            f[i2][j2] = '.';
        }
        f[i1][j1] = '.';
    }


    memset(win, -1, sizeof(win));
    queue<int> q;
    for (auto& i : id) {
        if (g1[i.second].size() == 0) {
            win[i.second] = 0;
            q.push(i.second);
            cerr << i.second << endl;
        }
    }
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (int i = 0; i < g1r[t].size(); ++i) {
            int y = g1r[t][i];
            if (win[y] != -1) continue;
            win[y] = -1;
            for (int j = 0; j < g1[y].size(); ++j) {
                if (win[g1[y][j]] == 0) {
                    win[y] = 1;
                    break;
                }
            }
            if (win[y] == -1) {
                bool allOne = true;
                for (int j = 0; j < g1[y].size(); ++j) {
                    if (win[g1[y][j]] != 1) {
                        allOne = false;
                        break;
                    }
                }
                if (allOne) win[y] = 0;
            }
            if (win[y] != -1)
                q.push(y);
        }
    }

    vector<string> inp(4);
    for (int i = 0; i < 4; ++i) cin >> inp[i];
    int start = getid(inp);
    cerr << start << endl;
    if (win[start] == 1) {
        cout << "Win\n";
    } else {
        cout << "No winning move exists\n";
        if (win[start] == 0) {
            cout << "Losing\n";
        } else {
            cout << "Draw\n";
        }
    }

    return 0;
}
