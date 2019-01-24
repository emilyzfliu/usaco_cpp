#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

void print(const vector<int>& V) {
    //    for (int i=0; i<V.size(); ++i) {
    //        cout << V[i] << " ";
    //    }
    //    cout << endl;
}

bool shout(const vector<int>& DD, const vector<int>& II, const vector<int>& S) {
    vector<int> D(DD), I(II);
    bool moved = true;
    print(S);
    
    while (moved) {
        moved = false;
        for (int s : S) {
            for (;;) {
                int p = I[s];
                if (p==0 && D[p+1] > s) break;
                if (p==D.size()-1 && D[p-1] < s) break;
                if (D[p-1] < s && s < D[p+1]) break;
                moved = true;
                if (p > 0 && D[p-1] > s) {
                    I[D[p-1]] = p;
                    I[s] = p-1;
                    D[p] = D[p-1];
                    D[p-1] = s;
                } else {
                    I[D[p+1]] = p;
                    I[s] = p+1;
                    D[p] = D[p+1];
                    D[p+1] = s;
                }
            }
        }
    }
    print(D);
    for (int i=0; i<D.size(); ++i) {
        if (D[i] != i) return false;
    }
    return true;
}

void subset(int N, int L, int C, vector<int>& S, const vector<int>& DD, const vector<int>& II, int K, int& k){
    if (L==0) {
        if (shout(DD, II, S)) {
            ++k;
            if (k == K) {
                cout << S.size() << endl;
                for (int s : S) {
                    cout << s+1 << endl;
                }
                exit(0);
            }
        }
        return;
    }
    for(int i=C; i<N;i++){
        S.push_back(i);
        subset(N, L-1, i+1, S, DD, II, K, k);
        S.pop_back();
    }
}

int main() {
    ifstream in("itout.in");
    ofstream out("itout.out");
    
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());
    
    int N, K;
    cin >> N >> K;
    
    vector<int> D(N), I(N);
    for (int i=0; i<N; ++i) {
        cin >> D[i];
        D[i]--;
        I[D[i]] = i;
    }
    
    int k = 0;
    for (int i=1; i<N; ++i) {
        vector<int> S;
        subset(N, i, 0, S, D, I, K, k);
    }
}
