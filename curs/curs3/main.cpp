#include <iostream>
using namespace std;

class salariat {
    int marca;
    char nume[20];
    int ol;
    int os;

    static int genm;

public:
    //constructor implicit
    salariat() : marca(0), ol(0), os(0)
    {
        genm++;
        strcpy(nume, "Zorro");
    }

    //constructor explicit
    salariat(const char* fnume, int fol, int fos) : marca(genm), ol(fol), os(fos)
    {
        genm++;
        strcpy(nume, fnume);
    }

    void Afisare()
    {
        cout << marca << " " << nume << " " << ol << " " << os << endl;
    }

    int get_marca() { return marca; }

    static int Marca_urm_sal() { return genm;}


    ~salariat() { cout << "Destructor!!!" << endl; }
};

int salariat::genm = 100;

int main()
{
    cout << "Marca urm. obiect: " << salariat::Marca_urm_sal() << endl;
    salariat s1, s2("Mirel", 12, 15), * ps;
    cout << "Marca urm. obiect: " << ps->Marca_urm_sal() << endl;
    s1.Afisare();
    s2.Afisare();
    //aici s au terminat duratele de viata pt s1 si s2 deci vedem mesajul destructor
    ps = new salariat("Gigi", 50, 12.5);
    cout << "Marca urm. obiect: " << salariat::Marca_urm_sal() << endl;
    ps->Afisare();
    //salariatul alocat dinamic trebuie dezalocat manual :(
    delete ps;

    return 0;
}