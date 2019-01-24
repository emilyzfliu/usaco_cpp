/*
 ID: emily.z1
 TASK: skidesign
 LANG: C++14
 */

#include <fstream>
#include <iostream>
#include <string>
#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

int sumsq(int i, vector<int> hills) {
    int sum = 0;
    for (int j=0; j<hills.size(); j++) {
        if (hills[j]<i) sum += (hills[j]-i)*(hills[j]-i);
        if (hills[j]>i+17) sum+=(i+17-hills[j])*(i+17-hills[j]);
    }
    return sum;
}

int main() {
    ifstream fin ("skidesign.in");
    ofstream fout ("skidesign.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    int N;
    cin >> N;
    
    vector<int> hills(N);
    
    int mmin = INT_MAX;
    int mmax = INT_MIN;
    
    for (int i=0; i<N; i++) {
        cin >> hills[i];
        if (hills[i]<mmin) mmin = hills[i];
        if (hills[i]>mmax) mmax = hills[i];
    }
    
    int minval = INT_MAX;
    bool check = false;
    
    for (int i=mmin; i<mmax-17; i++) {
        int t = sumsq(i, hills);
        if (t<minval) {
            minval = t;
            check = true;
        }
    }
    
    if (!check) minval = 0;
    
    cout << minval << endl;
}
