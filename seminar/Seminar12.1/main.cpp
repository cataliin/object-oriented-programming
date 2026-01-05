#include<iostream>
#include <string>
using namespace std;
//Home de facut toString ca in java
class Showable {
public:
    virtual string toString() const = 0;
    virtual ~Showable(){}
    friend ostream& operator<<(ostream& out, const Showable& s);
};

class Payable {
public:
    virtual float calculSalariu() = 0;
};

class Angajat : public Payable, public Showable { //metoda abstracta

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

    virtual float calculSalariu() {
        return this->salariuBaza;
    }

    virtual string toString() const override{
        string newString = this->nume + " " + to_string(this->salariuBaza);
        return newString;
    }

    ~Angajat() {
    }
};


class Manager : public Angajat {
    int nrSub = 0;
public:
    Manager(string _nume, float _salariuBaza, int _nrSub) : Angajat(_nume, _salariuBaza) {
        this->nrSub = _nrSub;
    }

    float calculSalariu() override {
        // return this->salariuBaza + this->nrSub*100;
        return Angajat::calculSalariu() + this->nrSub * 100;
    }

    string toString() const override{
        return Angajat::toString() + " " + to_string(this->nrSub);
    }

};


class Lucrator : public Angajat {
    int nrNoptiLucrate = 0;
public:
    Lucrator(string _nume, float _salariuBaza, int _nrNoptiLucrate) : Angajat(_nume, _salariuBaza) {
        this->nrNoptiLucrate = _nrNoptiLucrate;
    }

    float calculSalariu() override {
        // return this->salariuBaza + this->nrSub*100;
        return Angajat::calculSalariu() + this->nrNoptiLucrate * 50;
    }

    string toString() const override{
        return Angajat::toString() + " " + to_string(this->nrNoptiLucrate);
    }
};


//clasa Companie in relatie de has a cu Angajat
class Companie {
private:
    string numeCompanie;
    Angajat** listaAngajati;
    int nrAngajati;
    int capacitate;
public:
    Companie(string _numeCompanie) {
        this->numeCompanie = _numeCompanie;
        this->nrAngajati = 0;
        this->capacitate = 10;
        this->listaAngajati = new Angajat*[capacitate];
    }

    void adaugaAngajat(Angajat* a) {
        if (nrAngajati < capacitate) {
            listaAngajati[nrAngajati++] = a;
        }
        else {
            throw logic_error("Capacitate maxima atinsa");
        }
    }

    float calculTotalSalarii() {
        float total = 0;
        for (int i = 0; i < nrAngajati; ++i) {
            total += listaAngajati[i]->calculSalariu();
        }
        return total;
    }

    void afiseazaAng() {
            cout << "\n --- AFISARE COMAPNEI ----";
        for (int i = 0; i < this->nrAngajati; ++i) {
            cout << *listaAngajati[i];

        }
        cout << "\n------------------------";
    }


    ~Companie() {
        if (listaAngajati != nullptr) {
            delete[] listaAngajati;
        }
    }
};

ostream& operator<<(ostream& out, const Showable& s) {
    out << "\n" << s.toString();
    return out;
}


int main() {
    Angajat a1("Angajatul Gigel", 1000);
    Manager m1("Manager Gigel", 1000, 10);
    Lucrator l1("Lucrator Gigel", 1000, 5);

    Companie pg("P&G");
    try {
        pg.adaugaAngajat(&a1);
        pg.adaugaAngajat(&m1);
        pg.adaugaAngajat(&l1);
        cout << "Total salarii : " << pg.calculTotalSalarii();
        cout << endl;

        pg.afiseazaAng();
    }
    catch (exception err) {
        cout << err.what();
    }
    return 0;
}