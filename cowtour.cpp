/*
 ID: emily.z1
 TASK: cowtour
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
int adj[150][150];
double dp[150][150];
vector<pair<int, int>> logg;
double inf = INT_MAX;

int square(int x) {
    return x*x;
}

double ddist(int a, int b) {
    int x1 = logg[a].first;
    int y1 = logg[a].second;
    int x2 = logg[b].first;
    int y2 = logg[b].second;
    return sqrt(square(x1-x2)+square(y1-y2));
}

void initialize() {
    double temp = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i!=j) dp[i][j] = inf;
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (adj[i][j]==1) {
                dp[i][j] = ddist(i, j);
            }
        }
    }
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (dp[i][k]+dp[j][k]<dp[i][j]) dp[i][j] = dp[i][k]+dp[j][k];
            }
        }
    }
}

double getmax(int x) {
    double mmax = -1;
    for (int i=0; i<N; i++) {
        if (dp[x][i]==inf) continue;
        if (dp[x][i]>mmax) mmax = dp[x][i];
    }
    return mmax;
}

double mindiam(vector<int> field1, vector<int> field2) {
    double mindim = inf;
    double tempo = 0;
    int a=0; int b=0;
    for (int i=0; i<field1.size(); i++) {
        for (int j=0; j<field2.size(); j++) {
            a = field1[i];
            b = field2[j];
            tempo = getmax(a)+getmax(b)+ddist(a,b);
            if (mindim>tempo) mindim = tempo;
        }
    }
    double diam = 0;
    for (int i=0; i<field1.size(); i++) {
        diam = getmax(field1[i]);
        if (tempo<diam)tempo =diam;
    }
    for (int i=0; i<field2.size(); i++) {
        diam = getmax(field2[i]);
        if (tempo<diam)tempo =diam;
    }
    return mindim;
}

double diameter(vector<int> field) {
    double diam = -1;
    for (int i=0; i<field.size(); i++) {
        for (int j=i; j<field.size(); j++) {
            if (diam<dp[field[i]][field[j]])diam=dp[field[i]][field[j]];
        }
    }
    return diam;
}

int main() {
    ifstream fin ("cowtour.in");
    ofstream fout ("cowtour.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    
    pair<int, int> temp;
    
    int x = 0;
    
    for (int i=0; i<N; i++) {
        cin >> x;
        temp.first = x;
        cin >> x;
        temp.second = x;
        logg.push_back(temp);
    }
    
    string str;
    for (int i=0; i<N; i++) {
        cin >> str;
        for (int j=0; j<N; j++) {
            adj[i][j] = str[j]-'0';
        }
    }
    
    initialize();
    
    double mindim = inf;
    double tempo = 0;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (dp[i][j]!=inf) continue;
            tempo = getmax(i)+getmax(j)+ddist(i,j);
            if (tempo<mindim) mindim = tempo;
        }
    }
    
    for (int i=0; i<N; i++) {
        tempo = getmax(i);
        if (tempo>mindim) {
            mindim = tempo;
        }
    }
    cout << setprecision(6) << fixed << mindim << endl;
}
