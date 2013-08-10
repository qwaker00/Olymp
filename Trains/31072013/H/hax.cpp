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

int roomC, doorC;
char buf[111111];
vector<string> roomName;
vector< vector< pair<int, string> > > g;

struct TChar {
    bool used;
    string name;
    vector<string> inp;
    vector<string> out;
};

struct TRoom {
    int i, o, c;
    vector<TChar> chars;
    vector<TChar> objs;
    vector<string> its;
};
vector<TRoom> room;
vector<bool> wasRoom;
map<string, pair<int, int> > key;
vector<int> pred;

string strip(const char * s) {
    const char * ss = strlen(s) + s -1;
    while (*s == ' ') ++s;
    while (ss >= s && *ss == ' ') --ss;
    return string(s, ss - s + 1);
}

vector<string> split(char * s) {
    vector<string> res;

    int last = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == ',') {
            s[i] = 0;
            res.push_back(strip(s + last));
            last = i + 1;
        }
    }
    res.push_back(strip(s + last));

    return res;
}

void GoTo(int x, int xx, vector<string>& ans) {
    if (x == xx) return;
    vector<int> way;
    vector<int> wayR;
    while (pred[x] != -1) {
        x = pred[x];
        way.push_back(x);
    }
    while (pred[xx] != -1) {
        wayR.push_back(xx);
        xx = pred[xx];
    }
    for (int i = 0; i < way.size(); ++i) ans.push_back("go to " + roomName[way[i]]);
    for (int i = 0; i < wayR.size(); ++i) ans.push_back("go to " + roomName[wayR[wayR.size() - i - 1]]);
}

bool Contain(const set<string>& a, const vector<string>& b) {
    for (int i = 0; i < b.size(); ++i) if (a.find(b[i]) == a.end()) return false;
    return true;
}

string ListString(const vector<string>& a) {    
    if (a.size() == 1) {
        return a[0];
    }
    if (a.size() > 1) {
        string res;
        for (int i = 0; i < ((int)a.size()) - 2; ++i) res += a[i] + ", ";
        res += a[a.size() - 2] + " and " + a.back();
        return res;
    }
    return "";
}

void Explore(int x, set<string>& hand, vector<string>& ans, vector<int>& cango) {
    wasRoom[x] = true;
    cango.push_back(x);
    for (size_t i = 0; i < room[x].its.size(); ++i) {
        ans.push_back("pick " + room[x].its[i]);
        hand.insert(room[x].its[i]);
    }
}

int main() {
    freopen("quest.in", "r", stdin);
    freopen("quest.out", "w", stdout);

    scanf("%d\n", &roomC);
    for (int i = 1; i <= roomC; ++i) {
        gets(buf);
        string s = strip(buf);
        roomName.push_back(s);        
    }
    g.resize(roomC);
    room.resize(roomC);
    wasRoom.resize(roomC);
    pred.assign(roomC, -1);

    scanf("%d\n", &doorC);
    for (int i = 0; i < doorC; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        gets(buf);
        string s = strip(buf);
        key[s] = make_pair(x - 1, g[x - 1].size());
        g[x - 1].push_back(make_pair(y - 1, s));
        g[y - 1].push_back(make_pair(x - 1, s));
    }

    for (int i = 0; i < roomC; ++i) {
        scanf("%d%d%d\n", &room[i].c, &room[i].o, &room[i].i);

        for (int j = 0; j < room[i].c; ++j) {
            room[i].chars.push_back(TChar());
            TChar& ch = room[i].chars.back();

            gets(buf);
            ch.name = strip(buf);

            gets(buf);
            ch.inp = split(buf);

            gets(buf);
            ch.out = split(buf);

			ch.used = false;
        }

        for (int j = 0; j < room[i].o; ++j) {
            room[i].objs.push_back(TChar());
            TChar& ch = room[i].objs.back();

            gets(buf);
            ch.name = strip(buf);

            gets(buf);
            ch.inp = split(buf);

            gets(buf);
            ch.out = split(buf);

			ch.used = false;
        }
    
        for (int j = 0; j < room[i].i; ++j) {
            gets(buf);
            room[i].its.push_back( strip(buf) );
        }
    }

    gets(buf);
    int x = 0;
    string start = strip(buf);
    for (int i = 0; i < roomC; ++i) if (roomName[i] == start) {
        x = i;
        break;
    }

    gets(buf);
    string end = strip(buf);

    vector<string> ans;
    set<string> hand;
    vector<int> cango;

    Explore(x, hand, ans, cango);

    bool happyend = false;
    while (true) {
        if (roomName[x] == end) {
            ans.push_back("save princess");
            happyend = true;
            break;
        }

        bool found = false;
        for (int i = 0; i < cango.size(); ++i) {
            int xx = cango[i];
            TRoom& r = room[xx];

            for (int j = 0; j < g[xx].size(); ++j) {
                int yy = g[xx][j].first;
                if (!wasRoom[yy] && hand.find(g[xx][j].second) != hand.end()) {
                    GoTo(x, xx, ans);
                    ans.push_back("open door to " + roomName[yy]);
                    ans.push_back("go to " + roomName[yy]);
                    pred[yy] = xx;
                    x = yy;
                    found = true;

                    Explore(x, hand, ans, cango);
                }
            }

            for (int j = 0; j < r.objs.size(); ++j) {
                if (!r.objs[j].used && Contain(hand, r.objs[j].inp)) {
                    GoTo(x, xx, ans);
                    x = xx;

                    ans.push_back("use " + ListString(r.objs[j].inp) + " on " + r.objs[j].name);
                    ans.push_back("take " + ListString(r.objs[j].out) + " from " + r.objs[j].name);

                    for (int l = 0; l < r.objs[j].out.size(); ++l) {
                        hand.insert(r.objs[j].out[l]);
                    }
                    r.objs[j].used = true;

                    found = true;
                }
            }
            for (int j = 0; j < r.chars.size(); ++j) {
                if (!r.chars[j].used && Contain(hand, r.chars[j].inp)) {
                    GoTo(x, xx, ans);
                    x = xx;

                    ans.push_back("talk to " + r.chars[j].name);
                    ans.push_back("give " + ListString(r.chars[j].inp) + " to " + r.chars[j].name);
                    ans.push_back("take " + ListString(r.chars[j].out) + " from " + r.chars[j].name);

                    for (int l = 0; l < r.chars[j].inp.size(); ++l) {
                        hand.erase(r.chars[j].inp[l]);
                    }
                    for (int l = 0; l < r.chars[j].out.size(); ++l) {
                        hand.insert(r.chars[j].out[l]);
                    }
                    r.chars[j].used = true;

                    found = true;
                }
            }
        }
        if (!found) break;

    }
    if (happyend) {
        for (size_t i = 0; i < ans.size(); ++i) {
            puts(ans[i].c_str());
        }
    } else {
        puts("dead princess");
    }
    
    return 0;
}
