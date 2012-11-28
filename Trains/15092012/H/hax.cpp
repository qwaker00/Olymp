#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 10111;
const int M = 200111;

int n, m, mp;
int mc[N], hp[N], cd[N];

int go[M][26];
int status[M]; // 0 - none, 1 - spell, 2 - buf
int spellNumber[M];
int fath[M], fail[M], nxt[M], bufNumber[M];

int kv = 0;

void addWord(char* word, int sn, int st, int bn) {
    int cur = 0;
    while (true) {
        char c = *word;
        ++word;
        int letter = c - 'A';

        if (!c) {
            status[cur] = st;
            spellNumber[cur] = sn;
            bufNumber[cur] = bn;
            return;
        } else {
            if (go[cur][letter] == -1) {
                memset(go[kv], -1, sizeof(go[kv]));
                fath[kv] = cur;
                go[cur][letter] = kv++;
            }   
            cur = go[cur][letter];
        }
    }
}

int findNumber(char* word) {
    int cur = 0;
    while (true) {
        char c = *word;
        ++word;
        int letter = c - 'A';

        if (!c) {
            return spellNumber[cur];
        } else {
            if (go[cur][letter] == -1) {
                return -1;
            }   
            cur = go[cur][letter];
        }
    }
}

void build() {
    queue<int> q;
    queue<int> ch;

    q.push(0);
    ch.push(0);

    while (!q.empty()) {
        int x = q.front(); q.pop();
        int chr = ch.front(); ch.pop();

        if (x) {
            fail[x] = go[ fail[fath[x]] ][ chr ];
        } else {
            fail[x] = 0;
        }
        if (status[ fail[x] ]) {
            nxt[x] = fail[x];
        } else {
            nxt[x] = nxt[ fail[x] ];
        }

        for (int i = 0; i < 26; ++i)
            if (go[x][i] != -1) {
                q.push(go[x][i]);
                ch.push(i);
            } else {
                go[x][i] = go[ fail[x] ][i];
            }
    }
}

map<string, int> mapSpellName;

char buffer[111], buffer1[111], buffer2[111];
char W[500111];

vector<int> bufs[N];
bool bufEnabled[N];
int willAvailable[N];
int got[N];

vector<int> bufForVertex[N];
int forWhichVertex[N];

struct info {
    string name;
    int result;
    
    bool operator <(const info& A) const {
        if (result != A.result) return result > A.result;
        return name < A.name;
    }
} infos[N];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int _test = 0;
    while (scanf("%d%d", &n, &mp) != EOF) {
        ++_test;

        mapSpellName.clear();
        memset(go[0], -1, sizeof(0));
        
        for (int i = 0; i < n; ++i) {
            bufs[i].clear();

            scanf("%s", buffer);
            scanf("%s", buffer1);
            scanf("%d%d%d", mc + i, hp + i, cd + i);
            cd[i] *= 5;

            mapSpellName[ buffer ] = i;

            infos[i].name = buffer;

            addWord(buffer1, i, 1, -1);
        }
        memset(bufEnabled, 0, sizeof(bufEnabled));
        
        
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%s %s %s", buffer, buffer1, buffer2);
            int from = mapSpellName[ buffer ];
            int to = mapSpellName[ buffer1 ];
        
            forWhichVertex[i] = to;

            bufs[from].push_back(i);
            addWord(buffer2, to, 2, i);             
        }
        
        build();
        scanf("\n");
        gets(W);

        int len = strlen(W);

        int cur = 0;

        memset(got, 0, sizeof(got));
        
        int doInc = 5;
        int curMana = mp;
        for (int i = 0; i < len; ++i) {
            int letter = W[i] - 'A';

            if (go[cur][letter] == -1) cur = 0;
            else cur = go[cur][letter];

            for (int pos = cur; pos; pos = fail[pos]) {
                if (status[pos] == 1 || (status[pos] == 2 && bufEnabled[ bufNumber[pos] ])) {
                    int num = spellNumber[pos];

                    if (i >= willAvailable[num] && curMana >= mc[num]) {
                        curMana = min(mp, curMana - mc[num]);
                        willAvailable[num] = i + cd[num];

                        for (size_t j = 0; j < bufForVertex[num].size(); ++j)
                            bufEnabled[ bufForVertex[num][j] ] = false;
                        bufForVertex[num].clear();

                        for (size_t j = 0; j < bufs[num].size(); ++j) {
                            bufEnabled[ bufs[num][j] ] = true;
                            bufForVertex[ forWhichVertex[ bufs[num][j] ] ].push_back( bufs[num][j] );  
                        }

                        got[num] += hp[num];
                    } else {
                        break;    
                    }
                }
            }

            --doInc;
            if (doInc == 0) {
                doInc = 5;
                curMana = min(mp, curMana + 1);
            }
        }

        int whole = 0;
        for (int i = 0; i < n; ++i) {
            whole += got[i];
            infos[i].result = got[i];
        }

        if (_test != 1) {
            cout << endl;
        }
        cout << "Case " << _test << ":" << endl;
        if (whole > 0) {
            cout << "The Total Healing Point is " << whole << "." << endl;

            int cn = min(n, 3);
            while (cn--) {
                int cool = 0;
                for (int i = 1; i < n; ++i)
                    if (infos[i] < infos[cool]) {
                        cool = i;
                    }
                
                cout << infos[cool].name << " " << infos[cool].result << " " << infos[cool].result / hp[cool] << endl;

                infos[cool].result = -100;
            }

           
        } else {
            cout << "No Healing Spell!" << endl;
        }
    }

    return 0;
}
