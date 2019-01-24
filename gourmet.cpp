#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector < pair <int,int> > c,f;
set < pair <int,int> > a;

int main () {
    int n, m, i, q, w;
    cin >> n >> m;
    for (i=0; i<n; i++) {
        cin >> q >> w;
        c.push_back (make_pair (w, q));
    }
    for (i=0; i<m; i++) {
        cin >> q >> w;
        f.push_back (make_pair (w, q));
    }
    sort (c.begin (), c.end ());
    sort (f.begin (), f.end ());
    int r = m - 1;
    
    long long ans = 0;
    a.clear ();
    for  (i=n-1;i>=0;i--) {
        while (1) {
            if (r < 0) break;
            if (f[r].first >= c[i].first) {
                a.insert (make_pair (f[r].second, r));
                r--;
            }
            else break;
        }
        set< pair <int,int> >::iterator d =
        a.lower_bound (make_pair (c[i].second, -1));
        if  (d == a.end ()) {
            cout << -1 << endl;
            return 0;
        }
        ans +=  (*d).first;
        a.erase (d);
    }
    cout << ans << endl;
    return 0;
}

/*
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
long long N;
long long M;
vector<pair<long long, long long>> cows;
vector<pair<long long, long long>> store;

bool comp(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.second==b.second) return a.first>b.first;
    return a.second>b.second;
}

bool valid(pair<long long, long long> check, pair<long long, long long> orig) {
    return check.first>=orig.first && check.second>=orig.second;
}

int main() {
    cin >> N >> M;
    long long x; long long y;
    for (long long i=0; i<N; i++) {
        cin >> x >> y;
        cows.push_back(make_pair(x,y));
    }
    for (long long i=0; i<M; i++) {
        cin >> x >> y;
        store.push_back(make_pair(x,y));
    }
    sort(cows.begin(), cows.end(), comp);
    sort(store.begin(), store.end(), comp);
    
    set<pair<long long, long long>> keep;
    
    //for (long long i=0; i<N; i++) cout << cows[i].first << " " << cows[i].second << endl;
    // cout << endl;
    // for (long long i=0; i<M; i++) cout << store[i].first << " " << store[i].second << endl;
    // cout << endl;
    
    long long j = 0;
    long long cost = 0;
    for (long long i=0; i<N; i++) {
        //cout << "i " << i << endl;
        while (store[j].second>=cows[i].second) {
            keep.insert(make_pair(store[j].first, store[j].second));
            j++;
            //cout <<"j"<< j << endl;
        }
        //cout <<"size" << keep.size() << endl;
        set<pair<long long, long long>>::iterator it;
        it = keep.begin();
        while (!valid(*it, cows[i])) {
            //cout <<"NOT VALID: " << (*keep.begin()).first << " " << (*keep.begin()).second << endl;
            it++;
            //cout <<"size"<< keep.size() << endl;
        }
        //cout << cows[i].first << " " << cows[i].second << endl;
        //cout << (*it).first << " " << (*it).second << endl;
        cost+=(*it).first;
        keep.erase(it);
    }
    
    cout << cost << endl;
}
 */
