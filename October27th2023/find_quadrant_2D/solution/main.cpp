#include <iostream>
using namespace std;
class Diem{
    int x,y;
public:
    Diem(){x=0;y=0;}
    Diem(int xx, int yy){ x=xx;y=yy;}
    void input1Diem();
    void xuat1diem();
    void xacDinhGocPhan4();
    void setMotDiem(int xx,int yy){
        x = xx;
        y =yy;
    }
};
void Diem::input1Diem() {
    int xx,yy;
    cin>>xx>>yy;
    setMotDiem(xx,yy);
}
void Diem::xuat1diem(){
    cout<< "(" << x << "," << y << ")";
}

void Diem::xacDinhGocPhan4(){
if(x==0 && y==0){
    cout<<" la goc toa do"<<endl;
}
if(x==0 && y!=0){
    cout<<" nam tren truc tung"<<endl;
}
if(y==0 && x!=0){
    cout<<" nam tren truc hoanh"<<endl;
}

if(x>0 && y>0){
    cout<<" thuoc goc phan tu thu I" <<endl;
}

if(x>0 && y<0){
    cout<<" thuoc goc phan tu thu IV" <<endl;
}
    if(x<0 && y>0){
        cout<<" thuoc goc phan tu thu II" <<endl;
    }
    if(x<0 && y<0){
        cout<<" thuoc goc phan tu thu III" <<endl;
    }

}


class DS{
private:
    int n;
    Diem *diem;
public:
    DS(){
     int n = 0;
     diem = nullptr;
    }
    DS(int nn){
        n =nn;
        diem = new Diem[n+1];
    }
    void inputAll();
    void outputDS();
  void xacDinhGocPhanCuaTatCa();
};
void DS::inputAll(){
    for(int i = 0;i<n;i++){
        diem[i].input1Diem();
    }
}

void DS::outputDS() {
    for(int i = 0;i<n;i++){
        diem[i].xuat1diem();
        cout<<endl;
    }

}
void DS::xacDinhGocPhanCuaTatCa() {
    for(int i = 0;i<n;i++){
        diem[i].xuat1diem();
        diem[i].xacDinhGocPhan4();
    }

}
int main() {
int n; cin>>n;


    DS danhsachdiem(n);
    danhsachdiem.inputAll();

cout<<"Danh sach diem trong mat phang Oxy:"<<endl;
    danhsachdiem.outputDS();
    cout<<"Nhap mot diem de kiem tra:"<<endl;
    Diem a;
    a.input1Diem();
    cout<<"Diem ";
    a.xuat1diem(); cout<<" ";
    a.xacDinhGocPhan4();
cout<<"Kiem tra toan bo danh sach diem da nhap:"<<endl;
danhsachdiem.xacDinhGocPhanCuaTatCa();
    return 0;
}
