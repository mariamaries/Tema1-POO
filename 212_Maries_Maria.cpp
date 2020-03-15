#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

class complex
{
private:
    int real;
    int imaginar;
public:
    complex (int, int);
    complex (complex&);
    ~complex ();
    void set_real(int);
    void set_imaginar(int);
    int get_real()
    {
        return real;
    };
    int get_imag()
    {
        return imaginar;
    };
    void afisare(ostream &out);
    void citire(istream &in);
    friend istream& operator>>(istream &in, complex& z);
    friend ostream& operator<<(ostream &out, complex& z);
    double modul(); ///functia modul
    complex& operator=(complex &z);
    friend complex& operator+(complex& z1, complex& z2);
    friend complex& operator*(complex& z1, complex& z2);
    friend complex& operator/(complex& z1, complex& z2);
    friend class vector_complex;
};

complex::complex(int real = 0, int imaginar = 0)
{
    this->real = real;
    this->imaginar = imaginar;
}
complex::complex(complex &z)
{
    this->real = z.real;
    this->imaginar = z.imaginar;
}
complex::~complex()
{
    this->real=0;
    this->imaginar=0;
}
void complex::set_real(int x)
{
    real = x;
}
void complex::set_imaginar(int y)
{
    imaginar=y;
}
void complex::citire(istream &in)
{
    cout<<"Cititi partea reala: ";
    in>>real;
    cout<<"Cititi partea imaginara: ";
    in>>imaginar;
}
istream& operator>>(istream& in,complex& z)
{
    z.citire(in);
    return in;
}
void complex::afisare(ostream &out)
{
    if (imaginar==0)
    {
        out<<real;
    }
    else
    {
        if (imaginar < 0)
        {
            out<<real<<imaginar<<"*i";
        }
        else
        {
            out<<real<<"+"<<imaginar<<"*i";
        }
    }
}
ostream& operator<<(ostream& out, complex& z)
{
    z.afisare(out);
    return out;
}
double complex::modul()
{
    return sqrt(real*real+imaginar*imaginar);
}
complex& complex::operator=(complex &z)
{
    real=z.real;
    imaginar=z.imaginar;
}
inline complex& operator+(complex &z1, complex& z2)
{
    complex *z = new complex;
    z->real = z1.real + z2.real;
    z->imaginar = z1.imaginar + z2.imaginar;
    return *z;
}
inline complex& operator*(complex &z1, complex& z2)
{
    complex *z=new complex;
    z->real = z1.real * z2.real - z1.imaginar * z2.imaginar;
    z->imaginar = z1.real * z2.imaginar + z2.real * z1.imaginar;
    return *z;
}
complex& operator/(complex &z1, complex &z2)
{
    complex *z=new complex;
    z->real = (z1.real*z2.real + z1.imaginar * z2.imaginar) / (z2.real * z2.real + z2.imaginar * z2.imaginar);
    z->imaginar = (z2.real * z1.imaginar - z1.real * z2.imaginar) / (z2.real * z2.real + z2.imaginar * z2.imaginar);
    return *z;
}


class vector_complex
{
private:
    int lungime_vector;
    complex* vec;
public:
    vector_complex(complex element, int lng)
    {
        this->lungime_vector = lng;
        this->vec = new complex[lungime_vector];
        for(int i = 0; i < lungime_vector; i++)
            vec[i] = element;
    }
    vector_complex(vector_complex& v1)
    {
        lungime_vector = v1.lungime_vector;
        vec = v1.vec;
    }
    ~vector_complex()
    {
        delete []vec;
        lungime_vector = 0;
    }
    void setLungimeVector(int lungime_noua)
    {
        lungime_vector = lungime_noua;
    }

    complex* getVec()
    {
        return vec;
    }

    int getLungimeVector()
    {
        return lungime_vector;
    }

    void citire(istream &in)
    {
        cout<<"Lungimea vectorului: \n";
        in >> lungime_vector;
        cout<<"Elementele: \n";
        for(int i = 0; i < lungime_vector; i++)
            vec[i].citire(in);
    }

    void afisare(ostream &out)
    {
        out << "Vectorul este: [";
        for(int i = 0; i < lungime_vector; i++)
        {
            if ( i == lungime_vector - 1)
            {
                out << vec[i] << "]" << endl;
            }
            else
            {
                out << vec[i] << ", ";
            }
        }
    }

    friend ostream& operator<<(ostream& out, vector_complex& v)
    {
        v.afisare(out);
        return out;
    }

    friend istream& operator>>(istream& in, vector_complex& v)
    {
        v.citire(in);
        return in;
    }

    void getVecModules()
    {
        cout << "Modulele vectorului: [";
        for (int i = 0; i < this->lungime_vector; i++)
        {
            if ( i == this->lungime_vector - 1)
                cout << this->vec[i].modul() << "]" << endl;
            else
                cout << this->vec[i].modul() << ", ";
        }
        return;
    }

    void sort()
    {
        for (int i = 0; i < this->lungime_vector; i++)
        {
            for (int j = 0; j < this->lungime_vector; j++)
            {
                if (this->vec[i].modul() < this->vec[j].modul())
                {
                    // cream o copie folosind constructorul copie
                    complex tmp(this->vec[i]);
                    this->vec[i] = this->vec[j];
                    this->vec[j] = tmp;
                }
            }
        }
    }

    void sum()
    {
        complex result;
        for (int i = 0; i < this->lungime_vector; i++)
        {
            result = result + this->vec[i];
        }
        cout << "Suma vectorului: " << result << endl;
    }
};

void menu_output()
{
	cout << "\n Maries Maria 212 - Proiect - Tema 1 ( Clasa Vector_Complex): \n";
	cout << "\n\t MENIU:";
	cout << "\n";
    cout << "0. Iesire." << "\n";
	cout << "1. Citire vector initial" << "\n";
	cout << "2. Afisare vector initial" << "\n";
	cout << "3. Copiere vector initial in alt vector" << "\n";
	cout << "4. Afisare vector copiat" << "\n";
	cout << "5. Afisarea vectorului modulelor" << "\n";
	cout << "6. Sortare crescatoare a vectorului dupa module" << "\n";
	cout << "7. Suma tuturor elementelor din vector" << "\n";
	cout << "Introduceti numarul actiunii: " << "\n";
}

void menu()
{
    int opt;
    complex z;
    vector_complex v1(z,1);
    vector_complex v2(v1);

    do{
        menu_output();
        cin >> opt;

        switch(opt)
        {
            case 0:
                cout << "Exit";
                break;
            case 1:
                cin >> v1;
                break;
            case 2:
                cout << v1;
                break;
            case 3:
                v2 = v1;
                break;
            case 4:
                cout << v2;
                break;
            case 5:
                v1.getVecModules();
                break;
            case 6:
                v1.sort();
                cout << v1;
                break;
            case 7:
                v1.sum();
                break;
            default:
                cout << "Selectie invalida";
                break;
        }
        printf("\n");
        system("pause");
        system("cls");
    }while (opt != 0);

}

int main()
{
    menu();
    return 0;
}
