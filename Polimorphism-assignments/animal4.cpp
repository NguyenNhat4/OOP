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
	//  ###INSERT CODE HERE -
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void XungTen() = 0;
	CONVAT(CONVAT const &p);
	const CONVAT &operator=(const CONVAT &p);
	CONVAT *DCconvat()
	{
		return this;
	}
	int getIloai() { return iLoai; }

	virtual void DocTen();
	static void InSoConNhap();
	~CONVAT()
	{
		delete[] strTen;
	}
	static int getSoConNhap() { return iCount; };
	static void TangSoConNhap();

	virtual void NhapVao() = 0;

private:
	static int iCount;
};

int CONVAT::iCount = 0;
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
const CONVAT &CONVAT::operator=(const CONVAT &p)
{
	if (this != &p)
	{
		delete[] strTen;
		iLoai = p.iLoai;
		strTen = SaoChep(p.strTen);
	}
	return *this;
}
void CONVAT::DocTen()
{
	cout << strTen;
}

void CONVAT::InSoConNhap()
{
	cout << "\nSo con vat nhap kho: " << iCount;
}

void CONVAT::TangSoConNhap()
{
	iCount++;
}
//////CHO CLASS/////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CHO : public CONVAT
{
private:
	static int soChoNhap;

public:
	CHO(char *ten) : CONVAT(ten) { iLoai = 0; }
	CHO() : CONVAT() { iLoai = 1; }
	static void InSoChoNhap();

	void XungTen() override;

	CHO(const CONVAT &p);

	CHO(const CHO &s);

	const CHO &operator=(CHO const &p);

	void NhapVao()
	{
		CHO::soChoNhap++;
		CONVAT::TangSoConNhap();
	}
	static int getSoChoNhap() { return soChoNhap; };
	void DocTen();
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
	iLoai = 0;
}

CHO::CHO(const CHO &p)
{
	CHO::operator=(p);
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

	void NhapVao()
	{
		soMeoNhap++;
		CONVAT::TangSoConNhap();
	};
	static int getSoMeoNhap() { return soMeoNhap; };
	void DocTen();
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
}

const MEO &MEO::operator=(MEO const &p)
{

	if (&p != this)
	{
		CONVAT::operator=(p);
	}
	return *this;
}
void MEO::DocTen()
{
	cout << "\nMEO: " << strTen;
}
///
////////////////////////////////////////////////////////////////////////////////////////////////
///  ////////////////////////////////////////////////////////////////////////////////////////////////

///  ////////////////////////////////////////////////////////////////////////////////////////////////

///  ////////////////////////////////////////////////////////////////////////////////////////////////

class DANHSACHCV
{
private:
	int tongTrongKho;
	CONVAT **dscv;

public:
	DANHSACHCV();
	DANHSACHCV(int x);
	int Nhap(CONVAT *p);
	void In();
	~DANHSACHCV();
};

DANHSACHCV::DANHSACHCV()
{

	tongTrongKho = 0;
	dscv = nullptr;
}

DANHSACHCV::DANHSACHCV(int x)
{

	tongTrongKho = x;
	dscv = new CONVAT *[x + 1];
}

int DANHSACHCV::Nhap(CONVAT *p)
{
	for (int i = 0; i < tongTrongKho; i++)
	{
		if (dscv[i] == nullptr)
		{
			p->NhapVao();
			dscv[i] = p;
			break;
		}
	}
	return 0;
}
void DANHSACHCV::In()
{
	cout << "\nDanh sach " << CONVAT::getSoConNhap() << " cac con vat hien co, bao gom: " << CHO::getSoChoNhap() << " cho va " << MEO::getSoMeoNhap() << " meo";
	for (int i = 0; i < tongTrongKho; i++)
	{
		if (dscv[i] != nullptr)
		{
			dscv[i]->DocTen();
		}
	}
}
DANHSACHCV::~DANHSACHCV()
{
	for (int i = 0; i < tongTrongKho; i++)
	{
		delete dscv[i];
	}
	delete[] dscv;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	CONVAT::InSoConNhap();
	MEO::InSoMeoNhap();
	CHO::InSoChoNhap();
	return 0;
}
