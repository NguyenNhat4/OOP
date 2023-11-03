#include<iostream>
#include<math.h>
using namespace std;
class Point{
    int x,y;
public:
    Point(){x=0;y=0;}
    Point(int xx, int yy){x=xx;y=yy;}
    void inputOnePoint(){
        int xxxx;
        int yyyy;
        cin>>xxxx>>yyyy;
        x=xxxx;


        y=yyyy;

    }
    void outputOnePoint();
    int kiemtra();
    void checkOnePoint();
    int getOX(){return x;}
    int getOY(){return y;}
};
class DS{
    int n;
    Point *a;
public:
    DS(int m){
        n=m;
        a=new Point[n];
    }
    ~DS(){
        delete []a;
    }
    void output();
    void inputAll();
    void outputAll();
    void tinh(int q,int w);
};

void DS::inputAll(){

    for (int i=0;i<n;i++){

        a[i].inputOnePoint();

    }
}
void DS::outputAll(){
    cout<<"Kiem tra toan bo danh sach diem da nhap: "<<endl;
    for (int i=0;i<n;i++){
        a[i].outputOnePoint();
    }
}
void DS::output(){
    cout<<"Danh sach diem trong mat phang Oxy: "<<endl;
    for (int i=0;i<n;i++){
        cout<<"(";
        cout<<a[i].getOX();
        cout<<",";
        cout<<a[i].getOY()<<")"<<endl;
    }
}


void Point::checkOnePoint(){
    x = x*(-1);
    y= y*(-1);
    cout<<"("<<x<<","<<y<<")"<<endl;
}
void Point::outputOnePoint(){
    cout<<"("<<x<<","<<y<<")";
}
void DS::tinh(int q,int w){
    double min= sqrt( pow(-1*q-a[0].getOX(),2) + pow(-1*w-a[0].getOY(),2));
    int z,v;
    for(int i=0;i<n;i++){
        double k = sqrt( pow((-1)*q-a[i].getOX(),2) + pow((-1)*w-a[i].getOY(),2));
        if( k <= min){
            min = k;
            z = a[i].getOX();
            v = a[i].getOY();
        }
    }

    cout<<"Diem co khoang cach ngan nhat toi ""("1*q<<","<<-1*w<<"): " "("<<z<<","<<v<<")"<<endl;
}
int main(){
    int n;cin>>n;
    DS ds(n);
    ds.inputAll();
    ds.output();
    cout<<"\nNhap mot diem de kiem tra khoang cach:\n";
    Point b;
    b.inputOnePoint();
    cout<<"Diem doi xung voi ";
    b.outputOnePoint();
    cout<<" qua goc toa do O: ";
    b.checkOnePoint();

    ds.tinh(b.getOX(),b.getOY());
    return 0;
}