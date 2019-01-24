/*
 ID: emily.z1
 TASK: runround
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
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

bool uniquedigs(int k) {
    vector<bool> digs(9, false);
    int T = k;
    while (T>0) {
        int temp = T%10;
        if (temp==0) return false;
        if (digs[(temp-1)]) return false;
        digs[(temp-1)] = true;
        T/=10;
    }
    return true;
}

int numdigs (int k) {
    string str = to_string(k);
    return str.length();
}

bool runaround (int k) {
    if (!uniquedigs(k)) return false;
    int N = numdigs(k);
    int digs[N];
    int dex = N-1;
    int T = k;
    while (T>0) {
        int temp = T%10;
        digs[dex] = temp;
        dex--;
        T/=10;
    }
    int pointer = 0;
    vector<bool> seen(N, false);
    for (int i=0; i<N; i++) {
        pointer = (pointer+digs[pointer])%N;
        if (seen[pointer]) return false;
        seen[pointer] = true;
    }
    return true;
}

int main() {
    ifstream fin ("runround.in");
    ofstream fout ("runround.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    int M;
    cin >> M;
    
    int k = M+1;
    // /*
    while (!runaround(k)) {
        k++;
    } // */
    //    cout << (sumdigs(81362)) << endl;
    //    cout << (sumdigs(81362)%numdigs(81362)) << endl;
    //    cout << uniquedigs(81362) << endl;
    //    cout << runaround(81362) << endl;
    
    cout << k << endl;
}
