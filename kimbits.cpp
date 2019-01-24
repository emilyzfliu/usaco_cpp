/*
 ID: emily.z1
 TASK: kimbits
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
#include <queue>
#include <chrono>
#include <bitset>

using namespace std;

int N;
int L;
long long I;
long long dp[33][33];

void getsize() {
    //cout << N << " "<< L << " "<< I <<" "<< endl;
    for (int i=0; i<=32; i++) {
        dp[i][0] = 1;
    }
    //cout << N << " "<< L << " "<< I <<" "<< endl;
    for (int j=0; j<=32; j++) {
        dp[0][j] = 1;
    }
    //cout << N << " "<< L << " "<< I <<" "<< endl;
    for (int i=1; i<=32; i++) {
        for (int j=1; j<=32; j++) {
            //if (i<j) continue;
            /*if (i==j) {
             dp[i][j] = pow(2, i);
             continue;
             }*/
            dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
        }
    }
    //cout << N << " "<< L << " "<< I <<" "<< endl;
}

void bits(int n, int l, long long index) {
    if (n==0) return;
    //cout << n << " "  << l << " " << index << endl;
    int s = dp[n-1][l];
    if (index>s) {
        cout << "1";
        bits(n-1,l-1,index-s);
    }
    else {
        cout << "0";
        bits(n-1, l, index);
    }
}

int main() {
    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N >> L >> I;
    
    //cout << N << " "<< L << " "<< I <<" "<< endl;
    
    getsize();
    //cout << N << " "<< L << " "<< I <<" "<< endl;
    bits(N,L,I);
    cout << endl;
}
