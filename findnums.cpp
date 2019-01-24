#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int N = 0;
    int v = 0;
    while (!cin.eof()) {
        cin >> N;
        //cout << N << endl;
        int x[N];
        for (int i=0; i<N; i++) {
            cin >> x[i];
        }
        cin >> v;
        //cout << v << endl;
        int i = 0;
        for (i=0; i<N; i++) {
            //cout << v << " " << x[i] << endl;
            if (v==x[i]) {
                cout << i << endl;
                break;
            }
        }
        if (i==N) cout << "No" << endl;
    }
}
