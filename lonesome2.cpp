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
#include <complex>

using namespace std;

struct Point {
    int x;
    int y;
    int idx;
};

int N;
vector<Point> cows;
vector<Point> orig;
vector<Point> hull;


bool comp(Point a, Point b) {
    if (a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}

//a-b
Point diff(Point a, Point b) {
    Point ret;
    ret.x = a.x-b.x;
    ret.y = a.y-b.y;
    return ret;
}

int cross(Point a, Point b) {
    return a.x*b.y-a.y*b.x;
}

int dist(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void print (Point p) {
    cout << p.x << " " << p.y << endl;
}

int main() {
    cin >> N;
    cows.resize(N);
    hull.resize(N);
    orig.resize(N);
    for (int i=0; i<N; i++) {
        cin >> cows[i].x >> cows[i].y;
        orig[i].x = cows[i].x; orig[i].y = cows[i].y;
        cows[i].idx = i+1;
        orig[i].idx = cows[i].idx;
    }
    //cout << "read input" << endl;
    sort (cows.begin(), cows.end(), comp);
    //cout << "sorted" << endl;
    int size = 0;
    for (int i=0; i<N; i++) {
        //cout << i << endl;
        while (size>=2 && cross(diff(hull[size-2], hull[size-1]), diff(cows[i], hull[size-1]))<0) {
            size--;
        }
        hull[size] = cows[i];
        size++;
    }
    //cout << "clockwise" << endl;
    
    for (int i=N-2; i>=0; i--) {
        //cout << i << endl;
        while (size>=2 && cross(diff(hull[size-2], hull[size-1]), diff(cows[i], hull[size-1]))<0) {
            size--;
        }
        hull[size] = cows[i];
        size++;
    }
    //cout << "hull formed" << endl;
    int mmax = -1;
    int mmaxi =(1<<31)-1; int mmaxj = (1<<31)-1;
    for (int i=0, k=0; i<size-1; i++) {
        int maxd = 0;
        int maxi = (1<<31)-1; int maxj = (1<<31)-1;
        for (int j=k; j<size-1; j++) {
            int dis = dist(hull[i], hull[j]);
            if (dis<maxd) {
                break;
            }
            
            int a = min(hull[i].idx,hull[j].idx);
            int b = max(hull[i].idx,hull[j].idx);
            if (dis>maxd) {
                maxi = a;
                maxj = b;
                maxd = dis;
                k=j;
            }
            else {
                if (a<maxi) {
                    maxi=a;
                    maxj=b;
                }
                else if (a==maxi) {
                    if (b<maxj) {
                        maxi=a;
                        maxj =b;
                    }
                }
            }
        }
        if (mmax<maxd) {
            mmaxi = maxi; mmaxj = maxj; mmax = maxd;
        }
        else if (mmax==maxd) {
            if (maxi<mmaxi) {
                mmaxi = maxi; mmaxj = maxj;
            }
            else if (mmaxi==maxi) {
                if (maxj<mmaxj) {
                    mmaxi = maxi; mmaxj = maxj;
                }
            }
        }
    }
    cout << mmaxi << " " << mmaxj << endl;
}
