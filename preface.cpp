/*
 ID: emily.z1
 TASK: preface
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
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int N;
int totalicount;
int totalvcount;
int totalxcount;
int totallcount;
int totalccount;
int totaldcount;
int totalmcount;

struct roman {
    int icount; int vcount;
    int xcount; int lcount;
    int ccount; int dcount;
    int mcount;
    roman(): icount(0), vcount(0), xcount(0), lcount(0), ccount(0), dcount(0), mcount(0){};
};

roman digits[9][4];

void initialize_digits() {
    //ones
    for (int i=0; i<3; i++) {
        digits[i][0] = roman();
        digits[i][0].icount+=i+1;
    }
    digits[3][0] = roman(); digits[3][0].icount = 1; digits[3][0].vcount = 1;
    for (int i=4; i<8; i++) {
        digits[i][0] = roman();
        digits[i][0].icount+=((i+1)%5);
        digits[i][0].vcount+=1;
    }
    digits[8][0] = roman(); digits[8][0].icount = 1; digits[8][0].xcount = 1;
    //tens
    for (int i=0; i<3; i++) {
        digits[i][1] = roman();
        digits[i][1].xcount+=i+1;
    }
    digits[3][1] = roman(); digits[3][1].xcount = 1; digits[3][1].lcount = 1;
    for (int i=4; i<8; i++) {
        digits[i][1] = roman();
        digits[i][1].xcount+=((i+1)%5);
        digits[i][1].lcount+=1;
    }
    digits[8][1] = roman(); digits[8][1].xcount = 1; digits[8][1].ccount = 1;
    //hundreds
    for (int i=0; i<3; i++) {
        digits[i][2] = roman();
        digits[i][2].ccount+=i+1;
    }
    digits[3][2] = roman(); digits[3][2].ccount = 1; digits[3][2].dcount = 1;
    for (int i=4; i<8; i++) {
        digits[i][2] = roman();
        digits[i][2].ccount+=((i+1)%5);
        digits[i][2].dcount+=1;
    }
    digits[8][2] = roman(); digits[8][2].ccount = 1; digits[8][2].mcount = 1;
    //thousands
    for (int i=0; i<3; i++) {
        digits[i][3] = roman();
        digits[i][3].mcount+=i+1;
    }
}

void eval(int n) {
    string str = to_string(n);
    //cout << "eval " << n << endl;
    for (int place=0; place<str.length(); place++) {
        int dig = n%10;
        n/=10;
        if (dig==0) continue;
        //cout << dig << " " << place << endl;
        roman temp = digits[(dig-1)][place];
        //cout << temp.icount << " " << temp.vcount << endl;
        totalicount+=temp.icount; totalvcount+=temp.vcount;
        totalxcount+=temp.xcount; totallcount+=temp.lcount;
        totalccount+=temp.ccount; totaldcount+=temp.dcount;
        totalmcount+=temp.mcount;
    }
}

int main() {
    ifstream fin ("preface.in");
    ofstream fout ("preface.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    
    initialize_digits();
    
    totalicount = 0; totalvcount = 0;
    totalxcount = 0; totallcount = 0;
    totalccount = 0; totaldcount = 0;
    totalmcount = 0;
    
    for (int i=1; i<=N; i++) {
        eval(i);
    }
    
    if (totalicount>0) {
        cout << "I " <<totalicount << endl;
    }
    if (totalvcount>0) {
        cout << "V " <<totalvcount << endl;
    }
    if (totalxcount>0) {
        cout << "X " <<totalxcount << endl;
    }
    if (totallcount>0) {
        cout << "L " <<totallcount << endl;
    }
    if (totalccount>0) {
        cout << "C " <<totalccount << endl;
    }
    if (totaldcount>0) {
        cout << "D " <<totaldcount << endl;
    }
    if (totalmcount>0) {
        cout << "M " <<totalmcount << endl;
    }
}
