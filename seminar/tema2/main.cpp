#include <iostream>
#include <string>

using namespace std;

void elimKElem(int *&v, int& n, int k) {
    if (v == nullptr) {
        cout << "vectorul este nul\n";
        return;
    }
    if (k >= n || k < 0) {
        cout << "k trebuie sa fie pozitiv si mai mic decat n\n";
        return;
    }
    int* aux = new int[n-k];
    int j = 0;
    for (int i = k;i<n;i++) {
        aux[j++] = v[i];
    }
    delete[] v;
    v = aux;
    n -= k;
}

void dublareKElem(int *&v, int &n, int k) {
    if (v == nullptr) {
        cout << "vectorul este nul\n";
        return;
    }
    if (k >= n || k <0) {
        cout << "k trebuie sa fie pozitiv si mai mic decat n\n";
        return;
    }
    int* aux = new int[n+k];
    int j = 0;
    for (int i = 0; i<n;i++) {
        aux[j++]=v[i];
        if (i < k) {
            aux[j++] = v[i];
        }
    }
    delete[] v;
    v = aux;
    n +=k;
}

int cntPrenume(string* nume, int n, string& prenume) {
    int cnt = 0;
    for (int i = 0;i<n;i++) {
        int poz = -1;
        for (int j = 0;j<nume[i].length(); j++) {
            if (nume[i][j] == ' ') {
                poz = j;
                break;
            }
        }
        if (poz != -1) {
            string prenumeGasit = nume[i].substr(poz+1);
            if (prenumeGasit == prenume)
                cnt++;
        }
    }
    return cnt;
}

int main() {
    // int n;
    // cin >> n;
    // if (n<= 0) {
    //     cout << "n trebuie sa fie pozitiv si nenul";
    //     return 0;
    // }
    // int* v = new int[n];
    // for (int i = 0;i<n;i++)
    //     cin >> v[i];
    // int k;
    // cin >> k;
    // // elimKElem(v,n,k);
    // dublareKElem(v,n,k);
    // for (int i = 0;i<n;i++)
    //     cout << v[i] << ' ';
    // delete[] v;

    //problema cu stringuri
    int n;
    cin >> n;
    cin.get();

    if (n <=0) {
        cout << "n trebuie sa fie pozitiv si nenul";
        return 0;
    }
    string* nume = new string[n];
    for (int i = 0;i<n;i++)
        getline(cin,nume[i]);

    string prenume;
    getline(cin, prenume);

    cout << cntPrenume(nume,n,prenume);
    delete[] nume;
    return 0;
}