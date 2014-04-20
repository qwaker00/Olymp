#include <deque>
#include <iostream>

std::deque<int> q;

int main() {
    q.push_back(3);
    std::cout << q[0] << std::endl;
    return 0;
}