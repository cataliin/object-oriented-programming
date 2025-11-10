#include <iostream>

using namespace std;

class Salariat {

};

class Firma {
    Salariat* vs[100];
    int nrs;
    string numef;
public:
    Firma(const string& _nf="Nedefinit"):numef(_nf),nrs(0){}
    Firma& operator<<(Salariat *obs) {
        vs[nrs++] = obs;
        return *this;
    }
};

int main() {

    Firma obf;
    obf << new Salariat() << new Salariat() << new Salariat();
    return 0;
}