/*
 ID: emily.z1
 TASK: butter
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

int N; int P; int C;
vector<int> starts;
int adj[801][801];
vector<vector<int>> adjlist(801);
priority_queue<int> pcue;

int dij(int start) {
    vector<int> dists(P+1, (1<<31)-1);
    vector<bool> seen(P+1);
    priority_queue<pair<int, int>> pq;
    dists[start] = 0;
    pq.push(make_pair(0, start));
//    unordered_set<int> cows(starts.begin(), starts.end());
    int prev = (1<<31)-1;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
//        if (seen[u]) continue;
//        cows.erase(u);
        seen[u] = true;
        for (int v : adjlist[u]) {
            if (dists[u]+adj[u][v]<dists[v]) {
                dists[v] = dists[u]+adj[u][v];
                pq.push(make_pair(-dists[v], v));
            }
        }
        seen[u] = true;
    }
    
    int sum = 0;
    for (int i=0; i<N; i++) {
        sum+=dists[starts[i]];
    }
    return sum;
}

void addlist(int x, int y) {
    adjlist[x].push_back(y);
    adjlist[y].push_back(x);
}

int main() {
    ifstream fin("butter.in");
    ofstream fout("butter.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N >> P >> C;
    int x = 0; int y = 0;
    for (int i=0; i<N; i++) {
        cin >> x;
        starts.push_back(x);
    }
    for (int j=0; j<C; j++) {
        cin >> x >> y;
        cin >> adj[x][y];
        adj[y][x] = adj[x][y];
        addlist(x, y);
    }
    
    int mmin = (1<<31)-1;
    //cout << mmin << endl;
    vector<int> dum;
    int sum;
    
    for (int a = 1; a<=P; a++) {
        mmin = min(mmin, dij(a));
    }
    
    cout << mmin << endl;
}
