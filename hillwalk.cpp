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

long N;

struct Point {
    int64_t x, y;
    int idx=-1;
};

struct Line {
    Point a, b;
    int idx=-1;
    bool operator<(const Line& o) const {
        if (a.x > o.a.x) {
            double y = (double)(o.b.y - o.a.y) / (o.b.x - o.a.x) * (a.x - o.a.x) + o.a.y;
            return a.y < y;
        }
        double y = (double)(b.y - a.y) / (b.x - a.x) * (o.a.x - a.x) + a.y;
        return y < o.a.y;
    }
};

vector<Line> hills;
vector<Point> endpoints;

bool comp(const Point& a, const Point& b) {
    if (a.x!=b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    cin >> N;

    hills.resize(N);
    endpoints.resize(2*N);
    for (int i=0; i<N; i++) {
        cin >> hills[i].a.x >> hills[i].a.y >> hills[i].b.x >> hills[i].b.y;
        hills[i].idx = i;
        endpoints[2*i] = hills[i].a;
        endpoints[2*i].idx = i;
        endpoints[2*i+1] = hills[i].b;
        endpoints[2*i+1].idx = i;
    }
    sort(endpoints.begin(), endpoints.end(), comp);
    
    int cur = 0;
    int count = 1;
    set<Line> work;
    for (const Point& p : endpoints) {
        Line hill = hills[p.idx];
        if (hill.a.x == p.x) {
            // start point of the hill
            work.insert(hill);
        } else {
            // end point of the hill
            if (p.idx != cur) {
                work.erase(hill);
            } else {
                auto iter = work.find(hill);
                if (iter == work.begin()) {
                    break;
                } else {
                    iter--;
                    cur = iter->idx;
                    count++;
                    ++iter;
                    work.erase(iter, work.end());
                }
            }
        }
    }
    cout << count << endl;
}
