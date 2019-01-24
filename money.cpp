/*
 ID: emily.z1
 TASK: money
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

using namespace std;

int main() {
    ifstream fin ("money.in");
    ofstream fout ("money.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    int V;
    int N;
    cin >> V >> N;
    long long dp[V][N+1];
    vector<long long> coins;
    int x;
    
    for (int i=0; i<V; i++) {
        cin >> x;
        coins.push_back(x);
    }
    
    sort(coins.begin(), coins.end());
    
    for (int i=0; i<V; i++) dp[i][0] = 1;
    
    for (int i=0; i<N+1; i++) {
        //        cout << i << endl;
        //        cout << coins[0] << endl;
        if (i%coins[0]==0) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    
    //cout << "initialized for 1 coin" << endl;
    
    for (int j=1; j<=N; j++) {
        for (int i=1; i<V; i++) {
            //cout << i << " " << j << endl;
            if (j<coins[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j]+dp[i][j-coins[i]];
        }
    }
    
    cout << dp[V-1][N] << endl;
}
