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
#include <complex>

using namespace std;

int64_t N;
int64_t D;
vector<int64_t> m;

int64_t dp() {
    vector<int64_t> dp;
    dp.resize(N);
    dp[0] = m[0];
    dp[1] = m[1];
    for (int64_t i=2; i<N; i++) {
        for (int j=i-2; j>=0; j--) {
            //cout <<dp[i] << " "<< m[i] << " " << dp[j]<< endl;
            if (dp[i]<dp[j]+m[i]) dp[i] = dp[j]+m[i];
        }
        dp[i] = max(dp[i],dp[i-1]);
    }
    //for (int i=0; i<N; i++) cout << dp[i] << " ";
    //cout << endl;
    return dp[N-1];
}

int main() {
    cin >> N >> D;
    m.resize(N);
    int64_t sum = 0;
    for (int64_t i=0; i<N; i++) {
        cin >> m[i];
    }
    for (int64_t i=0; i<D; i++) {
        int64_t x; int64_t y;
        cin >> x >> y;
        m[x-1] = y;
        sum+=dp();
    }
    cout << sum << endl;
}
