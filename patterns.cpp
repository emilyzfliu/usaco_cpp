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
int K;
vector<int> days;
vector<int> h;
vector<int> pre;
map<int, int> data;
map<int, int> lookup;
int p;
int mod;

int expo(int a, int b) {
    if (b==0) return 1;
    if (b==1) return a;
    if (b%2==0) {
        return expo((a*a)%mod,(b/2)%mod);
    }
    return expo((a*a)%mod,((b-1)/2)%mod);
}

void initialize() {
    h.push_back(days[0]);
    for (int i=1; i<N; i++) {
        h.push_back(days[i]*expo(p,i)-h[i-1]);
    }
}

int hash(int i, int j) {
    if (i==0) return h[j];
    return (h[j]-h[i-1])*expo(p, 1-i);
}

int main() {
    cin >> N >> K;
    int x;
    p = 23;
    mod = 10000139;
    for (int i=0; i<N; i++) {
        cin >> x;
        days.push_back(x);
    }
    initialize();
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            int ha = hash(i,j);
            lookup.insert(make_pair(j-i, ha));
            data[ha]++;
        }
    }
    
}
