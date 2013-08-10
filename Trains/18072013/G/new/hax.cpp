#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

#ifdef DEBUG
    #define debug(x)  cerr << x << endl
    #define ensure(x) if (!(x)) { cerr << "EPIC FAIL: " #x " is wrong" << endl; }
    #define ensurem(x, m) if (!(x)) { cerr << "EPIC FAIL: " #x " is wrong, " m << endl; }
    #define fail(m) ensurem(false, m)
#else
    #define debug(x)
    #define ensure(x)
    #define ensurem(x, m)
    #define fail(m)
#endif


template<typename T>
class TPole {
protected:    

    virtual inline T Plus (const T& x, const T& y) { return x + y; }
    virtual inline T Minus(const T& x, const T& y) { return x - y; }
    virtual inline T Div  (const T& x, const T& y) { return x / y; }
    virtual inline T Mod  (const T& x, const T& y) { return x % y; }
    virtual inline T Mul  (const T& x, const T& y) { return x * y; }
    virtual inline T Pow  (const T& xx, const T& yy) {
        T res = 1, x = xx, y = yy;
        while (y) {
            if (y & 1) res *= x;
            x *= x;
            y >>= 1;
        }
        return res;
    }

    virtual inline void make_op(int op, vector<T>& vals) {
        ensure((int)vals.size() > (1 - Unary[op]));

#ifdef DEBUG
        if (Unary[op]) {
            cerr << char(op) << vals.back() << endl;
        } else {
            cerr << vals[vals.size() - 2] << char(op) << vals.back() << endl;
        }
#endif            
        switch (op) {
            case '+': vals[vals.size() - 2] = Plus(vals[vals.size() - 2], vals.back()); break;
            case '-': vals[vals.size() - 2] = Minus(vals[vals.size() - 2], vals.back()); break;
            case '/': vals[vals.size() - 2] = Div(vals[vals.size() - 2], vals.back()); break;
            case '*': vals[vals.size() - 2] = Mul(vals[vals.size() - 2], vals.back()); break;
            case '%': vals[vals.size() - 2] = Mod(vals[vals.size() - 2], vals.back()); break;
            case '^': vals[vals.size() - 2] = Pow(vals[vals.size() - 2], vals.back()); break;
            case '!': vals.back() = -vals.back(); break;
            case '$': break;
            default:
                fail("Unknown binary operation"); break;
        }
        if (!Unary[op]) {
            vals.pop_back();
        }
    }

    int Unary[256], Priority[256], Right[256], MayUnary[256];

public:
    TPole() {
        memset(MayUnary, 0, sizeof(MayUnary));
        memset(Priority, 0, sizeof(Priority));
        memset(Right, 0, sizeof(Right));
        memset(Unary, 0, sizeof(Unary));

        MayUnary['+'] = '$';
        MayUnary['-'] = '!';
        Right['^'] = Right['$'] = Right['!'] = true;
        Unary['$'] = Unary['!'] = true;
        Priority['+'] = Priority['-'] = 1;
        Priority['*'] = Priority['/'] = Priority['%'] = 2;
        Priority['^'] = 3;
        Priority['$'] = Priority['!'] = 4;
    }

    T Calculate(const char * expr, T (*valuer)(const char* token)) {
        bool unary = true;

        vector<int> ops;
        vector<T> vals;
        string token;

        while (*expr) {
            int ch = (unsigned)*expr;
            switch (ch) {
                case ' ': case '\t': case '\n': break;

                case '(':
                    ops.push_back('(');
                    unary = true;
                    break;

                case ')':
                    while (!ops.empty() && ops.back() != '(') {
                        make_op(ops.back(), vals);
                        ops.pop_back();
                    }
                    ensure(ops.size() > 0 && ops.back() == '(');
                    ops.pop_back();
                    unary = false;
                    break;

                case '+': case '-': case '/': case '*': case '%': case '^':
                    if (MayUnary[ch] && unary) ch = MayUnary[ch];
                    while (!ops.empty() && (
                            (Right[ch] && Priority[ops.back()] > Priority[ch]) ||
                            (!Right[ch] && Priority[ops.back()] >= Priority[ch])
                        ))
                    {
                        make_op(ops.back(), vals);
                        ops.pop_back();
                    }
                    ops.push_back(ch);
                    unary = true;
                    break;

                default:
                    token.clear();
                    ensure(isalnum(ch));
                    while (isalnum(*expr)) token += *(expr++);
                    --expr;
                    vals.push_back(valuer(token.c_str()));
                    unary = false;
                    break;
            }
            ++expr;
        }
        while (!ops.empty()) {
            make_op(ops.back(), vals);
            ops.pop_back();
        }
        ensure(vals.size() == 1);
        return vals[0];
    }
};

class TSuperPole : public TPole<int> {
    virtual inline int Div(const int& x, const int& y) {
        if (x < 0 && y < 0) {
            return (-x) / (-y);
        } else
        if (x < 0 && y >= 0) {
            return -((-x) / y);
        } else
        if (x >= 0 && y < 0) {
            return -(x / (-y));
        }
        return x / y;
    }

    virtual inline int Mod(const int& x, const int& y) { 
        if (x < 0 && y < 0) {
            return (-x) % (-y);
        } else
        if (x < 0 && y >= 0) {
            return -((-x) % y);
        } else
        if (x >= 0 && y < 0) {
            return -(x % (-y));
        }
        return x % y;
    }
};

map<string, int> ids;
vector<bool>     defined(1);
vector<int>      pr(1);
vector<int>      value(1);
int idcounter    = 0;

int GetId(const char * s) {
    int& i = ids[s];
    if (i == 0) {
        i = ++idcounter;
        pr.push_back(idcounter);
        defined.push_back(false);

        if (isdigit(s[0])) {
            value.push_back(atoi(s));
        } else {
            value.push_back(0);
        }
    }
    return i;
}

int FindSet(int x) {
    if (pr[x] != x) pr[x] = FindSet(pr[x]);
    return pr[x];
}

int Valuer(const char* s) {
    int i = GetId(s);
    return value[FindSet(i)];
}

void Define(const char *x, const char* y) {
    int idx = GetId(x);
    if (defined[idx]) return;

    int idy = GetId(y);
    if (FindSet(idx) == FindSet(idy)) return;

    defined[idx] = true;
    pr[idx] = idy;
}

char cmd[256];
char expr[1048576], buf1[1048576], buf2[1048576];

int main() {
    freopen("plcool.in", "r", stdin);
    freopen("plcool.out", "w", stdout);

    TSuperPole p;
    while (scanf("%s", cmd) == 1) {
        debug(endl);
        if (strcmp("print", cmd) == 0) {
            gets(expr);
            for (int i = 0; expr[i]; ++i) expr[i] = tolower(expr[i]);
            cout << p.Calculate(expr, Valuer) << endl;
        } else
        if (strcmp("define", cmd) == 0) {
            scanf("%s %s", buf1, buf2);
            for (int i = 0; buf1[i]; ++i) buf1[i] = tolower(buf1[i]);
            for (int i = 0; buf2[i]; ++i) buf2[i] = tolower(buf2[i]);
            Define(buf1, buf2);
        } else
            fail("Unknown op");
    }

    return 0;
}
