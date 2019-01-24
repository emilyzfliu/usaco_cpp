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
int coins[5001];
int dp[5001];
int sum[5001];

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> coins[i];
        //dp[0][i] = coins[i];
        sum[i+1] = sum[i]+coins[i];
    }
    
    /*for (int i=0; i<N; i++) {
     cout << coins[i] << " ";
     }cout << endl;
     
     for (int i=0; i<=N; i++) {
     cout << sum[i] << " ";
     }cout << endl;*/
    
    for (int len = 1; len<=N; len++) {
        //cout <<"len "<< len << endl;
        for (int i=0; i<=N-len; i++) {
            dp[i] = sum[i+len]-sum[i]-min(dp[i], dp[i+1]);
        }
        /*for (int i=0; i<=N; i++) {
         cout << dp[i] << " ";
         }cout << endl;*/
    }
    
    cout << dp[0] << endl;
    
}
