#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

 string format(string input, int len) {
    int need = len - input.size();
    stringstream ss;
    for (int i = 0; i < need; ++i) ss << ' ';
    ss << input;
    return ss.str();
}

string lltos(ll n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

struct packet {
    string inputInterface;
    string outputInterface;
    ull src, dst;
    string protocol;
    int sport, dport;
    int length;

    void parse(string args) {
        inputInterface = outputInterface = "none";
        stringstream ss(args);

        string cur;
        while (ss >> cur) {
            if (cur == "recv") continue;
            string equal;
            ss >> equal;

            if (cur == "IN") {
                ss >> inputInterface;
            } else if (cur == "OUT") {
                ss >> outputInterface;
            } else if (cur == "SRC") {
                ss >> cur;
                cur += '.';
                src = 0;
                ull sum = 0;
                for (int i = 0; i < cur.size(); ++i) {
                    if (cur[i] >= '0' && cur[i] <= '9') {
                        sum = cur[i] - '0' + sum * 10;
                    } else {
                        src = src * 256 + sum;
                        sum = 0;
                    }
                }
            } else if (cur == "DST") {
                ss >> cur;
                cur += '.';
                dst = 0;
                ull sum = 0;
                for (int i = 0; i < cur.size(); ++i) {
                    if (cur[i] >= '0' && cur[i] <= '9') {
                        sum = cur[i] - '0' + sum * 10;
                    } else {
                        dst = src * 256 + sum;
                        sum = 0;
                    }
                }
            } else if (cur == "PROTO") {
                ss >> protocol;
            } else if (cur == "SPT") {
                ss >> sport;
            } else if (cur == "DPT") {
                ss >> dport;
            } else if (cur == "LEN") {
                ss >> length;
            }
        }
    }
};

ull masks[55];

struct rule {
    string inputInterface;
    string outputInterface;
    string protocol;
    int sport, dport;
    ull snet, smask;
    bool snegation;
    ull dnet, dmask;
    bool dnegation;
    string action;

    bool hasInputInterface;
    bool hasOutputInteface;
    bool hasProtocol;
    bool hasSport, hasDport;
    bool hasSrc, hasDst;

    ll packets, bytes;

    rule() {
        snegation = dnegation = hasInputInterface = hasOutputInteface = hasProtocol = hasSport = hasDport = hasSrc = hasDst = false;
        dnet = dmask = snet = smask = 0;
        packets = bytes = 0;
    }

    int apply(const packet& p) {
        if (hasInputInterface && inputInterface != p.inputInterface) return 0;
        if (hasOutputInteface && outputInterface != p.outputInterface) return 0;
        if (hasProtocol && protocol != p.protocol) return 0;
        if (hasSport && sport != p.sport) return 0;
        if (hasDport && dport != p.dport) return 0;
        if (hasSrc) {
            bool match = true;
            if ((p.src & masks[smask]) != snet) match = false;
            if (match == snegation) return 0;
        }
        if (hasDst) {
            bool match = true;
            if ((p.dst & masks[dmask]) != dnet) match = false;
            if (match == dnegation) return 0;
        }

        packets += 1;
        bytes += p.length;
        if (action == "RETURN") return -1;
        if (action == "LOG") return 0;
        return 1;
    }

    void parse(string args) {
        stringstream ss(args);

        string cur;
        while (ss >> cur) {
            if (cur == "-i") {
                ss >> inputInterface;
                hasInputInterface = true;
            } else if (cur == "-o") {
                ss >> outputInterface;
                hasOutputInteface = true;
            } else if (cur == "-p") {
                ss >> protocol;
                hasProtocol = true;
            } else if (cur == "--sport") {
                ss >> sport;
                hasSport = true;
            } else if (cur == "--dport") {
                ss >> dport;
                hasDport = true;
            } else if (cur == "-s") {
                hasSrc = true;
                ss >> cur;
                if (cur == "!") {
                    snegation = true;
                    ss >> cur;
                }

                snet = 0;
                smask = 32;
                ull sum = 0;
                bool isMask = false;
                for (int i = 0; i < cur.size(); ++i) {
                    if (cur[i] >= '0' && cur[i] <= '9') {
                        sum = cur[i] - '0' + sum * 10;
                    } else {
                        snet = snet * 256 + sum;
                        sum = 0;
                        if (cur[i] == '/') isMask = true;
                    }
                }
                if (isMask) {
                    smask = sum;
                } else {
                    snet = snet * 256 + sum;
                }
            } else if (cur == "-d") {
                hasDst = true;
                ss >> cur;
                if (cur == "!") {
                    dnegation = true;
                    ss >> cur;
                }

                dnet = 0;
                dmask = 32;
                ull sum = 0;
                bool isMask = false;
                for (int i = 0; i < cur.size(); ++i) {
                    if (cur[i] >= '0' && cur[i] <= '9') {
                        sum = cur[i] - '0' + sum * 10;
                    } else {
                        dnet = dnet * 256 + sum;
                        sum = 0;
                        if (cur[i] == '/') isMask = true;
                    }
                }
                if (isMask) {
                    dmask = sum;
                } else {
                    dnet = dnet * 256 + sum;
                }
            } else if (cur == "-j") {
                ss >> action;
            }

        }
    }


    void zero() {
        packets = bytes = 0;
    }

    void print() {
        cout << format(lltos(packets), 8);
        cout << format(lltos(bytes), 8);
        cout << format(action, 8);
        cout << format(hasProtocol ? protocol : "any", 8);
        cout << format(hasInputInterface ? inputInterface : "any", 8);
        cout << format(hasOutputInteface ? outputInterface : "any", 8);
        if (hasSrc) {
            stringstream ss;
            if (snegation) ss << "! ";

            vector<ull> octets;
            ull tmp = snet;
            for (int i = 0; i < 4; ++i) {
                octets.push_back(tmp & 255);
                tmp >>= 8;
            }
            for (int i = 3; i >= 0; --i) ss << octets[i] << (i == 0 ? "" : ".");
            if (smask != 32) {
                ss << "/" << smask;
            }
            cout << format(ss.str(), 22);
        } else cout << format("anywhere", 22);
        if (hasDst) {
            stringstream ss;
            if (dnegation) ss << "! ";

            vector<ull> octets;
            ull tmp = dnet;
            for (int i = 0; i < 4; ++i) {
                octets.push_back(tmp & 255);
                tmp >>= 8;
            }
            for (int i = 3; i >= 0; --i) ss << octets[i] << (i == 0 ? "" : ".");
            if (dmask != 32) {
                ss << "/" << dmask;
            }
            cout << format(ss.str(), 22);
        } else cout << format("anywhere", 22);
        cout << format(hasSport ? lltos(sport) : "any", 8);
        cout << format(hasDport ? lltos(dport) : "any", 8);
        cout << endl;
    }



};

struct chain {
    vector<rule> rules;
    ll packets, bytes;
    string action;
    string name;

     void apply(const packet& p) {
        for (int i = 0; i < rules.size(); ++i) {
            int result = rules[i].apply(p);
            if (result == -1) break;
            if (result == 1) return;
        }

        packets += 1;
        bytes += p.length;
    }

    void zero() {
        packets = bytes = 0;
        for (int i = 0; i < rules.size(); ++i) rules[i].zero();
    }

    void reset() {
        action = "ACCEPT";
        rules.clear();
        packets = bytes = 0;
    }

    void changeTarget(string naction) {
        action = naction;
        bytes = packets = 0;
    }

    chain(string aname) {
        name = aname;
        reset();
    }

    void print() {
        cout << "Chain " << name << " (policy " << action << " " << packets << " packets, " << bytes << " bytes)" << endl;
        cout << format("pkts", 8) << format("bytes", 8) << format("target", 8) << format("proto", 8) << format("in", 8) << format("out", 8) << format("source", 22) << format("destination", 22) << format("sport", 8) << format("dport", 8) << endl;
        for (int i = 0; i < rules.size(); ++i) rules[i].print();
    }
};


string makeCool(string s) {
    stringstream result;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == '!') {
            result << " ! ";
        } else if (s[i] == '=') {
          result << " = ";
          if (i + 1 >= s.size() || s[i + 1] == ' ') {
            result << "none";
          }
        } else result << s[i];
    return result.str();
}

char buffer[11111];

int main() {
    masks[0] = 0;
    for (int i = 1; i <= 32; ++i) {
        masks[i] = masks[i - 1] + (((ull) 1) << (32 - i));
    }

    freopen("iptables.in", "r", stdin);
    freopen("iptables.out", "w", stdout);

    chain input("INPUT");
    chain output("OUTPUT");
    chain forward("FORWARD");

    while (gets(buffer)) {
        stringstream ss(makeCool(buffer));

        string cmd;
        if (!(ss >> cmd)) continue;

        if (cmd == "recv") {
            packet p;
            p.parse(ss.str());
            if (p.inputInterface != "none" && p.outputInterface != "none") forward.apply(p);
            else if (p.inputInterface == "none") output.apply(p);
            else input.apply(p);
        } else {
            string chname;
            ss >> cmd;
            if (cmd == "-vL") {
                input.print();
                output.print();
                forward.print();
                puts("");
                continue;
            }

            ss >> chname;

            chain* ch = 0;
            if (chname == "INPUT") ch = &input;
            else if (chname == "OUTPUT") ch = &output;
            else ch = &forward;

            if (cmd == "-A") {
                rule r;
                r.parse(ss.str());
                ch->rules.push_back(r);
            } else if (cmd == "-F") {
                ch->reset();
            } else if (cmd == "-Z") {
                ch->zero();
            } else if (cmd == "-P") {
                string action;
                ss >> action;
                ch->changeTarget(action);
            }
        }
    }

    return 0;
}
