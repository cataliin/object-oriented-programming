#include <iostream>

using namespace std;


class Ingredient {
protected:
	const int cod;
	string denumire = "Anonim";
	unsigned int stoc = 0;
	bool esteAlergen = false;
public:
	Ingredient() :cod(0) {}

	Ingredient(int _cod):cod(_cod){}

	Ingredient(int _cod, const string& _denumire, unsigned int _stoc, bool _esteAlergen):cod(_cod),denumire(_denumire),stoc(_stoc),esteAlergen(_esteAlergen){
	}

	Ingredient(const Ingredient& i):cod(i.cod) {
			this->denumire = i.denumire;
			this->stoc = i.stoc;
			this->esteAlergen = i.esteAlergen;
	}

	Ingredient& operator=(const Ingredient& i) {
		if (this != &i) {
			this->denumire = i.denumire;
			this->stoc = i.stoc;
			this->esteAlergen = i.esteAlergen;
		}
		return *this;
	}

	Ingredient operator-(int val) {
		Ingredient aux = *this; //copy constructor
		if (aux.stoc >= val) {
			aux.stoc -= val;
		}
		else {
			throw logic_error("Nu poti avea un stoc negativ");
		}
		return aux;
	}

	Ingredient operator+(int val) {
		Ingredient aux = *this;
		aux.stoc += val;
		return aux;
	}

	const string& getDenumire() const{
		return this->denumire;
	}

	friend Ingredient operator+(int val, const Ingredient& i);

	friend ostream& operator<<(ostream& out, const Ingredient& i);

	~Ingredient() = default;
};

Ingredient operator+(int val, const Ingredient& i) {
	Ingredient aux = i;
	aux = aux + val;
	return aux;
}

ostream& operator<<(ostream& out, const Ingredient& i) {
	out << endl << i.cod;
	out << endl << i.denumire;
	out << endl << i.stoc;
	out << endl << i.esteAlergen;
	return out;
}

class Reteta {
private:
	Ingredient* lista = nullptr;
	int cnt = 0;
public:
	Reteta() {}

	Reteta(Ingredient* _lista, int _cnt) {
		this->cnt = _cnt;
		this->lista = new Ingredient[this->cnt];

		for (int i = 0; i < this->cnt; ++i) {
			this->lista[i] = _lista[i];
		}
	}

	bool operator!=(string denumireElement) {
		int ok = 0;
		for (int i = 0; i < this->cnt; ++i) {
			if (this->lista[i].getDenumire() == denumireElement) {
				ok = 1;
				break;
			}
		}
		return ok == 1 ? false : true;
	}

	string operator[](int idx) {
		if (this->cnt <= idx || idx < 0)
		{
			throw logic_error("Index-ul atasat nu este valid");
		}

		return this->lista[idx].getDenumire();
	}

	~Reteta() {
		if (this->lista != nullptr) {
			delete[] this->lista;
			this->lista = nullptr;
		}
	}
};

int main() {
	Ingredient i1(102, "Faina", 100, true);
	Ingredient i2(103, "Grau", 101, true);
	Ingredient i3(104, "Lapte", 10, true);
	Ingredient lista[3] = { i1,i2,i3 };
	Reteta r1(lista, 3);
	try {
		if (r1 != "Faina")
			cout << "\nIngredientul nu face parte din lista";
		else cout << "\nIngredientul face parte din lista";

		string ingredient = r1[2];
		cout << endl << ingredient;
	}
	catch (exception err) {
		cout << err.what();
	}
	//cout << i1;
	//Ingredient i2(101);
	////i1 = i2;
	////cout << endl << endl << i1;
	//try {
	//	i2 = i1 - 10;
	//	cout << endl << i2;
	//}
	//catch (exception err) {
	//	cout << err.what();
	//}
	//i2 = 100+i2;
	//cout << i2;
	return 0;
}