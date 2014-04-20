#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 111111
#define eps 1e-9

struct TPoint3D {
	double x, y, z;

	TPoint3D() : x(0), y(0), z(0) {}
	TPoint3D(double x, double y, double z) : x(x), y(y), z(z) {}

	double length() {
		return sqrt(x * x + y * y + z * z);
	}

	double operator*(const TPoint3D& v) const {
		return x * v.x + y * v.y + z * v.z;
	}

	TPoint3D operator+(const TPoint3D& v) const {
		return TPoint3D(x + v.x, y + v.y, z + v.z);
	}

	TPoint3D operator-(const TPoint3D& v) const {
		return TPoint3D(x - v.x, y - v.y, z - v.z);
	}

	TPoint3D operator*(double v) const {
		return TPoint3D(x * v, y * v, z * v);
	}

	TPoint3D operator/(double v) const {
		return TPoint3D(x / v, y / v, z / v);
	}
};

inline double FromLine(double x, double y,
					   double x1, double y1,
					   double x2, double y2)
{	
	double A = y2 - y1;
	double B = x1 - x2;
	double C = -x1 * A - y1 * B;
	return (A * x + B * y + C) / sqrt(A * A + B * B);
}

inline double InRect(double x, double y,
					 double x1, double y1,
					 double x2, double y2)
{
	return fabs(fabs(x - x1) + fabs(x - x2) - fabs(x1 - x2)) < eps &&
	       fabs(fabs(y - y1) + fabs(y - y2) - fabs(y1 - y2)) < eps;
}


inline bool InTriangle(double x,  double y,
					   double x1, double y1,
					   double x2, double y2,
					   double x3, double y3)
{
	double p1 = FromLine(x, y, x1, y1, x2, y2);
	double p2 = FromLine(x, y, x2, y2, x3, y3);
	double p3 = FromLine(x, y, x3, y3, x1, y1);
	if (fabs(p1) < eps) return InRect(x, y, x1, y1, x2, y2);
	if (fabs(p2) < eps) return InRect(x, y, x2, y2, x3, y3);
	if (fabs(p3) < eps) return InRect(x, y, x3, y3, x1, y1);
	return (p1 < 0 && p2 < 0 && p3 < 0) || (p1 > 0 && p2 > 0 && p3 > 0);
}

inline bool InSegment(double x, double y,
					 double x1, double y1,
					 double x2, double y2)
{
	return fabs(FromLine(x, y, x1, y1, x2, y2)) < eps && InRect(x, y, x1, y1, x2, y2);
}

inline bool Intersect(double p1x, double p1y,
					  double p2x, double p2y,
					  double p3x, double p3y,
					  double p4x, double p4y,
					  double& x, double& y
					 )
{
	double A1 = p2y - p1y;
	double B1 = p1x - p2x;
	double C1 = -A1 * p1x - B1 * p1y;

	double A2 = p4y - p3y;
	double B2 = p3x - p4x;
	double C2 = -A2 * p3x - B2 * p3y;

	double d = A1 * B2 - A2 * B1;
	if (fabs(d) < eps) return false;

	x = (-C1 * B2 + C2 * B1) / d;
	y = (-A1 * C2 + A2 * C1) / d;
	return InSegment(x, y, p1x, p1y, p2x, p2y) && InSegment(x, y, p3x, p3y, p4x, p4y);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

	int n;
	while (scanf("%d", &n) == 1) {
		TPoint3D s, t, v;
		
		scanf("%lf%lf%lf", &s.x, &s.y, &s.z);
		scanf("%lf%lf%lf", &t.x, &t.y, &t.z);
		scanf("%lf%lf%lf", &v.x, &v.y, &v.z);

		TPoint3D v1, v2, vx, vy;
		if (fabsl(v.x) < eps) {
			if (fabsl(v.y) < eps) {
				vx = TPoint3D(1, 0, -v.x / v.z);
				vy = TPoint3D(0, 1, -v.y / v.z);
			} else {
				vx = TPoint3D(1, -v.x / v.y, 0);
				vy = TPoint3D(0, -v.z / v.y, 1);
			}
		} else {
			vx = TPoint3D(-v.y / v.x, 1, 0);
			vy = TPoint3D(-v.z / v.x, 0, 1);
		}
		v1 = vx;
		v2 = vy - vx * ((vx * vy) / (vx * vx));
		v1 = v1 / v1.length();
		v2 = v2 / v2.length();

		assert(fabsl(v1 * v) < eps);
		assert(fabsl(v2 * v) < eps);
		assert(fabsl(v2 * v1) < eps);
		assert(fabsl(v1 * v1 - 1) < eps);
		assert(fabsl(v2 * v2 - 1) < eps);

		double sx = v1 * s, sy = v2 * s;
		double tx = v1 * t, ty = v2 * t;
		double l = sqrt(sqr(sx - tx) + sqr(sy - ty));
		double ans = 0;

		for (int i = 0; i < n; ++i) {
			TPoint3D p1, p2, p3;
			scanf("%lf%lf%lf", &p1.x, &p1.y, &p1.z);
			scanf("%lf%lf%lf", &p2.x, &p2.y, &p2.z);
			scanf("%lf%lf%lf", &p3.x, &p3.y, &p3.z);

			if (l < eps) {
				ans += InTriangle(sx, sy,
								  p1 * v1, p1 * v2,
								  p2 * v1, p2 * v2,
								  p3 * v1, p3 * v2
								 );
			} else {
				vector< pair<double, double> > q;
				double x, y;
				q.push_back( make_pair(sx, sy) );
				q.push_back( make_pair(tx, ty) );
				if (InSegment(p1 * v1, p1 * v2, sx, sy, tx, ty)) q.push_back(make_pair(p1 * v1, p1 * v2));
				if (InSegment(p2 * v1, p2 * v2, sx, sy, tx, ty)) q.push_back(make_pair(p2 * v1, p2 * v2));
				if (InSegment(p3 * v1, p3 * v2, sx, sy, tx, ty)) q.push_back(make_pair(p3 * v1, p3 * v2));
				if (Intersect(sx, sy, tx, ty, p1 * v1, p1 * v2, p2 * v1, p2 * v2, x, y)) q.push_back(make_pair(x, y));
				if (Intersect(sx, sy, tx, ty, p2 * v1, p2 * v2, p3 * v1, p3 * v2, x, y)) q.push_back(make_pair(x, y));
				if (Intersect(sx, sy, tx, ty, p3 * v1, p3 * v2, p1 * v1, p1 * v2, x, y)) q.push_back(make_pair(x, y));
				sort(q.begin(), q.end());

				for (int i = 1; i < (int)q.size(); ++i) {
					if (InTriangle( (q[i].first + q[i - 1].first) / 2, (q[i].second + q[i - 1].second) / 2,
									p1 * v1, p1 * v2,
									p2 * v1, p2 * v2,
									p3 * v1, p3 * v2
								   )
					)
					{
						ans += sqrt(sqr(q[i].first - q[i - 1].first) + sqr(q[i].second - q[i - 1].second)) / l;
					}
				}
			}
		}

		printf("%.12lf\n", ans);
	}
    return 0;
}
