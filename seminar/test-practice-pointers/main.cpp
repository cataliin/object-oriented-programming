#include <iostream>
#include <memory>


class Student {
private:
    std::string nume;
    int nrNote;
    std::unique_ptr<int[]>note;
    float buget;
public:
    Student() {
        this->nume = "anonim";
        this->nrNote = 0;
        this->note = nullptr;
        this->buget = 0;
    }
    Student(const std::string& _nume, int _nrNote, const int* _note, float _buget) {
        this->nume = _nume;
        if (_nrNote > 0) {
            this->nrNote = _nrNote;
            this->note = std::make_unique<int[]>(this->nrNote);
            for (int i = 0;i < this->nrNote;i++)
                this->note[i] = _note[i];
        }
        this->buget = _buget;
    }

    std::unique_ptr<int[]> getNote() const {
        std::unique_ptr<int[]> noteCopie = std::make_unique<int[]>(this->nrNote);
        for (int i = 0;i < this->nrNote;i++)
            noteCopie[i] = this->note[i];
        return noteCopie;
    }// daca returnam std::move(this->note) caller-ul are acces la date interne;

    const int* getNote1() const {
        return this->note.get();
    }

    int getNrNote() const {
        return this->nrNote;
    }
};

int main() {
    int myGrades[] {10, 8, 7, 5};
    int cntNote = 4;
    Student s1("Catalin", cntNote,myGrades,400);
    const int* gr = s1.getNote1();
    for (int i = 0;i<4;i++)
        std::cout << gr[i] << ' ';
    std::unique_ptr<int[]>gr1 = s1.getNote();
    for (int i = 0;i<s1.getNrNote();i++)
        std::cout << gr1[i] << ' ';

    gr1[1] = 15;
    for (int i = 0;i<s1.getNrNote();i++)
        std::cout << gr1[i] << ' ';
    gr1 = s1.getNote();
    std::cout << std::endl;
    for (int i = 0;i<s1.getNrNote();i++)
        std::cout << gr1[i] << ' ';
    return 0;
}