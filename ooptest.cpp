#include <conio.h>
#include <iostream>
#include <string.h>
using namespace std;

class A
{
private:
    int a;
    char *str;

public:
    A()
    {
        a = 0;
        str = nullptr;
    }
    A(A &h)
    {
        this->a = h.a;
        this->str = strdup(h.str);
    }
    void Nhap()
    {
        cout << "\nNhap so nguyen lop A: ";
        cin >> a;
        if (str != nullptr)
            delete str;
        cout << "\nNhap chuoi lop A: ";
        char tg[30];
        fflush(stdin);
        gets(tg);
        str = strdup(tg);
    }
    void Xuat()
    {
        cout << "\n"
             << "So nguyen lop A = " << a;
        cout << " Chuoi lop A: " << str;
    }
};

class B
{
private:
    int b;
    char *str;

public:
    B()
    {
        b = 0;
        str = nullptr;
    }
    B(B &h)
    {
        this->b = h.b;
        this->str = strdup(h.str);
    }
    void Nhap()
    {
        cout << "\nNhap so nguyen lop B: ";
        cin >> b;
        if (str != nullptr)
            delete str;
        cout << "\nNhap chuoi lop B: ";
        char tg[30];
        fflush(stdin);
        gets(tg);
        str = strdup(tg);
    }
    void Xuat()
    {
        cout << "\n"
             << "So nguyen lop B: " << b;
        cout << " Chuoi lop B: " << str;
    }
};

class C : public B
{
private:
    int c;
    char *str;

public:
    C() : B()
    {
        c = 0;
        str = nullptr;
    }
    C(C &h) : B(h)
    {
        this->c = h.c;
        this->str = strdup(h.str);
    }
    void Nhap()
    {
        B::Nhap();
        cout << "\nNhap so nguyen lop C: ";
        cin >> c;
        if (str != nullptr)
            delete str;
        cout << "\nNhap chuoi lop C: ";
        char tg[30];
        fflush(stdin);
        gets(tg);
        str = strdup(tg);
    }
    void Xuat()
    {
        B::Xuat();
        cout << "\n"
             << "So nguyen lop C = " << c;
        cout << " Chuoi lop C: " << str;
    }
};

class D : public C
{
private:
    int d;
    char *str;
    A u;

public:
    D() : C(), u()
    {
        d = 0;
        str = nullptr;
    }

    D(D &h) : C(h), u(h.u)
    {
        this->d = h.d;
        this->str = strdup(h.str);
    }
    void Nhap()
    {
        u.Nhap();
        C::Nhap();
        cout << "\nNhap so nguyen lop D: ";
        cin >> d;
        if (str != nullptr)
            delete str;
        cout << "\nNhap chuoi lop D: ";
        char tg[30];
        fflush(stdin);
        gets(tg);
        str = strdup(tg);
    }
    void Xuat()
    {
        u.Xuat();
        C::Xuat();
        cout << "\n"
             << "So nguyen lop D: " << d;
        cout << " Chuoi lop D: " << str;
    }
};

int main()
{
    D h1;
    h1.Nhap();
    D h2(h1);
    cout << "\n\nH2: ";
    h2.Xuat();
    h1.Nhap();
    cout << "\n\nH2: ";
    h2.Xuat();
    cout << "\n\nH1: ";
    h1.Xuat();
    return 0;
}