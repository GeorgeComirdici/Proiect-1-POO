#include <iostream>
using namespace std;
class Numar_Complex
{
    double re;
    double im;
public:
    //constructori de initializare
    Numar_Complex()
    {
        re=0;
        im=0;
    }
    Numar_Complex(double v)
    {
        re=v;
        im=v;
    }
    Numar_Complex(double x, double y)
    {
        re=x;
        im=y;
    }
    //constructor de copiere
    Numar_Complex(const Numar_Complex& x)
    {
        re=x.re;
        im=x.im;
    }
    //destructor
    ~Numar_Complex(){};
    //functie care seteaza partea reala
    void setRe(double);
    //functie care returneaza partea reala
    double get_re();
    void setIm(double);
    double get_im();
    //supraincarcare operator <<
    friend ostream& operator<<(ostream& os,const Numar_Complex& x)
    {
        if(x.re==0 && x.im!=0)os<<x.im<<"*i";
        else if(x.re!=0 && x.im==0)os<<x.re;
        else if(x.re==0 && x.im==0)os<<0;
        else if(x.im<0)os<<x.re<<x.im<<"*i";
        else os<<x.re<<"+"<<x.im<<"*i";
        return os;
    }
    //supraincarcare operator >>
    friend istream& operator>>(istream& is,Numar_Complex& x)
    {
        is>>x.re;
        is>>x.im;
        return is;
    }
    //metoda publica de afisare a numerelor complexe
    void afis()
    {
        if(re==0 && im!=0)cout<<im<<"*i";
        else if(re!=0 && im==0)cout<<re;
        else if(re==0 && im==0)cout<<0;
        else if(im<0)cout<<re<<im<<"*i";
        else
            cout<<re<<"+"<<im<<"i";
    }
    //supraincarcare operator +
    Numar_Complex operator+(Numar_Complex ob)
    {
        Numar_Complex aux;
        aux.setIm(im+ob.im);
        aux.setRe(re+ob.re);
        return aux;
    }
    //supraincarcare operator *
    Numar_Complex operator*(Numar_Complex& ob)
    {
        Numar_Complex aux;
        aux.setRe(re*ob.re-im*ob.im);
        aux.setIm(re*ob.im+im*ob.re);
        return aux;
    }
    //supraincarcare operator =
    Numar_Complex& operator=(const Numar_Complex& ob)
    {
        re=ob.re;
        im=ob.im;
        return *this;
    }
};

void Numar_Complex::setIm(double aux)
{
    im=aux;
}
double Numar_Complex::get_im()
{
    return im;
}
void Numar_Complex::setRe(double aux)
{
    re=aux;
}
double Numar_Complex::get_re()
{
    return re;
}
class Matrice_Complexa
{
    int nr_lin,nr_col;
    Numar_Complex **v;
public:
    //constructor pentru initializarea cu numarul x pe toate pozitiile
    Matrice_Complexa(Numar_Complex x,int n,int m)
    {
        nr_lin=n;
        nr_col=m;
        v=new Numar_Complex*[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                v[i]=new Numar_Complex[m];
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            v[i][j]=x;
    }
    //constructori de initializare
    Matrice_Complexa()
    {
        nr_lin=0;
        nr_col=0;
    }
    Matrice_Complexa(int n,int m)
    {
        nr_lin=n;
        nr_col=m;
        v=new Numar_Complex*[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                v[i]=new Numar_Complex[m];
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            v[i][j]=0;
    }
    //destructor matrice
    ~Matrice_Complexa()
    {
        for(int i=0;i<nr_lin;i++)
            for(int j=0;j<nr_col;j++)
            delete []v[i];
        delete []v;
        nr_lin=nr_col=0;
    }
    //constructor de copiere
    Matrice_Complexa(const Matrice_Complexa& x)
    {
        for(int i=0;i<nr_lin;i++)
            for(int j=0;j<nr_col;j++)              //se dezaloca memoria pentru matrice pentru a putea copia in locul ei o matrice de dimensiuni diferite
            delete []v[i];
        delete []v;
        nr_lin=x.nr_lin;
        nr_col=x.nr_col;
         v=new Numar_Complex*[nr_lin];
        for(int i=0;i<nr_lin;i++)
        {
            for(int j=0;j<nr_col;j++)
                v[i]=new Numar_Complex[nr_col];             //se realoca memoria pentru noua matrice
        }
        for(int i=0;i<nr_lin;i++)
            for(int j=0;j<nr_col;j++)
        v[i][j]=x.v[i][j];
    }
    //supraincarcare operator <<
    friend ostream& operator<<(ostream& os,const Matrice_Complexa& x)
    {
        for(int i=0;i<x.nr_lin;i++)
            {for(int j=0;j<x.nr_col;j++)
            os<<x.v[i][j]<<" ";
            os<<endl;
    }
    return os;
    }
    //supraincarcare operator >>
    friend istream& operator>>(istream& is,Matrice_Complexa& x)
    {
        is>>x.nr_lin;
        is>>x.nr_col;
        x.v=new Numar_Complex*[x.nr_lin];
        for(int i=0;i<x.nr_lin;i++)
        {
            for(int j=0;j<x.nr_col;j++)
                x.v[i]=new Numar_Complex[x.nr_col];
        }
        for(int i=0;i<x.nr_lin;i++)
            for(int j=0;j<x.nr_col;j++)
            is>>x.v[i][j];
            return is;
    }
    //functia care seteaza elementul de pe pozitia (i,j) la valoarea x
    void setEl(Numar_Complex x,int i,int j)
    {
        v[i][j]=x;
    }
    int get_nr_col()
    {
        return nr_col;
    }
    int get_nr_lin()
    {
        return nr_lin;
    }
    //supraincarcare operator +
    Matrice_Complexa operator+(Matrice_Complexa& x)
    {
        if(nr_lin!=x.nr_lin || nr_col!=x.nr_col)
        {
            cout<<"Nu se poate face adunarea"<<endl;
            Matrice_Complexa aux;
            return aux;
        }
        Matrice_Complexa aux(nr_lin,nr_col);
        for(int i=0;i<nr_lin;i++)
            for(int j=0;j<nr_col;j++)
        aux.setEl(v[i][j]+x.v[i][j],i,j);        //seteaza fiecare element din matricea aux ca fiind suma elementelor corespunzatoare din matricele adunate
        return aux;
    }
    //inmultire matrice
    Matrice_Complexa operator*(Matrice_Complexa& x)
    {
        if(nr_col!=x.nr_lin)
        {
            cout<<"Nu se poate face inmultirea"<<endl;
            Matrice_Complexa aux;
            return aux;
        }
        Matrice_Complexa aux(nr_lin,x.nr_col);
        for(int i=0;i<nr_lin;i++)
        {
            for(int j=0;j<nr_col;j++)
                for(int k=0;k<nr_col;k++)
                aux.setEl(aux.v[i][j]+v[i][k]*x.v[k][j],i,j);
        }
        return aux;
    }
    friend class Numar_Complex;
};
class Citire
{
    int n;
    Matrice_Complexa *w;
public:
    Citire()
    {
        cout<<"n=";cin>>n;
        w=new Matrice_Complexa[n];
        for(int i=0;i<n;i++)
            cin>>w[i];

    }
    ~Citire(){delete []w;
    n=0;}
    void Afisare()
    {

        for(int i=0;i<n;i++)
            cout<<w[i]<<endl;
    }
    friend class Matrice_Complexa;
};
int main()
{
    Citire ob;
    ob.Afisare();
    /*Matrice_Complexa v;
    cin>>v;
    cout<<v;
    Matrice_Complexa v1;
    cin>>v1;
    cout<<v1;
    cout<<v*v1;*/
    return 0;
}
