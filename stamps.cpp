/*
 ID: emily.z1
 TASK: stamps
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
int K; int N;
vector<int> coins;
int dp[200*10000+1];

int main() {
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> K >> N;
    int x = 0;
    //cout << "read K, N" << endl;
    int maxcoin = -1;
    for (int i=0; i<N; i++) {
        cin >> x;
        coins.push_back(x);
        maxcoin = max(maxcoin, x);
    }
    //cout << "read" << endl;
    //for (int i=0; i<coins.size(); i++) cout << coins[i] << " ";
    //cout << endl;
    //dp.push_back(0);
    int i = 1;
    for (i=1; i<=maxcoin*K; i++) {
        //cout << i << endl;
        dp[i] = maxcoin*K;
        for (int j=0; j<N; j++) {
            if (i>=coins[j]) {
                //cout << dp[i-coins[j]+1]<< endl;
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
                //cout << i << " ";
            }
        }
        if (dp[i]>K) break;
    }
    cout << i-1 << endl;
}
