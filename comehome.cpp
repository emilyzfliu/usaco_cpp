/*
 ID: emily.z1
 TASK: comehome
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
int M;
int adj[52][52];
unordered_set<int> nlog;
vector<int> nodes;
vector<int> starts;


int convert(char a) {
    if (a>='a') return a-'a'+26;
    return a-'A';
}

char convert(int a) {
    if (a>=26) return char(a+71);
    return char(a+65);
}

int mindex(vector<int> arr, vector<bool> seen, vector<int> indices){
    int mini = INT_MAX;
    int mindex = -1;
    int i = -1;
    for (int j=0; j<indices.size(); j++) {
        i = indices[j];
        if (seen[i]) continue;
        if (arr[i]<mini) {
            mini = arr[i];
            mindex = i;
        }
    }
    return mindex;
}

bool eval(vector<bool> seen, vector<int> dist) {
    for (int j=0; j<nodes.size(); j++) {
        int i = nodes[j];
        if (!seen[i]) return true;
    }
    return false;
}

int dist(int init) {
    //cout << "INITIATE DIST WITH INIT = " << convert(init) << endl;
    vector<bool> seen(52, false);
    vector<int> distance(52, INT_MAX);
    distance[init] = 0;
    int curr = init;
    bool togo = true;
    int i = -1;
    
    //cout << "initiated dist" << endl;
    
    while (!seen[25] && togo) {
        seen[curr] = true;
        for (int j=0; j<nodes.size(); j++) {
            i = nodes[j];
            //cout << convert(curr) << " " << convert(i) << endl;
            if (adj[curr][i]==0) continue;
            //cout << convert(curr) << " " << convert(i) << endl;
            //cout << distance[curr]+adj[curr][i] << endl;
            //cout << distance[curr]+adj[curr][i] << endl;
            if (distance[i]>distance[curr]+adj[curr][i]) {
                //cout << "aaa" << endl;
                distance[i]=distance[curr]+adj[curr][i];
                //cout << distance[i] << endl;
            }
        }
        /*for (int k=0; k<nodes.size(); k++) {
         int j = nodes[k];
         cout << convert(j) << " " << distance[j] << endl;
         }*/
        curr = mindex(distance, seen, nodes);
        //cout << "new curr " << convert(curr) << endl;
        togo = eval(seen, distance);
        //cout << "togo " << togo << endl;
    }
    return distance[25];
}

int main() {
    ifstream fin ("comehome.in");
    ofstream fout ("comehome.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> M;
    
    char x; char y; int val;
    int a; int b;
    
    for (int i=0; i<52; i++) {
        for (int j=0; j<52; j++) adj[i][j] = INT_MAX;
    }
    
    //cout << "init adj with inf" << endl;
    
    for (int i=0; i<M; i++) {
        cin >> x >> y >> val;
        a = convert(x);
        b = convert(y);
        if (!nlog.count(a)) {
            nlog.insert(a);
            nodes.push_back(a);
            if (a<25) starts.push_back(a);
        }
        if (!nlog.count(b)) {
            nlog.insert(b);
            nodes.push_back(b);
            if (b<25) starts.push_back(b);
        }
        if (adj[a][b]>val) adj[a][b] = val;
        adj[b][a] = adj[a][b];
    }
    
    for (int i=0; i<52; i++) {
        for (int j=0; j<52; j++) {
            if (adj[i][j] == INT_MAX) adj[i][j] = 0;
        }
    }
    
    //cout<< "init asfdsfadj" << endl;
    
    int mmin = INT_MAX;
    int mindex = -1;
    int temp = 0;
    
    for (int i=0; i<starts.size(); i++) {
        temp = dist(starts[i]);
        //cout << "found dist for " << convert(starts[i]) << endl;
        //cout << "THIS " << convert(starts[i]) << " " << temp << endl;
        if (mmin>temp) {
            mmin = temp;
            mindex = starts[i];
        }
    }
    
    //cout << "solved" << endl;
    
    cout << convert(mindex) << " " << mmin << endl;
}
