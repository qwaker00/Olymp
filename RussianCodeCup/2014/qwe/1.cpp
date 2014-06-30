#include <cstdio>

char s[][100] = {
"    Yesterday, All",
"my troubles seemed",
"so far away, Now it",
"looks as though",
"they' re here to",
"stay, Oh, I believe",
"in yesterday.",
"    Suddenly, I'm",
"not half the man I",
"used to be, There' s",
"a shadow hanging",
"over me, Oh,",
"yesterday came",
"suddenly..."
};

int main() {
	freopen("output.txt", "w", stdout);
	int c = sizeof(s)/ sizeof(s[0]);
	for (int i =0; i < c; ++i) {
		puts(s[i]);
	}
	return 0;
}
