/*
 ID: emily.z1
 TASK: maze1
 LANG: C++14
 */

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

using namespace std;

int grid[201][77];
int mmax = -1;
int W; int H;

bool inbounds(int a, int b) {
    return a>=0 && a<H && b>=0 && b<W;
}

vector<pair<int, int>> next(pair<int, int> cur) {
    vector<pair<int, int>> ret;
    pair<int, int> test;
    //up
    test.first = cur.first-1; test.second = cur.second;
    if (inbounds(test.first, test.second)&&grid[test.first][test.second]==0) {
        grid[test.first][test.second] = grid[cur.first][cur.second]+1;
        mmax = max(mmax, grid[test.first][test.second]);
        ret.push_back(test);
    }
    //right
    test.first = cur.first; test.second = cur.second+1;
    if (inbounds(test.first, test.second)&&grid[test.first][test.second]==0) {
        grid[test.first][test.second] = grid[cur.first][cur.second]+1;
        mmax = max(mmax, grid[test.first][test.second]);
        ret.push_back(test);
    }
    //down
    test.first = cur.first+1; test.second = cur.second;
    if (inbounds(test.first, test.second)&&grid[test.first][test.second]==0) {
        grid[test.first][test.second] = grid[cur.first][cur.second]+1;
        mmax = max(mmax, grid[test.first][test.second]);
        ret.push_back(test);
    }
    //left
    test.first = cur.first; test.second = cur.second-1;
    if (inbounds(test.first, test.second)&&grid[test.first][test.second]==0) {
        grid[test.first][test.second] = grid[cur.first][cur.second]+1;
        ret.push_back(test);
        mmax = max(mmax, grid[test.first][test.second]);
    }
    return ret;
}

int main() {
    ifstream fin ("maze1.in");
    ofstream fout ("maze1.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> W >> H;
    W = 2*W+1;
    H = 2*H+1;
    
    queue<pair<int, int>> cue;
    //cout << "initialized W, H, queue" << endl;
    
    string x;
    getline(cin, x);
    
    for (int i=0; i<H; i++) {
        //cout << "I " << i << endl;
        getline(cin, x);
        //cout << x << endl;
        for (int j=0; j<W; j++) {
            //cout << x[j] << " ";
            if (x[j]=='+' || x[j] == '-' || x[j]=='|') grid[i][j] = -1;
            else if (x[j]==' '&&(i==0 || i==H-1 || j==0 || j==W-1)) {
                pair<int,int> init;
                init.first = i; init.second=j;
                //cout << i << " " << j << endl;
                grid[i][j] = 1;
                cue.push(init);
            }
            //cout << endl;
        }
    }
    
    /*for (int i=0; i<H; i++) {
     for (int j=0; j<W; j++) {
     cout << grid[i][j] << " ";
     }
     cout << endl;
     }*/
    
    //cout << "commence loop" << endl;
    while (cue.size()>0) {
        pair<int, int> cur = cue.front();
        cue.pop();
        vector<pair<int, int>> gn = next(cur);
        for (pair<int, int> t:gn) {
            cue.push(t);
        }
    }
    //cout << "finished loop" << endl;
    
    /*for (int i=0; i<H; i++) {
     for (int j=0; j<W; j++) cout << grid[i][j] << " ";
     cout << endl;
     }*/
    
    cout << (mmax/2) << endl;
}
