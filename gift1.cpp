/*
 ID: emily.z1
 TASK: gift1
 LANG: C++14
 */

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    int N;
    cin >> N;
    unordered_map<string, int> bal;
    vector<string> names(N);
    for (int i=0; i<N; i++) {
        cin >> names[i];
        bal[names[i]]=0;
    }
    for (int i=0; i<N; i++) {
        string name;
        int val;
        int n;
        cin >> name >> val >> n;
        if (n==0) continue;
        int amt = val/n;
        for (int i=0; i<n; i++) {
            string recip;
            cin >> recip;
            bal[recip]+=amt;
            bal[name]-=amt;
        }
    }
    for (int i=0; i<N; i++) {
        cout << names[i] << " " << bal[names[i]] << endl;
    }
}
