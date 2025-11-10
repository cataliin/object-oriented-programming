#include <iostream>

using namespace std;

class figurag {
protected:
    int el;
    virtual float calcul_lungime() = 0;

public:
    figurag(int _el = 0):el(_el){}
    float getLungime() {
        return calcul_lungime();
    }
};

class patrat : public figurag {
    float calcul_lungime() override {return 4*el;}
public:
    patrat(int _lat):figurag(_lat){}
};

class triunghi : public figurag {
    int l2,l3;
    float calcul_lungime() override { // nu a pus la curs override, dar ii spune compilatorului sa se uite la base class
        return el+l2+l3;
    }
public:
    triunghi(int _l1, int _l2, int _l3):figurag(_l1),l2(_l2),l3(_l3){}

};


int main() {
    figurag *pobfg;

    patrat obp(10);
    triunghi obt(10,7,4);
    pobfg = &obp;
    cout << "Patrat : "<<pobfg->getLungime() << endl;
    pobfg = &obt;
    cout << "Triunghi : " << pobfg->getLungime() << endl;

    return 0;
}