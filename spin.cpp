/*
 ID: emily.z1
 TASK: spin
 LANG: C++14
 */

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

using namespace std;

vector<pair<int, vector<pair<int, int>>>> wheels;

void update() {
    for (int c=0; c<wheels.size(); c++) {
        const auto& speed = wheels[c].first;
        auto& wedges = wheels[c].second;
        for (int i=0; i<wedges.size(); i++) {
            wedges[i].first += speed;
            wedges[i].first %= 360;
            wedges[i].second += speed;
            wedges[i].second %= 360;
        }
    }
}

bool valid() {
    for (int count=0; count<360; count++) {
        vector<bool> check(wheels.size(), false);
        int ret = 0;
        for (int c=0; c<wheels.size(); c++) {
            const auto& wedges = wheels[c].second;
            for (int i=0; i<wedges.size(); i++) {
                int s = wedges[i].first;
                int e = wedges[i].second;
                if (s==e) {
                    if (count==s) {
                        check[c] = true;
                        break;
                    }
                }
                if (s<e) {
                    if (count>=s && count<=e) {
                        check[c] = true;
                        break;
                    }
                }
                if (s>e) {
                    if ((count>=0 && count<=e) ||(count<=359 && count>=s)) {
                        check[c] = true;
                        break;
                    }
                }
            }
            if (check[c]) ret++;
        }
        if (ret==wheels.size()) return true;
    }
    return false;
}

int main() {
    ifstream fin("spin.in");
    ofstream fout("spin.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    int dum = 0;
    int num = 0;
    int val1 = 0;
    int val2 = 0;
    for (int i=0; i<5; i++) {
        cin >> dum;
        cin >> num;
        vector<pair<int, int>> x;
        for (int j=0; j<num; j++) {
            cin >> val1 >> val2;
            x.push_back(make_pair(val1, (val1+val2)%360));
        }
        wheels.push_back(make_pair(dum, x));
    }
    
    int t = 0;
    
    bool check = false;
    
    for (int d = 0; d<360; d++) {
        if (valid()) {
            check = true;
            break;
        }
        update();
        t++;
    }
    if (check) {
        cout << t << endl;
        return 0;
    }
    cout << "none" << endl;
}
