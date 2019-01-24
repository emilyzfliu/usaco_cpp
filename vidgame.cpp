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

int N; int C;
int dp[1000001];
int dpp[1000001];

int main() {
    cin >> N >> C;
    for (int i=0; i<C; i++) dp[i] = 0;
    int cons; int n;
    int price; int val;
    for (int c=0; c<N; c++) {
        cin >> cons >> n;
        for (int i=cons; i<=C; i++) {
            dpp[i] = dp[i-cons];
        }
        for (int i=0; i<n; i++) {
            cin >> price >> val;
            for (int j = C-price; j>=cons; j--) {
                if (dpp[j+price]<dpp[j]+val) {
                    dpp[j+price] = dpp[j]+val;
                }
            }
        }
        for (int i=cons; i<=C; i++) {
            if (dp[i]<dpp[i]) {
                dp[i] = dpp[i];
            }
        }
    }
    cout << dp[C] << endl;
}
