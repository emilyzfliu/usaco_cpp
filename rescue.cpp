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

long long N; long long M;
long long si; long long sj;
vector<pair<long long, long long>> eds;

bool isvalid (long long r, long long c) {
    if (r<=0 || c<=0) return false;
    if (r>N) return false;
    if (c>2*r-1) return false;
    return true;
}

long long dist(pair<long long, long long> loc1,pair<long long, long long> loc2) {
    pair <long long, long long> locc = min(loc1, loc2);
    pair <long long, long long> loccc = max(loc1, loc2);
    long long i1 = locc.first;
    long long j1 = locc.second;
    long long i2 = loccc.first;
    long long j2 = loccc.second;
    //cout << "dist from (" << i1 << ", " << j1 << ") to (" << i2 << ", " << j2 << ")" << endl;
    if (!isvalid(i1, j1) || !isvalid(i2, j2)) return 2147483647;
    if (j1%2==0) {
        return 1+min(dist(make_pair(i1, j1+1), loccc),dist(make_pair(i1, j1-1), loccc));
    }
    
    if (i1==i2) {
        return abs(j1-j2)+1;
    }
    if (j2>=j1 && j2<=j1+2*abs(i2-i1)) {
        if (j2%2==0) return abs(i2-i1)*2;
        return 1+abs(i2-i1)*2;
    }
    return abs(i2-i1)*2+
    min(dist(make_pair(i2, j1), loccc), dist(make_pair(i2, j1+2*abs(i2-i1)), loccc));
}

int main() {
    cin >> N >> M;
    cin >> si >> sj;
    long long x; long long y;
    for (long long i=0; i<M; i++) {
        cin >> x >> y;
        eds.push_back(make_pair(x,y));
    }
    long long mmin = 2147483647;
    pair<long long, long long> mindex;
    for (long long i=0; i<M; i++) {
        long long val = dist(make_pair(si, sj), eds[i]);
        //cout << eds[i].first << " " << eds[i].second << " " << val << endl;
        if (val<mmin) {
            mmin = val;
            mindex = eds[i];
        }
    }
    
    //cout << dist(make_pair(3,1), make_pair(3,5)) << endl;
    
    cout << mindex.first << " " << mindex.second << endl;
    cout << mmin << endl;
}
