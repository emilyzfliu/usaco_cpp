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
int K;
int h[5001];
int dp[5001];
//compare a/b to c/d
int comp(long long a, long long b, long long c, long long d) {
    //cout << a << " " << b << " " <<c << " " << d << endl;
    long long ad = a*d;
    long long bc = b*c;
    //cout << ad << " " << bc << endl;
    //cout << (ad>bc) << endl;
    if (ad>bc) return 1;
    if (ad<bc) return -1;
    return 0;
}

int main() {
    cin >> N >> K;
    for (int i=0; i<N; i++) cin >> h[i];
    
    dp[N-1] = 1;
    int maxx;
    int maxy;
    int maxdex;
    
    for (int i=N-2; i>=0; i--) {
        maxdex = -1;
        maxx = 1;
        maxy = -2147483647;
        dp[i] = 2147483647;
        for (int j=i+1; j<=min(N-1, K+i); j++) {
            //cout << i << " " << j << endl;
            //if (j==4 && i==0)cout << h[j]-h[i] << " " << j-i << endl;
            //cout << maxy << " " << maxx << endl;
            //if (j==4 && i==0)cout << comp(h[j]-h[i],j-i,maxy, maxx) << endl;
            //cout << maxy << " " << maxx << endl;
            if (comp(h[j]-h[i],j-i,maxy, maxx)>=0) {
                //cout << "valid" << endl;
                maxdex = j;
                maxx = j-i;
                maxy = h[j]-h[i];
                dp[i] = min(dp[i], dp[maxdex]+1);
            }
            //cout << dp[i] << endl;
            //else {
            //cout << "breaking: " << endl;
            //cout << i << " " << j << " " << maxdex << endl;
            //break;
            //dp[i] = min(dp[i], dp[maxdex]+1);
            //}
        }
        dp[i] = min (dp[i], dp[maxdex]+1);
    }
    
    //for (int i=0;i<N; i++) cout << dp[i]  << " ";
    //cout << endl;
    
    cout << dp[0] << endl;
}
