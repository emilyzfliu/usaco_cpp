/*
 ID: emily.z1
 TASK: prefix
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

int main() {
    ifstream fin ("prefix.in");
    ofstream fout ("prefix.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    set<string> prims;
    string x;
    cin >> x;
    int maxlen = 0;
    while (x!=".") {
        if (x.length()>maxlen) maxlen = x.length();
        prims.insert(x);
        cin >> x;
    }
    string word = "";
    while (cin >> x) {
        //cout << "input " << x << endl;
        word+=x;
    }
    /*for (const auto& str: prims) {
     cout << str << " ";
     }
     cout << endl;
     cout << word << endl;
     cout << maxlen << endl; */
    //cout << word << endl;
    vector<bool> cando(word.length(), false);
    string str;
    int pointer = 0;
    for (int i=1; i<=word.length(); i++) {
        str += word[i-1];
        if (prims.count(str)) {
            //cout << str << " is already in prims"<< endl;
            cando[i-1] = true;
            pointer = i;
            continue;
        }
        for (int j=1; j<=maxlen; j++) {
            if (i-j<=0) break;
            //cout << cando[0] << endl;
            if (cando[i-j-1]==true && prims.count(str.substr(i-j, i))){
                //cout << i << " " << j << endl;
                cando[i-1] = true;
                pointer = i;
                break;
            }
        }
    }
    cout << pointer << endl;
    //cout << word.length() << endl;
}
