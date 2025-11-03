#include <iostream>

using namespace std;

//polymorphism // mostenire

class ProdR {
protected: // se comporta ca private, doar ca mosteneste
    string np;
    int cm,cs,p;
    float pret;
    virtual void calcul_pret() { //se uita la this si stie ce clasa e
        pret=cm+cs+p;//se creeaza un vector de pointeri si se ingreuneaza memoria si timpul de rulare
    }
public:
    ProdR():np("nedefinit"),cm(0),cs(0),p(0){}

    ProdR(const string& _np,int _cm, int _cs, int _p):np(_np),cm(_cm),cs(_cs),p(_p){}

    friend ostream& operator<<(ostream &os, ProdR* obp) {
        // daca am un obiect de clasa de baza, se poate manipula si un
        //obiect de clasa derivata din cea de baza, dar invers nu (de asta merge aici sa dau si pe obiect derivat cout)
        obp->calcul_pret();
        os << "Produsul " << obp->np << " are pretul: " << obp->pret << endl;
        return os;
    }

};

class ProdA : public ProdR { // daca pui doar ProdR, atunci o ia implicit privata
    int ac;

    void calcul_pret() {
        ProdR::calcul_pret();
        pret+=ac;
    }

public:
    ProdA(): ac(0){}

    ProdA(const string& _np,int _cm, int _cs, int _p, int _ac):
    ProdR(_np,_cm,_cs,_p),ac(_ac){}

};
int main() {

    ProdR* po1, *po2; //pointerul poate sa fie de clasa de baza
    po1 = new ProdR("Tabla", 100,20,5);
    ProdR ob1("Tabla", 100,20,5);
    po2 = new ProdA("Tigla",180,25,5,10); //pointerul de clasa de baza poate primi adresa de obiect derivat

    cout << po1 << po2;

    delete po1,po2;
    return 0;
}