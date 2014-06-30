#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    freopen("monsters.in", "r", stdin);
    freopen("monsters.out", "w", stdout);

    int n;
    cin >> n;
    vector< pair<pair<ll, ll>, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i + 1;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j + 1 < n; ++j)
            if (a[j].first.first * a[j + 1].first.second > a[j + 1].first.first * a[j].first.second) {
                swap(a[j], a[j + 1]);
            }

    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i].first.first;
        ans += sum * a[i].first.second;
    }

    cout << ans << endl;
    for (int i = 0; i < n; ++i) cout << a[i].second << ' ';
    cout << endl;



    return 0;
}
