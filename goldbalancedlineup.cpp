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

int N;
int K;
vector<int> dp;
vector<int> pfx;

int main() {
    cin >> N >> K;
    dp.resize(N);
    pfx.resize(N+1);
    int mod = (1<<K)-1;
    
    for (int i=0; i<N; i++) {
        cin >> dp[i];
        //cout << dp[i] << " ";
    }//cout << endl;
    
    //cout << mod << endl;
    
    pfx[0] = 0;
    
    pfx[1] = dp[0];
    //cout << pfx[0] << " " << pfx[1] << " ";
    for (int i=1; i<=N; i++) {
        pfx[i] = dp[i-1]+pfx[i-1];
        //cout << pfx[i] << " ";
    }//cout << endl;
    
    int mmax = 0;
    int mleft = -1;
    int mright = -1;
    
    for (int i=1; i<N; i++) {
        for (int j=i; j<=N; j++) {
            int val = pfx[j]-pfx[i-1];
            if (val%mod==0 && mmax<val){
                mmax = val;
                mleft = i;
                mright = j;
            }
        }
    }
    //cout << mleft << " " << mright << " " << mmax << endl;
    
    if (mleft==-1 && mright==-1) {
        cout << 0 << endl;
        return 0;
    }
    
    cout << (mright-mleft+1) << endl;
}
