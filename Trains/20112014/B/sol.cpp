#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
	int n = 300000;
	vector<int> a(n);
	for (int i = 0; i < n ;++i) a[i] = i + 1;
	
	random_shuffle(a.begin(), a.end());

	cout << n << endl;
	for (int i = 0; i < n; ++i) cout << a[i] << " ";
}

