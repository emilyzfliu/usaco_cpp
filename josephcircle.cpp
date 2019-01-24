#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    int k;
    int m;
    cin >> N >> k >> m;
    vector<bool> seen(N, false);
    int num = N;
    int dex = k;
    while (num>1) {
        int i=0;
        int point = dex-1;
        while (i<m) {
            point++;
            //cout << "current pointer " << point << endl;
            if (seen[point]) {
                //cout << "skipped " << point << endl;
                continue;
            }
            point = point%N;
            i++;
        }
        //cout << "point " << point << endl;
        seen[point] = true;
        dex = (point+1)%N;
        num--;
    }
    for (int i=0; i<N; i++) if (seen[i]==false) cout << i << endl;
}
