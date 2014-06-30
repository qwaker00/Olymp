#include <iostream>
#include <unordered_set>
#include <ctime>
using namespace std;
int main() {
    long long tmp;
    std::unordered_set<long long> hashset;

    long long x = ((long long)(1 << 30)) * 4 * 1024 * 1024, y = x;
    for (int i = 0; i < 50000; ++i) {
        hashset.insert(y);
        y += x;
    }
    cerr << clock() << endl;

    return 0;
}
