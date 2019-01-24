/*
 ID: emily.z1
 TASK: fence
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
#include <stack>

using namespace std;

int F;
int N;
set<pair<int, int>> seen;
unordered_map<int, set<int>> adj;

void addtoadj(int x, int y) {
    //cout << "does this work?" << endl;
    adj[x].insert(y);
    adj[y].insert(x);
    //cout << "i guess so" << endl;
}

int findstart() {
    int minodd = (1<<31)-1;
    int mineven = (1<<31)-1;
    int siz = 0;
    int oddcount = 0;
    for (int node = 1; node<=N; node++) {
        siz = adj[node].size();
        //cout << node <<" siz " << siz << endl;
        if (siz%2==0) {
            mineven = min(node, mineven);
        }
        if (siz%2==1) {
            minodd = min(node, minodd);
            oddcount++;
        }
    }
    if (oddcount==0) return mineven;
    return minodd;
}

vector<int> eval(int init) {
    stack<int> sta;
    int loc = init;
    int nex = -1;
    vector<int> ret;
    while (seen.size()!=F*2) {
        set<int> dum = adj[loc];
        //cout <<"size " << dum.size() << endl;
        //cout << "loc " << loc << endl;
        if (dum.size()==0) {
            nex = sta.top();
            sta.pop();
            ret.push_back(loc);
        }
        else {
            nex = *dum.begin();
            while (seen.count(make_pair(loc, nex))) {
                dum.erase(*dum.begin());
                if (dum.size()==0) {
                    nex = sta.top();
                    sta.pop();
                    ret.push_back(loc);
                    break;
                }
                nex = *dum.begin();
            }
            if (dum.size()!=0) dum.erase(*dum.begin());
        }
        //cout << "nex " << nex << endl;
        seen.insert(make_pair(loc, nex));
        seen.insert(make_pair(nex, loc));
        sta.push(loc);
        loc = nex;
    }
    while (sta.size()!=0) {
        ret.push_back(sta.top());
        //cout << sta.top() << " ";
        sta.pop();
    }//cout << endl;
    //cout << ret << endl;
    ret.push_back(nex);
    return ret;
}

int main() {
    ifstream fin("fence.in");
    ofstream fout("fence.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    cin >> F;
    int x = 0; int y = 0;
    //cout << "time to start reading things" << endl;
    set<int> nu;
    N = -1;
    for (int i=0; i<F; i++) {
        cin >> x >> y;
        //cout << i << endl;
        addtoadj(x,y);
        N = max(N, max(x,y));
    }
    //cout << "added vals" << endl;
    
    int init = findstart();
    
    //cout << "found start, start is " << init << endl;
    
    vector<int> ret = eval(init);
    
    
    for (int i = ret.size()-2; i>=0; i--) {
        cout << ret[i] << endl;
    }
    
    
    cout << ret[ret.size()-1] << endl;
    
}
