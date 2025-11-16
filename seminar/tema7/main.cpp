#include <iostream>
#include <set>
#include <sstream>
#include <iomanip>
//Sa se implementeze clasa masina care detine numar inmatriculare si are un constructor
//care primeste un numar preferential
//constant este serie_sasiu, are si campul numar inmatriculare


static int generatorSerieSas=1000000;

std::string generateSerieSas() {
    std::ostringstream oss;
    oss << "SEM" << "OOP" << "25" << std::setw(9) << std::setfill('0') << generatorSerieSas++;

    return oss.str();
}

std::string generateNrInmatriculare() {
    std::ostringstream oss;
    static char lit1 = 'A';
    static char lit2= 'A';
    static char lit3='A';
    static int cnt = 1;
    static std::string judet = "B";

    oss << judet << "-" << std::setw(3) << std::setfill('0') << cnt << "-" <<lit1<<lit2<<lit3;
    cnt++;
    if (cnt > 999) {
        cnt = 1;
        lit3++;
        if (lit3 > 'Z') {
            lit3 = 'A';
            lit2++;
            if (lit2 > 'Z') {
                lit2= 'A';
                lit1++;
                if (lit1 > 'Z')
                    lit1='A';
            }
        }
    }
    return oss.str();
}

class Masina {
private:
    const std::string serieSas;
    std::string nume;
    std::string nrInmatriculare;
    static std::set<std::string> nrVazute;
public:
    Masina():
    serieSas(generateSerieSas()),nume("Anonim"),nrInmatriculare(generateNrInmatriculare()) {
        while (this->nrVazute.find(this->nrInmatriculare) != this->nrVazute.end()) {
            this->nrInmatriculare = generateNrInmatriculare();
        }
        this->nrVazute.insert(this->nrInmatriculare);
    }

    Masina(const std::string& _nume, const std::string& _nrPref):
    serieSas(generateSerieSas()), nume(_nume),nrInmatriculare(_nrPref) {
        if (this->nrVazute.find(_nrPref) != this->nrVazute.end()) {
            std::cout << "Numarul este deja folosit\n";
            this->nrInmatriculare = generateNrInmatriculare();
            while (this->nrVazute.find(this->nrInmatriculare) != this->nrVazute.end()) {
                this->nrInmatriculare = generateNrInmatriculare();
            }
        }
        this->nrVazute.insert(this->nrInmatriculare);
    }

    Masina(const std::string& _nume):
    serieSas(generateSerieSas()), nume(_nume),nrInmatriculare(generateNrInmatriculare()) {
        while (this->nrVazute.find(this->nrInmatriculare) != this->nrVazute.end()) {
            this->nrInmatriculare = generateNrInmatriculare();
        }
        this->nrVazute.insert(this->nrInmatriculare);
    }

    void afisare() const {
        std::cout <<"\n=========================";
        std::cout<< "\nSerie de sasiu : " << this->serieSas;
        std::cout << "\nMarca masinii : " << this->nume;
        std::cout << "\nNumarul de inmatriculare al masinii : " << this->nrInmatriculare;
        std::cout <<"\n=========================";
    }

};

std::set<std::string>Masina::nrVazute;

int main() {
    Masina m1;
    m1.afisare();
    Masina m2;
    m2.afisare();
    return 0;
}