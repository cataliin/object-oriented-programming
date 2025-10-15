#include <iostream>

using namespace std;

class Pet {
protected:
    string name;
    int age;
    static int petCount;
public:
    Pet() : name("Anonim"), age(0) {
        petCount++;
    }

    Pet(const string& _name, int _age) : name(_name), age(_age) {
        petCount++;
    }

    virtual void makeSound() {
        cout << this->name << " made a sound" << endl;
    }

    void eat() {
        cout << this->name << " just ate" << endl;
    }

    string getName() const {
        return this->name;
    }

    int getAge() const {
        return this->age;
    }

    static int getPetCount() {
        return petCount;
    }
    ~Pet() {
        petCount--;
        cout << this->name << " has been deleted" << endl;
    }
};

int Pet::petCount = 0;

class Dog : public Pet {
public:
    Dog(const string& name, int age): Pet(name,age){}

    void makeSound() override {
        cout << this->name << " just said WOOF WOOF !" << endl;
    }

    void fetch() const {
        cout << this->name << " just fetched a stick" << endl;
    }
};

int main() {
    Pet p1("carcotas",15);

    cout << p1.getName() << endl;
    p1.makeSound();
    p1.eat();
    cout << endl << p1.getPetCount();
    cout << endl;

    Dog d1("Strabism", 15);

    cout << d1.getPetCount() << endl;
    d1.makeSound();
    d1.fetch();

    Pet* pet1 = &d1;
    pet1->makeSound();

    return 0;
}