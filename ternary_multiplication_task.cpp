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
#include <stack>

using namespace std;

int main() {
    int x; int y;
    cin >> x >> y;
    
    int prod = x*y;
    
    int prodt3 = (prod%3==0)?(x*y+10):prod;
    //cout << prodt3 << endl;
    int prodt7 = (prod%7==0)?(x*y-10):prod;
    //cout << prodt7 << endl;
    //3, not 7
    int ret = (prodt3!=prod && prodt7==prod)?prodt3:prod;
    //cout << ret << endl;
    //7, not 3
    ret = (prodt7!=prod && prodt3==prod)?prodt7:ret;
    cout << ret << endl;
}
