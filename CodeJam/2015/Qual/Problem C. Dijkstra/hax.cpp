#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


typedef int inum;

const inum I = 2, J = 3, K = 4;

void out(inum x) {
	if (x < 0) {
		cout << '-';
		return out(-x);
	}
	if (x == 1)
		cout << '1';
	else if (x == I)
		cout << 'i';
    else if (x == J)
    	cout << 'j';
    else if (x == K)
    	cout << 'k';
    else
    	assert(false);
}

inum mulmem[4][4] = {
	{1, I, J, K},
	{I, -1, K, -J},
	{J, -K, -1, I},
	{K, J, -I, -1}
};

inum mul(inum x, inum y) {
	if (x < 0) return -mul(-x, y);
	if (y < 0) return -mul(x, -y);
	return mulmem[x - 1][y - 1];
}

inum fromchar(char c) {
	if (c == 'i') return I;
	if (c == 'j') return J;
	if (c == 'k') return K;
	assert(false);
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

	int T, __it = 0;
	cin >> T;
	while (T--) {
		int l;
		ll x;
		string s;
		cin >> l >> x;
		cin >> s;

		inum all = 1;
		for (int i = 0; i < l; ++i) {
			all = mul(all, fromchar(s[i]));
		}

		inum target = I;
		inum value = 1;
		bool stop = false;
		int it, i;
		for (it = 0; it < x && it < 8; ++it) {
			for (i = 0; i < l; ++i) {
				value = mul(value, fromchar(s[i]));
				if (value == target) {
					value = 1;
					if (target == I) target = J;else
					if (target == J) {
						stop = true;
						break;
					}
				}
			}
			if (stop) break;
		}

		__it++;
		cout << "Case #" << __it << ": ";
		if (stop) {
			for (++i; i < l; ++i) {
				value = mul(value, fromchar(s[i]));
			}
			++it;
			int rest = (x - it) % 4;
			while (rest--) {
				value = mul(value, all);
			}

			if (value == K) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else {
			cout << "NO\n";
		}
	}

    
    return 0;
}
