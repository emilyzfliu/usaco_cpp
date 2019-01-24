/*
 ID: emily.z1
 TASK: ratios
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
#include <queue>
#include <chrono>
#include <bitset>

using namespace std;

/*bool valid (int a, int b, int c) {
    return a*a!=b*c && b*b!=a*c && c*c!=a*b && a!=b && b!=c && a!=c;
}*/

int main() {
    ifstream fin("ratios.in");
    ofstream fout("ratios.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    int x0 = 0; int y0 = 0; int z0 = 0;
    int x1 = 0; int y1 = 0; int z1 = 0;
    int x2 = 0; int y2 = 0; int z2 = 0;
    int x3 = 0; int y3 = 0; int z3 = 0;
    cin >> x0 >> y0 >> z0;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    cin >> x3 >> y3 >> z3;
    int a = 0; int b = 0; int c = 0; int d = 0;
    int minval = pow(2,31)-1;
    int mmina = -1; int mminb = -1; int mminc = -1; int mmind = -1;
    bool check = false;
    for (a = 0; a<100; a++) {
        for (b =0; b<100; b++) {
            for (c=0; c<100; c++) {
                for (d=1; d<100; d++) {
                    if (x1*a+x2*b+x3*c==x0*d &&
                        y1*a+y2*b+y3*c==y0*d &&z1*a+z2*b+z3*c==z0*d) {
                        //cout << a << " "<< b << " "<< c << " "<< d << endl;
                        check = true;
                        if (a+b+c<minval) {
                            minval = a+b+c;
                            mmina = a; mminb = b;
                            mminc = c; mmind = d;
                        }
                    }
                }
            }
        }
    }
    if (check) {
        cout << mmina << " " << mminb << " " << mminc << " " << mmind << endl;
        return 0;
    }
    cout << "NONE" << endl;
}

