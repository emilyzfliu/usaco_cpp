/*
 ID: emily.z1
 TASK: castle
 LANG: C++14
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <climits>
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <utility>
#include <ctime>
#include <cmath>
#include <queue>

using namespace std;

int M;
int N;
int walls[50][50];
vector<int> rooms;
int flood[50][50];
int north[50][50];
int east[50][50];

int floodfill(int n, int i, int j) {
    if (flood[i][j]!=0) {
        return 0;
    }
    if (i<0 || j<0 || i>=N || j>=M) {
        return 0;
    }
    int ret = 1;
    flood[i][j] = n;
    if (int(walls[i][j]&1)==0) {
        ret+=floodfill(n, i, j-1);
    }
    if (int(walls[i][j]&2)==0) {
        ret+=floodfill(n, i-1, j);
    }
    if (int(walls[i][j]&4)==0) {
        ret+=floodfill(n, i, j+1);
    }
    if (int(walls[i][j]&8)==0) {
        ret+=floodfill(n, i+1, j);
    }
    return ret;
}

void initialize_ne() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (int(walls[i][j]&2)==2) {
                north[i][j] = 1;
            }
            if (int(walls[i][j]&4)==4) {
                east[i][j] = 1;
            }
        }
    }
}

void countrooms() {
    int count = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (flood[i][j]==0) {
                count++;
                rooms.push_back(floodfill(count,i,j));
            }
        }
    }
}

int maxroom() {
    int mmax = -1;
    for (int i=0; i<rooms.size(); i++) {
        if (mmax<rooms[i]) mmax = rooms[i];
    }
    return mmax;
}

pair <int, string> solvepart2() {
    int maxvaln = -1;
    int maxvale = -1;
    int maxxn = -1; int maxyn = -1;
    int maxxe = -1; int maxye = -1;
    for (int i=1; i<N; i++) {
        for (int j=M-1; j>=0; j--) {
            int hypmax = rooms[flood[i-1][j]-1]+rooms[flood[i][j]-1];
            if (flood[i-1][j]==flood[i][j]) hypmax = flood[i][j];
            //if (i==36 && j==17) cout << "TELL ME THE TRUTH " << hypmax << endl;
            if (hypmax>=maxvaln) {
                //cout << "maybe replace "<< maxvaln << " with " << hypmax << endl;
                if (hypmax==maxvaln) {
                    //cout << "values equal" << endl;
                    if (maxyn>j) {
                        //cout << j << " is farther west than " << maxyn << endl;
                        //cout << "REPLACEMENT SUCCEEDED" << endl;
                        maxvaln = hypmax;
                        maxxn = i+1;
                        maxyn = j+1;
                    }
                    if (maxyn==j) {
                        if (maxxn<i) {
                            //cout << "farther south" << endl;
                            maxvaln = hypmax;
                            maxxn = i+1;
                            maxyn = j+1;
                            //cout << "REPLACEMENT SUCCEEDED" << endl;
                        }
                        continue;
                    }
                    continue;
                }
                maxvaln = hypmax;
                maxxn = i+1;
                maxyn = j+1;
                //    cout << "REPLACEMENT SUCCEEDED" << endl;
            }
        }
    }
    //cout << "e" << endl;
    //east
    for (int i=0; i<N; i++) {
        //cout << "started loop E" << endl;
        for (int j=M-2; j>=0; j--) {
            //cout << i << " " << j << endl;
            int hypmax = rooms[flood[i][j+1]-1]+rooms[flood[i][j]-1];
            if (flood[i][j+1]==flood[i][j]) hypmax = flood[i][j];
            //cout << hypmax << endl;
            if (hypmax>=maxvale) {
                if (hypmax==maxvale) {
                    //              cout << "values equal" << endl;
                    if (maxye>j) {
                        //                cout << "farther west" << endl;
                        maxvale = hypmax;
                        maxxe = i+1;
                        maxye = j+1;
                    }
                    if (maxye==j) {
                        if (maxxe<i) {
                            //                  cout << "farther south" << endl;
                            maxvale = hypmax;
                            maxxe = i+1;
                            maxye = j+1;
                        }
                    }
                }
                maxvale = hypmax;
                maxxe = i+1;
                maxye = j+1;
            }
        }
    }
    pair<int, string> ret;
    //cout << maxvale << " " << maxvaln << endl;
    string walle = to_string(maxxe)+" "+to_string(maxye)+" E";
    string walln = to_string(maxxn)+" "+to_string(maxyn)+" N";
    //which is greater
    if (maxvale>maxvaln) {
        //cout << "maxvale is greater than maxvaln" << endl;
        ret.first = maxvale;
        ret.second = walle;
        return ret;
    }
    if (maxvaln>maxvale) {
        //cout << "maxvaln is greater than maxvale" << endl;
        ret.first = maxvaln;
        ret.second = walln;
        return ret;
    }
    //farthest west
    //cout << maxyn << " " << maxye << endl;
    if (maxyn<maxye) {
        //cout << "the n is farther west than the e" << endl;
        ret.first = maxvaln;
        ret.second = walln;
        return ret;
    }
    if (maxyn>maxye) {
        //cout << "the e is farther west than the n" << endl;
        ret.first = maxvale;
        ret.second = walle;
        return ret;
    }
    //farthest south
    if (maxxn>maxxe) {
        //cout << "the n is farther south than the e" << endl;
        ret.first = maxvaln;
        ret.second = walln;
        return ret;
    }
    if (maxxe>maxxn) {
        //cout << "the e is farther south than the n" << endl;
        ret.first = maxvale;
        ret.second = walle;
        return ret;
    }
    //north is tiebreakiest
    //cout << "in all other respects they are the same so n wins" << endl;
    ret.first = maxvaln;
    ret.second = walln;
    return ret;
}

int main() {
    ifstream fin ("castle.in");
    ofstream fout ("castle.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> M >> N;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> walls[i][j];
        }
    }
    
    countrooms();
    
    cout << rooms.size() << endl;
    cout << maxroom() << endl;
    
    pair<int, string> rest = solvepart2();
    
    cout << rest.first << endl;
    cout << rest.second << endl;
}
