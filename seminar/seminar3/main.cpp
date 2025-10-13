#include <iostream>

using namespace std;

class Student {
    int codStudent;
    char nume[31];
    int nrNote;
    int* note;

public:
    //metode specifice
    //1. metode tip constructor

    //constructor default / fara param
    Student() {
        cout << "\n Apel constructor default";
        codStudent = 0;
        strcpy(nume, "Anonim");
        nrNote = 0;
        note = nullptr; // pe x64 -> ocupa 8 octeti
    }

    //metode accesor (get si set)
    //se ataseaza campurilor private
    void setCodStudent(int _codStudent) {
        //validari
        if (_codStudent > 0) {
            this->codStudent = _codStudent;
        }
    }

    int getCodStudent() {
        return this->codStudent;
    }

    void setNume(const char* _nume) {
        if (strlen(_nume) >= 5 && strlen(_nume) <=30) {
            strcpy(this->nume, _nume);
        }
    }

    // const char* getNumeGresit() {
    //     return this->nume;
    // }

    //tinand cont de INCAPSULARE
    char* getNume() {
        //se face  o copie a numelui la o alta adresa pentru a pazi adresa reala
        char* rez = new char[strlen(this->nume)+1];
        strcpy(rez, this->nume);
        return rez;
    } // cand iesim din functie se dezaolca zona de memorie si ne trebuie alocare dinamica;
};

int main() {

    /*
     * pana la lucrare (sapt 5):
     * clasa + constructori (fara parm + toti param)
     * get si set (meth accesor)
     */

    Student s; // o clasa contine implicit constructorul default ; constructor ->
    // aloca pe stiva spatiu pentru variabilele clasei
    s.setCodStudent(67);
    cout << '\n' << s.getCodStudent();
    cout << '\n';
    s.setNume("Ionescu Gigel");
    cout << endl;
    char* nume = s.getNume();
    cout << endl << nume;
    delete[] nume;

    // char* sir = (char*)s.getNume();
    // strcpy(sir, "papa gigigel");
    // cout << endl << sir;

    // s.codStudent = 100;
    // strcpy(s.nume, "Gigel");
    // s.nrNote = 3;
    // s.note = new int[s.nrNote];
    // s.note[1] = 10;
    // s.note[2] = 6;
    // s.note[2] = 8;


    return 0;
}