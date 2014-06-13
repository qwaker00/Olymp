#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    double pw, x;
    scanf("%lf%lf", &x, &pw);
    x /= 100;
    pw /= 100;

    double pl = 1. - pw;

    double cans = -1e18;
    for (int n = 0; n <= 10000; ++n) {
        double ans = (pw - pl) * n;

        double binom = 1;
        double sum = 0;
        for (int a = 0; a + a < n; ++a) {
            sum += double(n - a - a) * binom * pow(pl, double(n - a)) * pow(pw, double(a));

            binom *= (n - a);
            binom /= a + 1;
        }

        ans += x * sum;
        cans = max(ans, cans);
    }

    cout << cans << endl;



    return 0;
}

