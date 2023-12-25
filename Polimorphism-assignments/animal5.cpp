/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
###End banned keyword*/
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
    int getIloai() { return iLoai; }

    virtual void DocTen() = 0;
    static void InSoConNhap();
    virtual ~CONVAT();
    static int getSoConNhap() { return iCount; };
    virtual void NhapVao() = 0;
    static void TangSoConNhap();
    static void GiamSoConNhap();
    char *layten();

private:
    static int iCount;
};

int CONVAT::iCount = 0;
CONVAT::CONVAT()
{
    strTen = nullptr;
    iLoai = -1;
}
CONVAT::CONVAT(char *ten)
{
    strTen = SaoChep(ten);
}
CONVAT::CONVAT(CONVAT const &p)
{
    iLoai = p.iLoai;
    strTen = SaoChep(p.strTen);
}
const CONVAT &CONVAT::operator=(const CONVAT &p)
{
    if (this != &p)
    {
        delete[] strTen;
        iLoai = p.iLoai;
        strTen = SaoChep(p.strTen);
    }
    return p;
}

void CONVAT::InSoConNhap()
{
    cout << "\nSo con vat nhap kho: " << iCount;
}
CONVAT::~CONVAT()
{
    delete[] strTen;
}
void CONVAT::TangSoConNhap()
{
    CONVAT::iCount++;
}
void CONVAT::GiamSoConNhap()
{
    CONVAT::iCount--;
}
char *CONVAT::layten()
{
    return strTen;
}
//////CHO CLASS/////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CHO : public CONVAT
{
private:
    static int soChoNhap;

public:
    CHO(char *ten) : CONVAT(ten) { iLoai = 0; }
    CHO() : CONVAT() { iLoai = 0; }
    static void InSoChoNhap();

    void XungTen() override;

    CHO(const CONVAT &p);

    CHO(const CHO &s);

    const CHO &operator=(CHO const &p);

    void NhapVao() override;
    static int getSoChoNhap() { return soChoNhap; };
    void DocTen();
    virtual ~CHO() {}
};

int CHO::soChoNhap = 0;
void CHO::InSoChoNhap()
{

    cout << "\nSo con cho nhap kho: " << soChoNhap;
}

void CHO::XungTen()
{
    cout << "\nDay la con cho, ten la " << strTen;
}

CHO::CHO(const CONVAT &p) : CONVAT(p)
{
}

CHO::CHO(const CHO &p)
{
    CHO::operator=(p);
    iLoai = 0;
}

const CHO &CHO::operator=(CHO const &p)
{
    {
        if (this != &p)
        {
            CONVAT::operator=(p);
        }
        return *this;
    }
}
void CHO::NhapVao()
{
    CHO::soChoNhap++;
    CONVAT::TangSoConNhap();
}

void CHO::DocTen()
{
    cout << "\nCHO: " << strTen;
}

//////MEO CLASS/////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MEO : public CONVAT
{
private:
    static int soMeoNhap;

public:
    MEO(char *ten) : CONVAT(ten) { iLoai = 1; }
    MEO() : CONVAT() { iLoai = 1; }
    static void InSoMeoNhap();

    void XungTen() override;

    MEO(const CONVAT &p);

    MEO(const MEO &s);

    const MEO &operator=(MEO const &p);

    void NhapVao();
    static int getSoMeoNhap() { return soMeoNhap; };
    void DocTen();
    virtual ~MEO() {}
};
int MEO::soMeoNhap = 0;
void MEO::InSoMeoNhap()
{
    cout << "\nSo con meo nhap kho: " << soMeoNhap;
}

void MEO::XungTen()
{
    cout << "\nDay la con meo, ten la " << strTen;
}

MEO::MEO(const CONVAT &p) : CONVAT(p)
{
    iLoai = 1;
}

MEO::MEO(const MEO &s)
{

    MEO::operator=(s);
    iLoai = 1;
}

const MEO &MEO::operator=(MEO const &p)
{

    if (&p != this)
    {
        CONVAT::operator=(p);
    }
    return *this;
}
void MEO::NhapVao()
{
    MEO::soMeoNhap++;
    CONVAT::TangSoConNhap();
}

void MEO::DocTen()
{
    cout << "\nMEO: " << strTen;
}

///  ////////////////////////////////////////////////////////////////////////////////////////////////

class DANHSACHCV
{
private:
    int tongTrongKho;
    CONVAT **dscv;
    int tongConHienTai, tongMeo, tongCho;

public:
    DANHSACHCV();
    DANHSACHCV(int x);
    int Nhap(CONVAT *p);
    void In();
    void Ban(int x);
    void Ban(char *p);
    ~DANHSACHCV();
};

DANHSACHCV::DANHSACHCV()
{

    tongMeo = tongCho = tongTrongKho = 0;
    tongConHienTai = 0;
    dscv = nullptr;
}

DANHSACHCV::DANHSACHCV(int x)
{
    tongConHienTai = 0;
    tongCho = tongMeo = 0;
    tongTrongKho = x;
    dscv = new CONVAT *[x];
    for (int i = 0; i < x; ++i)
    {
        dscv[i] = nullptr;
    }
}

int DANHSACHCV::Nhap(CONVAT *p)
{
    int i;
    for (i = 0; i < tongTrongKho; i++)
    {
        if (i == (tongTrongKho - 1))
        {
            cout << "\nHet cho, khong nhap duoc";
            return -1;
        }
        if (dscv[i] == nullptr)
        {
            p->getIloai() == 1 ? tongMeo++ : tongCho++;
            tongConHienTai++;
            p->NhapVao();
            dscv[i] = p;
            break;
        }
    }

    return i;
}
void DANHSACHCV::In()
{
    cout << "\nDanh sach " << tongConHienTai << " cac con vat hien co, bao gom: " << tongCho << " cho va " << tongMeo << " meo";
    for (int i = 0; i < tongTrongKho; i++)
    {
        if (dscv[i] != nullptr)
        {
            dscv[i]->DocTen();
        }
    }
}
int SoSanh(const char *str1, const char *str2)
{

    while (*str1 != '\0' && *str2 != '\0')
    {

        if (*str1 != *str2)
        {
            return false;
        }

        ++str1;
        ++str2;
    }

    return *str1 == '\0' && *str2 == '\0';
}

void DANHSACHCV::Ban(int i)
{
 
    if (i < 0 || i >= tongTrongKho)
    {
        cout << "\nVi tri " << i << " khong hop le";
        return;
    }
    
    if (dscv[i] == nullptr)
    {
        cout << "\nVi tri " << i  << " chua co con vat nao";
        return;
    }

    int iloai = dscv[i]->getIloai();
    char *loai = iloai == 1 ? SaoChep("meo") : SaoChep("cho");
    iloai == 1 ? tongMeo-- : tongCho--;
    tongConHienTai--;
    cout << "\nDa ban con " << loai << " ten " << dscv[i]->layten();
    delete dscv[i];
    cout << "\n(goi ham huy giai phong vung nho)";

    dscv[i] = nullptr;
}

void DANHSACHCV::Ban(char *p)
{
    for (int i = 0; i < tongTrongKho; ++i)
    {
        if (dscv[i] == nullptr)
        {
            continue;
        }

        if (SoSanh(p, dscv[i]->layten()))
        {

            int iloai = dscv[i]->getIloai();
            char *loai = iloai == 1 ? SaoChep("meo") : SaoChep("cho");
            iloai == 1 ? tongMeo-- : tongCho--;
            tongConHienTai--;
            cout << "\nDa ban con " << loai << " ten " << p;
            cout << "\n(goi ham huy giai phong vung nho)";

            delete dscv[i];
            dscv[i] = nullptr;
            return;
        }
    }
    cout << "\nKhong co con vat ten " << p;
}

DANHSACHCV::~DANHSACHCV()
{
    for (int i = 0; i < tongTrongKho; i++)
    {
        delete dscv[i];
    }
    delete[] dscv;
}

int main()
{
    string s;
    cin >> s;
    CONVAT *c1 = new CHO("MUC");
    CONVAT *c2 = new CHO("LAI");
    CONVAT *c3 = new CHO("NHAT");
    c1->XungTen();
    c2->XungTen();
    c3->XungTen();
    CONVAT *m1 = new MEO("MUOP");
    CONVAT *m2 = new MEO("DEN");
    m1->XungTen();
    m2->XungTen();

    DANHSACHCV d(10); // danh sách có tối đa 10 con
    d.Nhap(c1);
    d.Nhap(c2);
    int ic3 = d.Nhap(c3);
    d.Nhap(m1);
    d.Nhap(m2);
    d.In();

    d.Ban(-1);
    d.Ban(10);
    d.Ban(7);

    d.Ban(ic3);
    d.In();
    d.Ban("DEN");
    d.In();
    d.Ban("MUN");

    d.Nhap(new CHO("HEO"));
    d.In();

    CONVAT::InSoConNhap();
    MEO::InSoMeoNhap();
    CHO::InSoChoNhap();
    return 0;
}
