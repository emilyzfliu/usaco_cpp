/*
 ID: emily.z1
 TASK: sort3
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

int N;
int arr1[3];
int arr2[3];
int arr3[3];

int tfer12() {
    int onetwo = arr1[1];
    int twoone = arr2[0];
    arr1[0] += twoone;
    arr1[1] = 0;
    arr1[2] += (onetwo-twoone);
    arr2[0] = 0;
    arr2[1] += onetwo;
    arr2[2] -=(onetwo-twoone);
    if (onetwo>twoone) return onetwo;
    return twoone;
}

int tfer23() {
    int twothree = arr2[2];
    int threetwo = arr3[1];
    arr2[0] += (twothree-threetwo);
    arr2[1] +=threetwo;
    arr2[2] = 0;
    arr3[0] -= (twothree-threetwo);
    arr3[1] = 0;
    arr3[2] +=twothree;
    if (twothree>threetwo) return twothree;
    return threetwo;
}

int tfer31() {
    int onethree = arr1[2];
    int threeone = arr3[0];
    arr1[0] += threeone;
    arr1[1] -= (onethree-threeone);
    arr1[2] = 0;
    arr3[0] = 0;
    arr3[1] -= (onethree-threeone);
    arr3[2] += threeone;
    if (onethree>threeone) return onethree;
    return threeone;
}

int main() {
    ifstream fin ("sort3.in");
    ofstream fout ("sort3.out");
    
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    
    cin >> N;
    
    int arr[N];
    
    int count1 = 0; int count2 = 0; int count3 = 0;
    
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        if (arr[i]==1) count1++;
        if (arr[i]==2) count2++;
        if (arr[i]==3) count3++;
    }
    
    for (int i=0; i<count1; i++) {
        arr1[(arr[i]-1)]++;
    }
    for (int i=count1; i<count1+count2; i++) {
        arr2[(arr[i]-1)]++;
    }
    for (int i=count1+count2; i<count1+count2+count3; i++) {
        arr3[(arr[i]-1)]++;
    }
    
    cout << (tfer12()+tfer23()+tfer31()) << endl;
}
