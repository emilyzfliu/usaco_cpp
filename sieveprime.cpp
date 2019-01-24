#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int N;
vector<int> qu;
int mmax;

int main() {
    cin >> N;
    int x = 0;
    mmax = -1;
    for (int i=0; i<N; i++) {
        cin >> x;
        qu.push_back(x);
        if (mmax<x) mmax = x;
    }
    vector<bool> sieve(mmax+1, true);
    sieve[0]= false;
    sieve[1] = false;
    double sq = sqrt(mmax);
    for (int i=2; i<=sq; i++) {
        if (sieve[i]==false) continue;
        for (int j=2*i; j<=mmax; j+=i) {
            sieve[j] = false;
        }
    }
    
    vector<int> dp;
    
    dp.push_back(0);
    dp.push_back(0);
    int temp = 0;
    
    for (int i=2; i<=mmax; i++) {
        if (sieve[i]) temp = dp[i-1]+1;
        else temp = dp[i-1];
        dp.push_back(temp);
    }
    /*
     for (int i=0; i<=mmax; i++) {
     cout << i << " " << sieve[i] << " " << dp[i]<< endl;
     }*/
    
    for (int i=0; i<N; i++) {
        cout << dp[qu[i]] << endl;
    }
}
