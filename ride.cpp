/*
 ID: emily.z1
 TASK: ride
 LANG: C++14
 */

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    string s1, s2;
    cin >> s1 >> s2;
    int prod1 = 1;
    int prod2 = 1;
    for (int i=0; i<s1.length(); i++) {
        prod1*=(char(s1[i])-64);
    }
    for (int i=0; i<s2.length(); i++) {
        prod2*=(char(s2[i])-64);
    }
    prod1 = prod1%47;
    prod2 = prod2%47;
    if (prod1==prod2) cout << "GO" << endl;
    else cout << "STAY" << endl;
}
