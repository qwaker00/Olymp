#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

	int T, __it = 0;
	cin >> T;
	while (T--) {
		__it++;
		cout << "Case #" << __it << ": ";

		int x, r, c;
		cin >> x >> r >> c;
		if (r > c) swap(r, c);

		if ( (r * c) % x != 0) {
			cout << "RICHARD\n";
		} else
		if (x == 1) {
			cout << "GABRIEL\n";
		} else 
		if (x == 2) {
			cout << "GABRIEL\n";
		} else
		if (x == 3) {
			if (r == 1 && c == 3) {
				cout << "RICHARD\n";
			} else {
				cout << "GABRIEL\n";
			}
		} else
		if (x == 4) {
			if ((r == 1 && c == 4) ||
			    (r == 2 && c == 4) ||
			    (r == 2 && c == 2))
		    {
				cout << "RICHARD\n";
		    } else {
				cout << "GABRIEL\n";
		    }
		} else 
		if (x == 5) {
			if (r <= 3) {
				cout << "RICHARD\n";				
			} else {
				cout << "GABRIEL\n";
			}
		} else
		if (x == 6) {
			if (r <= 3) {
				cout << "RICHARD\n";				
			} else {
				cout << "GABRIEL\n";
			}
		} else
		if (x >= 7) {
			cout << "RICHARD\n";			
		}
	}
    
    return 0;
}
