/*
 ID: emily.z1
 TASK: zerosum
 LANG: C++14
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <cmath>
#include <iomanip>
#include <queue>

using namespace std;

int N;

vector<string> next(string str) {
    int len = str.length();
    //cout << "len " << len << endl;
    int num = str[len-1]-'0';
    //cout << "num " << num << endl;
    num++;
    vector<string> ret;
    ret.push_back("+"+to_string(num));
    ret.push_back(" "+to_string(num));
    ret.push_back("-"+to_string(num));
    return ret;
}

int parse (string str) {
    bool append = false;
    int add = 0;
    int sub = 0;
    int prev = 0;
    char prexp = '+';
    for (int i=0; i<str.length(); i++) {
        char c = str[i];
        //cout << c << endl;
        //cout << to_string(c=='+') << " " << to_string(c=='-') << endl;
        if (c=='+' || c=='-') {
            if (prexp == '+') {
                //cout << "added " << prev << endl;
                add+=prev;
                prev = 0;
                prexp = c;
            }
            if (prexp == '-') {
                //cout << "subtracted " << prev << endl;
                sub+=prev;
                prev = 0;
                prexp = c;
            }
            continue;
        }
        if (c==' ') prev*=10;
        else {
            //cout << c << endl;
            int n = c-'0';
            //cout << n << endl;
            prev += n;
        }
    }
    if (prexp == '+') {
        //cout << "added " << prev << endl;
        add+=prev;
    }
    if (prexp == '-') {
        //cout << "subtracted " << prev << endl;
        sub+=prev;
    }
    //cout << add << " " << sub << endl;
    return add-sub;
}

int main() {
    ifstream fin ("zerosum.in");
    ofstream fout ("zerosum.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    
    queue<string> cue;
    cue.push("1");
    
    string temp = "";
    
    set<string> asdf;
    
    //cout << "commence bfs" << endl;
    
    while (cue.size()!=0) {
        string cur = cue.front();
        //cout << cur << endl;
        cue.pop();
        vector<string> adj = next(cur);
        for (string s: adj) {
            //cout << s << endl;
            temp = cur+s;
            //cout << temp << endl;
            if (temp[temp.length()-1]-'0'!=N) {
                cue.push(temp);
            }
            else asdf.insert(temp);
        }
    }
    
    for (string str: asdf) {
        if (parse(str)==0) cout << str << endl;
    }
}
