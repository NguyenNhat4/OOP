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
    T *pElement; // con trỏ quản lý mảng động
    int iLength; // kích thước của mảng, số lượng phần tử tối đa mà mảng có thể chứa được

public:
    // ###INSERT CODE HERE -
    T &ElementAt(T x) const;
    int GetLength() const;
    T &operator[](int idx) const;
    int &operator=(T n) const;
    MyArray();
    MyArray(int a);
};

template <class T>
T &MyArray<T>::ElementAt(T x) const
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
int &MyArray<T>::operator=(T n) const
{
    return *this = n;
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
    }
}

main()
{
    string test;
    cin >> test;
    MyArray<int> a(3), b;

    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[-1] = -1;
    a[3] = 3;
    a.ElementAt(1) = 10;
    a.ElementAt(2) = 20;
    a.ElementAt(3) = 30;
    cout << "\nMang a: ";
    for (int i = 0; i < a.GetLength(); i++)
        cout << a[i] << " ";
    cout << "\nSo luong phan tu cua mang b: ";
    cout << b.GetLength();

    MyArray<int> c(-3);
    cout << "\nSo luong phan tu cua mang c: ";
    cout << c.GetLength();
    return 0;
}
