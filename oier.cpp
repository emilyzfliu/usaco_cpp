#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

bool valid(string s) {
    //cout << "function!!" << endl;
    if (s.length()==0) return false;
    if (s[0]==' ' || s[s.length()-2]==' ') {
        //cout << "crit. 1 failed" << endl;
        return false;
    }
    //cout << "crit. 1 passed" << endl;
    int dex = s.find(" ");
    int prev = -1;
    while (dex!=-1) {
        //cout << "prev " << prev << " dex " << dex << endl;
        prev = dex;
        dex = s.find(" ", prev+1);
        if (dex-prev==1) {
            //cout << "crit. 2 failed" << endl;
            return false;
        }
    }
    //cout << "crit. 2 passed" << endl;
    dex = s.find(" ");
    prev = -1;
    string temp = "";
    while (dex!=-1) {
        temp = s.substr(prev+1, 4);
        //cout << "prev " << prev << " dex " << dex << endl;
        //cout << temp << endl;
        if (temp != "oier") {
            //cout << "crit. 3 failed" << endl;
            return false;
        }
        prev = dex;
        dex = s.find(" ", prev+1);
    }
    //cout << "crit. 3 passed" << endl;
    return true;
}

int main() {
    int N;
    cin >> N;
    string dum;
    //cout << N << endl;
    getline(cin, dum);
    for (int i=0; i<N; i++) {
        //cout << i << endl;
        string s;
        getline(cin, s);
        //cout << s << endl;
        if (valid(s)) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}
