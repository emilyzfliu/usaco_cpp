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

int mod = 1000000009;
int N;
int C[50000];
int pre[50001];
int dp[50001];
int BIT[50001];
map<int, int> mp;

int get(int idx) {
    int ret = 0;
    for (; idx>0; idx-=idx&-idx)
        ret+=BIT[idx]%mod;
    return ret;
}

void add (int idx, int val) {
    for (; idx<50001; idx+=idx&-idx)
        BIT[idx]+=val%mod;
}

int main () {
    cin >> N;
    for (int i=0; i<N; i++) cin >> C[i];
    for (int i=1; i<=N; i++) pre[i] = (pre[i-1]+C[i-1]%mod)%mod;
    for (int i=0; i<=N; i++) mp[pre[i]] = 1;
    
    int index = 0;
    for (map<int, int>::iterator it = mp.begin(); it!=mp.end(); it++) {
        it -> second=++index;
    }
    
    dp[0] = 1;
    add(mp[0], 1);
    
    for (int i=1; i<=N; i++) {
        int cur_idx = mp[pre[i]]%mod;
        dp[i] = get(cur_idx)%mod;
        add(cur_idx%mod, dp[i]%mod);
    }
    
    cout << dp[N]%mod << endl;
}
