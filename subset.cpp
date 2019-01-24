/*
 ID: emily.z1
 TASK: subset
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
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int N;

int main() {
    ifstream fin ("subset.in");
    ofstream fout ("subset.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    
    if (N%4==1 || N%4==2) {
        cout << 0 << endl;
        return 0;
    }
    
    int sum = N*(N+1)/4;
    
    long long dp[N+1][sum+1];
    
    for (int i=0; i<sum+1; i++) {
        dp[0][i] = 0;
    }
    
    for (int i=0; i<N+1; i++) {
        dp[i][0] = 1;
    }
    
    for (int i=1; i<N+1; i++) {
        for (int j=1; j<sum+1; j++) {
            //cout << "dp with i = "<<i<<" and j = "<< j << endl;
            long long dpone = 0; long long dptwo = dp[i-1][j];
            if ((j-i)>=0) {
                dpone = dp[i-1][j-i];
            }
            //cout << dpone << " " << dptwo << endl;
            dp[i][j] = dpone+dptwo;
            //cout << " yields " << dp[i][j] << endl;
        }
    }
    //cout << "this should be correct" << endl;
    /* for (int i=0; i<N+1; i++) {
     for (int j=0; j<sum+1; j++) {
     cout << dp[i][j] << " ";
     }
     cout << endl;
     }*/
    
    cout << (dp[N][sum]/2) << endl;
}

