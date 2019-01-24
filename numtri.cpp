/*
ID: emily.z1
TASK: numtri
LANG: C++14
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <climits>
#include <unordered_set>
#include <map>
#include <vector>
#include <utility>
#include <ctime>

using namespace std;

int main() {
    ifstream fin ("numtri.in");
    ofstream fout ("numtri.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    int N;
    cin >> N;
    int vals[N][N];
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<i+1; j++) {
            cin >> vals[i][j];
        }
    }
    
    int m[N][N];
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<i+1; j++) {
            if (j==0) {
                if (i==0) {
                    m[i][j] = vals[i][j];
                    continue;
                }
                m[i][j] = m[i-1][j]+vals[i][j];
                continue;
            }
            if (i==j) {
                m[i][j] = m[i-1][j-1]+vals[i][j];
                continue;
            }
            m[i][j] = max(m[i-1][j-1]+vals[i][j], m[i-1][j]+vals[i][j]);
        }
    }
    
    int ret = -1;
    for (int y=0; y<N; y++) {
        ret = max(ret, m[N-1][y]);
    }
    
    cout << ret << endl;
}
