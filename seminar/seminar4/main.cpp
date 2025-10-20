#include <iostream>

using namespace std;

class Student {
    string nume;
    int nrNote;
    int* note;
    double buget;

    //ex de meth private
    // bool esteNota(int _nota) {
    //     return true;
    // }
    //
    // bool esteIndex(int _index) {
    //     return true;
    // }

public:
    //constructor fara param
    Student() {
        cout << "\nApel constructor fara param";
        this->nume = "Anonim";
        this->nrNote = 0;
        this->note = nullptr;
        this->buget = 0;
    }
    //constructor cu 1 param
    Student(double _buget) {
        cout << "\nApel constructor cu un param";
        this->nume = "Anonim";
        this->nrNote = 0;
        this->note = nullptr;
        if (_buget >0) {
            this->buget = _buget;
        }
        else {
            this->buget = 0;
        }
    }
    //constructor cu toti parametrii
    Student(const char* _nume, int _nrNote, int* _note, double _buget) { //pot pune char* chiar daca e string
        //ne trebuie const char pentru a putea apela Student("Gigel"...)
        if (strlen(_nume) >=3) {
            this->nume = _nume;
        }else {
            this->nume = "Anonim";
        }
        if (_nrNote > 0 && _note != nullptr) {
            this->nrNote = _nrNote;
           // this->note = _note; //shallow copy -> copiere superficiala |
            //deep copy -> copiere care nu mai depinde deloc de obiectul pe care l-am copiat
            this->note = new int[this-> nrNote];
            for (int i = 0;i<this->nrNote;i++) {
                this-> note[i] = _note[i];
            }
        }
        else {
            this->nrNote = 0;
            this->note = nullptr;
        }
        if (_buget >0) {
            this->buget = _buget;
        }
        else {
            this->buget = 0;
        }

    }
    //get si set pentru note
    void setNote(int* _note, int _nrNote) {
        if (_note != nullptr && _nrNote > 0) {
            //obj spre care pointeaza this deja exista
            delete[] this->note;
            this->note = nullptr;
            this-> nrNote=0;

            this->nrNote = _nrNote;
            this->note = new int[this-> nrNote];
            for (int i = 0;i<this->nrNote;i++) {
                this-> note[i] = _note[i];
            }
        }
        else {
            // depinde de specificatii
        }
    }

    void setNota(int _nota, int _index) {
        if (_index >=0 && _index < this->nrNote)
            if (_nota >= 1 && _nota <=10) {
                this->note[_index] = _nota;
            }
    }

    int* getNote() {
        //dar de facut o copie a vectorului de note ca sa pastram incapsulare
        return nullptr;
    } //TEMA

    int getNota(int _index) {
        if (_index >=0 && _index < this->nrNote) {
            return this->note[_index];
        }

        return 0;
    }
    int getNrNote() {
        return true;
    } //TEMA

    //meth de afisare
    void afisare() const { // nu ne modifica obiectu this IMPORTANT pt getters
        cout << "\n-------------";
        cout << "\nNume: " << this->nume;
        cout << "\nNumar note: " << this->nrNote;
        cout << "\nNotele: ";
        for (int i = 0;i<this->nrNote;i++)
            cout << this->note[i] << ' ';
        cout << "\nBuget: " << this->buget;
        cout << "\n-------------";
    }

};

int main() {

    // Student s;
    // Student s2[5]; // 5 * sizeof(student)
    // Student* ps;
    // ps = &s;
    // ps = new Student();
    // Student s3(); // nu apeleaza constructorul, este o greseala
    // Student* ps2[5]; // vector de pointeri la obj de tip Obiect, ocupa 8 bytes, depinzand de sistem
    // Student s4(2); // se apeleaza constructoru cu un parametru
    // Student s5 = 2; // apelator cu un parametru
    // Student *ps3;
    // Student *ps4;
    // ps3 = new Student[5];
    // ps3 = new Student(5);
    int note[]{10,7,4};
    Student s6("Gigel", 3, note,120);
    s6.afisare();


    return 0;
}
