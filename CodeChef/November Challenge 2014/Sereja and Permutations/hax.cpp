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
#include <cassert>

#include <unordered_map>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int Ph1 = 307;
const int Ph2 = 503;
//const int Ph1 = 100;
//const int Ph2 = 1000;
ULL ph1[333], ph2[333];
ULL h1[333], h2[333];

struct iset {
	unsigned data[10];
	int sz;

	inline void insert(int x) {
		if (data[x >> 5] & (1u << (x & 31))) return;
		++sz;
		data[x >> 5] |= (1u << (x & 31));
	}

	inline int size() const { return sz; };
	
	inline void reset() {
		memset(data, 0, sizeof(data));
	}
};

namespace std {

  template <>
  struct hash< pair<ULL, ULL> >
  {
    std::size_t operator()(const pair<ULL, ULL>& k) const
    {
      using std::size_t;
      using std::hash;

      // Compute individual hash values for first,
      // second and third and combine them using XOR
      // and bit shifting:

      size_t h1 = hash<LL>()(k.first);
      size_t h2 = hash<LL>()(k.second);
      return h1 ^ (h1 >> 3) ^ (h1 >> 5) ^ (h2 >> 2) ^ (h2 >> 4) ^ h2;
    }
  };

}

vector<int> make_array(vector<int> q, int x, int y) {
	for (size_t i = 0; i < q.size(); ++i) if (q[i] >= x) ++q[i];
	q.insert(q.begin() + y, x);
	return q;
}

pair<ULL, ULL> make_hash(vector<int> q, int x, int y) {
	for (size_t i = 0; i < q.size(); ++i) if (q[i] >= x) ++q[i];
	q.insert(q.begin() + y, x);

	pair<ULL, ULL> res;
	for (size_t i = 0; i < q.size(); ++i) {
		res.first += q[i] * ph1[i];
		res.second += q[i] * ph2[i];
	}
	return res;
}

const int MASK = 8388607;
pair<int, int> save[MASK + 1];
iset poss[MASK + 1];
int ok[MASK + 1];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    ph1[0] = ph2[0] = 1;
    for (int i = 1; i <= 300; ++i) {
    	ph1[i] = ph1[i - 1] * Ph1;
    	ph2[i] = ph2[i - 1] * Ph2;
    }
    	
    int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);

		//unordered_map< pair<ULL, ULL>, pair<int, int> > save;
		//unordered_map< pair<ULL, ULL>, iset > poss;
		//map< pair<ULL, ULL>, pair<int, int> > save[256];
		//map< pair<ULL, ULL>, iset > poss[256];
		
//		auto hasher = std::hash<pair<ULL,ULL>>();
		//unordered_map< ULL , pair<int, int> > save;
		//unordered_map< ULL , iset > poss;
		int okn = 0;

		ULL res = 0;
		vector<int> out;
		for (int i = 0; i < n; ++i) {
			vector<int> q(n - 1);
			for (int j = 0; j < n - 1; ++j) {
				scanf("%d", &q[j]);
			}
			if (i == 0) out = q;

			for (int j = 1; j <= n; ++j) {
				h1[0] = 0;
				//h2[0] = 0;
				for (int k = 0; k < n - 1; ++k) {
					int qqk = q[k] + (q[k] >= j);
					h1[k + 1] = h1[k] + ph1[k] * qqk;
					//h2[k + 1] = h2[k] + ph2[k] * qqk;
				}
				for (int p = 0; p < n; ++p) {
					//pair<ULL, ULL> hash;
					//hash.first = (h1[n - 1] - h1[p]) * Ph1 + h1[p] + ph1[p] * j;
					//hash.second = (h2[n - 1] - h2[p]) * Ph2 + h2[p] + ph2[p] * j;

					//assert(make_hash(q, j, p) == hash);

					ULL hash = (h1[n - 1] - h1[p]) * Ph1 + h1[p] + ph1[p] * j;
					int v = hash & MASK;
					if (i == 0) {
						save[v] = make_pair(j, p);
						poss[v].insert(j);
						ok[okn++] = v;
					} else if (save[v].first) {
						poss[v].insert(j);
					}
//						auto it = poss.find(hash);
//						if (it != poss.end()) it->second.insert(j);					
//					res += std::hash< pair<ULL, ULL> >()(hash);

					//vector<int> qq = make_array(q, j, p);
					//if (qq == vector<int>({12,10,6,15,32,3,22,21,31,8,13,27,1,11,17,5,36,9,7,2,24,18,33,4,14,20,29,28,26,19,30,23,25,16,34,35})) {
					//	cerr << hash.first << " " << hash.second << " " << i << " " << j << " " << p << " " << poss[hash].size() << endl;
					//}
				}
			}
		}
//		cerr << res << endl;
		
		bool any = false; 
		for (int _i = 0; _i < okn; ++_i) {
			if (!any && poss[ok[_i]].size() == n) {
				any = true;
				int x = save[ok[_i]].first, y = save[ok[_i]].second;

				for (size_t i = 0; i < out.size(); ++i) if (out[i] >= x) ++out[i];
				out.insert(out.begin() + y, x);

				for (size_t i = 0; i < out.size(); ++i) {
					printf("%d ", out[i]);
				}
				puts("");
			}
			save[ok[_i]].first = 0;
			poss[ok[_i]].reset();
		}
		assert(any);
		cerr << clock() << endl;
	}
//	cerr << clock() << endl;
//	assert(clock() <= CLOCKS_PER_SEC);

    return 0;
}
