/*
 ID: emily.z1
 TASK: ariprog
 LANG: C++14
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <climits>
#include <unordered_set>
#include <map>
#include <vector>
#include <utility>
#include <ctime>

using namespace std;

int N;
int M;
unordered_set<int> bisq;

int main() {
    ifstream fin ("ariprog.in");
    ofstream fout ("ariprog.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N >> M;
    
    //double now = time(nullptr);
    for (int i=0; i<=M; i++) {
        for (int j=0; j<=M; j++) {
            bisq.insert(i*i+j*j);
        }
    }
    //cout << time(nullptr) - now << endl;
    vector<int> bis(bisq.begin(), bisq.end());
    sort(bis.begin(), bis.end());
    vector<pair<int,int>> progs;
    for (int ib=0; ib < bis.size(); ++ib) {
        int b = bis[ib];
        for (int ic=ib+1; ic < bis.size(); ++ic) {
            int c = bis[ic];
            int diff = c-b;
            if (b + (N-1)*diff > bis.back()) break;
            bool exists = true;
            for (int i=0; i<N; i++) {
                if (!bisq.count(b+i*diff)) {
                    exists = false;
                    break;
                }
            }
            if (exists) {
                progs.push_back(make_pair(diff, b));
            }
        }
    }
    sort(progs.begin(), progs.end());
    if (progs.size()==0) cout << "NONE" << endl;
    else {
        for (int i=0; i<progs.size(); i++) {
            cout << progs[i].second << " " << progs[i].first << endl;
        }
    }
}
