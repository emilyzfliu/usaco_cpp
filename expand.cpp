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

struct Barn {
    int a, b, c, d;
};

int N;
vector<Barn> barns;
unordered_set<int> seen;

int main() {
    cin >> N;
    barns.resize(N);
    for (int i=0; i<N; i++) {
        cin >> barns[i].a >> barns[i].b >> barns[i].c >> barns[i].d;
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (barns[j].c==barns[i].a) {
                seen.insert(i);
                seen.insert(j);
            }
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (barns[j].d==barns[i].b) {
                seen.insert(i);
                seen.insert(j);
            }
        }
    }
    cout << N-seen.size() << endl;
}
