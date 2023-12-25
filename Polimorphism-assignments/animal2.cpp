
#include <iostream>
#include <string.h>
using namespace std;

char *SaoChep(const char *s)
{
    return strcpy(new char[strlen(s) + 1], s);
}
class CONVAT
{
protected:
    char *strTen;
    int iLoai; // 0: cho,1:meo
public:
    CONVAT();
    CONVAT(char *ten);
    // ###INSERT CODE HERE -
    virtual void XungTen() = 0;
    CONVAT(CONVAT const &p);
};
CONVAT::CONVAT()
{
    strTen = NULL;
    iLoai = -1;
}
CONVAT::CONVAT(char *ten)
{
    strTen = SaoChep(ten);
}

CONVAT::CONVAT(CONVAT const &p)
{
    cout << "\n(goi ham tao sao chep)";
    iLoai = p.iLoai;
    strTen = SaoChep(p.strTen);
}

class CHO : public CONVAT
{
public:
    static void InSoChoNhap();
    void XungTen() override;
    CHO(char *ten) : CONVAT(ten) { iLoai = 0; }
    CHO() : CONVAT() { iLoai = 0; }
    CHO(const CONVAT &p);

private:
    static int soChoNhap;
};

CHO::CHO(const CONVAT &p) : CONVAT(p)
{
    iLoai = 0;
}

int CHO::soChoNhap = 0;
void CHO::InSoChoNhap()
{
    cout << "\nSo con cho nhap kho: " << soChoNhap;
}
void CHO::XungTen()
{
    cout << "\nDay la con cho, ten la " << strTen;
}

class MEO : public CONVAT
{
public:
    void XungTen() override;
    MEO(char *ten) : CONVAT(ten) { iLoai = 1; }
    MEO() : CONVAT() { iLoai = 1; }
    static void InSoMeoNhap();
    MEO(const CONVAT &p);

private:
    static int soMeoNhap;
};

MEO::MEO(const CONVAT &p) : CONVAT(p)
{
    iLoai = 1;
}

int MEO::soMeoNhap = 0;
void MEO::XungTen()
{
    cout << "\nDay la con meo, ten la " << strTen;
}

void MEO::InSoMeoNhap()
{
    cout << "\nSo con meo nhap kho: " << soMeoNhap;
}

int main()
{
    string s;
    cin >> s;

    CONVAT *c1 = new CHO("MUC");
    CONVAT *c2 = new CHO("LAI");
    CONVAT *c3 = new CHO("NHAT");
    CONVAT *m1 = new MEO("MUOP");
    CONVAT *m2 = new MEO("DEN");

    MEO m3(*m1);
    m3.XungTen();
    CHO c4(*c3);
    c4.XungTen();

    return 0;
}
