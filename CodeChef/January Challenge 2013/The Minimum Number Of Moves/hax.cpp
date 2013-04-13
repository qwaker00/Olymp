#include <iostream>
using namespace std;
int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0, mi = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> x;
            sum += x;
            if (x < mi) mi = x;
        }
        cout << sum - mi * n << endl;
    }
    return 0;
}
