#include <stdio.h>

int main() {
    while ( !feof(stdin) ) {
        char ch = getchar();
        if (ch)
            putchar(ch);
    }
    return 0;
}