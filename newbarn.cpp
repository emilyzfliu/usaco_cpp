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
vector<int> xvals;
vector<int> yvals;
set <pair<int, int>> seen;
set <pair<int, int>> hascow;

int manhat(int x, int y) {
    int sum = 0;
    for (int i=0; i<N; i++) {
        sum+=abs(x-xvals[i])+abs(y-yvals[i]);
    }
    return sum;
}

int main() {
    cin >> N;
    xvals.resize(N); yvals.resize(N);
    int miny = (1<<31)-1;
    int minx = (1<<31)-1;
    int maxy = -1;
    int maxx = -1;
    for (int i=0; i<N; i++) {
        cin >> xvals[i];
        cin >> yvals[i];
        if (xvals[i]>maxx) maxx = xvals[i];
        if (yvals[i]>maxy) maxy = yvals[i];
        if (xvals[i]<minx) minx = xvals[i];
        if (yvals[i]<miny) miny = yvals[i];
        hascow.insert(make_pair(xvals[i], yvals[i]));
    }
    //cout << minx << " " << maxx << endl;
    //cout << miny << " " << maxy << endl;
    int count = 0;
    int minval = (1<<31)-1;
    for (int i=0; i<N; i++) {
        for (int j=miny; j<=maxy; j++) {
            if (seen.count(make_pair(xvals[i], j))) continue;
            if (hascow.count(make_pair(xvals[i], j))) continue;
            int test = manhat(xvals[i], j);
            
            //cout << xvals[i] << " " << j  <<" "<< test<< endl;
            seen.insert(make_pair(xvals[i], j));
            if (test<minval) {
                count = 1;
                minval = test;
                continue;
            }
            else if (test==minval) {
                //cout << test << endl;
                count++;
            }
        }
    }
    for (int i=minx; i<=maxx; i++) {
        for (int j=0; j<N; j++) {
            if (seen.count(make_pair(i, yvals[j]))) continue;
            if (hascow.count(make_pair(i, yvals[j]))) continue;
            int test = manhat(i, yvals[j]);
            //cout << i << " " << yvals[j]  <<" "<< test<< endl;
            seen.insert(make_pair(i, yvals[j]));
            if (test<minval) {
                count = 1;
                minval = test;
                continue;
            }
            else if (test==minval) {
                //cout << test << endl;
                count++;
            }
        }
    }
    cout << minval << " " << count << endl;
}
