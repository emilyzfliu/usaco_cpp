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
int grid[251][251];
int pfx[251][251];

void init() {
    pfx[0][0] = grid[0][0];
    for (int i=1; i<N; i++) {
        pfx[0][i] = pfx[0][i-1]+grid[0][i];
    }
    for (int i=1; i<N; i++) {
        pfx[i][0] = pfx[i-1][0]+grid[i][0];
    }
    for (int i=1; i<N; i++) {
        for (int j=1; j<N; j++) {
            pfx[i][j] = pfx[i-1][j]+pfx[i][j-1]-pfx[i-1][j-1]+grid[i][j];
        }
    }
}

int numones(int a, int b, int c, int d) {
    int ret = pfx[c][d];
    if (a-1>=0) ret-=pfx[a-1][d];
    if (b-1>=0) ret-=pfx[c][b-1];
    if (a-1>=0 && b-1 >=0) ret+=pfx[a-1][b-1];
    return ret;
}

int main () {
    cin >> N;
    string x;
    for (int i=0; i<N; i++) {
        cin >> x;
        for (int j=0; j<N; j++) {
            grid[i][j] = x[j]-'0';
        }
    }
    init();
    for (int len=1; len<N; len++) {
        int count = 0;
        for (int i=0; i<N-len; i++) {
            for (int j=0; j<N-len; j++) {
                if (numones(i,j,i+len,j+len)==(len+1)*(len+1)) count++;
            }
        }
        if (count!=0) cout << (len+1) << " " << count << endl;
    }
}
