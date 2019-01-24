/*
 ID: emily.z1
 TASK: humble
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

using namespace std;

long K;
long N;
int primes[100];
int pdex[100];
long humble[100000+1];

//set<long long> seen;
//long long heap[1433585];
//int S=0;

int main() {
    ifstream fin("humble.in");
    ofstream fout("humble.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> K >> N;
    //long x = 0;
    for (int i=0; i<K; i++) {
        cin >> primes[i];
    }
    
    
    int count = 0;
    
    humble[count++] = 1;
    
    int mmin = 0;
    int minp = 0;
    
    while (count<=N) {
        mmin = pow(2,31)-1;
        minp = -1;
        for (int i=0; i<K; i++) {
            while((double)primes[i]*humble[pdex[i]]<=humble[count-1]) pdex[i]++;
            if ((double)primes[i]*humble[pdex[i]]<mmin) {
                mmin =primes[i]*humble[pdex[i]];
                minp = i;
            }
        }
        humble[count++] = mmin;
        pdex[minp]++;
    }
    
    cout << humble[N] << endl;
}
