#include <bits/stdc++.h>
using namespace std;

class Persoana{
protected:
    string nume;
    string cnp;

public:
    Persoana(){ //constructor fara parametri
        nume = "";
        cnp = "";
    }

    Persoana(string nm, string cn)  //constructor cu parametrii
    {
        nume = nm;
        cnp = cn;
    }

    ~Persoana() //destructor
    {
        nume = "";
        cnp = "";
    }

    Persoana(Persoana& c)
    {
        nume = c.nume;
        cnp = c.cnp;
    }

    Persoana &operator=(const Persoana &c)
    {
        this->nume = c.nume;
        this->cnp = c.cnp;
        return *this;
    }

    friend istream& operator>>(istream& in,Persoana& a);
    friend ostream& operator<<(ostream& out,Persoana& a);

    setnume(string Nume){
        nume = Nume;
    }
    string getnume(){
        return this->nume;
    }

    setcnp(string CNP){
        cnp = CNP;
    }
    string getcnp(){
        return this->cnp;
    }

    virtual void fvirt(){
        cout << "In acest moment ne aflam in clasa persoanei";
    }
};



inline istream& operator>>(istream& in, Persoana& a){
        in>>a.nume;
        in>>a.cnp;
        return in;
}

inline ostream& operator<<(ostream& out,Persoana& a){
        out<<"Datele persoanei sunt: "<<endl;
        out<<"Nume: "<<a.nume;
        out<<endl;
        out<<"Cnp: "<<a.cnp;
        return out;
}


class Abonat :public Persoana{
protected:
    int nrMaxCarti, nrCartiImprumutate, pretAbonament;
public:
    Abonat():Persoana(){
        nrMaxCarti = 0;
        nrCartiImprumutate = 0;
        pretAbonament = 0;
    }
    Abonat(string nm,string cn,int mx,int impr, int pret):Persoana(nm,cn){
        if(impr > mx || pret > mx)
        {
            cout<<"Date invalide";
        }
        else
        {
            nrMaxCarti = mx;
            nrCartiImprumutate = impr;
            pretAbonament = pret;
        }
    }
    ~Abonat(){
        nrMaxCarti = 0;
        nrCartiImprumutate = 0;
        pretAbonament = 0;

    }
    Abonat(Abonat& c):Persoana(c){
        nrMaxCarti = c.nrMaxCarti;
        nrCartiImprumutate = c.nrCartiImprumutate;
        pretAbonament = c.pretAbonament;
    }
    friend istream& operator>>(istream& in,Abonat& a);
    friend ostream& operator<<(ostream& out,Abonat& a);

    setmaxcarti(int x){
        nrMaxCarti = x;
    }
    int getmaxcarti(){
        return this -> nrMaxCarti;
    }

    setimprumutate(int x){
        nrCartiImprumutate = x;
    }
    int getimprumutate(){
        return this -> nrCartiImprumutate;
    }

    setpret(int x){
        pretAbonament = x;
    }
    int getpretabonament(){
        return this -> pretAbonament;
    }

    Abonat &operator=(const Abonat &c)
    {
        Persoana::operator=(c);

        this->nrMaxCarti = c.nrMaxCarti;
        this->pretAbonament = c.pretAbonament;
        this->nrCartiImprumutate = c.nrCartiImprumutate;

        return *this;
    }

    void fvirt(){
        cout << "In acest moment ne aflam in clasa Abonat";
    }
};

inline istream& operator>>(istream& in, Abonat& a){
        in>>a.nume>>a.cnp;
        in>>a.nrMaxCarti>>a.nrCartiImprumutate>>a.pretAbonament;
        if(a.nrCartiImprumutate > a.nrMaxCarti || a.pretAbonament > a.nrMaxCarti)
            cout<<endl<<"Date invalide"<<endl<<endl;
        return in;
}

inline ostream& operator<<(ostream& out,Abonat& a){
        out<<"Datele persoanei sunt: "<<endl;
        out<<"Nume: "<<a.nume<<endl;
        out<<"CNP: "<<a.cnp<<endl;
        out<<"Max Carti: "<<a.nrMaxCarti;
        out<<endl;
        out<<"Carti imprumutate: "<<a.nrCartiImprumutate;
        out<<endl;
        out<<"Pretul abonamentului: "<<a.pretAbonament;
        return out;
}

class Dosar: public Abonat{
    int nr;
    Abonat *v;
    static int numar_imprumutate10;
public:
    Dosar(){
        nr = 0;
        v = new Abonat[200];
    }
    Dosar(Abonat a[200],int n)
    {
        nr = n;
        for(int i=1;i<=n;i++)
        {
            v[i] = a[i];
            if(a[i].getimprumutate()>=10)
            {
                numar_imprumutate10++;
            }
        }
    }
    ~Dosar(){
        delete []v;
        nr = 0;
        v = nullptr;
    }
    setabonat(Abonat x)
    {
        if(x.getimprumutate() <= x.getmaxcarti() && x.getpretabonament() <= x.getmaxcarti())
        {
            nr = nr + 1;
            v[nr] = x;
            if(x.getimprumutate()>=10)
                numar_imprumutate10++;
        }

    }

    Abonat getabonat(int i)
    {
        return v[i];
    }
    setnr(int x)
    {
        nr = x;
    }
    int getnr(){
        return nr;
    }
    void afisare(){
        if(nr!=0)
            cout<<"Datele abonatilor din dosar sunt: "<<endl<<endl;
        else
            cout<<endl<<"Dosarul este gol";
        int i;
        for(i=1;i<=nr;i++)
        {
            cout<<v[i];
            cout<<endl<<endl;
        }
    }

    Dosar &operator=(const Dosar &c)
    {
        Abonat::operator=(c);
        this -> nr = c.nr;
        for(int i=1;i<=c.nr;i++)
        {
            this -> v[i] = c.v[i];
        }
        return *this;
    }

    setnr10(int x)
    {
        numar_imprumutate10 = x;
    }
    static int getnr10(){
        return numar_imprumutate10;
    }

    void aflare(string cp)
    {
        int ok=1,i,j,x;
        for(i=1;i<=nr;i++){
            if(v[i].getnume() == cp)
            {
                ok = 0;
                x = varsta(v[i].getcnp());
            }
        }
        if(ok==1)
            cout<<"Abonatul cu numele introdus nu exista in dosar"<<endl;
        else
            cout<<"Varsta abonatului este: "<<x<<endl;
    }

    int varsta(string s)
    {
    int k=0,i=0,x=0,y,l,z;
    y  = 0;
    l = 0;
    z = 0;
    y = (s[1]-'0')*10+(s[2]-'0');
    l = (s[3]-'0')*10+(s[4]-'0');
    z = (s[5]-'0')*10+(s[6]-'0');
    if(y<=22)
    {
        y = 21-y;
        if(l>4)
            y++;
        if(l==4)
        {
            if(10>=z)
                y++;
        }
    }
    else
    {
        y = 100-y+21;
        if(l>4)
            y++;
        if(l==4)
        {
            if(10>=z)
                y++;
        }
    }
    return y;
}


/*
    static void ab10(){
        if(numar_imprumutate10==0)
            cout<<"Nu exista abonati care au imprumutat mai mult de 10 carti";
        else
        {
            for(int i=1;i<=nr;i++)
                cout<<v[i].getnume()<<endl;
        }
    }
*/
};

int Dosar::numar_imprumutate10 = 0;


int main()
{
    Dosar p;
    Abonat x;
    Persoana* y = new Abonat();
    y ->fvirt();


    int i,j,k,n;
    string nm,cn;
    int p1,p2,p3;

    p1 = 10;
    while(p1!=0)
    {
        cout<<endl;
        cout<<endl<<"Pentru a afisa dosarul, apasati tasta 1"<<endl;
        cout<<"Pentru a adauga un abonat la dosar, apasati tasta 2"<<endl;
        cout<<"Pentru a adauga la dosar n abonati, apasati tasta 3"<<endl;
        cout<<"Pentru a afisa varsta unei persoane, apasati tasta 4"<<endl;
        cout<<"Pentru a iesi din meniu, apasati tasta 0"<<endl<<endl;
        cout<<"Apasati tasta:";
        cin>>p1;
        if(p1==1)
            p.afisare();
        if(p1==2)
        {
            cout<<"Introduceti datele abonatului: "<<endl;
            cout<<"Numele (Nume_Prenume) :";
            cin>>nm;
            x.setnume(nm);
            cout<<endl;
            cout<<"CNP-ul: ";
            cin>>cn;
            x.setcnp(cn);
            cout<<endl<<"Introduceti numarul maxim de carti pe care acesta le poate imprumuta: ";
            cin>>j;
            x.setmaxcarti(j);
            cout<<endl<<"Introduceti numarul de carti pe care acesta le-a imprumutat: ";
            cin>>j;
            if(j>x.getmaxcarti())
            {
                cout<<"Abonatul a depasit limita de carti. "<<endl;
            }
            else
            {
                x.setimprumutate(j);
                cout<<endl<<"Introduceti pretul abonamentului: ";
                cin>>j;
                if(j<x.getmaxcarti())
                {
                    x.setpret(j);
                    p.setabonat(x);
                }
                else
                {
                    cout<<"Pretul abonamentului nu poate fi mai mare decat numarul de carti maxim de carti care pot fi imprumutate"<<endl;
                }
            }
            cout<<endl;
        }
        if(p1 == 3)
        {
             cout<<"Introduceti numarul de abonati pe care doriti sa ii inregistrati in dosar:";


                cin>>n;

                for(i=1;i<=n;i++)
                {
                    cout<<"Introduceti datele abonatului:"<<endl;
                    cout<<"Numele (Nume_Prenume) :";
                    cin>>nm;
                    x.setnume(nm);
                    cout<<endl;
                    cout<<"CNP-ul: ";
                    cin>>cn;
                    x.setcnp(cn);
                    cout<<endl<<"Introduceti numarul maxim de carti pe care acesta le poate imprumuta: ";
                    cin>>j;
                    x.setmaxcarti(j);
                    cout<<endl<<"Introduceti numarul de carti pe care acesta le-a imprumutat: ";
                    cin>>j;
                    if(j>x.getmaxcarti())
                    {
                        cout<<"Abonatul a depasit limita de carti. "<<endl;
                    }
                    else
                    {
                        x.setimprumutate(j);
                        cout<<endl<<"Introduceti pretul abonamentului: ";
                        cin>>j;
                        if(j<x.getmaxcarti())
                        {
                            x.setpret(j);
                            p.setabonat(x);
                        }
                        else
                        {
                            cout<<"Pretul abonamentului nu poate fi mai mare decat numarul de carti maxim de carti care pot fi imprumutate"<<endl;
                        }
                    }
                    cout<<endl;
                }
        }
        if(p1==4)
        {
            cout<<endl;
            cout<<"Introduceti numele persoanei careia doriti sa ii aflati varsta:  ";
            string pers;
            cin>>pers;
            p.aflare(pers);
        }
    }

    cout<<endl<<endl<<endl;
  //  p.afisare();
    cout<<endl;
    cout<<endl;
    Abonat test2;
    test2 = p.getabonat(2);
    return 0;
}
/*
Exemple pentru clasa Persoana:
2

Alexandru
5020407231270
15 7 8

Marian
5051123454587
20 13 100
*/

/*
Exemple pentru clasa Abonat:
55 22 250

*/
