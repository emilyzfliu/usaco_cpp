/*
 ID: emily.z1
 TASK: concom
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

int adjown[100][100];
int adjco[100][100];
int N;
unordered_set<int> cset;
vector<int> comps;
bool changing = true;

bool controls1(int a, int b) {
    if (a==b) return true;
    return adjown[a][b]>50;
}

bool controls2(int a, int b) {
    int sum = adjown[a][b];
    //if (a==0 && b==29) cout << "check controls2" << endl;
    //if (a==0 && b==29) cout << a+1 << " " << b+1 << endl;
    //if (a==0 && b==29) cout << "commence loop" << endl;
    for (int i: comps) {
        //if (a==0 && b==29 && i==45) cout << adjco[a][44] << endl;
        if (adjco[a][i-1]==1 && a!=i-1) {
            /*if (a==0 && b==29 && i==45) {
             cout << "works" << endl;
             }*/
            //if (a==0 && b==29 && i==45) cout <<" company owned: "<< i << endl;
            sum+=adjown[i-1][b];
            //if (a==0 && b==29 && i==45) cout <<" added amount: "<<adjown[i-1][b]<<endl;
        }
    }
    return sum> 50;
}

int main() {
    ifstream fin ("concom.in");
    ofstream fout ("concom.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    int x; int y;
    
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        if (!cset.count(x)) comps.push_back(x);
        if (!cset.count(y)) comps.push_back(y);
        cset.insert(x); cset.insert(y);
        cin >> adjown[x-1][y-1];
    }
    
    int a; int b;
    
    //  for (int i=0; i<comps.size(); i++) cout << comps[i] << " ";
    // cout << endl;
    
    for (int i=0; i<comps.size(); i++) {
        for (int j=0; j<comps.size(); j++) {
            a = comps[j]-1;
            b = comps[i]-1;
            // cout << a << " " << b << endl;
            adjco[a][b] = controls1(a,b);
        }
    }
    changing = true;
    int co = 0;
    while (changing) {
        co = 0;
        for (int j=0; j<comps.size(); j++) {
        for (int i=0; i<comps.size(); i++) {
                a = comps[j]-1;
                b = comps[i]-1;
                if (adjco[a][b]==1) continue;
                //cout << a << " " << b << endl;
                bool c = controls2(a,b);
                //cout << adjco[0][44] << endl;
                if (c) {
                    adjco[a][b] = 1;
                    co++;
                }
                else adjco[a][b] = 0;
                //cout << co << endl;
            }
        }
        if (co==0) changing = false;
    }
    
    //    for (int i=0; i<comps.size(); i++) cout << comps[i] << " ";
    // cout << endl;
    
    vector<pair<int,int>> ret;
    pair<int,int> p;
    int count = 0;
    for (int i=0; i<comps.size(); i++) {
        for (int j=0; j<comps.size(); j++) {
            a = comps[j]-1;
            b = comps[i]-1;
            if (adjco[a][b]==1 && a!=b) {
                p = make_pair(a+1,b+1);
                ret.push_back(p);
                count++;
            }
        }
    }
    //cout << adjco[3][1]<<" "<<adjown[3][1] << endl;
    //cout << adjco[3][4] <<" "<<adjown[3][4]<< endl;
    //cout << adjco[3][2] <<" "<<adjown[3][2]<< endl;
    //cout << adjown[1][2] << endl;
    //cout << adjown[4][2] << endl;
    
    sort(ret.begin(), ret.end());
    for (int i=0; i<count; i++) {
        cout << ret[i].first << " " << ret[i].second << endl;
    }
    //cout << adjco[0][44] << endl;
    //cout << adjown[29][79] << endl;
}
