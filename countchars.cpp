#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int lettercount[26];

int main() {
    while (!cin.eof()) {
        string str;
        getline(cin, str);
        //cout << str << endl;
        for (int i=0; i<str.length(); i++) {
            //cout << i << " "<< str[i] << endl;
            if (str[i]>='a' && str[i] <='z') {
                lettercount[str[i]-'a']++;
            }
        }
    }
    cout << "read input" << endl;
    for (int i=0; i<26; i++) {
        if (lettercount[i]!=0) {
            cout << (char)(i+'a') << ":" << lettercount[i] << endl;
        }
    }
}
