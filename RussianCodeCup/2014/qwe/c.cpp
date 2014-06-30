#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

const int MOD=1000000007;
const int INF=2000000000;
const long long INFll=4000000000000000000ll;

vector <string> e;
int w, b;
string tab="";

inline void solve(string s){
    string cur="";
    e.clear();
    for (int i=0; i<s.length(); ++i){
        if (s[i]>='0' && s[i]<='9' || s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
            cur+=s[i];
        else{
            if (s[i]!=' ')
                cur+=s[i];
            if (cur!="")
                e.push_back(cur);
            cur="";
        }
    }
    cout<<tab;
    int l=b;
    int k=1;
    for (int i=1; i<e.size(); ++i)
        if (e[i][0]=='.' || e[i][0]==',' || e[i][0]=='!' || e[i][0]=='?' || e[i][0]=='-' || e[i][0]==':' || e[i][0]==39)
            e[k-1]+=e[i];
        else
            e[k++]=e[i];
    for (int i=0; i<k; ++i)
        if (e[i].length()+l+(i>0)<=w){
            if (i)
                cout<<" ";
            cout<<e[i];
            l+=e[i].length()+(i>0);
        }
        else{
            cout<<endl<<e[i];
            l=e[i].length();
        }
    cout<<endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin>>w>>b;
    string s, t="";
    getline(cin, s);
    for (int i=0; i<b; ++i)
        tab+=" ";
    bool f=false;
    while (getline(cin, s)){
        if (s==""){
            if (f){
                solve(t);
                f=false;
                t="";
            }
            continue;
        }
        f=true;
        t+=" "+s;
    }
    return 0;
}
