/*
 ID: emily.z1
 TASK: pprime
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

using namespace std;

unordered_set<int> primes;
vector<int> pvec;
unordered_set<int> palindromes;
vector<int> palvec;
int a;
int b;

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
        //cout << n << " is prime" << endl;
        return true;
    }
    for (int i=0; i<pvec.size(); i++) {
        if (n%pvec[i]==0) {
            //cout << n << " is not prime" << endl;
            return false;
        }
    }
    //cout << n << " is prime" << endl;
    return true;
}

bool isPalindrome(int n) {
    if (palindromes.count(n)) return true;
    string strn = to_string(n);
    for (int i=0; i<strn.length()/2; i++) {
        if (strn[i]!=strn[strn.length()-1-i]) {
            //cout << n << " is not a palindrome" << endl;
            return false;
        }
    }
    //cout << n << " is a palindrome" << endl;
    return true;
}

bool enumerate_palindromes() {
    string stra = to_string(a);
    string strb = to_string(b);
    int lena = stra.length();
    int lenb = strb.length();
    for (int c=1; c<=8; c++) {
        if (lena<=c && lenb>=c) {
            if (c==1) {
                if (a<=2 && b>=2) {
                    palindromes.insert(2);
                    palvec.push_back(2);
                }
                if (a<=3 && b>=3) {
                    palindromes.insert(3);
                    palvec.push_back(3);
                }
                if (a<=5 && b>=5) {
                    palindromes.insert(5);
                    palvec.push_back(5);
                }
                if (a<=7 && b>=7) {
                    palindromes.insert(7);
                    palvec.push_back(7);
                }
            }
            if (c==2) {
                if (a<=11 && b>=11) {
                    palindromes.insert(11);
                    palvec.push_back(11);
                }
            }
            if (c==3) {
                for (int i=1; i<=9; i+=2) {
                    if (i==5) continue;
                    for (int j=0; j<=9; j++) {
                        int pal = 101*i+10*j;
                        if (b<pal) break;
                        if (a<=pal) {
                            palindromes.insert(pal);
                            palvec.push_back(pal);
                        }
                    }
                }
            }
            if (c==4) {
                for (int i=1; i<=9; i+=2) {
                    if (i==5) continue;
                    for (int j=0; j<=9; j++) {
                        int pal = 1001*i+110*j;
                        if (b<pal) break;
                        if (a<=pal) {
                            palindromes.insert(pal);
                            palvec.push_back(pal);
                        }
                    }
                }
            }
            if (c==5) {
                for (int i=1; i<=9; i+=2) {
                    if (i==5) continue;
                    for (int j=0; j<=9; j++) {
                        for (int k=0; k<=9; k++) {
                            int pal = 10001*i+1010*j+100*k;
                            if (b<pal) break;
                            if (a<=pal) {
                                palindromes.insert(pal);
                                palvec.push_back(pal);
                            }
                        }
                    }
                }
            }
            if (c==6) {
                for (int i=1; i<=9; i+=2) {
                    if (i==5) continue;
                    for (int j=0; j<=9; j++) {
                        for (int k=0; k<=9; k++) {
                            int pal = 100001*i+10010*j+1100*k;
                            if (b<pal) break;
                            if (a<=pal) {
                                palindromes.insert(pal);
                                palvec.push_back(pal);
                            }
                        }
                    }
                }
            }
            if (c==7) {
                for (int i=1; i<=9; i+=2) {
                    if (i==5) continue;
                    for (int j=0; j<=9; j++) {
                        for (int k=0; k<=9; k++) {
                            for (int l=0; l<=9; l++){
                                int pal = 1000001*i+100010*j+10100*k+1000*l;
                                if (b<pal) break;
                                if (a<=pal) {
                                    palindromes.insert(pal);
                                    palvec.push_back(pal);
                                }
                            }
                        }
                    }
                }
            }
            if (c==8) {
                for (int i=1; i<=9; i+=2) {
                    if (i==5) continue;
                    for (int j=0; j<=9; j++) {
                        for (int k=0; k<=9; k++) {
                            for (int l=0; l<=9; l++){
                                int pal = 10000001*i+1000010*j+100100*k+11000*l;
                                if (b<pal) break;
                                if (a<=pal) {
                                    palindromes.insert(pal);
                                    palvec.push_back(pal);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
}

int main() {
    ifstream fin ("pprime.in");
    ofstream fout ("pprime.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> a >> b;
    
    enumerate_primes();
    enumerate_palindromes();
    
    for (int i=0; i<palvec.size(); i++) {
        //cout << "i " << palvec[i] << endl;
        if (isPrime(palvec[i]))  {
            //cout << i +" is prime palindrome" << endl;
            cout << palvec[i] << endl;
        }
    }
}
