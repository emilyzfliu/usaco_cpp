/*
 ID: emily.z1
 TASK: ttwo
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

using namespace std;

/*
 0: North
 1: East
 2: South
 3: West
 */

int grid[10][10];
pair<int, int> fps;
pair<int, int> cpos;
int fdir;
int cdir;

void update() {
    if (fdir == 0) {
        fps.first--;
        if (fps.first<0 || grid[fps.first][fps.second]==1) {
            fps.first++;
            fdir = 1;
        }
    }
    else if (fdir == 1) {
        fps.second++;
        if (fps.second>=10 || grid[fps.first][fps.second]==1) {
            fps.second--;
            fdir = 2;
        }
    }
    else if (fdir == 2) {
        fps.first++;
        if (fps.first>=10 || grid[fps.first][fps.second]==1) {
            fps.first--;
            fdir = 3;
        }
    }
    else if (fdir == 3) {
        fps.second--;
        if (fps.second<0 || grid[fps.first][fps.second]==1) {
            fps.second++;
            fdir = 0;
        }
    }
    
    if (cdir == 0) {
        cpos.first--;
        if (cpos.first<0 || grid[cpos.first][cpos.second]==1) {
            cpos.first++;
            cdir = 1;
        }
    }
    else if (cdir == 1) {
        cpos.second++;
        if (cpos.second>=10 || grid[cpos.first][cpos.second]==1) {
            cpos.second--;
            cdir = 2;
        }
    }
    else if (cdir == 2) {
        cpos.first++;
        if (cpos.first>=10 || grid[cpos.first][cpos.second]==1) {
            cpos.first--;
            cdir = 3;
        }
    }
    else if (cdir == 3) {
        cpos.second--;
        if (cpos.second<0 || grid[cpos.first][cpos.second]==1) {
            cpos.second++;
            cdir = 0;
        }
    }
}

int main() {
    ifstream fin ("ttwo.in");
    ofstream fout ("ttwo.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    fdir = 0; cdir = 0;
    
    string x;
    for (int i=0; i<10; i++) {
        cin >> x;
        for (int j=0; j<10; j++) {
            if (x[j]=='*') grid[i][j] = 1;
            if (x[j]=='F') {
                fps.first = i; fps.second = j;
            }
            if (x[j]=='C') {
                cpos.first = i; cpos.second = j;
            }
        }
    }
    
    //cout << fps.first << " " << fps.second << endl;
    //cout << cpos.first << " " << cpos.second << endl;
    
    //cout << "commence loop" << endl;
    int i = 0;
    for (i=0; i<160000; i++) {
        //cout << "iteration " << i << endl;
        update();
        //cout << fps.first << " " << fps.second << endl;
        //cout << cpos.first << " " << cpos.second << endl;
        if (fps.first == cpos.first && fps.second == cpos.second) break;
        //cout << i << endl;
    }
    
    cout << ((i+1)%(160001)) << endl;
}
