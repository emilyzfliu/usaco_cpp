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

vector<Point> cows;

bool comp(const Point& a, const Point& b) {
    if (a.x!=b.x) return a.x < b.x;
    return a.y < b.y;
}

bool comp2(const Point& a, const Point& b) {
    if (a.y!=b.y) return a.y < b.y;
    return a.x < b.x;
}

const int K=5;

int64_t nearest(vector<Point>& cows, int low, int high, int& a, int& b) {
    //    cout << low << "---" << high << endl;
    if (high - low <= K) {
        int64_t m = (1LL<<63) - 1;
        for (int i=low; i<high; ++i) {
            for (int j=i+1; j<high; ++j) {
                int64_t dx = cows[i].x - cows[j].x;
                int64_t dy = cows[i].y - cows[j].y;
                int64_t dist = dx*dx + dy*dy;
                int A = min(cows[i].idx, cows[j].idx);
                int B = max(cows[i].idx, cows[j].idx);
                if (dist < m || ((dist == m) && (A < a || (A==a && B < b)))) {
                    m = dist;
                    a = A;
                    b = B;
                }
            }
        }
        //        cout << "***" << m << " " << a << " " << b << endl;
        return m;
    } else {
        int mid = (low + high) / 2;
        int aleft, bleft;
        aleft = bleft = cows.size();
        int64_t mleft = nearest(cows, low, mid, aleft, bleft);
        int aright, bright;
        aright = bright = cows.size();
        int64_t mright = nearest(cows, mid, high, aright, bright);
        int64_t delta = min(mleft, mright);
        if (mleft == mright) {
            if (aleft < aright || (aleft == aright && bleft < bright)) {
                a = aleft;
                b = bleft;
            } else {
                a = aright;
                b = bright;
            }
        } else if (mleft < mright) {
            a = aleft;
            b = bleft;
        } else {
            a = aright;
            b = bright;
        }
        
        int64_t x = (cows[mid].x + cows[mid+1].x) / 2;
        int64_t d = sqrt(delta);
        int64_t xleft = x - d;
        int64_t xright = x + d;
        Point left;
        left.x = xleft;
        left.y = 1LL<<63;
        auto ileft = lower_bound(cows.begin(), cows.end(), left, comp);
        Point right;
        right.x = xright;
        right.y = (1LL<<63)-1;
        auto iright = upper_bound(cows.begin(), cows.end(), right, comp);
        sort(ileft, iright, comp2);
        for (auto iter = ileft; iter < iright; ++iter) {
            Point up;
            up.y = ceil(iter->y+d);
            auto limit = upper_bound(ileft, iright, up, comp2);
            for (auto jter = iter+1; jter<limit; jter++) {
                int64_t dx = iter->x - jter->x;
                int64_t dy = iter->y - jter->y;
                int64_t dist = dx*dx + dy*dy;
                int A = min(iter->idx, jter->idx);
                int B = max(iter->idx, jter->idx);
                if (dist < delta || ((dist == delta) && (A < a || (A==a && B < b)))) {
                    delta = dist;
                    a = A;
                    b = B;
                }
            }
        }
        //        cout << "***" << delta << " " << a << " " << b << endl;
        return delta;
    }
}

int main() {
    cin >> N;
    cows.resize(N);
    for (int i=0; i<N; i++) {
        cin >> cows[i].x >> cows[i].y;
        cows[i].idx = i+1;
    }
    
    sort(cows.begin(), cows.end(), comp);
    int a, b;
    a = b = cows.size();
    nearest(cows, 0, cows.size(), a, b);
    cout << a << ' ' << b << endl;
}
