
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
    const CONVAT &operator=(const CONVAT &p);
    CONVAT *DCconvat()
    {
        return this;
    }

private:
    static int iCount;
};

int CONVAT::iCount = 0;

const CONVAT &CONVAT::operator=(const CONVAT &p)
{

    strTen = SaoChep(p.strTen);
    iLoai = p.iLoai;
    cout << "\n(goi toan tu gan)";
    return p;
}
CONVAT::CONVAT(CONVAT const &p)
{
    cout << "\n(goi ham tao sao chep)";
    iLoai = p.iLoai;
    strTen = SaoChep(p.strTen);
}

CONVAT::CONVAT()
{
    strTen = NULL;
    iLoai = -1;
}
CONVAT::CONVAT(char *ten)
{
    strTen = SaoChep(ten);
}



class CHO : public CONVAT
{
private:
    static int soChoNhap;

public:
    static void InSoChoNhap();
    void XungTen() override;
    CHO(char *ten) : CONVAT(ten) { iLoai = 0; }
    CHO() : CONVAT() { iLoai = 0; }
    CHO(const CONVAT &p);
    const CHO &operator=(CHO &p);
};
CHO::CHO(const CONVAT &p) : CONVAT(p)
{
    iLoai = 0;
}
const CHO &CHO::operator=(CHO &p)
{
    CONVAT *u1, *u2;
    u1 = this->DCconvat();
    u2 = p.DCconvat();
    *u1 = *u2;
    return p;
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
private:
    static int soMeoNhap;

public:
   
    void XungTen() override;
    MEO(char *ten) : CONVAT(ten) { iLoai = 1; }
    MEO() : CONVAT() { iLoai = 1; }
    static void InSoMeoNhap();
    MEO(const CONVAT &p);
    const MEO &operator=(MEO &p);
};
int MEO::soMeoNhap = 0;
MEO::MEO(const CONVAT &p) : CONVAT(p)
{
    iLoai = 1;
}
const MEO &MEO::operator=(MEO &p)
{
    CONVAT *u1, *u2;
    u1 = this->DCconvat();
    u2 = p.DCconvat();
    *u1 = *u2;
    return p;
}

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

    MEO m3("MUN"), m4;
    m4 = m3;
    m4.XungTen();
    MEO m5 = *m2;
    m5.XungTen();
    CHO c4("HEO"), c5;
    c5 = c4;
    c5.XungTen();

    return 0;
}

///////////
