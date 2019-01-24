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

#define inf (1<<31)-1

int T; int S; int N;

int dp[101][10000];

struct Slope {
    int lvl;
    int t;
    int idx;
};

struct Lesson {
    int start;
    int dur;
    int lvl;
};

vector<Slope> slopes;
vector<Lesson> lessons;
map<int, int> lvlog;
map<Lesson, vector<Lesson>> lmap;

bool compslope (Slope a, Slope b) {
    if (a.lvl!=b.lvl) return a.lvl<b.lvl;
    return a.t<b.t;
}

bool comples (Lesson a, Lesson b) {
    if (a.start!=b.start) return a.start<b.start;
    if (a.dur!=b.dur) return a.dur<b.dur;
    return a.lvl<b.lvl;
}

void findmins() {
    lvlog.insert(make_pair(1, inf));
    for (int i=0; i<S; i++) {
        lvlog.insert(make_pair(lessons[i].lvl, inf));
    }
    map<int, int>:: iterator it;
    int pointer = N-1;
    //fix this
    for (it=lvlog.end(); it!=lvlog.begin(); --it) {
        cout << "level: " << (it->first) << endl;
        cout << "level in queStion: " << slopes[pointer].lvl << endl;
        while (slopes[pointer].lvl>(it->first)) pointer--;
        cout << "target level: " << slopes[pointer].lvl << endl;
        cout << slopes[pointer].t << endl;
        lvlog[it->first] = min(it->second, slopes[pointer].t);
    }
}

//construct map of which lessons are possible to take in succession
void flmap() {
    
}

int main() {
    cin >> T >> S >> N;
    lessons.resize(S);
    slopes.resize(N);
    for (int i=0; i<S; i++) {
        cin >> lessons[i].start >> lessons[i].dur >> lessons[i].lvl;
    }
    for (int i=0; i<N; i++) {
        cin >> slopes[i].lvl >> slopes[i].t;
        slopes[i].idx = i+1;
    }
    
    sort(slopes.begin(), slopes.end(), compslope);
    sort(lessons.begin(), lessons.end(), comples);
    
    for (int i=0; i<S; i++) {
        cout << lessons[i].start << " " << lessons[i].dur << " " << lessons[i].lvl << endl;
    }
    
    findmins();
    
    map<int, int>:: iterator it;
    for (it=lvlog.begin(); it!=lvlog.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    //perform bfs
    
}
