/*
 ID: emily.z1
 TASK: hamming
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

int N;
int B;
int D;

int ham(int a, int b) {
    int x = a^b;
    int ret = 0;
    for (int i=0; i<B; i++) {
        if (x&(1<<i)) {
            ret++;
        }
    }
    return ret;
}

int main() {
    ifstream fin ("hamming.in");
    ofstream fout ("hamming.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N >> B >> D;
    
    vector<int> works;
    works.push_back(0);

    for (int j=1; j<pow(2,B); j++) {
        bool good = true;
        for (int k=0; k<works.size(); k++) {
            if (ham(works[k],j)<D) {
                good = false;
                break;
            }
        }
        if (good) works.push_back(j);
        if (works.size() == N) break;
    }
    
    for (int i=0; i<works.size(); i++) {
        cout << works[i];
        if (i%10==9 || i==works.size()-1) cout << endl;
        else cout << " ";
    }
}
