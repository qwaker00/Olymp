#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795

using namespace std;

double sqr(double x) {
    return x*x;
}

double dis(double x1, double y1, double x2, double y2) {
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

pair<double, double> get(double x1, double y1, double x2, double y2, double r) {
    double d = dis(x1, y1, x2, y2);
    double cosa = d / 2;
    double sina = sqrt(1. - sqr(cosa));

    double dx = x2 - x1;
    double dy = y2 - y1;
    dx /= d;
    dy /= d;

    double cx = x1 + dx * d / 2;
    double cy = y1 + dy * d / 2;

    double adx = dy;
    double ady = -dx;
    
    if (sqr(cx + adx * sina) + sqr(cy + ady * sina) <= sqr(r)) return make_pair(cx - adx * sina, cy - ady * sina);
    return make_pair(cx + adx * sina, cy + ady * sina);
}

double crand[111];
double angle[111];
vector< pair<double, double> > res;


void init() {
angle[2] = 1.304502314746134;
angle[3] = 0.904955241740992;
angle[4] = 0.699022822280569;
angle[5] = 0.570661236793793;
angle[6] = 0.482482989758225;
angle[7] = 0.418037881485588;
angle[8] = 0.368835347552515;
angle[9] = 0.330021655359145;
angle[10] = 0.298612790425400;
angle[11] = 0.272670421737943;
angle[12] = 0.250879735334047;
angle[13] = 0.232316845714465;
angle[14] = 0.216313404725164;
angle[15] = 0.202373824015301;
angle[16] = 0.190122812580161;
angle[17] = 0.179270931506580;
angle[18] = 0.169591333763912;
angle[19] = 0.160903744604421;
angle[20] = 0.153063048876010;
angle[21] = 0.145951129129439;
angle[22] = 0.139470872576431;
angle[23] = 0.133541686813620;
angle[24] = 0.128096127888865;
angle[25] = 0.123077337631646;
angle[26] = 0.118437032091930;
angle[27] = 0.114133944749634;
angle[28] = 0.110132603322066;
angle[29] = 0.106402341590558;
angle[30] = 0.102916508861767;
angle[31] = 0.099651842570644;
angle[32] = 0.096587938885383;
angle[33] = 0.093706832259331;
angle[34] = 0.090992636859634;
angle[35] = 0.088431249465271;
angle[36] = 0.086010125153135;
angle[37] = 0.083718046905384;
angle[38] = 0.081544964663980;
angle[39] = 0.079481845720460;
angle[40] = 0.077520547547239;
angle[41] = 0.075653716901384;
angle[42] = 0.073874685888849;
angle[43] = 0.072177404449459;
angle[44] = 0.070556363008531;
angle[45] = 0.069006539404249;
angle[46] = 0.067523339078452;
angle[47] = 0.066102556271129;
angle[48] = 0.064740333520605;
angle[49] = 0.063433121848625;
angle[50] = 0.062177656195193;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    
    init();
    

    int n;
    cin >> n;


    if (n & 1) {
        int k = n / 2;
        double beta = angle[k];
        double alpha = PI - k * beta;

        double r = 1.9 / 2. / sin(beta);
        
        
        vector< pair<double, double> > points;
        vector< double > angles;
        angles.push_back(2 * alpha);
        for (int i = 0; i < k; ++i) {
            angles.push_back(angles.back() + 2 * beta);
        } 
        
        for (int i = 1; i < angles.size(); i += 2) {
            if (rand() & 1)
                angles[i] += PI / 1000. * rand() / RAND_MAX;
            else
                angles[i] -= PI / 1000. * rand() / RAND_MAX;
        }

        for (int i = 0; i < angles.size(); ++i) points.push_back(make_pair(r * cos(angles[i]), r * sin(angles[i])));

        
        for (int i = 0; i + 1 < points.size(); ++i) {
            res.push_back(points[i]);
            res.push_back(get(points[i].first, points[i].second, points[(i + 1) % points.size()].first, points[(i + 1) % points.size()].second, r));
        }
        res.push_back(points.back());
    } else {
        int k = n / 2;
        double beta = PI / k;

        double r = 1.9 / 2. / sin(beta);

        vector< pair<double, double> > points;
        vector< double > angles;
        angles.push_back(0); 
        for (int i = 1; i < k; ++i) {
            angles.push_back(angles.back() + 2 * beta);
        } 
        
        for (int i = 1; i < angles.size(); i += 2) {
            if (rand() & 1)
                angles[i] += PI / 1000. * rand() / RAND_MAX;
            else
                angles[i] -= PI / 1000. * rand() / RAND_MAX;
        }

        for (int i = 0; i < angles.size(); ++i) points.push_back(make_pair(r * cos(angles[i]), r * sin(angles[i])));

        for (int i = 0; i < points.size(); ++i) {
            res.push_back(points[i]);
            res.push_back(get(points[i].first, points[i].second, points[(i + 1) % points.size()].first, points[(i + 1) % points.size()].second, r));
        }
    }

    cout.precision(16);
    cout << fixed;
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;

    
    res.push_back(res[0]);
    for (int i = 0; i + 1 < res.size(); ++i)
        cerr << dis(res[i].first, res[i].second, res[i + 1].first, res[i + 1].second) << endl;
    
    return 0;
}
