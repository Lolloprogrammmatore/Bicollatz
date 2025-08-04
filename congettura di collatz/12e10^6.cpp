#include <stdio.h>
#include <assert.h>
#include <map>
#include <signal.h>
#include <cstdlib>
#include <unistd.h>
#include<iostream>
using namespace std;
void differenza(int x){
    bool b = x>10^6;
    bool b1 = x>12;
    cout << b << " " << b1 << endl;
}
int main() {
    for(int i=0; i<1000000; i++){
        differenza(i);
    }
    return 0;
}