#include <iostream>

using namespace std;
typedef long long ll;
ll f[44][44];

int main() {
	for (int i = 0; i < 44; ++i) {
		f[i][0] = f[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
		}
	}

	ll sum = 0;
	for (int i = 0; i < 44; ++i) {
		sum += f[40][i];
		cout << i << " " << sum << endl;
	}
}