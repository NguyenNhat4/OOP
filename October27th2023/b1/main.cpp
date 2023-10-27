
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
struct
###End banned keyword*/

#include <iostream>
#include <math.h>

using namespace std;

class CDate
{
    static int dayTab[][13]; // luu so ngay cua moi thang
    int day, month, year;
public:
    static bool LeapYear(int y); // kiem tra nam nhuan
    static int DayOfMonth(int m, int y); // tra ve so ngay cua thang
    static bool ValidDate(int d, int m, int y); //kiem tra ngay hop le
    void Input(); //nhap 1 ngay hop le
    void Output(); //xuat thong tin thang co bao nhieu ngay
};

//###INSERT CODE HERE -
int CDate::dayTab[][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31},
};

bool CDate::LeapYear(int y)
{
    return ((y%4==0 && y%100!=0) || (y%100==0 && y%400==0));
}

int CDate::DayOfMonth(int m, int y) {
    return  dayTab[LeapYear(y)][m];
}

bool between(int m,int min,int max){
    return m<=max && m>=min;
}

bool CDate::ValidDate(int d, int m, int y) {
    return between(m,1,12) &&  between(d,1, DayOfMonth(m,y));
}
void CDate::Input() {
    cout<<"Moi ban nhap 1 ngay: "<<endl;
    do {
        cin>>day>>month>>year;
        if(ValidDate(day,month,year)==0){
            cout<<"Xin hay nhap 1 ngay hop le: "<<endl;
        }
    }while(ValidDate(day,month,year)==0);

}

void CDate::Output() {
    cout<<"Thang "<< month<<"/"<<year<< " co " <<DayOfMonth(month,year)<< " ngay";
}


int main()
{
    CDate date;
    date.Input();
    date.Output();

    return 0;
}
