#include <iostream>
#include <cstring>

using namespace std;

class CDate
{
    static int dayTab[][13]; // luu so ngay cua moi thang
    int day, month, year;
public:
    int getday(){return day;}
    static bool LeapYear(int y); // kiem tra nam nhuan
    static int DayOfMonth(int m, int y); // tra ve so ngay cua thang
    static bool ValidDate(int d, int m, int y); //kiem tra ngay hop le
    void Input(); //nhap 1 ngay hop le
    void Output(); //xuat thong tin thang co bao nhieu ngay
};
int CDate::dayTab[][13]={
        {0,31,28,31,30,31,30,31,31,30,31,30,31},
        {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
bool CDate::LeapYear(int y){
    return ((y%4==0 && y%100!=0) || (y%100==0 && y%400==0));
}
int CDate::DayOfMonth(int m,int y){
    return (dayTab[LeapYear(y)][m]);
}
bool between(int x,int min,int max){
    return (x>=min && x<=max);
}
bool CDate::ValidDate(int d,int m,int y){
    return (between(m,1,12) && between(d,1,DayOfMonth(m,y)));
}
void CDate::Output(){
    cout<<day<<"/"<<month<<"/"<<year;
}
void CDate::Input(){
    do {
        cin>>day>>month>>year;
    }while(ValidDate(day,month,year)==0);
}

class chuoi {
private:
    char* data;
public:
    chuoi() : data(nullptr) {}
    void getline(istream& is) {
        char buffer[300];
        is.getline(buffer, sizeof(buffer));
        if (data) {
            delete[] data;
            data = nullptr;
        }
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }
        data = new char[strlen(buffer) + 1];
        strcpy(data, buffer);
    }

    friend istream& operator>>(istream& is, chuoi& sh) {

        char buffer[256];
        is >> buffer;
        if (sh.data) {
            delete[] sh.data;
            sh.data = nullptr;
        }
        sh.data = new char[strlen(buffer) + 1];
        strcpy(sh.data, buffer);
        return is;
    }
    friend ostream& operator<<(ostream& os, const chuoi& sh) {
        os<<sh.data;
        return os;
    }

    ~chuoi() {
        if (data) {
            delete[] data;
        }
    }
};


class Person{
private:
    chuoi name;
    int id;
    CDate ngaysinh;
public:

    void input(){
        cin>>id;
        cin.ignore();
        name.getline(cin);
        ngaysinh.Input();
    }

    void output(){
        //  cout<<"ID\t|Full name\t|Date of birth\t|Maths\t|Phys\t|Chemis\t|Average score\n";
        cout<<id<<"\t|";
        cout<<name<<"\t|";
        ngaysinh.Output();
        cout<< "\t|";
    }
};
class Student: public Person{
private:
    float toan,ly,hoa;
public:
    float average(){
        return (toan+ly+hoa)/3;
    }
    void inputStudent(){
        Person::input();
        cin>>toan>>ly>>hoa;
    }
    void outputStudent(){
        // cout<<"ID\t|Full name\t|Date of birth\t|Maths\t|Phys\t|Chemis\t|Average score\n";
        Person::output();
        cout<<toan<<"\t|";
        cout<<ly<<"\t|";
        cout<<hoa<<"\t|";
        cout<<average()<<"\n";
    }

};

int main(){
    int n;
    Student* a = new Student[n];
    cout<<"ID\t|Full name\t|Date of birth\t|Maths\t|Phys\t|Chemis\t|Average score\n";
    cin>>n;
    for(int i =0;i<n;i++){
        a[i].inputStudent();
    }
    for(int i =0;i<n;i++){
        a[i].outputStudent();
    }
    delete []a;
    return 0;
}