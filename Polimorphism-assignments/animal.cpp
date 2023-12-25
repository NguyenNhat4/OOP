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
class CONVAT {
protected:
    char *strTen;
    int iLoai; //0: cho,1:meo
public:
    CONVAT();
    CONVAT(char *ten);
    //###INSERT CODE HERE -
    virtual   void XungTen() =0 ;
   static void InSoConNhap();
    private: 
   static int soConNhap ;
};
int CONVAT::soConNhap = 0; //  

void CONVAT::InSoConNhap() {
    cout<<"\nSo con vat nhap kho: ";
    cout<<soConNhap;
}
CONVAT::CONVAT() {
    strTen=NULL;
    iLoai = -1;
}
CONVAT::CONVAT(char *ten) {
    strTen = SaoChep(ten);
}

class CHO : public  CONVAT{
public:
static void InSoChoNhap();
 void XungTen()   override;
    CHO(char *ten):CONVAT(ten){iLoai=0;}
    CHO():CONVAT(){iLoai=0;}
    private:
    static int soChoNhap;

};
int CHO::soChoNhap = 0;
void CHO::InSoChoNhap(){
cout<< "\nSo con cho nhap kho: " << soChoNhap;
}
void CHO::XungTen() {
    cout<<"\nDay la con cho, ten la "<<strTen;
}
class MEO: public  CONVAT{
public:
    void XungTen()   override;
    MEO(char *ten):CONVAT(ten){iLoai=1;}
    MEO():CONVAT(){iLoai=1;}
    static void InSoMeoNhap();
    private:
    static int soMeoNhap;
};
int MEO::soMeoNhap = 0;
void MEO::XungTen() {
    cout<<"\nDay la con meo, ten la "<<strTen;
}
 void MEO::InSoMeoNhap(){
    cout<<"\nSo con meo nhap kho: "<<soMeoNhap;
 }
int main()
{
    string test;cin>>test;

CONVAT *c1 = new CHO("MUC"); CONVAT *c2 = new CHO("LAI"); CONVAT *c3 = new CHO("NHAT");
	c1->XungTen();c2->XungTen();c3->XungTen();
	CONVAT *m1 = new MEO("MUOP"); CONVAT *m2 = new MEO("DEN");
	m1->XungTen();m2->XungTen();
	CONVAT::InSoConNhap();
	MEO::InSoMeoNhap();
	CHO::InSoChoNhap();

	return 0;
}