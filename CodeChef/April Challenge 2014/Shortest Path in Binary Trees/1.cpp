#include <cstdio>
#include <cstdlib>

inline void bar(char* s, int& p, unsigned int l)
{
    if (!rand()) ++p;
    printf ("r1 = %d\n", (unsigned)p < l);
	if(!s[p]) return;
    printf ("r2 = %d\n", (unsigned)p < l);
}

int main(int argc, char** argv) {
	char s[] = "1";
    int z = 0;
	bar(s, z, -1);
	return 0;
}
