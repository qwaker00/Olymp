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

struct matrix {
    int n;
    vector<vector<double> > a;

    matrix(int m) {
        n = m;
        a.resize(n);
        for (int i = 0; i < n; ++i) a[i].resize(n);
    }

    matrix operator *(const matrix& A) const {
        matrix res(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                res.a[i][j] = 0;
                for (int k = 0; k < n; ++k)
                    res.a[i][j] += a[i][k] * A.a[k][j];
            }
        return res;
    }

    vector<double> gauss(vector<double> b) {
        vector<vector<double> > A = a;


        for (int i = 0; i < n; ++i) {
            int cool = i;
            for (int j = i + 1; j < n; ++j)
                if (fabs(a[cool][i]) < fabs(a[j][i])) {
                    cool = j;
                }

            swap(a[i], a[cool]);


            for (int j = i + 1; j < n; ++j) {
                double factor = -a[j][i] / a[i][i];

                a[j][i] = 0;
                for (int k = 0; k < n; ++k) {
                    a[j][k] += a[i][k] * factor;        
                }

                b[j] += b[i] * factor;
            } 
        }

        b[n - 1] /= a[n - 1][n - 1];
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                b[i] -= a[i][j] * b[j];
            }    
            b[i] /= a[i][i];
        }

        a = A;
        return b;
    }
};

matrix getFromScale(double a, double b, double c) {
    matrix res(4);
    res.a[0][0] = a;
    res.a[1][1] = b;
    res.a[2][2] = c;
    res.a[3][3] = 1;
    return res;
}

matrix getFromTranslate(double a, double b, double c) {
    matrix res(4);
    res.a[0][0] = 1;
    res.a[1][1] = 1;
    res.a[2][2] = 1;
    res.a[3][3] = 1;

    res.a[0][3] = a;
    res.a[1][3] = b;
    res.a[2][3] = c;
    return res;
}

const double eps = 1e-8;

double points[3][3];

double getPoint(double a, double b, double c, double& x, double& y, double& z, double s1, double s2) {
    if (a != 0) {
        y = s1;
        z = s2;
        x = (-b * y - c * z) / a;
    } else if (b != 0) {
        x = s1;
        z = s2;
        y = (-a * x - c * z) / b;
    } else {
        x = s1;
        y = s2;
        z = (-b * y - a * x) / c;
    }
}

matrix getFromRotate(double a, double b, double c, double d) {
    d *= acos(-1.) / 180.;
    matrix res(4);


    if (a == 0 && b == 0) {
        res.a[0][0] = cos(d);
        res.a[0][1] = -sin(d);
        res.a[1][0] = sin(d);
        res.a[1][1] = cos(d);
        return res;
    }
    if (a == 0 && c == 0) {
        res.a[0][0] = cos(d);
        res.a[0][1] = -sin(d);
        res.a[1][0] = sin(d);
        res.a[1][1] = cos(d);
        return res;
    }
    if (a == 0 && b == 0) {
        res.a[0][0] = cos(d);
        res.a[0][1] = -sin(d);
        res.a[1][0] = sin(d);
        res.a[1][1] = cos(d);
        return res;
    }

    vector<double> B(9);
    
    getPoint(a, b, c, points[0][0], points[0][1], points[0][2], 0, 1);
    getPoint(a, b, c, points[0][0], points[0][1], points[0][2], 1, 0);
    point[2][0] = a;
    point[2][1] = b;
    point[2][2] = c;
    
    matrix tosolve(9);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            tosolve.a[i][j] = point[i][j];
            tosolve.a[i + 3][j + 3] = point[i][j];
            tosolve.a[i + 6][j + 6] = point[i][j];
        }
    
            
} 

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    


    return 0;
}
