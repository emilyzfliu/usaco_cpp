/*
 ID: emily.z1
 TASK: sprime
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

unordered_set<int> primes;
vector<int> pvec;

void enumerate_primes() {
    for (int i=2; i<=10000; i++) {
        bool prime = true;
        for (int j=0; j<pvec.size(); j++) {
            if (i%pvec[j]==0) {
                prime = false;
                break;
            }
        }
        if (prime && !primes.count(i)) {
            primes.insert(i);
            pvec.push_back(i);
        }
    }
}

bool isPrime (int n) {
    if (primes.count(n)) {
        return true;
    }
    for (int i=0; i<pvec.size(); i++) {
        if (n%pvec[i]==0) {
            return false;
        }
    }
    return true;
}

vector<int> getprimes (int n) {
    vector<int> ret;
    int units[] = {1, 3, 7, 9};
    for (int i: units) {
        int hypothet = n*10+i;
        if (isPrime(hypothet)) ret.push_back(hypothet);
    }
    return ret;
}

int len(int n) {
    string str = to_string(n);
    return str.length();
}

int main() {
    ifstream fin ("sprime.in");
    ofstream fout ("sprime.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    
    if (N==1) {
        cout << 2 << endl;
        cout << 3 << endl;
        cout << 5 << endl;
        cout << 7 << endl;
        return 0;
    }
    
    enumerate_primes();
    
    queue<int> cue;
    cue.push(2);
    cue.push(3);
    cue.push(5);
    cue.push(7);
    
    vector<int> superprimes;
    
    while (cue.size()>0) {
        int curr = cue.front();
        cue.pop();
        vector<int> nextprimes = getprimes(curr);
        for (int i: nextprimes) {
            if (len(i)<N) cue.push(i);
            if (len(i)==N) superprimes.push_back(i);
        }
    }
    
    sort(superprimes.begin(), superprimes.end());
    
    for (int i=0; i<superprimes.size(); i++) {
        cout << superprimes[i] << endl;
    }
}
