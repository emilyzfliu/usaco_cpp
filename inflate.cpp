/*
 ID: emily.z1
 TASK: inflate
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

int M; int N;
vector<int> val;
vector<int> tp;
int t[10001];

int main() {
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> M >> N;
    //cout << "read vals" << endl;
    int x; int y;
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        val.push_back(x);
        tp.push_back(y);
    }
    //cout << "read all vals" << endl;
    //cout << tp.size() << endl;
    for (int i=0; i<N; i++) {
        //    cout << i << endl;
        //    cout << val[i] << " " << tp[i] << endl;
        for (int j=tp[i]; j<=M; j++) {
            t[j] = max(t[j], t[j-tp[i]]+val[i]);
        }
    }
    cout << t[M] << endl;
}
