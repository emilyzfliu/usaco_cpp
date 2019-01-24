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

int N;
int D;
vector<pair<int, int>> drops;
vector<int> xvals;
vector<int> yvals;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second<b.second;
}

int main() {
    cin >> N >> D;
    pair<int, int> dum;
    int x; int y;
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        drops.push_back(make_pair(x,y));
    }
    sort(drops.begin(), drops.end(), comp);
    for (int i=0; i<N; i++) {
        xvals.push_back(drops[i].first);
        yvals.push_back(drops[i].second);
    }
    int w = (1<<31)-1;
    for (int i=0; i<N; i++) {
        std::vector<int>::iterator it;
        it = lower_bound(yvals.begin(), yvals.end(), yvals[i]+D);
        for (int j=it-yvals.begin(); j<N; j++) {
            w = min(w, abs(xvals[i]-xvals[j]));
        }
    }
    if (w==(1<<31)-1) w = -1;
    cout << w << endl;
}
