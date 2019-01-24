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
#include <complex>

using namespace std;

long long N;
long long K;
priority_queue<long long> planks;

int main() {
    cin >> N;
    long long x;
    for (long long i=0; i<N; i++) {
        cin >> x;
        planks.push(0-x);
    }
    
    long long sum = 0;
    
    while (planks.size()!=1) {
        long long a = planks.top();
        planks.pop();
        long long b = planks.top();
        planks.pop();
        planks.push(a+b);
        sum+=0-(a+b);
    }
    
    cout << sum << endl;
    
    
}
