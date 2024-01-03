/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
###End banned keyword*/
#include <iostream>
using namespace std;


template<class T> class MyArray
{
    private:
        T *pElement; //con trỏ quản lý mảng động
        int iLength; //kích thước của mảng, số lượng phần tử tối đa mà mảng có thể chứa được

    public:


    
    T &ElementAt(int x) const;
    int GetLength() const;
    T &operator[](int idx) const;
    const MyArray<T> &operator=(const MyArray &b);

    void PrintArray() const;
    MyArray();
    MyArray(int a);
    MyArray(int a, int b);
    MyArray(const MyArray &p);
    MyArray(string s);
    ~MyArray();
};

template <class T>
T &MyArray<T>::ElementAt(int x) const
{
    if (x < 0 || x >= iLength)
    {
        cout << "\nLoi: truy xuat phan tu ngoai pham vi mang";
    }

    return pElement[x];
}
template <class T>
int MyArray<T>::GetLength() const
{
    return iLength;
}

template <class T>
T &MyArray<T>::operator[](int x) const
{
    return ElementAt(x);
}

template <class T>
const MyArray<T> &MyArray<T>::operator=(const MyArray &b)
{

    if (pElement == nullptr)
    {
        cout << "\nCap phat bo nho truoc khi gan";
        iLength = b.iLength;
        pElement = new T[iLength];
    }
    if (iLength != b.iLength)
    {
        cout << "\nPhep gan khong tuong thich, khong gan duoc";
        return *this;
    }

    for (int i = 0; i < iLength; i++)
    {
        ElementAt(i) = b.pElement[i];
    }

    return *this;
}

template <class T>
void MyArray<T>::PrintArray() const
{
    if (iLength == 0)
    {
        cout << "Mang rong";
        return;
    }
    for (size_t i = 0; i < iLength; i++)
    {
        cout << pElement[i] << " ";
    }
}

template <class T>
MyArray<T>::MyArray()
{
    pElement = nullptr;
    iLength = 0;
}

template <class T>
MyArray<T>::MyArray(int a)
{
    if (a < 0)
    {
        iLength = 0;
        pElement = nullptr;
        cout << "\nLoi: chieu dai mang la so am";
    }
    else
    {
        iLength = a;
        pElement = new T[iLength];
    }
}
template <class T>
MyArray<T>::MyArray(int a, int b)
{
    if (a <= 0)
    {
        iLength = 0;
        pElement = nullptr;
        cout << "\nLoi: chieu dai mang la so am";
    }
    else
    {
        iLength = a;
        pElement = new T[iLength];
        for (size_t i = 0; i < iLength; i++)
        {
            pElement[i] = b;
        }
    }
}
template <class T>
MyArray<T>::MyArray(const MyArray &p) : iLength{p.iLength}
{

    pElement = new T[iLength];
    for (size_t i = 0; i < iLength; i++)
    {
        pElement[i] = p.pElement[i];
    }
}

template <class T>
MyArray<T>::~MyArray()
{
   cout << "\nGoi ham huy";
}




int main()
{
    string test;cin>>test;
    MyArray<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    cout<<"\nMang a: ";
    a.PrintArray();
    MyArray<int> b1(a), b2=a;
    cout<<"\nMang b1: ";
    b1.PrintArray();
    cout<<"\nMang b2: ";
    b2.PrintArray();


    MyArray<int> c1(3),c2;
    c2=c1=a;
    cout<<"\nMang c1: ";
    c1.PrintArray();
    cout<<"\nMang c2: ";
    c2.PrintArray();

    return 0;
}
