/*
 ID: emily.z1
 TASK: lamps
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

using namespace std;

int N;
int C;
vector<int> on;
vector<int> off;

string modify (const string& vec, int init, int delta) {
    string ret = vec;
    for (int i = init; i<N; i+=delta) {
        if (ret[i] == '1') ret[i] = '0';
        else ret[i] = '1';
    }
    return ret;
}

void eval(const string& lamps, set<string>& result) {
    string lamps1 = modify(lamps,0,1);
    //cout << lamps1 << endl;
    string lamps2 = modify(lamps,0,2);
    //cout << lamps2 << endl;
    string lamps3 = modify(lamps,1,2);
    //cout << lamps3 << endl;
    string lamps4 = modify(lamps,0,3);
    //cout << lamps4 << endl;
    result.insert(lamps1);
    result.insert(lamps2);
    result.insert(lamps3);
    result.insert(lamps4);
}

bool isValid(const string& lamp) {
    for (int i=0; i<on.size(); i++) {
        if (lamp[on[i]-1]=='0') {
            //cout << on[i] << " " << lamp << " supposed to be true, is false" << endl;
            return false;
        }
    }
    for (int i=0; i<off.size(); i++) {
        if (lamp[off[i]-1]=='1') {
            //cout << off[i] << " " << lamp << " supposed to be false, is true" << endl;
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin ("lamps.in");
    ofstream fout ("lamps.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N >> C;
    
    int temp;
    cin >> temp;
    while (temp!=-1) {
        on.push_back(temp);
        cin >> temp;
    }
    cin >> temp;
    while (temp!=-1) {
        off.push_back(temp);
        cin >> temp;
    }
    
    string init = "";
    for (int i=0; i<N; i++) init+="1";
    int count = 0;
    set<string> cur;
    cur.insert(init);
    
    while (count != C) {
        count++;
        //   cout << count << endl;
        //    cout << ttemp.size() << endl;
        set<string> next;
        for (const auto& t : cur) {
            //          cout << ttemp[i] << endl;
            eval(t, next);
        }
//        cur.swap(next);
        cur = next;
    }
    
    vector<string> output;
    
    //   cout << fins.size() << endl;
    
    for (const auto& f : cur) {
        if (isValid(f)) {
            //cout << "valid" << endl;
            output.push_back(f);
        }
    }
    
    sort(output.begin(), output.end());
    
    //    cout << output.size() << endl;
    
    for (int i=0; i<output.size(); i++) {
        cout << output[i] << endl;
    }
    
    if (output.size()==0) cout << "IMPOSSIBLE" << endl;
}
