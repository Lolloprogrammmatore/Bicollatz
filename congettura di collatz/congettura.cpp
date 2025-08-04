#include<iostream>
#include<map>
#include<fstream>
using namespace std;
map<int,int> memo;
int congettura(int n){
    if(n == 1) return 1;
    if(memo.count(n)) return memo[n];
    if(n % 2 == 0) return memo[n] = 1 + congettura(n / 2);
    return memo[n] = 1 + congettura(3 * n + 1);
}
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;
    cin >> n;
    cout<<congettura(n)<<endl;
    return 0;
}