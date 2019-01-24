/*
 ID: emily.z1
 TASK: wormhole
 LANG: C++14
 */

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int N, X[13], Y[13];
int partner[13];
int next_on_right[13];

//test for cycle
bool cycle_exists() {
    for (int a=1; a<=N; a++) {
        int pos = a;
        for (int c=0; c<N; c++) {
            pos = next_on_right[partner[pos]];
        }
        if (pos!=0) return true;
    }
    return false;
}

//counts all solns
int solve () {
    //enumerate those pairs
    int i, total = 0;
    //find first unpaired wormhole
    for (i=1; i<=N; i++) {
        if (partner[i]==0) break;
    }
    //base case
    if (i>N) {
        if (cycle_exists()) {
            return 1;
        }
        return 0;
    }
    
    //pair i with all other wormholes j
    for (int j=1+i; j<=N; j++) {
        if (partner[j]==0) {
            //try pairing i and j
            partner[i] = j;
            partner[j] = i;
            total+=solve();
            partner[i] = partner[j] = 00;
        }
    }
    return total;
}

int main() {
    ifstream fin ("wormhole.in");
    ofstream fout ("wormhole.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    
    for (int i=1; i<=N; i++) {
        cin >> X[i] >> Y[i];
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (X[j]>X[i] && Y[i]==Y[j]) {
                if (next_on_right[i]==0 ||
                    X[next_on_right[i]]>X[j]) {
                    next_on_right[i] = j;
                }
            }
        }
    }
    
    cout << solve() << endl;
    return 0;
}
