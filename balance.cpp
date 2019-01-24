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
vector<float> refe;
float ep = 1e-12;

bool c(const vector<float>& test) {
    for (int i=1; i<=N; i++) {
        if (fabs(test[i]-refe[i])>ep) return false;
    }
    return true;
}

int main() {
    //ifstream fin("balance.in");
    //ofstream fout("balance.out");
    
    //cin.rdbuf(fin.rdbuf());
    //cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    refe.resize(N+2);
    
    refe[0] = 0;
    refe[N+1] = 0;
    
    for (int i=1; i<=N; i++) {
        cin >> refe[i];
    }
    
    vector<float> f(refe);
    
    //for (int i=0; i<N+2; i++) cout << refe[i] << " ";
    //cout << endl;
    
    bool conv = false;
    
    vector<float> temp(N+2);
    while (!conv) {
        //cout << indices.size() << endl;
        for (int i=1; i<=N; i++) {
            //cout << refe[i] << " " << (refe[i-1]+refe[i+1])/2 << endl;
            temp[i] = max(f[i], (refe[i-1]+refe[i+1])/2);
        }
        conv = c(temp);
        refe.swap(temp);
        //for (int i=0; i<N+2; i++) cout << refe[i] << " ";
        //cout << endl;
    }
    
    for (int i=1; i<=N; i++) {
        cout << (int)(100000*refe[i]) << endl;
    }
    
}
