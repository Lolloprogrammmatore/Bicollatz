#include <stdio.h>
#include <assert.h>
#include <map>
using namespace std;

map<pair<int, int>, int> memoria;

int bicollatz(int A, int B,int depth) {
    if(depth>10^6) return -1;//fa solo quattro casi ovvero i rimanete di questa condizione if(depth>1000000)
    int steps = 0;
    pair<int, int> stato = {A, B};
    if (memoria.find(stato) != memoria.end()) {
        return memoria[stato];
    }

    if (A == 1 && B == 1) return 0;

    if (A % 2 == 0 && B % 2 == 0) {
        steps = 1 + bicollatz(A / 2, B / 2, depth + 1);
    } else if (A % 2 == 1 && B % 2 == 1) {
        steps = 1 + bicollatz(A * 3 + 1, B * 3 + 1, depth + 1);
    } else if (A % 2 == 1) {
        steps = 1 + bicollatz(A + 3, B, depth + 1);
    } else if (B % 2 == 1) {
        steps = 1 + bicollatz(A, B + 3, depth + 1);
    }

    return steps;
}

int main() {
    FILE *fr, *fw;
    int A, B;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &A, &B));

    fprintf(fw, "%d\n", bicollatz(A, B, 0));
    fclose(fr);
    fclose(fw);
    return 0;
}
