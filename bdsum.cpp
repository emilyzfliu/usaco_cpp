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

int N;
int sum;
int choose[11];
vector<long long> nums;

vector<int> tovec(int val) {
    vector<int> ret;
    int temp = val;
    for (int i=0; i<N; i++) {
        ret.push_back(temp%10);
        temp/=10;
    }
    return ret;
}

long long toint(int vec[]) {
    long long ret = 0;
    for (int i=N-1; i>=0; i--) {
        ret+=vec[i];
        ret*=10;
    }
    ret/=10;
    return ret;
}

int eval(long long val) {
    //cout << "eval" << endl;
    vector<int> temp = tovec(val);
    int ret = 0;
    for (int i=0; i<N; i++) {
        ret+=(temp[i]+1)*choose[i];
        //cout << "ret" << ret << endl;
    }
    //cout << "done" << endl;
    return ret;
}

string splice(int val) {
    string ret = "";
    vector<int> temp = tovec(val);
    ret+=to_string(temp[N-1]+1);
    for (int i=N-2; i>=0; i--) {
        ret+=" "+to_string(temp[i]+1);
    }
    return ret;
}

void heap(int a[], int size) {
    if (size == 1) {
        long long t = toint(a);
        if (sum == eval(t)) {
            nums.push_back(t);
        }
        return;
    }
    for (int i=0; i<size; i++) {
        heap(a,size-1);
        if (size%2==1){
            swap(a[0], a[size-1]);
        }
        else {
            swap(a[i], a[size-1]);
        }
    }
}

int main() {
    cin >> N >> sum;
    choose[0] = 1;
    for (int i=1; i<N; i++) {
        choose[i] = choose[i-1]*(N-i)/i;
    }
    
    //cout << "fslkdj" << endl;
    
    int init[11];
    for (int i=0; i<N; i++) {
        init[i] = i;
    }
    //cout << "sdlkfjlk" << endl;
    
    heap(init, N);
    
    //cout<< "weoriu" << endl;
    
    sort(nums.begin(), nums.end());
    
    //cout << "weiorusdlfjk" << endl;
    
    //for (long long i: nums) cout << i << ' ';
    //cout << endl;
    
    cout << splice(nums[0]) << endl;
    /*
     for (long long i : nums) {
     //cout << *it << endl;
     //cout << eval(*it) << endl;
     //cout << *it << endl;
     if (eval(i)==sum) {
     cout << splice(i) << endl;
     return 0;
     }
     }
     */
    //    cout << "wac" << endl;
}
