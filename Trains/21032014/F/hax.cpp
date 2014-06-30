#include <iostream>
#include <cstdio>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

struct Graph {
    long long a[2][2];

    Graph() {
        a[0][0] = 0;
        a[1][0] = 1;
        a[0][1] = 1;
        a[1][1] = -1e9;
    }

    const long long* operator[](int x) const {
        return a[x];
    }

    long long* operator[](int x) {
        return a[x];
    }

    Graph Parallel(const Graph& b) const {
        const Graph& a = *this;
        Graph c;

        c[0][0] = a[0][0] + b[0][0];
        c[1][0] = a[1][0] + b[1][0] - 1;
        c[0][1] = a[0][1] + b[0][1] - 1;
        c[1][1] = a[1][1] + b[1][1] - 2;

        return c;
    }

    Graph Serial(const Graph& b) const {
        const Graph& a = *this;
        Graph c;

        c[0][0] = max(a[0][0] + b[0][0], a[0][1] + b[1][0] - 1);
        c[1][0] = max(a[1][0] + b[0][0], a[1][1] + b[1][0] - 1);
        c[0][1] = max(a[0][0] + b[0][1], a[0][1] + b[1][1] - 1);
        c[1][1] = max(a[1][0] + b[0][1], a[1][1] + b[1][1] - 1);

        return c;
    }

    int Ans() {
        return max(max(a[0][0], a[0][1]), max(a[1][0], a[1][1]));
    }
};

char s[222222];

int main() {
    freopen("independent.in", "r", stdin);
    freopen("independent.out", "w", stdout);

    gets(s);
    stack<char> ops;
    stack<Graph> values;
    for (int i = strlen(s) - 1; i >= 0; --i) {
        char c = s[i];
        if (c == 'g') {
            values.push(Graph());
        } else {
            Graph g1 = values.top(); values.pop();
            Graph g2 = values.top(); values.pop();
            if (c == 'P')
                values.push(g1.Parallel(g2));
            else
                values.push(g1.Serial(g2));
        }
    }
    cout << values.top().Ans() << endl;

    return 0;
}
