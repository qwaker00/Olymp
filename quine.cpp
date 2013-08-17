#include <iostream>

using namespace std;

int main() {
    char quote = 34;
    const char* lines[] = {
        "#include <iostream>",
        "",
        "using namespace std;",
        "",
        "int main() {",
        "    char quote = 34;",
        "    const char* lines[] = {",
        "        ",
        "    };",
        "    for (int i = 0; i < 7; ++i) cout << lines[i] << endl;",
        "    for (int i = 0; i < 14; ++i) cout << lines[7] << quote << lines[i] << quote << ',' << endl;",
        "    for (int i = 8; i < 14; ++i) cout << lines[i] << endl;",
        "    return 0;",
        "}",
    };
    for (int i = 0; i < 7; ++i) cout << lines[i] << endl;
    for (int i = 0; i < 14; ++i) cout << lines[7] << quote << lines[i] << quote << ',' << endl;
    for (int i = 8; i < 14; ++i) cout << lines[i] << endl;
    return 0;
}
