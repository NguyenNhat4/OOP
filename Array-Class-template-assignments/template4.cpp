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
    string name;

public:
    MyArray(string s = "");        // thêm đối mặc định cho 3.2
    MyArray(int n, string s = ""); // thêm đối mặc định cho 3.2
    int GetLength() const;
    T &ElementAt(const int &iIndex);  // nếu bỏ & thì hàm chỉ return giống như trả về 1 giá trị để đọc, chứ không truy cập vào vùng nhớ của phần thử để gán
    T &operator[](const int &iIndex); // Kết quả trả về là tham chiếu để phần tử trả về, có thể đứng ở bên trái của phép toán gán.
    // bổ sung cho bài 2
    MyArray(int n, T value, string name = ""); // thêm đối mặc định cho 3.2
    void PrintArray() const;
    T ElementAt(const int &iIndex) const;  // phiên bản dành riêng cho đối tượng hằng
    T operator[](const int &iIndex) const; // phiên bản dành riêng cho đối tượng hằng
    // bổ sung cho bài 3
    ~MyArray();
    MyArray(const MyArray &b, string s = ""); // thêm đối mặc định cho 3.2
    MyArray &operator=(const MyArray &b);     // toán tử gán
    // bổ sung cho bài 4
    void InputArray();
    template <class T>
    friend ostream &operator<<(ostream &os, MyArray &a);
    template <class T>
    friend ifstream &operator>>(ifstream &if, MyArray &a);
};

// ###INSERT CODE HERE -
template <class T>
void MyArray<T>::InputArray()
{

    if (pElement == nullptr)
    {
        if (name == "")
        {
            cout << "\nNhap so luong phan tu cua mang: ";
            cin >> iLength;
            pElement = new T[iLength];
        }
        else
        {
            cout << "\nNhap so luong phan tu cua mang " << name << ": ";
            cin >> iLength;
            pElement = new T[iLength];
        }
    }
    if (name == "")
    {
        cout << "\nNhap mang voi " << iLength << " gia tri: ";
    }
    else
    {
        cout << "\nNhap mang " << name << " voi " << iLength << " gia tri: ";
    }

    for (size_t i = 0; i < iLength; i++)
    {
        cin >> pElement[i];
    }
}

template <class T>
T &MyArray<T>::ElementAt(const int &x)
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
T MyArray<T>::operator[](const int &x) const
{
    return ElementAt(x);
}
template <class T>
T &MyArray<T>::operator[](const int &x)
{
    return ElementAt(x);
}
template <class T>
MyArray<T> &MyArray<T>::operator=(const MyArray &b)
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
ifstream &operator>>(ifstream &in, MyArray &a)
{
    if (pElement == nullptr)
    {
        if (name == "")
        {
            cout << "\nNhap so luong phan tu cua mang: ";
            in >> iLength;
            pElement = new T[iLength];
        }
        else
        {
            cout << "\nNhap so luong phan tu cua mang " << name << ": ";
            in >> iLength;
            pElement = new T[iLength];
        }
    }
    if (name == "")
    {
        cout << "\nNhap mang voi " << iLength << " gia tri: ";
    }
    else
    {
        cout << "\nNhap mang " << name << " voi " << iLength << " gia tri: ";
    }

    for (size_t i = 0; i < iLength; i++)
    {
        in >> pElement[i];
    }
    return in;
}

template <class T>
ostream &operator<<(ostream &os, MyArray &a)
{
    if (name == "")
    {
        os << "\nXuat mang: ";
    }
    else
    {
        os << "\nXuat mang " << name << ": ";
    }

    if (iLength == 0)
    {
        os << "Mang rong";
        return;
    }
    for (size_t i = 0; i < iLength; i++)
    {
        os << pElement[i] << " ";
    }
    return os;
}

template <class T>
MyArray<T>::MyArray(string s) : pElement(nullptr), iLength(0), name(s) {}

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
MyArray<T>::MyArray(int a, T b, string s)
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

    MyArray<int> a(3), b, c(5, "c"), d("d");
    a.InputArray();
    a.PrintArray();
    b.InputArray();
    b.PrintArray();
    c.InputArray();
    c.PrintArray();
    d.InputArray();
    d.PrintArray();

    return 0;
}
