/*
 ID: emily.z1
 TASK: nocows
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

using namespace std;

int main() {
    ifstream fin ("nocows.in");
    ofstream fout ("nocows.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    int N;
    int K;
    cin >> N >> K;
    
    int w = (N+1)/2+1;
    int h = K+1;
    
    int dp[w][h];
    
    if (N%2==0) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i=0; i<w; i++) {
        dp[i][0] = 0;
    }
    
    for (int i=0; i<h; i++) {
        dp[0][i] = 1;
        if (i!=0) {
            dp[1][i] = 1;
            //        cout << "initialized row 1 value "<< i << " " << endl;
        }
    }
    
    dp[1][1] = 1;
    
    for (int j=1; j<h; j++) {
        for (int i=1; i<w; i++) {
            if (i!=1) dp[i][j] = 0;
            //cout << "starting loop with "<<i << " " << j << endl;
            for (int k=1; k<i; k++) {
                dp[i][j]+=((dp[i-k][j-1]%9901)*(dp[k][j-1]%9901))%9901;
                //  cout << dp[i][j] <<" " << k<< endl;
            }
        }
    }/*
      
      cout << dp[1][2] << " " << dp[2][2] << endl;
      
      cout << 2*dp[1][2]*dp[2][2] << endl;
      
      for (int i=0; i<w; i++) {
      for (int j=0; j<h; j++) {
      cout << dp[i][j] << " ";
      }
      cout << endl;
      }*/
    
    int ret = (dp[w-1][h-1]%9901-dp[w-1][h-2]%9901+9901)%9901;
    
    cout << ret << endl;
}
