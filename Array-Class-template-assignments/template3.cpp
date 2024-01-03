/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
struct
###End banned keyword*/
#include <iostream>
using namespace std;

template <class T>
class MyArray
{
private:
    T *pElement;
    int iLength;
    string name; // thêm tên của mảng
public:
    // ###INSERT CODE HERE -

    T &ElementAt(int x) const;
    int GetLength() const;
    T &operator[](int idx) const;
    const MyArray<T> &operator=(const MyArray &b);

    void PrintArray() const;
    MyArray(int a);
    MyArray(int a, int b);
    MyArray(const MyArray &p);
    MyArray();
    MyArray(int a, int b, string s);
    MyArray(int a, string s);
    MyArray(const MyArray &p, string s);
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
    if (name == "")
    {
        cout << "\nXuat mang: ";
    }
    else
    {
        cout << "\nXuat mang " << name << ": ";
    }

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
MyArray<T>::MyArray(string s) : pElement(nullptr), iLength(0), name(s) {}
template <class T>



MyArray<T>::MyArray() : pElement(nullptr), iLength(0), name("") {}
template <class T>
MyArray<T>::MyArray(int a, string s)
{
    name = s;
    if (a <= 0)
    {
        iLength = 0;
        pElement = nullptr;
        cout << "\nLoi: chieu dai mang la so am";
    }
    if (a > 0)
    {
        iLength = a;
        pElement = new T[a];
    }
}
template <class T>
MyArray<T>::MyArray(int a, int b, string s)
{
    if (a <= 0)
    {
        name = s;
        iLength = 0;
        pElement = nullptr;
        cout << "\nLoi: chieu dai mang la so am";
    }
    else
    {
        name = s;
        iLength = a;
        pElement = new T[iLength];
        for (size_t i = 0; i < iLength; i++)
        {
            pElement[i] = b;
        }
    }
}

template <class T>
MyArray<T>::MyArray(const MyArray &p, string s) : iLength{p.iLength}, name{s}
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
}
int main()
{
    string test;
    cin >> test;
    MyArray<int> a1(3), a2(5, -1, "a2");
    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 3;
    a1.PrintArray();
    a2.PrintArray();

    MyArray<int> b1(a1), b2(a2, "b2"), b3 = a1;
    b1.PrintArray();
    b2.PrintArray();
    b3.PrintArray();

    MyArray<int> c1(3, "c1");
    MyArray<int> c2(3, "c2");
    MyArray<int> d1("d1");
    MyArray<int> d2;
    c2 = c1 = a1;
    c1.PrintArray();
    c2.PrintArray();
    d1 = d2 = a2;
    d1.PrintArray();
    d2.PrintArray();

    return 0;
}
