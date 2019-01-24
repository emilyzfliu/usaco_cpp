/*
 ID: emily.z1
 TASK: beads
 LANG: C++14
 */

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int N;
string b;

int collect (const string& b, int i) {
    int ret = 0;
    //left
    char ref = b[i];
    int N = b.size();
    int j = N+i;
    while ((ref=='w' || b[j%N]==ref || b[j%N]=='w') && j>i) {
        ret++;
        j--;
        if (ref=='w' && b[j%N]!='w') ref = b[j%N];
    }
    //right
    ref = b[i+1];
    int k = i+1;
    while (k<=j && (ref=='w' || b[k%N]==ref || b[k%N]=='w')) {
        ret++;
        k++;
        if (ref=='w' && b[k%N]!='w') ref = b[k%N];
    }
    return ret;
}

int main() {
    ifstream fin ("beads.in");
    ofstream fout ("beads.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N >> b;
    int most = -1;
    for (int i=0; i<N; i++) {
        int val = collect(b, i);
        if (val>most) most = val;
    }
    cout << most << endl;
}
