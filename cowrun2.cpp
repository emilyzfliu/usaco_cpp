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

using namespace std;

bool your_move(int idx, int R, int move) {
    int choose = (int)(rand()*0.5);
    return bessies_move(idx, R, move,choose) && bessies_move(idx, R, move, 1-choose);
}

bool bessies_move(int idx, int R, int your_move, int b_move) {
    R+=R*pile[idx][your_move*4+b_move*2]+pile[idx][your_move*4+2*b_move+1];
    if (idx==N) {
        return R%M<K || (M-R)%M<K;
    }
    return your_move(idx+1, R, 0) || your_move(idx+1, R, 1);
}

int main() {
    for (int i=0; i<N; i++) {
        if (your_move(i, R, 0)) {
            //update R here
            cout << "B" << endl;
        }
        else {
            //update R here
            cout << "T" << endl;
        }
        R+=pile[i][ym*4+tm[i]*2]+pile[i][ym*4+tm[i]*2+1];
    }
}
