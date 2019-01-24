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
string str;
string rev;
vector<short> dp;
vector<short> pre;

void reverse() {
    for (int i=str.length()-1; i>=0; i--) {
        rev+=str[i];
    }
}

int main() {
    cin >> N;
    cin >> str;
    reverse();
    
    for (int i=0; i<=N; i++) {
        pre.push_back(0);
        dp.push_back(0);
    }
    
    for (int i=0; i<=N; i++)
    {
        for (int j=0; j<=N; j++)
        {
            if (i == 0 || j == 0) {
                dp[j] = 0;
                continue;
            }
            if (str[i-1] == rev[j-1]) {
                dp[j] = pre[j-1] + 1;
                continue;
            }
            else {
                dp[j] = max(pre[j], dp[j-1]);
            }
        }
        for (int k=0; k<=N; k++) {
            pre[k] = dp[k];
        }
    }
    
    //for (int i=0; i<N; i++) cout << dp[i] << " ";
    //cout << endl;
    
    cout << N-dp[N] << endl;
}
