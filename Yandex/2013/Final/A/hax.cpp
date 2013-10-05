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

char s[1111111];
vector<string> tokens;
vector<char> data;
string lastw;

bool isdelim(const string& s) {
    return s.length() == 1 && !isalpha(s[0]);
}
string doted(const string& s, int i) {
    if (i < 1) i = 1;
    if (i > s.length()) i = s.length();
    if (i == s.length()) return s;
    return s.substr(0, i) + ".";
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    gets(s);
    int l = strlen(s);
    for (int i = 0; i < l; ++i) {
        if (isalpha(s[i])) {
            lastw += s[i];
        } else {
            if (lastw.length()) {
                tokens.push_back(lastw);
                lastw = "";
            }
            tokens.push_back(string(s + i, 1));
        }
    }
    if (lastw.length()) tokens.push_back(lastw);

    for (int i = (int)tokens.size() - 1; i >= 0; --i)
        if (!isdelim(tokens[i])) {
            int pnt = (int)data.size() - 1;
            int cnt = 1;
            while (pnt >= 0) {
                char ch = (cnt < tokens[i].length()) ? tokens[i][cnt] : data[(int)data.size() - (cnt - tokens[i].length()) - 1];
                if (data[pnt] == tolower(ch)) {
                    pnt--;
                    cnt++;
                } else break;
            }
            if (pnt < 0) {
                cnt = 1;
            } else {
                char ch = (cnt < tokens[i].length()) ? tokens[i][cnt] : data[(int)data.size() - (cnt - tokens[i].length()) - 1];
                if (tolower(ch) < data[pnt]) {
                    ++cnt;
                } else {
                    cnt = 1;
                }
            }
            tokens[i] = doted(tokens[i], cnt);
            for (int j = (int)tokens[i].length() - 1; j >= 0; --j)
                if (tokens[i][j] != '.')
                    data.push_back(tolower(tokens[i][j]));
        }

    for (int i = 0; i < tokens.size(); ++i) fputs(tokens[i].c_str(), stdout);
    puts("");
    return 0;
}
