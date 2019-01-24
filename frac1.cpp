/*
 ID: emily.z1
 TASK: frac1
 LANG: C++14
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <climits>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <ctime>
#include <cmath>
#include <queue>

using namespace std;

int N;

struct frac {
    int num;
    int den;
    frac(int n, int d) : num(n), den(d) {}
};

int gcd(int n, int d) {
    if (n==0) return d;
    if (d==0) return n;
    if (n>d) return gcd(n%d, d);
    return gcd(n, d%n);
}

bool comp(frac a, frac b) {
    int numa = a.num*b.den;
    int numb = b.num*a.den;
    return numa<numb;
}

int main() {
    ifstream fin ("frac1.in");
    ofstream fout ("frac1.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    
    vector<frac> fracs;
    
    frac zero; zero.num = 0; zero.den = 1;
    frac one; one.num = 1; one.den = 1;
    fracs.push_back(zero);
    fracs.push_back(one);
    
    for (int d=2; d<=N; d++) {
        for (int n=1; n<d; n++) {
            if (gcd(n,d)==1) {
                frac temp;
                temp.num = n;
                temp.den = d;
                fracs.push_back(temp);
            }
        }
    }
    
    sort (fracs.begin(), fracs.end(), comp);
    
    for (int i=0; i<fracs.size(); i++) {
        cout << fracs[i].num <<"/"<< fracs[i].den << endl;
    }
}
