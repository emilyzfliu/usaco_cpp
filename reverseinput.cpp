#include <iostream>

using namespace std;

void f(){
    if (cin.eof()) return;
    int x;
    cin >> x;
    f();
    cout << x << endl;
}

int main() {
    f();
}
