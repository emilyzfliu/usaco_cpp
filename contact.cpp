/*
 ID: emily.z1
 TASK: contact
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

class strcomp
{
public:
    bool operator() (string a, string b)
    {
        if (a.length()>b.length()) return true;
        if (a.length()<b.length()) return false;
        return a>b;
    }
};

unordered_map<string, int> leg;
map<int, priority_queue<string, vector<string>, strcomp>, greater<int>> ret;
int A; int B; int N;
priority_queue<string, vector<string>, strcomp> dum;
string str;

int main() {
    ifstream fin("contact.in");
    ofstream fout("contact.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    cin >> A >> B >> N;
    
    string x;
    //cout << str.length() << endl;
    while (!cin.eof()) {
        cin >> x;
        str+=x;
        x = "";
    }
    //cout << str << endl;
    //cout << str << endl;
    string temp = "";
    for (int i=A; i<=B; i++) {
        for (int j=0; j<=str.length()-i; j++) {
            if (i+j>str.length()) break;
            temp = str.substr(j, i);
            //cout <<i << " " << j << " " << temp << endl;
            if (leg.find(temp)==leg.end()) {
                leg.insert(make_pair(temp, 0));
            }
            leg[temp]+=1;
        }
    }
    
    for (const auto &[key, value]: leg) {
        //cout << key <<" "<< value << endl;
        if (ret.find(value)==ret.end()) {
            ret.insert(make_pair(value, dum));
        }
        ret[value].push(key);
    }
    int count = 0;
    int aa = 0;
    for (const auto &[key, value]: ret) {
        if (count==N) break;
        cout << key << endl;
        aa = ret[key].size();
        //cout <<"aaaa" << aa << endl;
        for (int i=0; i<aa-1; i++) {
            cout << ret[key].top();
            ret[key].pop();
            if (i%6==5) cout << endl;
            else cout << " ";
        }cout << ret[key].top() << endl;
        /*for (const auto & s:ret[key]) {
         cout << s << " ";
         }cout << endl;*/
        count++;
    }
}
