/*
 ID: emily.z1
 TASK: agrinet
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

using namespace std;

int N;
int adj[100][100];
int int_max = 2147483647;

int mindex(vector<int> arr, vector<bool> seen) {
    int mdex = -1;
    int mval = int_max;
    for (int i=0; i<N; i++) {
        if (seen[i]) continue;
        if (arr[i]<mval) {
            mval = arr[i];
            mdex = i;
        }
    }
    return mdex;
}


int mst() {
    vector<int> dist;
    vector<int> parent;
    parent.push_back(-1);
    dist.push_back(0);
    for (int i=1; i<N; i++) parent.push_back(0);
    for (int i=1; i<N; i++) dist.push_back(int_max);
    vector<bool> seen;
    for (int i=0; i<N; i++) seen.push_back(false);
    for (int c=0; c<N; c++) {
        int curr = mindex(dist, seen);
        seen[curr] = true;
        for (int i=0; i<N; i++) {
            if (adj[curr][i]!=0 && !seen[i] && dist[i]>adj[curr][i]) {
                dist[i] = adj[curr][i];
                parent[i] = curr;
            }
        }
    }/*
    if (N==4) {
        for (int j=0; j<N; j++) {
            cout << dist[j] << " ";
        }
        cout << endl;
        for (int j=0; j<N; j++) {
            cout << parent[j] << " ";
        }
        cout << endl;
    }*/
    
    int sum = 0;
    for (int i=1; i<N; i++) {
        sum+=adj[parent[i]][i];
    }
    return sum;
}

int main() {
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> adj[i][j];
        }
    }
    /*for (int i=0; i<N; i++) {
     for (int j=0; j<N; j++) {
     cout << adj[i][j] << " ";
     }
     cout << endl;
     }*/
    cout << mst() << endl;
}
