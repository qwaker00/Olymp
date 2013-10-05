#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 1000111;
char s[N];

int l1, l2;
char straight[N];
char reversed[N];

void calcz(char* s, int n, vector<int>& z) {
	z.resize(l);
	z[0] = 0;
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
}

void calc(int l, int r, vector<int>& a) {
	a.resize(r - l + 1);
	if (l == r + 1) {
		a[0] = 0;
		a[1] = 1;
		return;
	}
	
	vector<int> left, right;
	int center = (l + r) >> 1;
	calc(l, center, left);
	calc(center, r, right);
	
	l1 = l2 = 0;
	for (int i = center; i < r; ++i) {
		straight[l1++] = s[i];
	}
	straight[l1++] = '$';
	for (int i = l; i < center; ++i) {
		straight[l1++] = s[i];
	}
	straight[l1] = 0;

	for (int i = center - 1; i >= l; --i) {
		reversed[l2++] = s[i];
	}
	reversed[l2++] = '$';
	for (int i = r - 1; i >= center; --i) {
		reversed[l2++] = s[i];
	}
	reversed[l2] = 0;

	vector<int> zstraight, zreversed;
	calcz(straight, l1, zstraight);
	calcz(reversed, l2, zreversed);

	int mlen = r - l + 1;
	for (int len = 1; len <= mlen; ++len) {
		a[len] = 1;
		if (len + len > mlen) {
			continue;
		}

		if (len < left.size()) {
			a[len] = max(a[len], left[len]);
		}
		if (len < right.size()) {
			a[len] = max(a[len], right[len]);
		}

		int lenright = zstraight[len - 1];
	}
}

int main() {

	
	return 0;
}
