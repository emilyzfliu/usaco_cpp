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

#define N 20;
#define MAX (1+(1<<6));
#define inf 0x7fffffff;

int arr[N];
int tree[MAX];

void build(int node, int a, int b) {
    if (a>b) return;
    if (a==b) {
        tree[node] = arr[a];
        return;
    }
    build(node*2, a, (a+b)/2);
    build(node*2+1, (a+b)/2+1, b);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

void update(int node, int a, int b, int i, int j, int val) {
    if (a>b || a>j || b<i) return;
    if (a==b) {
        tree[node]+=val;
        return;
    }
    update(node, a, (a+b)/2, i, j, val);
    update(node, (a+b)/2+1, b, i, j, val);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

int query(int node, int a, int b, int i, int j) {
    if (a>b || a>j || b<i) return -inf;
    if (a>=i && b<=j) return tree[node];
    int q1 = query(node*2, a, (a+b)/2, i, j);
    int q2 = query(node*2+1, (a+b)/2+1, b, i, j);
    return max(q1, q2);
}

int main () {
    for (int i=0; i<N; i++) arr[i] = 1;
    build(1,0,N-1);
    update(1,0,N-1,0,6,5);
    update(1,0,N-1,7,10,12);
    update(1,0,N-1,12,N-1,100);
}
