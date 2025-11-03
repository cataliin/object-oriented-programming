#include<iostream>
using namespace std;

//atribut constant + atribut static

class Student {
	string nume;
	int nrNote;
	int* note;
	double buget;
	static double taxaRestanta;

public:
	Student() {
		cout << "\nApel constructor fara param";
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		this->buget = 0;
	}

	Student(double _buget) {
		cout << "\nApel constructor cu 1 param";
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
		if (_buget > 0) {
			this->buget = _buget;
		}
		else {
			this->buget = 0;
		}
	}

	Student(const char* _nume, int _nrNote,
		int* _note, double _buget) {
		cout << "\nApel constructor cu toti param";
		if (strlen(_nume) >= 3) {
			this->nume = _nume;
		}
		else {
			this->nume = "Anonim";
		}
		if (_nrNote > 0 && _note != nullptr) {
			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				this->note[i] = _note[i];
			}
		}
		else {
			this->nrNote = 0;
			this->note = nullptr;
		}
		if (_buget > 0) {
			this->buget = _buget;
		}
		else {
			this->buget = 0;
		}
	}

	//home -> chiar daca e const, ce nu e protejat din s
	Student(const Student& s) {
		cout << "\nApel constructor copiere";
		this->nume = s.nume;

		if (s.nrNote > 0 && s.note != nullptr) {
			this->nrNote = s.nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				this->note[i] = s.note[i];
			}
		}
		else {
			this->nrNote = 0;
			this->note = nullptr;
		}
			this->buget = s.buget;

	}

	void setNote(int* _note, int _nrNote) {
		if (_note != nullptr && _nrNote > 0) {
			delete[] this->note;
			this->note = nullptr;
			this->nrNote = 0;

			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				this->note[i] = _note[i];
			}
		}
		else {

		}
	}

	void setNota(int _nota, int _index) {
		if (_index >= 0 && _index < this->nrNote) {
			if (_nota >= 1 && _nota <= 10) {
				this->note[_index] = _nota;
			}
		}
	}

	int getNota(int _index) {
		if (_index >= 0 && _index < this->nrNote) {
			return this->note[_index];
		}
	}

	int getNrNote() {
		return this->nrNote;
	}

	void afisare() const {
		cout << "\n-------------";
		cout << "\nNume: " << this->nume;
		cout << "\nNr note: " << this->nrNote;
		cout << "\nNote: ";
		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << " ";
		}
		cout << "\nBuget: " << this->buget;
		cout << "\n-------------";
	}

	Student& operator=(const Student& s) {
		//obj this deja exista
		//destructor + constructor de copiere
		cout << endl << "Operator egal" << endl;
		if (this!=&s) { // fara if, la auto-asignare imi sterge vectorul de note
			if (this->note != nullptr) {
				delete[] this->note;
				this->note = nullptr;
			}

			this->nume = s.nume;

			if (s.nrNote > 0 && s.note != nullptr) {
				this->nrNote = s.nrNote;
				this->note = new int[this->nrNote];
				for (int i = 0; i < this->nrNote; i++) {
					this->note[i] = s.note[i];
				}
			}
			else {
				this->nrNote = 0;
				this->note = nullptr;
			}
			this->buget = s.buget;
		}
		return *this;
	}

	static double getTaxaRestanta() {
		return Student::taxaRestanta;
	}

	static void setTaxaRestanta(double _taxaRestanta) {
		if (_taxaRestanta > 0) {
			Student::taxaRestanta = _taxaRestanta;
		}
	}

	~Student() {
		cout << "\nApel destructor";
		if (this->note != nullptr) {
			delete[] this->note;
			this->note = nullptr;
		}
	}
};

double Student::taxaRestanta = 100;

Student f1(Student s) {
	return s;
}

Student f2(Student s[10], int n) {
	return s[0];
}

Student f3(Student s) {
	Student aux;
	//..
	return aux;
}

//CRAPA
// !!!!GRIJA la ce se returneaza
Student& f4() {
	static Student aux; // cu static evitam sa crape aici si se face variabila globala
	//...
	return aux; // aici se apeleaza destructorul si s-a distrus si functia returneaza o adresa distrusa
}

Student functie() {
	return Student();
}

int main() {
	int note[]{ 10,7,4 };
	int note2[]{ 9,9,9,9 };
	Student s1("Gigel", 3, note, 120);
	Student s4("Costel", 4, note2, 999);
	s1.afisare();

	Student s2 = s1;
	Student s3(s1);
	s2.afisare();

	//constructor de copiere
	//op =
	//destructor
//	s2 = s3; // operatorul = creeaza un nou obiect si nu si initializeaza
//	s2.operator=(s3);

	s1 = s4;
	s1.operator=(s4);
	s1.afisare();
	s2 = s1 = s4; //apel in cascada/ in compunere

	s1=s1; //auto-asignare
	s1.afisare();




	//copy elision (nu se realizeaza copierea si distrugerea obj care se returneaza prin valoare) -> de uitat acasa

	cout << "\n===========================";

	Student s5 = functie();

	cout << "\n===========================";

	cout << "\n============end===============";

	 s5 = functie();

	cout << "\n==============atribut static=============";

	cout << "\nTaxa restanta: " << Student::getTaxaRestanta();
	Student::setTaxaRestanta(150);
	cout << "\nTaxa restanta: " << Student::getTaxaRestanta();

	//REGULI SUPRAINCARCARE OPERATORI

	/*
	P1. identificare tip operanzi
	P2. daca primul operand este de tipul clasei, atunci supraincarcarea se poate realiza printr-o metoda a clasei,
	iar primul operand este inghitit de this
	Daca primul operand NU este de tipul clasei, atunci OBLIGATORIU se supraincarca prin functie globala
	P3. ce returneaza operatorul???
	P4. se modifica this? sau alti operanzi
	*/

	// Student* ps = new Student(); -> asa se apeleaza constructoru de mai multe ori decat destructoru
	// delete ps; -> asa se apeleaza destructoru
	return 0;
}