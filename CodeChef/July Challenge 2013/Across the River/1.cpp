#include <iostream>

using namespace std;

int main() {
    int i = 5;
    int  any_array[] = {0,1,2,3,4,5,6,7,8,9,10};
    int a = any_array[i];
    int b = any_array[++i];
    int c = any_array[i++];
    cout << a << " " << b << " " << c << endl;
}