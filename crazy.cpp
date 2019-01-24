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

int N; int C;
map<pair<int, int>, pair<int, int>> fences;
vector<pair<pair<int, int>, pair<int, int>>> fencelog;
vector<int> fenceid;
vector<pair<int, int>> cows;

int main() {
    cin >> N >> C;
    int a; int b; int c; int d;
    for (int i=0; i<N; i++) {
        cin >> a >> b >> c >> d;
        fences.insert(make_pair(make_pair(a,b), make_pair(c,d)));
        fencelog.push_back(make_pair(make_pair(a,b), make_pair(c,d)));
    }
    fenceid.resize(N);
    for (int i=0; i<C; i++) {
        cin >> a >> b;
        cows.insert(make_pair(a,b));
    }
    int count = 1;
    for (int i=0; i<N; i++) {
        if (fenceid[i]!=0) continue;
        fenceid[i] = count;
        pair<int, int> nextpt = fences[fencelog[i].second];
        while (nextpt!=fencelog[i].first) {
            
        }
    }
}
