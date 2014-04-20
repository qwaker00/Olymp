#include <stdio.h>

inline int bar(char* s, int& p, unsigned l)
{
    int cmp1 = (l > p);
	if(!s[p]) return -1;
    return (cmp1 << 1) | (l > p);
}

int main(int argc, char** argv) {
	char s[3] = "12";
    int ZERO = argc - 1;
	printf("%d should be 3\n", bar(s, ZERO, -1));
	return 0;
}
