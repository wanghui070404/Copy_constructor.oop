#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;
class TS
{
private:
    char ht[25];
    int sobd;
    float td;

public:
    void nhap()
    {
        cout << "\nHo ten: ";
        fflush(stdin);
        gets(ht);
        cout << "So bao danh: ";
        cin >> sobd;
        cout << "\nTong diem: ";
        cin >> td;
    }
    virtual void in()
    {
        cout << "\nHo ten: " << ht;
        cout << "\n So bao danh: " << sobd;
        cout << "\n Tong diem: " << td;
    }
    void xem_in()
    {
        int ch;
        cout << "\nHo ten: " << ht;
        cout << "\n Co in khong? - C/K";
        ch = toupper(getch());
        if (ch == 'C')
            in();
    }
};

class TS2 : public TS
{
private:
    char dc[30];

public:
    void nhap()
    {
        TS::nhap();
        cout << "Dia chi: ";
        fflush(stdin);
        gets(dc);
    }
    void in()
    {
        TS::in();
        cout << "\nDia chi: " << dc;
    }
};
int main()
{
    TS2 t[100];
    int i, n;
    cout << "So thi sinh: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        t[i].nhap();
    }
    for (int i = 0; i < n; i++)
    {
        t[i].xem_in();
        cout << '\n';
    }
    return 0;
}