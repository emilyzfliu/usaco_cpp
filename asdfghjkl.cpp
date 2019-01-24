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

int N;
vector<int> p;
unordered_set<int> aa;

int solve(unordered_set<int> seen) {
    cout << "iteration" << endl;
    if (seen.size()==N) {
        return 0;
    }
    int m = pow(2, 31)-1;
    int temp = 0;
    for (int i=0; i<N; i++) {
        temp = val+p[i];
    }
    int smaller = 0;
    int larger = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; i++) {
            smaller = min(p[i], p[j]);
            larger = max(p[i], p[j]);
            seen.insert(larger);
            seen.insert(smaller);
            temp = val+smaller+larger;
            int mini = pow(2, 310)-1;
            for (const auto &int n:seen) {
                mini = min(mini, n);
            }
            seen.erase(mini);
            m = min(m, larger+mini+solve(seen, temp));
            seen.insert(mini);
            seen.erase(larger);
            seen.erase(smaller);
        }
    }
    return m;
}

int main() {
    cin >> N;
    int x = 0;
    for (int i=0; i<N; i++) {
        cin >> x;
        p.push_back(x);
    }
    unordered_set<int> other = aa;
    cout << solve(other) << endl;
}
