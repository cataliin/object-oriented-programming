#include<iostream>
using namespace std;

//met virtuale
//met virtuale pure
//clase abstracte -> clasa care contine cel putin o met virtuala pura
//interfete -> clasa abstracta care contine doar metode virtuale pure

//depend upon the abstract, DO NOT depend upon the concrete
//open-closed principle => many client specific interfaces are better than
//one general interface



class Printable {

};
//Home de facut toString ca in java
class Showable {
public:
    virtual void displayInfo() = 0;

};

class Payable {
public:
    virtual float calculSalariu() = 0;
};

class Angajat : public Payable{ //metoda abstracta

protected:
    string nume = "Anonim";
    float salariuBaza = 0;

public:
    void displayInfo() {
        cout << "\nAfisare angajat";
    }
    Angajat() {

    }

    Angajat(string _nume) {
        this->nume = _nume;
    }

    Angajat(string _nume, float _salariuBaza) {
        this->nume = _nume;
        this->salariuBaza = _salariuBaza;
    }

    Angajat(const Angajat& a) {
        this->nume = a.nume;
        this->salariuBaza = a.salariuBaza;
    }

    Angajat& operator=(const Angajat& a) {
        if (this != &a) {
            this->nume = a.nume;
            this->salariuBaza = a.salariuBaza;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Angajat& a);

    // virtual float calculSalariu() = 0; //metoda virtuala pura

    virtual float calculSalariu() { //virtual function pointer
        //pp ca exista o regula complexa de calcul salariu
        return this->salariuBaza;
    }



    ~Angajat() {
    }
};

ostream& operator<<(ostream& out, const Angajat& a) {
    out << "\nNume: " << a.nume;
    out << "\nSalariu baza: " << a.salariuBaza;
    return out;
}

class Manager: public Angajat {
    int nrSub=0;
public:
    Manager(string _nume, float _salariuBaza, int _nrSub): Angajat(_nume, _salariuBaza) {
        this->nrSub = _nrSub;
    }

    float calculSalariu() override{
        // return this->salariuBaza + this->nrSub*100;
        return Angajat::calculSalariu() + this->nrSub * 100;
    }


    friend ostream& operator<<(ostream& out, const Manager& m);
};

ostream& operator<<(ostream& out, const Manager& m) {
    out << (Angajat&)m;
    out << "\nNr subordonati: " << m.nrSub;
    return out;
}

class Lucrator: public Angajat {
    int nrNoptiLucrate = 0;
public:
    Lucrator(string _nume, float _salariuBaza, int _nrNoptiLucrate): Angajat(_nume, _salariuBaza) {
        this->nrNoptiLucrate = _nrNoptiLucrate;
    }

    float calculSalariu() override{
        // return this->salariuBaza + this->nrSub*100;
        return Angajat::calculSalariu() + this->nrNoptiLucrate * 50;
    }

    friend ostream& operator<<(ostream& out, const Lucrator& m);
};

ostream& operator<<(ostream& out, const Lucrator& m) {
    out << (Angajat&)m;
    out << "\nNr subordonati: " << m.nrNoptiLucrate;
    return out;
}

//clasa Companie in relatie de has a cu Angajat

int main() {
    Angajat a1("Angajatul Gigel", 1000);
    Manager m1 ("Manager Gigel", 1000,10);
    Lucrator l1("Lucrator Gigel", 1000, 5);
    // cout << l1.calculSalariu();
    cout << "\nSalariu Angajat: " << a1.calculSalariu();
    cout << "\nSalariu Manager: " << m1.calculSalariu();
    cout << "\nSalariu Lucrator: " << l1.calculSalariu();

    //calculam fondul necesar de salarii
    float totalSalarii = 0;
    Angajat v[] = {a1,m1,l1};
    for (int i = 0;i<3;++i) {
        totalSalarii+= v[i].calculSalariu();
    }
    cout << endl << totalSalarii;

    float totalSalarii2 = 0;
    Angajat* pointer;
    pointer = new Manager(m1);
    Angajat* vp[] = {&a1,&m1,&l1};
    for (int i = 0;i<3;++i) {
        totalSalarii2+= vp[i]->calculSalariu();
    }
    cout << endl << totalSalarii2;
    //polimorfism tare -> la runtime
    //polimorfism slab -> avem cel putin 2 metode de ales
    return 0;
//HOME2 : de transformat vectorul de pointeri din main in clasa companie, care e in relatie
    //has a cu familia de clase (angajat,manager,lucrator)
}