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
vector<complex<double>> pts;
complex<double> H[5000];

bool comp(complex<double> a, complex<double> b) {
    if (a.real()!=b.real()) return a.real()<b.real();
    return a.imag()<b.imag();
}

int cross(complex<double> a, complex<double> b) {
    return (conj(a)*b).imag();
}

int main() {
    cin >> N;
    int x; int y;
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        complex<double> temp(x, y);
        pts.push_back(temp);
    }
    sort(pts.begin(), pts.end(), comp);
    //for (int i=0; i<N; i++) cout << pts[i] << endl;
    
    int sz = 0;
    
    for (int i=0; i<N; i++) {
        while (sz>=2 && cross(H[sz-2]-H[sz-1], pts[i]-H[sz-1])<0) {
            sz--;
        }
        H[sz] = pts[i];
        sz++;
    }
    
    for (int i=N-1; i>=0; i--) {
        while (sz>=2 && cross(H[sz-2]-H[sz-1], pts[i]-H[sz-1])<0) {
            sz--;
        }
        H[sz] = pts[i];
        sz++;
    }
    //cout << sz << endl;
    double ret = 0;
    //cout << H[0] << endl;
    for (int i=1; i<sz; i++) {
        ret+=abs(H[i]-H[i-1]);
        //cout << H[i] << endl;
    }
    
    cout <<fixed << setprecision(2) << ret << endl;
}
