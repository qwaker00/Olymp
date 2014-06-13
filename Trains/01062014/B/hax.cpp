#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cassert>
#include <string>

using namespace std;

void outcontent(string& s, int depth) {
    int outed = 0;
    int lastsep = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
            if (lastsep == 1) continue;
            lastsep = 1;
            if (outed) putchar(' ');
        } else {
            lastsep = 0;
            if (outed == 0) {
                for (int i = 0; i < depth; ++i) putchar(' ');
            }
            putchar(s[i]);
            ++outed;
        }
    }
    if (outed) putchar('\n');
}
void outtag(string& s, int depth) {
    for (int i = 0; i < depth; ++i) putchar(' ');
    puts(s.c_str());
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    int it = 0;
    while(T--) {
        ++it;
        printf("Case #%d:\n", it);
        int st = 0;
        string content;
        string tag;
        int depth = 0;
        while (true) {
            char ch = getchar();
            if (feof(stdin)) break;
            if (st == 0) {
                if (ch == '<') {
                    outcontent(content, depth);
                    content = "";

                    st = 1;
                    tag = "<";
                } else {
                    content += ch;
                }
            } else
            if (st == 1) { // tag
                tag += ch;
                if (ch == '>') {
                    int closed;
                    if (tag.length() >= 2 && tag.substr(tag.length() - 2) == "/>") closed = 2;else
                    if (tag.length() >= 2 && tag.substr(0, 2) == "</") closed = 1;else closed = 0;

                    if (closed == 1) --depth;

                    outtag(tag, depth);


                    if (closed == 0) ++depth;

                    if (tag == "</html>" || tag == "<html/>") break;
                    tag = "";

                    st = 0;
                }
            }
        }
    }

    return 0;
}
