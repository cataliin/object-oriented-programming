#include <iostream>

using namespace std;
namespace MyData {

	template <typename T>
	class Vector {
	private:
		static int idUnic;
		int id;
		T* el;
		int dim;
	public:
		Vector() : id(idUnic++), dim(1) {
			this->el = new T[this->dim] {(T)0};

		}

		Vector(int _dim, T* _el) : id(idUnic++) {
			if (_dim > 0) {
				this->dim = _dim;
				this->el = new T[this->dim];
				for (int i = 0; i < this->dim; ++i) {
					this->el[i] = _el[i];
				}
			}
			else {
				this->dim = 1;
				this->el = new T[this->dim] {(T)0};
			}

		}

		Vector(const Vector& v) : id(idUnic++), dim(v.dim) {
			this->el = new T[this->dim];
			for (int i = 0; i < this->dim; ++i) {
				this->el[i] = v.el[i];
			}

		}

		Vector& operator=(const Vector& v) {
			if (this == &v)
				return *this;
			if (this->el != nullptr) {
				delete[] this->el;
				this->el = nullptr;
			}
			this->dim = v.dim;
			this->el = new T[this->dim];
			for (int i = 0; i < this->dim; ++i) {
				this->el[i] = v.el[i];
			}

			return *this;
		}

		void setElemente(T val) {
			for (int i = 0; i < this->dim; ++i) {
				this->el[i] = val;
			}
		}

		operator int() const {
			return this->dim;
		}

		T& operator[](int idx) {
			if (idx >= 0 && idx < this->dim)
				return this->el[idx];

			throw out_of_range("Elementul cautat nu are index valid");
		}

		T operator[](int idx) const {
			if (idx >= 0 && idx < this->dim)
				return this->el[idx];

			return T();
		}

		friend ostream& operator<<(ostream& out, const Vector<T>& v) {
			{
				out << "\nID: " << v.id;
				out << "\nDimensiunea este : " << v.dim;
				out << "\nElementele vectorului sunt : ";
				for (int i = 0; i < v.dim; ++i) {
					cout << v.el[i] << ' ';
				}
				return out;
			}
		}

		~Vector() {
			if (this->el != nullptr) {
				delete[] this->el;
				this->el = nullptr;
			}
		}
	};

	template <typename T>
	int Vector<T>::idUnic = 1;

	template <typename T>
	class Matrix {
	private:
		Vector<T>* linii;
		int nrLin;
		int nrCol;
	public:
		Matrix(int r, int c) :nrLin(r), nrCol(c) {
			linii = new Vector<T>[r];

			T* aux = new T[c]{};
			Vector<T> templateRow(c, aux);
			delete[] aux;
			aux = nullptr;
			for (int i = 0;i<r;++i) {
				linii[i] = templateRow;
			}
		}

		~Matrix() {
			delete[] linii;
		}
	};
}
int main() {
	MyData::Vector<double> v1;
	std::vector<double> vectorC; //pot avea 2 tipuri de vector, si al meu si c++

	cout << v1;
	MyData::Vector<double> v2(3, new double[3] {1.2, 2.5, 7.4});
	cout << v2;
	MyData::Vector<double> v3 = v2;
	//cout << "\n============";
	//cout << v3 << endl << endl;
	//cout << v2;
	//cout << "\n==============";

	//v2.setElemente(0);
	//cout << v2;

	/*int size = v2;
	cout << endl << size;*/

	// cout << "\nElement: \n";
	// cout << v2[0];
	// v2[0] = 6.7;
	// cout << "\nElement: \n";
	// cout << v2[0]'
	return 0;
}