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

int F; int V;
int flowers[100][100];
int dp[100][100];


int main() {
    cin >> F >> V;
    for (int i=0; i<F; i++) {
        for (int j=0; j<V; j++) {
            cin >> flowers[i][j];
        }
    }
    dp[0][0] = flowers[0][0];
    for (int i=1; i<F; i++) {
        dp[i][i] = dp[i-1][i-1]+flowers[i][i];
    }
    
    for (int i=1; i<V-F+1; i++) {
        dp[0][i] = max(dp[0][i-1], flowers[0][i]);
    }
    
    for (int i=1; i<F; i++) {
        for (int j=i; j<V-(F-i-1); j++) {
            dp[i][j] = max(dp[i][j-1], flowers[i][j]+dp[i-1][j-1]);
        }
    }
    
    cout << dp[F-1][V-1] << endl;
}
