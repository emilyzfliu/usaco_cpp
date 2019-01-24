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

int N; int M;

int dp[10001][501];
int dist[10000];

bool valid (int i, int j) {
    if (i<0 || j<0) return false;
    if (i>N || j>M) return false;
    if (j>i) return false;
    if (j>N-i) return false;
    return true;
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> dist[i];
    //cout << valid(5,1) << endl;
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=M; j++) {
            if (!valid(i, j)) {
                //cout << i << " " << j << " is not valid" << endl;
                dp[i][j] = -1;
                continue;
            }
            if (j==0) {
                if (i==0) continue;
                for (int k=1; k<=M; k++) {
                    if (valid(i-k, k)) dp[i][j] = max(dp[i][j], dp[i-k][k]);
                }
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
                continue;
            }
            dp[i][j] = dp[i-1][j-1]+dist[i-1];
        }
    }
    
    /*for (int i=0; i<=M; i++) {
     for (int j=0; j<=N; j++) cout << dp[j][i] << " ";
     cout << endl;
     }*/
    
    cout << dp[N][0] << endl;
}
