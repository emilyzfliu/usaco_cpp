/*
 ID: emily.z1
 TASK: fracdec
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

int num;
int den;
int val;
string intpart;
string norep;
string rep;
unordered_set<int> seen;
vector<int> decpart;
vector<int> divlog;
int fac;

void setIntpart() {
    int ipart = num/den;
    val = num%den;
    intpart = to_string(ipart);
}

void partition() {
    if (fac==-1) {
        for (int i=0; i<divlog.size(); i++) {
            norep+=to_string(decpart[i]);
        }
        return;
    }
    int divi = -1;
    /*cout << fac << endl;
     for (int i=0; i<divlog.size(); i++) {
     cout << divlog[i] << " ";
     }
     cout << endl;*/
    for (int i=decpart.size()-2; i>=0; i--) {
        if (fac==divlog[i]) {
            divi = i;
            break;
        }
    }
    //cout << "divi " << divi << endl;
    for (int i=0; i<=divi; i++) {
        norep+=to_string(decpart[i]);
    }
    for (int i=divi+1; i<decpart.size(); i++) {
        rep+=to_string(decpart[i]);
    }
}

void setDecimal() {
    //cout << (val*10) << " " << den << endl;
    int quot = (val*10)/den;
    int mod = (val*10)%den;
    //cout << (val*10) << endl;
    seen.insert(val);
    if (mod==0) {
        //cout << "terminates" << endl;
        decpart.push_back(quot);
        divlog.push_back(mod);
        fac = -1;
        partition();
        return;
    }
    if (seen.count(mod)) {
        //cout << "seen before" << endl;
        //cout << mod << endl;
        divlog.push_back(mod);
        decpart.push_back(quot);
        fac = mod;
        /*for (int i=0; i<decpart.size(); i++) {
         cout << decpart[i] << " ";
         }
         cout << endl;*/
        partition();
        return;
    }
    decpart.push_back(quot);
    divlog.push_back(mod);
    /*cout << "decpart ";
     for (int i=0; i<decpart.size(); i++) {
     cout << decpart[i] << " ";
     }*/
    //cout << endl;
    val = mod;
    //seen.insert(val);
    setDecimal();
}

void print(string str) {
    for (int i=0; i<str.length(); i++) {
        cout << str[i];
        if (i%76==75) cout << endl;
    }
    cout << endl;
}

int main() {
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> num >> den;
    
    val = num;
    
    //cout << "read input" << endl;
    
    setIntpart();
    
    //cout << "set int part "<<intpart << endl;
    
    setDecimal();
    
    //cout << "set decimal" << endl;
    
    string ret = "";
    ret+=intpart;
    ret+=".";
    if (norep.length()==0 && rep.length()==0) {
        ret+="0";
        print(ret);
        return 0;
    }
    ret+=norep;
    if (rep.length()!=0) {
        ret+="(";
        ret+=rep;
        ret+=")";
    }
    print(ret);
}
