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

int N;
int M;
unordered_map<int, vector<int>> f;
vector<pair<int, int>> criteria;
unordered_set<int> notlast;
vector<int> tree;

void add(int n, int m) {
    vector<int> temp;
    if (!f.count(n)) f.insert(make_pair(n, temp));
    f[n].push_back(m);
}

void buildtree(int i) {
    //cout << "BUILDING TREE WITH i = " << i << endl;
    unordered_set<int> seen;
    int cur = i;
    tree[cur] = 0;
    stack<int> st;
    seen.insert(cur);
    st.push(cur);
    while (seen.size()!=N) {
        cur = st.top();
        st.pop();
        seen.insert(cur);
        vector<int> next = f[cur];
        //cout << "cur = " << cur << endl;
        //for (int i=0; i<next.size(); i++) {
        //  cout << next[i] << " ";
        //}cout << endl;
        for (int i=0; i<next.size(); i++) {
            if (seen.count(next[i])) continue;
            st.push(next[i]);
            tree[next[i]] = tree[cur]+1;
        }
    }
    // cout << "i = " << i << endl;
    //for (int i=0; i<=N; i++) {
    //      cout << tree[i] << " ";
    //  }cout << endl;
}

bool check() {
    for (int i=0; i<M; i++) {
        pair<int, int> t = criteria[i];
        if (tree[t.first]<tree[t.second]) return false;
    }
    return true;
}

bool possible(int i) {
    buildtree(i);
    return check();
}

int main() {
    ifstream fin("gathering.in");
    ofstream fout("gathering.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    
    cin >> N >> M;
    tree.resize(N+1);
    
    for (int i=0; i<N-1; i++) {
        int x; int y;
        cin >> x >> y;
        add(x,y);
        add(y, x);
    }
    
    for (int i=0; i<M; i++) {
        int x; int y;
        cin >> x >> y;
        criteria.push_back(make_pair(x,y));
        notlast.insert(x);
    }
    
    for (int i=1; i<=N; i++) {
        if (notlast.count(i)) {
            cout << 0 << endl;
            continue;
        }
        cout << possible(i) << endl;
    }
}
