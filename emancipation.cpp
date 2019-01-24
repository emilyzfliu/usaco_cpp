#include <iostream>

using namespace std;
int N;
int M;
int S;

long long grid[1002][1002];
long long mmax;

int val(int left, int right, int up, int low) {
    int sum = 0;
    for (int j = left; j<=right; j++) {
        for (int i=up; i<=low; i++) sum+=grid[i][j];
    }
    return sum;
}

long long pfxdiff(int a, int b, int c, int d) {
    long long sum = 0;
    sum+=grid[c][d];
    if (a-1>=0 && b-1>=0) sum+=grid[a-1][b-1];
    if (b-1>=0) sum-=grid[c][b-1];
    if (a-1>=0) sum-=grid[a-1][d];
    return sum;
}

void pfix() {
    for (int i=2; i<=M; i++) {
        grid[1][i] = grid[1][i]+grid[1][i-1];
    }
    for (int i=2; i<=N; i++) {
        grid[i][1] = grid[i][1]+grid[i-1][1];
    }
    for (int i=2; i<=N; i++) {
        for (int j=2; j<=M; j++) {
            grid[i][j] = grid[i][j-1]+grid[i-1][j]+grid[i][j]-grid[i-1][j-1];
        }
    }
}

int main()
{
    cin >> N >> M >> S;
    int thresh = S/2;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) cin >> grid[i][j];
    }
    
    pfix();
    
    for (int i=1; i<=min(N,thresh-1); i++) {
        int j = min(M, thresh-i);
        for (int a = 0; a<N-i+1; a++) {
            for (int b = 0; b<M-j+1; b++) {
                mmax = max(mmax, grid[a+i][b+j]-grid[a][b+j]-grid[a+i][b]+grid[a][b]);
            }
        }
    }
    
    /*int c =0; int d = 0;
    for (int a=0; a<N; a++) {
        for (int b=0; b<M; b++) {
            for (int e = 0; e<thresh-1; e++) {
                c = a+e;
                d = b+thresh-2-e;
                mmax = max(mmax, pfxdiff(a,b,c,d));
            }
        }
    }*/
    cout << mmax << endl;
}
