/*
 ID: emily.z1
 TASK: holstein
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
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int V;
int G;
int vites[25];
int feeds[15][25];

vector<int> eval(int n) {
    //cout << "evaluating " << n << endl;
    vector<int> ret;
    //  cout << "eval " << n;
    for (int i=0; i<G; i++) {
        if (n&(1<<i)) {
            //            cout << " " << i;
            ret.push_back(i);
        }
    }
    //  cout << endl;
    //cout << "done evaluating" << endl;
    return ret;
}

int isValid(vector<int> vals) {
    //cout << "checking valid" << endl;
    int metasum = 0;
    for (int i=0; i<V; i++) {
        int sum = 0;
        //    cout << "size" <<vals.size() << endl;
        for (int j = 0; j<vals.size(); j++) {
            int k = vals[j];
            //            cout << feeds[k][i] << endl;
            sum+=feeds[k][i];
        }
        //        cout << sum << " " << vites[i] << endl;
        if (sum<vites[i]) {
            //        cout << "check returned negative" << endl;
            return -1;
        }
        metasum+=sum;
    }
    //cout << "check done" << endl;
    return metasum;
}

int main() {
    ifstream fin ("holstein.in");
    ofstream fout ("holstein.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> V;
    for (int i=0; i<V; i++) {
        cin >>vites[i];
    }
    cin >> G;
    for (int i=0; i<G; i++) {
        for (int j=0; j<V; j++) {
            cin>>feeds[i][j];
        }
    }
    //cout << "read variables" << endl;
    
    vector<int> vals;
    vector<int> minvals;
    int mmin = INT_MAX;
    int minscoops = INT_MAX;
    
    //cout << "declared some other variables" << endl;
    
    for (int i=1; i<pow(2,G); i++) {
        //    cout << "looping "<< i << endl;
        vals = eval(i);
        int v = isValid(vals);
        // cout << i << ' ' << v << endl;
        if (v>0 && vals.size()<minscoops) {
            minvals = vals;
            mmin = v;
            minscoops = vals.size();
        }
        if (v>0 && vals.size()==minscoops) {
            if (v<mmin) {
                minvals = vals;
                mmin = v;
                minscoops = vals.size();
            }
        }
    }
    // cout << "exited loop" << endl;
    
    cout << minvals.size() << " ";
    for (int i=0; i<minvals.size()-1; i++) {
        cout << (minvals[i]+1) << " ";
    }
    cout << (minvals[minvals.size()-1]+1) << endl;
}
