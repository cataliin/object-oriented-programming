#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


//Prima problema
void inlocuirePare(int* v, int n) {
    for (int i = 0;i<n;i++) { //test
        if (v[i]%2==0)
            v[i] = 0;
    }
}
//A doua problema
int* dublarePare(int* v, int n, int *cntPare) {
    (*cntPare) = n;
    for (int i = 0;i<n;i++) {
        if (v[i]%2==0)
            (*cntPare)++;
    }
    int *aux = (int*)malloc((*cntPare)*sizeof(int));
    int j = 0;
    for (int i = 0;i<n;i++) {
        aux[j++]= v[i];
        if (v[i]%2==0)
            aux[j++] = v[i];
    }
    return aux;
}
// A treia problema
void deletePare(int*v, int *n) {
    int j = 0;
    for (int i = 0;i<(*n);i++) {
        if (v[i]%2!=0)
        v[j++] = v[i];
    }
    (*n)=j;
}

int main() {
    int n;
    cin >> n;
    int* v = (int*)malloc(n*sizeof(int));
    for (int i = 0;i<n;i++) {
        cin >> v[i];
    }

    //De comentat pentru celelalte functi
    // inlocuirePare(v,n);
    // for (int i = 0;i<n;i++) {
    //     cout << v[i] << ' ';
    // }

    cout << "\n\n\n";
    int cntPare;
    int* dubluPare = dublarePare(v,n,&cntPare);
    for (int i = 0;i<cntPare;i++) {
        cout << dubluPare[i] << ' ';
    }
    // cout << "\n\n\n";
    // deletePare(v,&n);
    // for (int i = 0;i<n;i++)
    //     cout << v[i] << ' ';

    free(dubluPare);
    free(v);
}