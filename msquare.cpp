/*
 ID: emily.z1
 TASK: msquare
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
#include <chrono>
#include <bitset>

using namespace std;

map<int, pair<string, int>> info;

int A(int orig) {
    int a = orig/10000000;
    int b = (orig/1000000)%10;
    int c = (orig/100000)%10;
    int d = (orig/10000)%10;
    int e = (orig/1000)%10;
    int f = (orig/100)%10;
    int g = (orig/10)%10;
    int h = orig%10;
    int ret = pow(10,7)*h+pow(10,6)*g+pow(10,5)*f+pow(10,4)*e+pow(10,3)*d+100*c+10*b+a;
    return ret;
}

int B(int orig) {
    int a = orig/10000000;
    int b = (orig/1000000)%10;
    int c = (orig/100000)%10;
    int d = (orig/10000)%10;
    int e = (orig/1000)%10;
    int f = (orig/100)%10;
    int g = (orig/10)%10;
    int h = orig%10;
    int ret = pow(10,7)*d+pow(10,6)*a+pow(10,5)*b+pow(10,4)*c+pow(10,3)*f+100*g+10*h+e;
    return ret;
}

int C(int orig) {
    int a = orig/10000000;
    int b = (orig/1000000)%10;
    int c = (orig/100000)%10;
    int d = (orig/10000)%10;
    int e = (orig/1000)%10;
    int f = (orig/100)%10;
    int g = (orig/10)%10;
    int h = orig%10;
    int ret = pow(10,7)*a+pow(10,6)*g+pow(10,5)*b+pow(10,4)*d+pow(10,3)*e+100*c+10*f+h;
    return ret;
}

int main() {
    ifstream fin("msquare.in");
    ofstream fout("msquare.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    int goal = 0;
    int x = 0;
    for (int i=0; i<8; i++) {
        cin >> x;
        goal*=10;
        goal+=x;
    }
    int init = 12345678;
    
    if (goal==init) {
        cout << 0 << endl;
        cout << endl;
        return 0;
    }
    
    queue<int> cue;
    unordered_set<int> seen;
    cue.push(init);
    
    while (cue.size()>0) {
        int cur = cue.front();
        seen.insert(cur);
        cue.pop();
        int a = A(cur); int b = B(cur); int c = C(cur);
        if (!seen.count(a)) {
            cue.push(a);
            info.insert(make_pair(a, make_pair("A", cur)));
        }
        if (!seen.count(b)) {
            cue.push(b);
            info.insert(make_pair(b, make_pair("B", cur)));
        }
        if (!seen.count(c)) {
            cue.push(c);
            info.insert(make_pair(c, make_pair("C", cur)));
        }
        if (cur==goal) break;
    }
    string ret = "";
    int cur = goal;
    int nex = -1;
    while (nex!=init) {
        nex = info[cur].second;
        //cout << cur << " " << nex << endl;
        ret = info[cur].first+ret;
        cur = nex;
    }
    cout << ret.size() << endl;
    cout << ret << endl;
}
