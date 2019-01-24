/*
 ID: emily.z1
 TASK: milk3
 LANG: C++14
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <functional>
#include <climits>
#include <unordered_set>
#include <map>
#include <vector>
#include <utility>
#include <ctime>
#include <queue>

using namespace std;
int A;
int B;
int C;

struct triple {
    int a;
    int b;
    int c;
};

struct triple_hash {
    size_t operator()(const triple& t) const {
        hash<int> hf;
        return hf(t.a) + hf(t.b) + hf(t.c);
    }
};

struct triple_equal {
    bool operator()(const triple& t, const triple& u) const {
        return t.a==u.a && t.b==u.b && t.c==u.c;
    }
};

typedef unordered_set<triple, triple_hash, triple_equal> HashTable;

bool valid (triple t) {
    return t.a>=0 && t.b>=0 && t.c>=0;
}

HashTable getNext(triple t) {
    HashTable ret;
    triple newt;
    //ca
    newt.b = t.b;
    newt.a = min(A, t.c+t.a);
    newt.c = t.c-newt.a+t.a;
    triple_equal eq;
    if (valid(newt)&&!eq(newt, t)) ret.insert(newt);
    //cb
    newt.a = t.a;
    newt.b = min(B, t.c+t.b);
    newt.c = t.c-newt.b+t.b;
    if (valid(newt)&&!eq(newt, t)) ret.insert(newt);
    //bc
    newt.a = t.a;
    newt.c = min(C, t.b+t.c);
    newt.b = t.b-newt.c+t.c;
    if (valid(newt)&&!eq(newt, t)) ret.insert(newt);
    //ba
    newt.c = t.c;
    newt.a = min(A, t.b+t.a);
    newt.b = t.b-newt.a+t.a;
    if (valid(newt)&&!eq(newt, t)) ret.insert(newt);
    //ab
    newt.c = t.c;
    newt.b = min(B, t.a+t.b);
    newt.a = t.a-newt.b+t.b;
    if (valid(newt)&&!eq(newt, t)) ret.insert(newt);
    //ac
    newt.b = t.b;
    newt.c = min(C, t.a+t.c);
    newt.a = t.a-newt.c+t.c;
    if (valid(newt)&&!eq(newt, t)) ret.insert(newt);
    return ret;
}

int main() {
    ifstream fin ("milk3.in");
    ofstream fout ("milk3.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> A >> B >> C;
    
    unordered_set<int> cvals;
    triple init;
    init.a = 0; init.b = 0;
    init.c = C;
    
    queue<triple> cue;
    HashTable seen;
    
    cue.push(init);
    
    while (cue.size()>0) {
        triple cur = cue.front();
        cue.pop();
        HashTable next = getNext(cur);
        for (triple t: next) {
            if (seen.count(t)) continue;
            seen.insert(t);
            if (t.a==0) cvals.insert(t.c);
            cue.push(t);
        }
    }
    vector<int> finc(cvals.begin(), cvals.end());
    sort (finc.begin(), finc.end());
    
    for (int i=0; i<finc.size()-1; i++) cout << finc[i] << " ";
    
    cout << finc[finc.size()-1] << endl;
    
}
