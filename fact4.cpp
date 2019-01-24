/*
 ID: emily.z1
 TASK: fact4
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

using namespace std;

int N;

int MAXN = 1000000;

int strip(int x) {
    if (x==0) return 0;
    while (x%10==0) {
        x/=10;
    }
    return x;
}

int main() {
    ifstream fin("fact4.in");
    ofstream fout("fact4.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    
    int ret = 1;
    
    for (int i=1; i<=N; i++) {
        ret = (ret%MAXN*i%MAXN)%MAXN;
        ret = strip(ret);
        //cout << ret << endl;
    }
    
    cout << ret%10 << endl;
}
