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
vector<pair<int, int>> query;
map<pair<int, int>, int> info;

bool intersect(pair<int, int> a, pair<int, int> b) {
    if (a.second<b.first) return false;
    if (a.first>b.second) return false;
    return true;
}

int main () {
    cin >> N;
    int x; int y;
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        query.push_back(make_pair(x,y));
    }
    info.insert(make_pair(query[0], 1));
    for (int i=1; i<N; i++) {
        bool nu = true;
        map<pair<int, int>, int> dum;
        for (map<pair<int, int>, int>:: iterator it = info.begin(); it!=info.end(); it++) {
            if (intersect((*it).first, query[i])) {
                //cout << (*it).first.first << " " << (*it).first.second << " "<< (*it).second << endl;
                pair<int, int> temp = make_pair(max(((*it).first).first, query[i].first),
                                 min(((*it).first).second, query[i].second));
                
                //cout << temp.first << " " << temp.second << endl;
                int val = (*it).second+1;
                dum.insert(make_pair(temp,val));
                //info.erase(it);
                
                nu = false;
            }
        }
        if (nu) info.insert(make_pair(query[i], 1));
        for (map<pair<int, int>, int>:: iterator it = dum.begin(); it!=dum.end(); it++) {
            info.insert(*it);
        }
    }
    
    int ret = -1;
    
    for (map<pair<int, int>, int>:: iterator it = info.begin(); it!=info.end(); it++) {
        //cout << (*it).first.first << " " << (*it).first.second << " "<< (*it).second << endl;
        if (ret<(*it).second) ret = (*it).second;
    }
    cout << ret << endl;
}

