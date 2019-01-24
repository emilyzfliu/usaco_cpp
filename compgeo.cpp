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

// 1: counterclockwise
// 0: collinear
// -1: clockwise
int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int dx1, dx2, dy1, dy2;
    dx1 = b.first-a.first; dy1 = b.second-a.second;
    dx2 = c.first-b.first; dy2 = c.second-b.second;
    if (dx1*dy2>dy1*dx2) return 1;
    if (dx1*dx2<0 || dy1*dy2<0) return -1;
    if (dx1*dx1+dy1*dy1<dx2*dx2+dy2*dy2) return 1;
    return 0;
}

int intersect(pair<int, int> l1a, pair<int, int> l1b,
              pair<int, int> l2a, pair<int, int> l2b) {
    return ccw(l1a, l1b, l2a)*ccw(l1a, l1b, l2b)<=0 &&
            cw(l2a, l2b, l1a)*ccw(l2a, l2b, l1b)<=0;
}

int main() {
    
    
}
